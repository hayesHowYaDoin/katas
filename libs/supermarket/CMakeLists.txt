add_library(supermarket-lib STATIC)
add_library(katas::supermarket ALIAS supermarket-lib)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/supermarket/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(supermarket-lib
    PUBLIC
        ${headers}
    PRIVATE
        ${sources}
)

target_include_directories(supermarket-lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/supermarket-lib-${PROJECT_VERSION}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(PACKAGE_TESTS)
    add_subdirectory(test)
endif()