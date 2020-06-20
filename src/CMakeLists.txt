add_library(
        example
        ""
        example.h
        Customer.h
        Movie.h
        Rental.h
)

target_sources(
        example
        PRIVATE
        example.cpp
        Customer.cpp
        Movie.cpp
        main.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/example.h
        ${CMAKE_CURRENT_LIST_DIR}/Customer.h
        ${CMAKE_CURRENT_LIST_DIR}/Movie.h
        ${CMAKE_CURRENT_LIST_DIR}/Rental.h
)

target_include_directories(
        example
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)