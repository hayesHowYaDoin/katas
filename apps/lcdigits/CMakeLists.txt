add_executable(lcdigits)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_sources(lcdigits PRIVATE ${headers} ${sources})

target_link_libraries(lcdigits PRIVATE katas::lcdigits)