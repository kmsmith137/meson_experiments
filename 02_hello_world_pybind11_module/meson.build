project('pybind11_example', 'cpp', default_options : ['cpp_std=c++17'])

# https://mesonbuild.com/Python-module.html
py3 = import('python').find_installation('python3')
# message('py3.path = ', py3.path())

# Sometimes useful for debugging
ret = run_command(py3.path(), '-c', 'import sys; print(sys.path)', check: true)
message('py3.sys.path = ', ret.stdout().strip())


# ---------- PYBIND11 BOILERPLATE STARTS HERE ----------

# https://mesonbuild.com/External-commands.html
pybind11_ret = run_command(py3.path(), '-m', 'pybind11', '--includes', check: true)
pybind11_ret = pybind11_ret.stdout().strip()
# message('Output of python -m pybind11 --includes: ', pybind11_ret)

pybind11_include_dirs = [ ]
foreach include_dir: pybind11_ret.split()
    include_dir = include_dir.strip().strip('-I')
    pybind11_include_dirs += include_dir
endforeach

# message('pybind11_include_dirs = ', pybind11_include_dirs)
pybind11_dep = declare_dependency(include_directories: pybind11_include_dirs)

# ---------- PYBIND11 BOILERPLATE ENDS HERE ----------

pybind11_example = py3.extension_module(
     'pybind11_example',
     sources: ['pybind11_example.cpp'],
     dependencies : [pybind11_dep],
     link_language : 'cpp',
     override_options: ['cpp_rtti=true'],
     install: true
)
