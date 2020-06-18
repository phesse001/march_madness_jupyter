# Documentation

Here you will find everything you need to get started with using binder.

## Getting Started

First, you will need to have a GitHub repository containing at least one Jupyter notebook and one environment.yml file.

Here is a sample of what a 'binderized' repository would look like

├── environment.yml

├── index.ipynb

└── README.md

The two required files are
* .yml file
* .ipynb file

Where the .yml file will specify an anaconda environment

And the .ipynb is any Jupyter notebook

## Setting Up the .yml File

The following specifies ways in which a .yml file can be set up for your conda environment [yml configuration](https://conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#sharing-an-environment)

This file can also be created automatically

```bash
conda env export --from-history -f environment.yml
```

While not garunteeded to be perfect, if you are working within a specific environment, this will capture all the dependencies in that environment. You can also run this command and go back and remove any dependencies you may not need or specify particular versions.

For Example:

```
name: example-environment
channels:
  - conda
dependencies:
  -example-package=3.5.2
```

## Building the Image with [Binder](https://mybinder.org/)

Now that you have a GitHub repository with whatever notbooks you want to use and the environment.yml specifying the environment in which the notebooks were created, you are ready to build and deploy the image with your work.
