# Documentation

Here you will find everything you need to get started with using binder.

## Getting Started

First, you will need to have a GitHub repository containing at least one Jupyter notebook and one environment.yml file.

Here is a sample of what a 'binderized' repository would look like

![](https://github.com/phesse001/march_madness_jupyte/tree/gh-pages/images/example-binder-repo.PNG?raw=true)

```bash
pip install jupyter
```

For the PDF output to work, a distribution of LaTeX must be installed. Also, we
will need pandoc:

```bash
pip install pandoc
```

## Using the Package

### Downloading the Template

The easiest way to get started is to clone the package repository using Git:

```bash
git clone https://github.com/ChrisRackauckas/JupyterSite
```

### The Notebooks

The files which the site is built from are the notebooks that are included in
the Notebooks folder. The `Index.ipynb` file build the site index (the first
page shown in the webpage) and additional `.ipynb` files are rendered in the various
forms. Thus to add your own content, simply add the `.ipynb` files to this directory.

Note that notebooks have to be setup for slides in order for the slideshow to work.
Inside the notebook, use view > CellToolbar > Slideshow and set the appropriate blocks
to slides.

### Building The Site

To build the site files, use the `publish.sh` file. To do so, go to the top directory
of the repository and use the command:

```bash
sh publish.sh
```

If your Git is correctly setup, this will render the files and upload the files to
Github. Upon success, your `index.html` will be available at:

```
http://<github-username>.github.io/<repository-name>/
```

For example, my user name is ChrisRackauckas and this repository is named JupyterSite.
Therefore the site for that this makes is at

```
http://ChrisRackauckas.github.io/JupyterSite/
```

For organizations, the user name is replaced with the organization name.

#### Caveat

Note that PDF output is not compatible with the usage of Markdown images (though
code with images will allow the PDFs to build, but the images will not appear).

## Easy Usage from Julia

This repository is also setup as a Julia package repository. To have users easily
open up the Jupyter notebooks, they can use the commands from within Julia:

```julia
Pkg.add("IJulia") # use once to install IJulia
Pkg.clone("https://github.com/ChrisRackauckas/JupyterSite") # Change this to your Github repo
using IJulia
notebook(dir=Pkg.dir("JupyterSite")*"/Notebooks")
```

This will open up the Jupyter notebook at the location of your notebooks

### Addition: Continuous Integration Testing

One can use Julia's continuous integration testing framework to test your notebooks.
To do so, check out [this blog post](http://www.stochasticlifestyle.com/finalizing-julia-package-documentation-testing-coverage-publishing/)
for how to setup Julia CI and [NBinclude.jl](https://github.com/stevengj/NBInclude.jl) for how
to include notebook files into Julia. Use this to add tests to the test/runtests.jl
file. To run the tests locally, use the commands

```julia
Pkg.test("JupyterSite")
```

# Example Output

The example notebooks can be found at:

https://github.com/ChrisRackauckas/JupyterSite/blob/master/Notebooks

## HTML

https://chrisrackauckas.github.io/JupyterSite/

https://chrisrackauckas.github.io/JupyterSite/Html/GithubIntroduction.html

## Slides

https://chrisrackauckas.github.io/JupyterSite/

https://chrisrackauckas.github.io/JupyterSite/Slides/GithubIntroduction.html

## Markdown

https://github.com/ChrisRackauckas/JupyterSite/tree/master/Markdown

## LaTeX

https://github.com/ChrisRackauckas/JupyterSite/tree/master/Tex

## PDF

https://github.com/ChrisRackauckas/JupyterSite/tree/master/Pdfs


# Live Notebooks

For mixing the "live" part of the notebook with slideshows, try [RISE](https://github.com/damianavila/RISE).
RISE works with the notebooks included in this repository.
