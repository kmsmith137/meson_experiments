project('three_level', 'cpp',
        default_options: ['optimization=3','debug=false','cpp_std=c++17'])

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']

# https://mesonbuild.com/Python-module.html
# Note that pure=false is needed if we're including an extension module in the package.
py3 = import('python').find_installation('python3', pure: false)
message('Debug: py3.path = ', py3.path())

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

# https://mesonbuild.com/Reference-manual_functions.html#shared_library
# https://mesonbuild.com/Reference-manual_returned_lib.html

add_three_lib = shared_library(
    'three_level',
    ['src_lib/three_level.cpp'],
    cpp_args: cpp_args,
    install: true,
    install_dir: py3.get_install_dir() / 'three_level'
)

# https://mesonbuild.com/Python-module.html#extension_module
# https://mesonbuild.com/Reference-manual_functions.html#shared_module

py3.extension_module(
     '_three_level_pyext',   # Note underscore (this will end up as three_level._three_level_pyext)
     sources: ['src_pyext/three_level_pyext.cpp'],
     dependencies : [pybind11_dep],
     cpp_args: cpp_args,
     link_args: link_args,
     link_language : 'cpp',
     link_with: add_three_lib,  # link add_three.so to _three_level_pyext.so
     override_options: ['cpp_rtti=true'],
     subdir: 'three_level',
     install: true,
     # install_rpath: py3.get_install_dir() / 'three_level'    # doesn't seem to be necessary
)


executable(
    'test-add-three',
    'src_bin/test-add-three.cpp',
    cpp_args: cpp_args,
    link_args: link_args,
    link_with: add_three_lib
)
