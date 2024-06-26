# project(): https://mesonbuild.com/Reference-manual_functions.html#project
# python.install_env: https://mesonbuild.com/Builtin-options.html#python-module

project(
   'three_level',
   'cpp',
   default_options: ['python.install_env=auto','optimization=3','debug=false','cpp_std=c++17']
)

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']

# https://mesonbuild.com/Python-module.html
# Note that pure=false is needed if we're including an extension module in the package.
py3 = import('python').find_installation('python3', pure: false)
message('py3.path = ', py3.path())
message('py3.install_dir = ', py3.get_install_dir())

# Show sys.path for debugging
# ret = run_command(py3.path(), '-c', 'import sys; print(sys.path)', check: true)
# message('Debug: py3.sys.path = ', ret.stdout().strip())


# ---------- PYBIND11 BOILERPLATE STARTS HERE ----------

# https://mesonbuild.com/External-commands.html
pybind11_ret = run_command(py3.path(), '-m', 'pybind11', '--includes', check: true)
pybind11_ret = pybind11_ret.stdout().strip()
# message('Debug: Output of python -m pybind11 --includes: ', pybind11_ret)

pybind11_include_dirs = [ ]
foreach include_dir: pybind11_ret.split()
    include_dir = include_dir.strip().strip('-I')
    pybind11_include_dirs += include_dir
endforeach

# message('Debug: pybind11_include_dirs = ', pybind11_include_dirs)
pybind11_dep = declare_dependency(include_directories: pybind11_include_dirs)

# ---------- PYBIND11 BOILERPLATE ENDS HERE ----------

# https://mesonbuild.com/Python-module.html#install_sources
py3.install_sources(
    'src_python/three_level/__init__.py',
    'src_python/three_level/add_one.py',
    subdir: 'three_level'
)

# FIXME I wanted to put the library in 'three_level/lib', but extension_module(..., install_rpath:)
# didn't seem to work. (The extension module always seems to include its containing directory in its
# rpath, but no other directories.)
#
# https://mesonbuild.com/Reference-manual_functions.html#shared_library
# https://mesonbuild.com/Reference-manual_returned_lib.html

three_level_lib = shared_library(
    'three_level',
    ['src_lib/three_level.cpp'],
    cpp_args: cpp_args,
    link_args: link_args,
    install: true,
    install_dir: py3.get_install_dir() / 'three_level'
)

# https://mesonbuild.com/Python-module.html#extension_module
# https://mesonbuild.com/Reference-manual_functions.html#shared_module

py3.extension_module(
     'three_level_pybind11',
     sources: ['src_lib/three_level_pybind11.cpp'],
     dependencies : [pybind11_dep],
     cpp_args: cpp_args,
     link_args: link_args,
     link_language : 'cpp',
     link_with: three_level_lib,  # link three_level.so to three_level_pybind11.so
     override_options: ['cpp_rtti=true'],
     subdir: 'three_level',
     install: true,
     # install_rpath: py3.get_install_dir() / 'three_level/lib'    # doesn't seem to work
)


# Note: to install headers, use py3.install_sources(), not install_headers(...  py3.get_install_dir() ...)
# Note: need one call to install_sources() for each directory/subdirectory containing headers

py3.install_sources(
    'include/three_level.hpp',
    subdir: 'three_level/include'
)


executable(
    'test-add-three',
    'src_bin/test-add-three.cpp',
    cpp_args: cpp_args,
    link_args: link_args,
    link_with: three_level_lib
)
