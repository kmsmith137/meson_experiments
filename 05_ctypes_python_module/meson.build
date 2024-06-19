project(
    'ctypes_example',
    'cpp',
    default_options: ['optimization=3','debug=false','cpp_std=c++17']
)

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']

# https://mesonbuild.com/Python-module.html
# Note that pure=false is needed if we're including an extension module in the package.
py3 = import('python').find_installation('python3', pure: false)
# message('Debug: py3.path = ', py3.path())

# Show sys.path for debugging
# ret = run_command(py3.path(), '-c', 'import sys; print(sys.path)', check: true)
# message('Debug: py3.sys.path = ', ret.stdout().strip())

# https://mesonbuild.com/Python-module.html#install_sources
py3.install_sources(
    'src_python/ctypes_example/__init__.py',
    'src_python/ctypes_example/_ctypes_wrappers.py',
    subdir: 'ctypes_example'
)

# Note: python code assumes that meson shared_library('name' ...) creates filename 'libname.so'.
# https://mesonbuild.com/Reference-manual_functions.html#shared_library
# https://mesonbuild.com/Reference-manual_returned_lib.html

example_ctypes_lib = shared_library(
    'example_ctypes_module',
    [ 'src_lib/example_ctypes_module.cpp' ],
    cpp_args: cpp_args,
    link_args: link_args,
    install: true,
    install_dir: py3.get_install_dir() / 'ctypes_example'
)

# FIXME currently building as extension_module -- I don't think this is quite right!
# https://mesonbuild.com/Python-module.html#extension_module
#py3.extension_module(
#     '_example_ctypes_module',   # Note underscore (this will end up as ctypes_example._example_ctypes_module)
#     sources: ['src_lib/example_ctypes_module.cpp'],
#     cpp_args: cpp_args,
#     link_args: link_args,
#     link_language : 'cpp',
#     # override_options: ['cpp_rtti=true'],
#     subdir: 'ctypes_example',
#     install: true
#)
