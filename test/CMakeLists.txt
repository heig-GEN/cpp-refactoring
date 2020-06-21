add_executable(
        unit_tests
        test_integration.cpp
        test_categories.cpp
        test_movies.cpp
        test_rental.cpp
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