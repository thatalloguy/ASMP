
file(GLOB_RECURSE ASMP_SRC

    src/Globals.h
    src/Globals.cpp
    src/Parser.h
    src/Parser.cpp

)


add_library(ASMP STATIC
        ${ASMP_SRC}
        ${IMGUI_SOURCE}
        ${GLAD_SRC}
)

target_include_directories(ASMP PUBLIC src)

target_link_libraries(ASMP PUBLIC SDL3::SDL3)


target_include_directories(ASMP PUBLIC ${GLAD_INCLUDE})
target_include_directories(ASMP PUBLIC ${imgui_content_SOURCE_DIR})