# Overview
This is a Code Nummy about Github Actions

# Python instructions

* create the file `.github/workflows/main.yml`
```
name: Validate Python

on:
  push:
    branches: [ master ]

jobs:
  build:
    runs-on: ubuntu-latest
```

* Set up the correct python version is set up. For this we want to use e.g. python 3.9. [Hint](https://github.com/actions/setup-python)
* Use the [checkout action](https://github.com/actions/checkout) to get a copy of the repository 
* Install the dependencies with pip by executing `pip install -r requirements.txt`
* Execut the tests via `python -m pytest`

# C++ Instructions