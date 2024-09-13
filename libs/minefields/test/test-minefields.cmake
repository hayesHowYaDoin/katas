add_executable(test-minefields)

file(GLOB_RECURSE tests CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp")
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
target_sources(test-minefields PRIVATE ${tests} ${headers})

target_include_directories(test-minefields
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:test-minefields-${PROJECT_VERSION}>
)

target_link_libraries(test-minefields
    PUBLIC
        GTest::GTest
        GTest::Main
    PRIVATE 
        katas::minefields
)

gtest_discover_tests(test-minefields)