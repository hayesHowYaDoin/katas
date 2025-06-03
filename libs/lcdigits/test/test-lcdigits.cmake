add_executable(test-lcdigits)

file(GLOB_RECURSE tests CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp")
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
target_sources(test-lcdigits PRIVATE ${tests} ${headers})

target_include_directories(test-lcdigits
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:test-lcdigits-${PROJECT_VERSION}>
)

target_link_libraries(test-lcdigits
    PUBLIC
        GTest::gtest
        GTest::gtest_main
    PRIVATE 
        katas::lcdigits
)

gtest_discover_tests(test-lcdigits)