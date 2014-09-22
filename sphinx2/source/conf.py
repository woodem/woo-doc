# -*- coding: utf-8 -*-
#
# Woo documentation build configuration file, created by
# sphinx-quickstart on Sat Jun 16 15:52:22 2012.
#
# This file is execfile()d with the current directory set to its containing dir.
#
# Note that not all possible configuration values are present in this
# autogenerated file.
#
# All configuration values have a default; values that are commented out
# serve to show the default.

import sys, os, re

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#sys.path.insert(0, os.path.abspath('.'))

# -- General configuration -----------------------------------------------------

# If your documentation needs a minimal Sphinx version, state it here.
#needs_sphinx = '1.0'

# Add any Sphinx extension module names here, as strings. They can be extensions
# coming with Sphinx (named 'sphinx.ext.*') or your custom ones.

try:
	import IPython.sphinxext.ipython_directive
	import IPython.sphinxext.ipython_console_highlighting
except ImportError:
	raise ImportError("IPython.sphinxext.ipython_directive or IPython.sphinxext.ipython_console_highlighting module not found?!")

try:
	import cloud_sptheme
except ImportError:
	raise ImportError("Sphinx cloud theme is not importable; install it using 'easy_install cloud_sptheme'.")

try:
	import sphinxcontrib.bibtex
except ImportError:
	raise ImportError("BibTeX support for sphinx not found; install it using 'easy_install sphinxcontrib-bibtex'")

try:
	import sphinxcontrib.newsfeed
except ImportError:
	raise ImportError("Disqus support for sphinx not found; install it using 'easy_install sphinxcontrib-newsfeed'")

mathjax=('PNGMATH' not in os.environ)
if not mathjax: print 100*'#'+'  USING PNGMATH  '+100*'#'

extensions = ['sphinx.ext.autodoc', 'sphinx.ext.doctest', 'sphinx.ext.mathjax' if mathjax else 'sphinx.ext.pngmath', 'sphinx.ext.viewcode', 'matplotlib.sphinxext.plot_directive', 'sphinx.ext.inheritance_diagram', 'sphinx.ext.intersphinx', 'sphinx.ext.todo', 'sphinx.ext.extlinks', 'sphinxcontrib.bibtex','sphinxcontrib.newsfeed',
	# local copies
	'sphinxcontrib_youtube',
	'tikz',
	'IPython.sphinxext.ipython_directive','IPython.sphinxext.ipython_console_highlighting',
	# experimental
	# 'breathe'
]

breathe_default_project='woo'
breathe_projects={'woo':'../../doxygen/xml'}
breathe_default_members=('members','undoc-members','private-members')


# customize prompts
# TODO
ipython_rgxin =re.compile(r'Woo \[(\d+)\]:\s?(.*)\s*')
ipython_rgxout=re.compile(r'Out\[(\d+)\]:\s?(.*)\s*')
#ipython_rgxout=re.compile(r'\s*\S*(Out)\S*: \[0m(.*)\s*')
ipython_promptin ='Woo[%d]:'  ### make smaller to be aligned with "Out" as " -> " does not show up
ipython_promptout=' -> [%d]:' ### FIXME:: this does not work for some reason :|

import IPython.sphinxext.ipython_console_highlighting as ich
# TODO: 
ich.IPythonConsoleLexer.input_prompt=re.compile(r'(Woo\[[0-9]+\]: )')
ich.IPythonConsoleLexer.output_prompt=re.compile(r'(( -> |Out)|\[[0-9]+\]: )')
ich.IPythonConsoleLexer.continue_prompt=re.compile(r'\s+\.\.\.+:')

intersphinx_mapping={'yade':('http://www.yade-dem.org/doc',None)}

# make graphviz determine the best size instead of hard-coded one
# http://stackoverflow.com/a/2151808/761090
inheritance_graph_attrs = dict(size='""')

todo_include_todos=True

## matplotlib default params
import matplotlib
matplotlib.rc('lines',linewidth=3)
matplotlib.rc('axes',grid=True)

tikz_latex_preamble=r'\usepackage{pgfplots}'
tikz_tikzlibraries=''

# show discussion form at the bottom of every page
disqus_shortname='woodem'
rst_epilog='\n\n.. disqus::\n\n'

extlinks={'woosrc':('http://bazaar.launchpad.net/~eudoxos/woo/trunk/view/head:/%s','')}

## customize mathjax
## hack from https://bitbucket.org/birkenfeld/sphinx/issue/969/allow-mathjax-customization-via-localjs 
mathjax_path = 'MathJax_local.js' # file including MathJax from CDN plus local config, in _static

# config for pngmath (in case we have to use that)
pngmath_use_preview=True
pngmath_add_tooltips=True
pngmath_latex_preamble=r'''
\usepackage{euler} % must be loaded before fontspec for the whole doc (below); this must be kept for pngmath, however
\usepackage{hyperref}
\usepackage{amsmath}
\usepackage{amsbsy}
\usepackage{underscore}
% symbols
\let\mat\boldsymbol % matrix
\let\vec\boldsymbol % vector
\let\tens\boldsymbol % tensor


\def\normalized#1{\frac{31}{|\cdot|}}
\def\u#1{\,\mathrm{#1}}
\def\d{\,\mathrm{d}}
\DeclareMathOperator{\tr}{tr}

% timestep
\def\Dt{\Delta t}
% variants for greek symbols
\let\epsilon\varepsilon
\let\theta\vartheta
\let\phi\varphi
\let\eps\varepsilon % abbrev

% variables at different points of time 
\def\prev#1{#1^-}
\def\pprev#1{#1^\ominus}
\def\curr#1{#1^{\circ}}
\def\nnext#1{#1^\oplus}
\def\next#1{#1^+}
'''



# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# The suffix of source filenames.
source_suffix = '.rst'

# The encoding of source files.
#source_encoding = 'utf-8-sig'

# The master toctree document.
master_doc = 'contents'

# General information about the project.
project = u'Woo'
copyright = u'2012, Václav Šmilauer <eu@doxos.eu>'

# The version info for the project you're documenting, acts as replacement for
# |version| and |release|, also used in various other places throughout the
# built documents.
#
# The short X.Y version.
version = '0.99'
# The full version, including alpha/beta/rc tags.

from bzrlib.branch import BzrBranch
revno=str(BzrBranch.open_containing('../../..')[0].last_revision_info()[0])
release = 'rev'+revno

# The language for content autogenerated by Sphinx. Refer to documentation
# for a list of supported languages.
#language = English

# There are two options for replacing |today|: either, you set today to some
# non-false value, then it is used:
#today = ''
# Else, today_fmt is used as the format for a strftime call.
#today_fmt = '%B %d, %Y'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
exclude_patterns = ['**/wooExtra']

# The reST default role (used for this markup: `text`) to use for all documents.
#default_role = None

# If true, '()' will be appended to :func: etc. cross-reference text.
#add_function_parentheses = True

# If true, the current module name will be prepended to all description
# unit titles (such as .. function::).
#add_module_names = True

# If true, sectionauthor and moduleauthor directives will be shown in the
# output. They are ignored by default.
show_authors = True

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = 'sphinx'

# A list of ignored prefixes for module index sorting.
modindex_common_prefix = ['woo.']


# -- Options for HTML output ---------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
if 0:
	html_theme = 'pyramid'
else:
	import cloud_sptheme
	html_theme='cloud'
	html_theme_path=[cloud_sptheme.get_theme_dir()]
	html_theme_options={'roottarget':'index','stickysidebar':'true','popuptoc':'true'}

# Theme options are theme-specific and customize the look and feel of a theme
# further.  For a list of options available for each theme, see the
# documentation.
#html_theme_options = {}

# Add any paths that contain custom themes here, relative to this directory.
#html_theme_path = []

# The name for this set of Sphinx documents.  If None, it defaults to
# "<project> v<release> documentation".
#html_title = None

# A shorter title for the navigation bar.  Default is the same as html_title.
#html_short_title = None

# The name of an image file (relative to this directory) to place at the top
# of the sidebar.
#html_logo = None

# The name of an image file (within the static path) to use as favicon of the
# docs.  This file should be a Windows icon file (.ico) being 16x16 or 32x32
# pixels large.
html_favicon = '_static/woo-favicon.ico'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

# If not '', a 'Last updated on:' timestamp is inserted at every page bottom,
# using the given strftime format.
#html_last_updated_fmt = '%b %d, %Y'

# If true, SmartyPants will be used to convert quotes and dashes to
# typographically correct entities.
#html_use_smartypants = True

# Custom sidebar templates, maps document names to template names.
#html_sidebars = {}

# Additional templates that should be rendered to pages, maps page names to
# template names.
#html_additional_pages = {}
html_additional_pages = { 'index':'index.html'}
html_index='index.html'


# If false, no module index is generated.
#html_domain_indices = True

# If false, no index is generated.
#html_use_index = True

# If true, the index is split into individual pages for each letter.
#html_split_index = False

# If true, links to the reST sources are added to the pages.
#html_show_sourcelink = True

# If true, "Created using Sphinx" is shown in the HTML footer. Default is True.
#html_show_sphinx = True

# If true, "(C) Copyright ..." is shown in the HTML footer. Default is True.
#html_show_copyright = True

# If true, an OpenSearch description file will be output, and all pages will
# contain a <link> tag referring to it.  The value of this option must be the
# base URL from which the finished HTML is served.
#html_use_opensearch = ''

# This is the file name suffix for HTML files (e.g. ".xhtml").
#html_file_suffix = None

# Output file base name for HTML help builder.
htmlhelp_basename = 'Woodoc'


# -- Options for LaTeX output --------------------------------------------------

latex_elements = {
# The paper size ('letterpaper' or 'a4paper').
#'papersize': 'letterpaper',

# The font size ('10pt', '11pt' or '12pt').
#'pointsize': '10pt',

# Additional stuff for the LaTeX preamble.
'preamble': '\usepackage{tikz,pgfplots}',
}

# Grouping the document tree into LaTeX files. List of tuples
# (source start file, target name, title, author, documentclass [howto/manual]).
latex_documents = [
  ('index', 'Woo.tex', u'Woo Documentation',
   u'Václav Šmilauer', 'manual'),
]

# The name of an image file (relative to this directory) to place at the top of
# the title page.
#latex_logo = None

# For "manual" documents, if this is true, then toplevel headings are parts,
# not chapters.
#latex_use_parts = False

# If true, show page references after internal links.
#latex_show_pagerefs = False

# If true, show URL addresses after external links.
#latex_show_urls = False

# Documents to append as an appendix to all manuals.
#latex_appendices = []

# If false, no module index is generated.
#latex_domain_indices = True


# -- Options for manual page output --------------------------------------------

# One entry per manual page. List of tuples
# (source start file, name, description, authors, manual section).
man_pages = [
    ('index', 'woo', u'Woo Documentation',
     [u'Václav Šmilauer'], 1)
]

# If true, show URL addresses after external links.
#man_show_urls = False


# -- Options for Texinfo output ------------------------------------------------

# Grouping the document tree into Texinfo files. List of tuples
# (source start file, target name, title, author,
#  dir menu entry, description, category)
texinfo_documents = [
  ('index', 'Woo', u'Woo Documentation',
   u'Václav Šmilauer', 'Woo', 'One line description of project.',
   'Miscellaneous'),
]

# Documents to append as an appendix to all manuals.
#texinfo_appendices = []

# If false, no module index is generated.
#texinfo_domain_indices = True

# How to display URL addresses: 'footnote', 'no', or 'inline'.
#texinfo_show_urls = 'footnote'

graphviz_output_format='png'

