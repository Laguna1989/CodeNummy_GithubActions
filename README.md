# Overview

This is a Code Nummy about Github Actions. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Introduction

Please find some short presentation [here](https://docs.google.com/presentation/d/1vmMu76I2omW6LNN7hPXUzOnCzCxcCFuMzDbzJVC1AT0/edit?usp=sharing). You will need to fork this repository to your own github account.


# Instructions

* create the file `.github/workflows/main.yml`

```
name: Validate

on:
  push:
    branches: [ master ]

jobs:
  build:
    runs-on: ubuntu-latest
```

After you push that file (with at least one step added to the jobs), github will automatically 
start to process the specified workflow.

**Note**: For every step in the job you can specify the working directory via
```
working-directory: ${{github.workspace}}/python
```
. This will be required for github actions to work in the correct folder (e.g. in a `build`-subfolder).

## Python instructions

* Set up the correct python version. Assume that python
  3.9 is required. [Hint](https://github.com/actions/setup-python)
* Use the [checkout action](https://github.com/actions/checkout) to get a copy of the repository
* Install the dependencies with pip by executing `pip install -r requirements.txt`
* Execut the tests via `python -m pytest`

## C++ Instructions

* Install the correct cmake version (it is required to use 3.21)
  using [actions-setup-cmake](https://github.com/marketplace/actions/actions-setup-cmake)
* Install the correct g++ version  (it is required to use g++ 9) using [install-gcc](https://github.com/marketplace/actions/install-gcc)
* Use the [checkout action](https://github.com/actions/checkout) to get a copy of the repository
* call cmake
* execute the test

## Optional Additional Tasks

* Add
  a [badge](https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge)
  to the Readme file, which shows the CI status
* Provide the binary as a precompiled version automatically. Could be done
  using [gh-pages](https://github.com/peaceiris/actions-gh-pages). Python can e.g. use pyinstaller to create a binary
* Create a second job that performs a build on windows

