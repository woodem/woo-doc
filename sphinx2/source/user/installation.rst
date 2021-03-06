***************
Installing Woo
***************

Linux
=====

Linux is the platform of choice for both developing and using Woo. Installation can be done in several ways, trading fexibility for straightforwardness.

Package installation
---------------------

.. admonition:: Ubuntu

   Installation from pre-compiled packages is **no longer** the recommended method of installation. The packages are often broken or out of date. For the posterity, outdated instructions follow; use at your own danger.
   
   You will receive updates automatically via your system's package manager. `Woo-daily package archive <https://code.launchpad.net/~eudoxos/+archive/woo-daily>`_ contains the packages. The oldest supported version is 14.04 LTS, but you are well advised to stay with newer (e.g. last LTS) if possible.
   
   Open the terminal and type::

      sudo add-apt-repository ppa:eudoxos/woo-daily
      sudo apt-get update
      sudo apt-get install python3-woo

   On older distribution, ``python3-woo`` is not available and you can install ``python-woo`` instead. It is advised to use Python 3; functionality is the same, user scripts are 99% compatible (if you avoid centrain constructs) and Python 2.7 support will be dropped at some later point. If you use python 2.7, drop the ``3`` prefix from commands listed below (``python-pip`` instead of ``python3-pip``, ``pip`` instead of ``pip3``).

   If you see this or similar error when running ``woo``::

      /usr/lib/python2.7/dist-packages/IPython/lib/inputhook.pyc in enable_gui(gui, app)
          538     except KeyError:
          539         e = "Invalid GUI request %r, valid ones are:%s" % (gui, guis.keys())
      --> 540         raise ValueError(e)
          541     return gui_hook(app)
          542
      
      ValueError: Invalid GUI request 'qt5', valid ones are:['osx', 'qt4', 'glut', None, 'gtk3', 'pyglet', 'wx', 'none', 'qt', 'gtk', 'tk']

   the packaged version of ``ipython`` does not support ``qt5`` yet. This can be fixed by installing a newer version from `Python package index (a.k.a. PyPI) <https://pypi.python.org/>`__ by running (provided you have ``pip3`` installed; if not, run ``sudo apt-get install python3-pip``)::

      pip3 install ipython

   or::

      sudo pip3 install --system ipython     # installation for all users

   which should pull IPython from PyPI and install it locally; this newer version will take precedence over the one installed from APT packages, no problem to have both installed at the same time. After this, ``woo`` should launch normally.


Compilation from source
-----------------------
Source code is hosted at `GitHub <https://github.com/woodem/woo>`__ and can be otained with the `Git revision control system <http://git-scm.com/>`__ by saying ``git clone https://github.com/woodem/woo.git``.

(We still also use the hosting and `Launchpad <http://www.launchpad.net/woo>`_ and sources synced from GitHub can be obtained with the `Bazaar  <http://bazaar.canonical.com>`_ by saying ``bzr checkout lp:woo``. Prefer to use git, however, since updates via ``-RR`` are more reliable, and git is also much faster).

Woo is written in `C++11 <http://en.wikipedia.org/wiki/C%2B%2B11>`_ and can be compiled with gcc>=4.6 or clang >= 3.1. Note that clang does not support all features (``openmp`` in particular).

Woo depends on a number of libraries. Those are in particular

#. `boost <http://www.boost.org>`_, version >= 1.48.
#. `python <http://www.python.org>`_, version 2.7 or >= 3.4 (support for 2.7 is currently retained, but will be removed in the future)
#. `eigen <http://eigen.tuxfamily.org>`_ (math routines)
#. `Qt5 <http://qt.digia.com>`_ and `PyQt5 <http://www.riverbankcomputing.co.uk/software/pyqt>`_ (optional: user interface), or Qt4 (older, but supported)
#. `VTK <http://www.vtk.org>`_ (optional: export to `Paraview <http://www.paraview.org>`_)
#. `GTS <http://gts.sourceforge.net>`_ (optional: manipulation of triangulated surfaces)
#. `FreeGLUT <http://freeglut.sourceforge.net>`_, `GLE <http://www.linas.org/gle>`_ (optional: OpenGL display)
#. A number of python modules: ``matplotlib`` (plotting), ``genshi`` (HTML export), ``xlrd`` & ``xlwt`` (XLS export), ``minieigen`` (math in python), ``xlib``, ``psutil``, …

Ubuntu machines can be easily set up for development with Woo using the `woo-install-ubuntu.sh <http://bazaar.launchpad.net/~eudoxos/woo/trunk/view/head:/scripts/woo-install-ubuntu.sh>`_ script. This script also installs packages neede for building.

Compilation is driven using `scons <http://www.scons.org>`_ and takes a number of options. They are listed when ``scons -h`` is run from the source directory, and are remembered accross compilations (they can be given just the first time):

-  ``features``: Comma-separated list of features to compile with. Important values are

   * ``openmp``: Compile with OpenMP, to support multi-threaded computations. This feature is supported only by ``gcc`` (not ``clang``). Note that number of threads can be set :ref:`at runtime <Running_Woo>` using the ``-jN`` option.
   * ``qt4``: Enable user interface based on Qt4 (**deprecated**);
   * ``qt5``: Enable user interface based on Qt5;
   * ``opengl``: Enable 3D display during simulations; requires ``qt4`` or ``qt5`` to be enabled as well.
   * ``vtk``: Enable export to file using VTK file formats, for export to `Paraview <http://www.paraview.org>`_.
   * ``gts``: Enable building the (adapted) :obj:`woo.gts` module.

- ``jobs``: Number of compilations to run simultaneously. Can be set to the number of cores your machine has, but make sure you have at least 3GB RAM per each job if you use ``gcc`` − Woo is quite RAM-hungry during compilation, due to extensive use of templates, especially in boost::python.
- ``CPPPATH``: Path for preprocessor. Usually, you only need to set this if you have VTK or Eigen in non-standard locations.
- ``CXX``: The compiler to use.
- ``PYTHON``: Python interpreter to use; SCons itself always runs with python 2.x, but it is possible to use a different interpreter for Woo itself (such as ``python3``).

.. note:: Using Python 3.x is recommended (>=3.4, which all recent distributions ship); do this as shown below by passing the ``PYTHON`` option.

A typical first-compile command line may look like this::

   scons jobs=4 CXX='ccache g++' features=qt4,opengl,vtk,openmp,gts PYTHON=/usr/bin/python3

For quick development, woo takes the ``-R`` flag, which will recompile itself (with remembered options) and run. The ``-RR`` flag will, in addition, update the source from upstream before recompiling (if managed with git).


Virtual environment
^^^^^^^^^^^^^^^^^^^

Python allows for creation of separate `Virtual environments <http://docs.python-guide.org/en/latest/dev/virtualenvs/>`__ which is an isolated working copy of Pyhon. This is useful if you want to keep multiple version of Woo around simultaneously, or don't want to install system-wide (where different users need a different version, and perhaps don't have permissions to install to system directories).

If you want to use SCons for building (which is quite useful for keeping your installation up-to-date, and necessary if you want to modify the source code), do something like the following example. You need to have all required headers and libraries installed somewhere where they will be found. This example compiles Woo without the ``opengl`` and ``qt4`` features, for running Woo without the graphical interface (useful e.g. on computing nodes in clusters).

.. code-block:: bash

    # install the support for virtual environments
    pip3 install virtualenv
    # create the virtual environment in some directory
    virtualenv my/venv
    # sets environment variables (e.g. $PATH) so that venv commands are found first
    source my/venv/bin/activate
    # install all required python modules, this may take a while
    # note: headers for HDF5 must be installed (libhdf5-dev)
    pip install git+https://github.com/eudoxos/minieigen.git
    pip install git+https://github.com/python-xlib/python-xlib
    pip install scons cython ipython numpy matplotlib genshi xlwt xlrd h5py lockfile psutil pillow colour-runner future
    # if you need the GUI, also run this (and add opengl,qt4 features to scons below)
    ln -s /usr/lib/python3/dist-packages/{sip*,PyQt5} $VIRTUAL_ENV/lib/python$(python -c'import sys; print("%d.%d"%(sys.version_info[0:2]))')/site-packages
    # checkout the source
    git clone https://github.com/woodem/woo.git
    ### for wooExtra modules (if you need some)
    ## create directory for extras
    mkdir woo/wooExtra
    ## checkout extras, put them under there so that they are installed automatically
    git clone URL woo/wooExtra/...
    cd woo
    # compile the source, put all options necessary (saved in scons.flavor-default)
    scons features='vtk,gts,openmp,hdf5' CPPPATH='/usr/include/vtk-6.3:/usr/include/eigen3:/usr/include/hdf5/serial'
    # run self-tests to check that everything is OK
    woo --test
    # exit the virtual environment
    deactivate

The ``woo`` executable remembers virtual python used during the build (in `shebang <http://en.wikipedia.org/wiki/Shebang_%28Unix%29>`__), so you can also execute it *without* activating the virtual environment (by saying ``my/venv/bin/woo``) the next time, and it *should* work (including recompilation with ``-R`` or ``-RR``), **unless** you have another installation of woo system-wide (in that case, make sure you always activate the virtual environment properly).

.. note:: There used to be a script ``scripts/make-venv.sh`` which contained the above commands; it cannot be maintained meaningfully in the repo, create one for yourself based on the code above if you need it.


Distribution-specific instructions
----------------------------------

.. toctree::
   dist/suse.rst

Distutils
-----------

Woo can also be compiled using distutils, which uses ``setup.py`` to drive the compilation and installation. This is in fact the method used to produced Debian/Ubuntu packages. It works with both python 2.x and 3.x, but has less auto-detection and configuration features than scons; more importantly, it lacks the ability of partial re-compilation after changes to the source code (which is normally done by re-running ``scons`` or passing ``-R`` to Woo).

Windows
=======

Windows Subsystem for Linux
----------------------------

WSL supports running native Linux apps inside Windows. Follow `official Microsoft docs <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__ to install WSL itself, choose to install Ubuntu 18.04 inside the WSL.

Once this is done, install a X-server (display server for Linux apps), we recommend `VcXsrv <https://sourceforge.net/projects/vcxsrv/>`__. Woo itself will run without display server just fine but GUI will be disabled.

VcXsrv should be started with the multiple windows option, and **disabling native OpenGL** (see `Does WSL support OpenGL? <https://github.com/Microsoft/WSL/issues/2855>`__):

.. figure:: fig/wsl-vcxsrv-opengl.png

You can install Woo from source as usual, you can also use `script <https://raw.githubusercontent.com/woodem/woo/master/scripts/woo-install.py>`__ to install from source; in the terminal, type::

   $ wget https://raw.githubusercontent.com/woodem/woo/master/scripts/woo-install.py
   $ python3 woo-install.py

Once the compilation finishes, you should be able to run ``woo`` as normally in Linux. You have to set the ``DISPLAY`` environment variable (by hand, or export it in ``~/.bashrc`` to be set automatically. Shortcuts might not work in the Windows terminal (under investigation), you might need to type ``woo.qt.Controller()`` to open the controller window.

.. figure:: fig/wsl-controller.png



Obsolete instructions (native build)
-------------------------------------

Running woo under Windows is supported, but with some limitations:

#. Only 64bit systems are supported.
#. Compilation from source under Windows is not supported; since there is poor standardization for Windows development, the compilation process is tailored for a single insllation of development tools.
#. The computation is about 15% slower under Windows; the cause is − probably − less efficient locking provided by the OS, and perhaps also less agressive optimization, since the compiler has to optimize for the lowest common instruction set.

Binaries can be downloaded from `Launchpad download page <https://launchpad.net/woo/+download>`_, as follows:

#. Download and run ``Woo-libs-*-installer.exe`` with the highest version number.
#. Download and run ``Woo-main-*-installer.exe``. It must be installed into the same directory as libs (this is checked at install-time)
#. Download and run any installers for custom modules you may have (``Woo-wooExtra.*-installer.exe``)

The installer installs the code system-wide, supports unattended installation via the `/S` switch, and the uninstaller should remove all files. Uninstaller for ``Woo-libs`` must be run after all other components have been uninstalled. Installation directory of Woo is added to the ``PATH`` environment variable, so the command ``wwoo`` is understood wherever you are in the filesystem.

An icon is added to the start menu under ``Woo/woo``.


Uninstallation
==============

To uninstall the current installation of Woo from your machine (which is useful e.g. when switching from packaged version to locally compiled one `or vice versa <https://ask.woodem.org/index.php/294/would-completely-uninstall-version-that-built-from-source>`__), the following steps will clean installed files depending on the method you used to install Woo.

Compilation from source
    If you used the default ``PREFIX`` value for ``scons``, run the following command::

       rm -rf /usr/local/bin/woo* /usr/local/lib/python2.7/dist-packages/woo* 
    
    This will delete executables (``woo`` and ``woo-batch``) and modules. Be careful and check first there are not other ``woo*`` files installed in that location (unlikely, but possible).

Virtual Environment
    If you created the environment for Woo, you can simply delete all of it. Otherwise, follow the steps for source-compiled uninstallation, altering paths accordingly.

Debian/Ubuntu packages
    Uninstall the package the standard way, from package manager or by saying::

       sudo apt-get remove python-woo    # or python3-woo, depending on what you installed

Windows
    Uninstallation is done via standard :menuselection:`Control Panel --> Add/Remove Software`, removing both Woo and Woo-libs.
