add_library(lcdigits-lib STATIC)
add_library(katas::lcdigits ALIAS lcdigits-lib)

set_target_properties(lcdigits-lib PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/lcdigits/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(lcdigits-lib
    PUBLIC
        ${headers}
    PRIVATE
        ${sources}
)

target_include_directories(lcdigits-lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/lcdigits-lib-${PROJECT_VERSION}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(PACKAGE_TESTS)
    add_subdirectory(test)
endif()