add_executable(minefields)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

target_sources(minefields PRIVATE ${headers} ${sources})

target_link_libraries(minefields PRIVATE katas::minefields)