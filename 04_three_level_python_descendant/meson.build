# project(): https://mesonbuild.com/Reference-manual_functions.html#project
# python.install_env: https://mesonbuild.com/Builtin-options.html#python-module

project('three_level_descendant', 'cpp',
        default_options: ['python.install_env=auto','optimization=3','debug=false','cpp_std=c++17'])

# https://mesonbuild.com/Fs-module.html
fs = import('fs')

# https://mesonbuild.com/Reference-manual_returned_compiler.html
cpp = meson.get_compiler('cpp')

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']

# https://mesonbuild.com/Python-module.html
# Note that pure=false is needed if we're including an extension module in the package.
py3 = import('python').find_installation('python3', pure: false)
py3_install_dir = py3.get_install_dir()
message('py3.path = ', py3.path())
message('py3.install_dir = ', py3_install_dir)

# Show sys.path for debugging
# ret = run_command(py3.path(), '-c', 'import sys; print(sys.path)', check: true)
# message('Debug: py3.sys.path = ', ret.stdout().strip())


# ----------  three_level dependency starts here  ----------


# Find header/library for the three_level library.

# https://mesonbuild.com/External-commands.html
three_level_ret = run_command(py3.path(), '-c', 'import three_level; print(three_level.__file__)', check: true)
three_level_ret = three_level_ret.stdout().strip()
message('three_level_ret = ', three_level_ret)

three_level_incdir = fs.parent(three_level_ret) / 'include'
three_level_libdir = fs.parent(three_level_ret)

if not fs.exists(three_level_incdir / 'three_level.hpp')
    error('Couldn\'t find three_level.hpp in expected location -- time to debug')
endif

if not fs.exists(three_level_libdir / 'libthree_level.so')
    error('Couldn\'t find libthree_level.so in expected location -- time to debug')
endif

# https://mesonbuild.com/Reference-manual_returned_compiler.html#compilerfind_library
# https://mesonbuild.com/Reference-manual_returned_dep.html

three_level_lib = cpp.find_library('three_level', dirs: three_level_libdir)

# FIXME delete this?
#three_level_lib = cpp.find_library(
#    'three_level',
#    has_headers: 'three_level.hpp',
#    dirs: three_level_libdir,
#    header_include_directories: include_directories(three_level_incdir)
#)


# ----------  pybind11 dependency starts here  ----------

# https://mesonbuild.com/External-commands.html
pybind11_ret = run_command(py3.path(), '-m', 'pybind11', '--includes', check: true)
pybind11_ret = pybind11_ret.stdout().strip()
message('Debug: Output of python -m pybind11 --includes: ', pybind11_ret)

pybind11_include_dirs = [ ]
foreach include_dir: pybind11_ret.split()
    include_dir = include_dir.strip().strip('-I')
    pybind11_include_dirs += include_dir
endforeach

# message('Debug: pybind11_include_dirs = ', pybind11_include_dirs)
pybind11_dep = declare_dependency(include_directories: pybind11_include_dirs)

# ---------------  dependencies end here  ---------------


# https://mesonbuild.com/Python-module.html#install_sources
py3.install_sources(
    'src_python/three_level_descendant/__init__.py',
    subdir: 'three_level_descendant'
)

# https://mesonbuild.com/Reference-manual_functions.html#shared_library
# https://mesonbuild.com/Reference-manual_returned_lib.html

three_level_descendant_lib = shared_library(
    'three_level_descendant',
    ['src_lib/three_level_descendant.cpp'],
    cpp_args: cpp_args,
    dependencies: [three_level_lib],
    include_directories: three_level_incdir,
    install: true,
    install_dir: py3.get_install_dir() / 'three_level_descendant'
)

# https://mesonbuild.com/Python-module.html#extension_module
# https://mesonbuild.com/Reference-manual_functions.html#shared_module

py3.extension_module(
     'three_level_descendant_pybind11',
     sources: ['src_lib/three_level_descendant_pybind11.cpp'],
     cpp_args: cpp_args,
     dependencies : [pybind11_dep],     # I don't think I need three_level_lib
     include_directories: three_level_incdir,
     link_args: link_args,
     link_language : 'cpp',
     link_with: three_level_descendant_lib,  # link three_level_descendant.so to three_level_descendant_pybind11.so
     override_options: ['cpp_rtti=true'],
     subdir: 'three_level_descendant',
     install: true,
     # install_rpath: py3.get_install_dir() / 'three_level_descendant'    # doesn't seem to be necessary
)

executable(
    'test-descendant',
    'src_bin/test-descendant.cpp',
    cpp_args: cpp_args,
    dependencies: [three_level_lib],
    include_directories: three_level_incdir,
    link_args: link_args,
    link_with: three_level_descendant_lib
)
