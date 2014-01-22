#!/usr/bin/env python

import os

from distutils import log
from distutils.dir_util import copy_tree
from setuptools import setup, bootstrap_install_from, Extension
from setuptools.command.sdist import sdist
from setuptools.command.install import install


# Don't install deps for development mode.
bootstrap_install_from = None

here = os.path.abspath(os.path.dirname(__file__))
README = open(os.path.join(here, "README.txt")).read()


LIBSKELETON_INCLUDE = [
  'src',
  'src/native',
]

LIBSKELETON_LIBS = [
  'rt',
]

LIBSKELETON_COMPILE_ARGS = [
  '-g',
]

setup(
  name = 'LIBSKELETON',
  url = 'https://github.com/sholsapp/native-pyext-skeleton',
  author = 'Stephen Holsapple',
  author_email = 'sholsapp@gmail.com',
  version = '0.0.1',
  platforms = 'linux',
  description = README,
  # What are we packaging up?
  package_dir = {'': 'src'},
  include_package_data = True,
  ext_modules = [
    Extension('libskeleton', [
      'src/pylibskeleton.cc',
    ],
    include_dirs=LIBSKELETON_INCLUDE,
    libraries=LIBSKELETON_LIBS,
    extra_compile_args=LIBSKELETON_COMPILE_ARGS)
  ],
  zip_safe = False,
  verbose = False,
)
