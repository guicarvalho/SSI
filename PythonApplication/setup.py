from distutils.core import setup, Extension

setup(name='algo_crypt', version='1.0', ext_modules=[Extension('algo_crypt', ['algo_crypt.c'])])
