add_library(minefields-lib STATIC)
add_library(katas::minefields ALIAS minefields-lib)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/minefields/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(minefields-lib
    PUBLIC
        ${headers}
    PRIVATE
        ${sources}
)

target_include_directories(minefields-lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/minefields-lib-${PROJECT_VERSION}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(PACKAGE_TESTS)
    add_subdirectory(test)
endif()