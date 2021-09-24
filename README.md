# Overview

This is a Code Nummy about Github Actions. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Introduction

Please find some short presentation [here](https://docs.google.com/presentation/d/1vmMu76I2omW6LNN7hPXUzOnCzCxcCFuMzDbzJVC1AT0/edit?usp=sharing)


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

**Note**: For every step in the job you can specify the working directory via
`working-directory: ${{github.workspace}}/python`. This will be required for github actions to start in the correct
folder.

## Python instructions

* Set up the correct python version is set up. For this we want to use e.g. python
  3.9. [Hint](https://github.com/actions/setup-python)
* Use the [checkout action](https://github.com/actions/checkout) to get a copy of the repository
* Install the dependencies with pip by executing `pip install -r requirements.txt`
* Execut the tests via `python -m pytest`

## C++ Instructions

* Install the correct cmake version (we want to use 3.21)
  using [actions-setup-cmake](https://github.com/marketplace/actions/actions-setup-cmake)
* Install the correct g++ version  (use g++ 9) using [install-gcc](https://github.com/marketplace/actions/install-gcc)
* call cmake
* execute the test

## Optional Additional Tasks

* Add
  a [badge](https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge)
  to the Readme file, which shows the CI status
* Create a binary and provide it automatically. Could be done
  using [gh-pages](https://github.com/peaceiris/actions-gh-pages). 
