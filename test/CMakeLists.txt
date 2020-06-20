add_executable(
        unit_tests
        test_integration.cpp
)

target_link_libraries(
        unit_tests
        gmock_main
        gtest_main
        mainSources
)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)