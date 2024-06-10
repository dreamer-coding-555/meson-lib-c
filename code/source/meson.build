code = files('module.c')

lib = library('fossil-c',
    code,
    dependencies : code_deps,
    include_directories: dir)

fossil_dep = declare_dependency(
    link_with: lib,
    dependencies : code_deps,
    include_directories: dir)
