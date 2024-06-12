project('hello_world_library', 'cpp',
        default_options: ['optimization=3','debug=false','cpp_std=c++17'])

cpp_args = ['-m64']

hello_world_lib = library('hello_world', 'src_lib/say_hello.cpp', cpp_args: cpp_args)
executable('say-hello', 'src_bin/say-hello.cpp', link_with: hello_world_lib)
