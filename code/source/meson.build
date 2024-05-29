code = files('module.c')

lib = library('fscl-c',
    code,
    install: true,
    include_directories: dir)

fscl_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
