# Documentation for Woo

This repository contains documentation split-off from Woo (http://github.com/eudoxos/woodem) which is normally built and uploaded to http://woodem.org.

Usually, the repository would be cloned into `woo/doc` (where `woo` is the clone of Woo itself).

## Building the documentation

Clone the repository, run `make`. That will generate documentation in HTML and LaTeX. The whole process supposes a large number of things installed.

* woo itself;
* a number of sphinxcontrib modules;
* LaTeX and many of its packages.

`make upload` is used to upload the generated docs to woodem.org (works only for the maintainer, obviously).
