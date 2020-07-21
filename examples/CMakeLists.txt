file(GLOB SOURCES *.c)

foreach (source ${SOURCES})
    get_filename_component(target_name ${source} NAME_WE)
    set(target example_${target_name})
    add_executable(${target} ${target_name}.c)
    target_link_libraries(${target} archetypes_static)
endforeach (source)