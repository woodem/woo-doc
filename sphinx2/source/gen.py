import woo.document
# import all modules here
from woo import utils,log,timing,pack,document,manpage,plot,post2d,runtime,WeightedAverage2d
import minieigen,re,sys,sphinx,os,os.path
import builtins
import sphinx.cmd.build
##
## generated parts of the docs here
##
cg2=open('theory/geom/generated-cg2-table.rst-fragment','w')
cg2.write(woo.document.makeCGeomFunctorsMatrix()+'\n\n')
cg2.close()

import warnings
warnings.filterwarnings('ignore',category=DeprecationWarning,module='.*IPython.*')




if not '--only-extras' in sys.argv:
    rsts=woo.document.allWooPackages('.')
    print('*** RST:',rsts)
    wooMods='wooMods.rst'
    with open(wooMods,'w') as f:
        f.write('Woo modules\n######################\n\n')
        f.write('.. toctree::\n\n')
        for o in sorted(rsts):
            print('USING',o)
            if re.match('(^|.*/)wooExtra(\..*)?$',o):
                print('[SKIPPED]')
                continue
            f.write('    %s\n'%o)
    if 1:
        for fmt in ['html','latex']:
            # see discussion of https://github.com/sphinx-doc/sphinx/issues/4623
            # the first arg used to be ignored, now is used
            args=['-T','-b',fmt,'-j','1','-d','../build/doctrees','../source','../build/%s'%fmt]
            print('Calling sphinx.cmd.build.build_main with: '+str(args))
            builtins.woo_sphinx_fmt=fmt # this is used in conf.py
            # RemovedInSphinx20Warning: `sphinx.build_main()` has moved to `sphinx.cmd.build.build_main()`.
            sphinx.cmd.build.build_main(args)
            print('Sphinx finished for format %s.'%fmt)



#
# document extra modules, in separate trees
#
import pkg_resources, shutil,re 
for mName in [m for m in sys.modules if m.startswith('wooExtra.') and len(m.split('.'))==2]:
    mod=sys.modules[mName]
    srcDir='../source-extra/'+mod.KEY
    outDir='../build-extra/'+mod.KEY
    if not os.path.exists(srcDir): os.makedirs(srcDir)
    outName=srcDir+'/index.rst'
    print('WRITING OUTPUT FOR %s TO %s'%(mName,outName))
    with open(outName,'w') as f:
        f.write('.. note:: This page is not `documentation of Woo itself <http://www.woodem.org>`_, only of an extra module.\n\n')
        f.write('%s module\n################################\n\n'%mName)
        woo.document.oneModuleWithSubmodules(mod,f)
    # copy config over
    confName=srcDir+'/conf.py'
    shutil.copyfile('conf.py',confName) 
    statDir=srcDir+'/_static'
    #shutils.copyfile(glob.glob('_static/*),srcDir+
    if not os.path.exists(statDir): os.symlink(os.path.relpath('_static',srcDir),statDir)
    ## copy package resources to the source directory
    for R in ('resources','data'): # future-proof :)
        try:
            resDir=pkg_resources.resource_filename(mName,R) # if zipped, seaches in zip, possibly raising KeyError
            print(srcDir,resDir,R)
            if os.path.exists(resDir) and not os.path.exists(srcDir+'/'+R): os.symlink(resDir,srcDir+'/'+R)
        except KeyError: pass 
    # HACK: change some values in the config
    with open(confName,'a') as conf:
        conf.write(u"""
project = u'{mName}'
version = u'{version}'
release = u'{version}'
copyright = u'{copyright} (distributor)'
master_doc = u'index'
templates_path=['../../source/_templates'] 
html_static_path=['../../source/_static']
intersphinx_mapping={{'woo':('https://woodem.org',None)}}
extensions=[e for e in extensions if e!='sphinx.ext.viewcode'] # don't show code in extras, stragely wooExtra.* is included, not just the one particular extra module
html_additional_pages = {{ }} # double here because of .format(...)
modindex_common_prefix = [ '{mName}' ]
latex_documents = [('index','{mName}','{mName} Documentation',u'Václav Šmilauer','manual')]
latex_logo='../../source/woo-logo.pdf'
        """.format(
            version=pkg_resources.get_distribution(mName).version,
            mName=mName,
            copyright=re.sub('<[^<]+?>','',mod.distributor.replace('<br>',', '))
        ))
    if 1:
        for fmt in 'html',: # 'latex':
            args=['-T','-b',fmt,'-j','1','-d','../build-doctrees',srcDir,outDir+'/'+fmt]
            print('Calling sphinx.build_main with: '+str(args))
            builtins.woo_sphinx_fmt=fmt # this is used in conf.py
            sphinx.cmd.build.build_main(args)

        

