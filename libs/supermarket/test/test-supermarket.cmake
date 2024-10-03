add_executable(test-supermarket)

file(GLOB_RECURSE tests CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp")
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
target_sources(test-supermarket PRIVATE ${tests} ${headers})

target_include_directories(test-supermarket
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:test-supermarket-${PROJECT_VERSION}>
)

target_link_libraries(test-supermarket
    PUBLIC
        GTest::GTest
        GTest::Main
    PRIVATE 
        katas::supermarket
)

gtest_discover_tests(test-supermarket)