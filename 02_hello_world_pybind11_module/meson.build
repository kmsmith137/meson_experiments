project('pybind11_example', 'cpp', default_options : ['cpp_std=c++17',])

py3 = import('python').find_installation('python3')

pybind11_config = find_program('pybind11-config')
pybind11_config_ret = run_command(pybind11_config, ['--includes'])
pybind11_includes = [ pybind11_config_ret.stdout().split('-I')[-1].strip() ]
pybind11_dep = declare_dependency(include_directories: pybind11_includes)

pybind11_example = py3.extension_module('pybind11_example',
     sources: ['pybind11_example.cpp'],
     dependencies : [pybind11_dep],
     link_language : 'cpp',
     override_options: ['cpp_rtti=true']
)
