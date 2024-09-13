add_library(minefields STATIC)
add_library(katas::minefields ALIAS minefields)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(minefields PRIVATE ${headers} ${sources})

target_include_directories(minefields 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/minefields-${PROJECT_VERSION}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(PACKAGE_TESTS)
    add_subdirectory(test)
endif()