project('hello_world_library', 'cpp',
        default_options: ['optimization=3','debug=false','cpp_std=c++17'])

# Not sure if this is really necessary
cpp_args = ['-m64']
link_args = ['-m64']

# https://mesonbuild.com/Reference-manual_functions.html#library
# https://mesonbuild.com/Reference-manual_returned_lib.html
hello_world_lib = library('hello_world', 'src_lib/say_hello.cpp', cpp_args: cpp_args, link_args: link_args)

# https://mesonbuild.com/Reference-manual_functions.html#executable
executable('say-hello', 'src_bin/say-hello.cpp', cpp_args: cpp_args, link_args: link_args, link_with: hello_world_lib)
