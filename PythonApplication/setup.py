from distutils.core import setup, Extension

setup(name='algo_crypt', version='1.0', ext_modules=[Extension('algo_crypt', sources=['algo_crypt.c', 'caesar.c', 'otp.c', 'hill.c'])])
