---
nav_order: 2
---
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

Click [Here](https://conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#sharing-an-environment)
to find information on how to set up a .yml file for your purposes

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

Head to [mybinder.org](https://mybinder.org/) and you should see the following

![](https://github.com/phesse001/march_madness_jupyter/blob/gh-pages/images/my-binder-example.PNG)

Copy and paste the url to the repository you just created and you are ready to launch! If you launch with just the url filled in, after the build completes you will be redirected to Jupyter server containing everything from your GitHub repository. 

You can edit on any of the files and execute any of the notebooks. These changes will only occur on the server side and will not affect the state of the files in the GitHub repository.

You also have the option to specify a path to a notebook. If you fill in this argument, once the image is built, instead of being redirected to a view of your GitHub Repository in Jupyter, you will be redirected directly to the notebook you specified.

## References
<a id="1">[1]</a> 
Dijkstra, E. W. (1968). 
Go to statement considered harmful. 
Communications of the ACM, 11(3), 147-148.
