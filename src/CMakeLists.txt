add_library(
        mainSources
        ""
        Category.h
        Customer.h
        Movie.h
        Rental.h
)

target_sources(
        mainSources
        PRIVATE
        Category.cpp
        Customer.cpp
        Movie.cpp
        main.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Category.h
        ${CMAKE_CURRENT_LIST_DIR}/Customer.h
        ${CMAKE_CURRENT_LIST_DIR}/Movie.h
        ${CMAKE_CURRENT_LIST_DIR}/Rental.h
)

target_include_directories(
        mainSources
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
        program
        main.cpp
)

target_link_libraries(
        program
        mainSources
)