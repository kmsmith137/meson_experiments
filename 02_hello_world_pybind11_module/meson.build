project(
    'pybind11_example',
    'cpp',
     default_options: ['optimization=3','debug=false','cpp_std=c++17']
)

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']
        
# https://mesonbuild.com/Python-module.html
py3 = import('python').find_installation('python3')
# message('Debug: py3.path = ', py3.path())

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

# https://mesonbuild.com/Python-module.html#extension_module
pybind11_example = py3.extension_module(
     'pybind11_example',
     sources: ['pybind11_example.cpp'],
     dependencies : [pybind11_dep],
     cpp_args: cpp_args,
     link_args: link_args,
     link_language : 'cpp',
     override_options: ['cpp_rtti=true'],
     install: true
)
