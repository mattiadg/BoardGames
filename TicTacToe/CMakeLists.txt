cmake_minimum_required(VERSION 3.11)

project(TicTacToe)

set(GAME_DIR
    ${PROJECT_SOURCE_DIR})

set(ttt_sources
    backend/TicTacToe.cpp
    backend/TicTacToeBoard.cpp
    backend/TicTacToeBoardDescriptor.cpp
    engine/TicTacToePlayer.cpp
    presentation/TicTacToeDisplay.cpp
    )

set(project_sources
    ${ttt_sources}
    main.cpp)

set(backend_headers
    backend/TicTacToe.h
    backend/TicTacToeBoard.h
    backend/TicTacToeBoardDescriptor.h)

set(engine_headers
    engine/TicTacToePlayer.h)

set(presentation_headers
    presentation/TicTacToeDisplay.h)

set(project_headers
    ${backend_headers}
    ${engine_headers}
    ${presentation_headers})

set(BASE_TEST_DIR
    ${GAME_DIR}/tests)

if(MSVC)
    set(USE_FOLDERS ON)
    source_group("Header Files\\Backend" FILES ${backend_headers})
    source_group("Header Files\\Engine" FILES ${engine_headers})
    source_group("Header Files\\Presentation" FILES ${presentation_headers})
endif(MSVC)

add_library(TTTBASE
            ${project_headers}
            ${project_sources})

add_executable(${PROJECT_NAME}
    ${project_headers}
    ${project_sources})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


### TESTING ###
option(BUILD_TESTS "Determines whether to build tests." ON)

set(BASE_TEST_SOURCES
        tests/test.cpp
        tests/TicTacToeDescriptorTest.cpp
        tests/TicTacToeBoardTest.cpp
        tests/TicTacToeTest.cpp
        tests/TicTacToePlayerTest.cpp)

if(BUILD_TESTS)
    enable_testing()

    add_executable(unit_tests
            ${BASE_TEST_SOURCES}
            ${ttt_sources})
    add_library(Catch INTERFACE)
    target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/Catch)
    target_link_libraries(unit_tests Catch)
    target_include_directories(unit_tests PUBLIC ${BASE_TEST_DIR})
    #target_compile_definitions(Base_Test PRIVATE $<$<CONFIG:Debug>:GHULBUS_CONFIG_ASSERT_LEVEL_DEBUG>)
    add_test(NAME TestBase COMMAND unit_tests)

    #if(GB_GENERATE_COVERAGE_INFO AND (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
    #    target_compile_options(gbBase PRIVATE --coverage)
    #    target_link_libraries(gbBase PRIVATE --coverage)
    #    target_compile_options(gbBase_Test PRIVATE --coverage)
    #    target_link_libraries(gbBase_Test PRIVATE --coverage)
    #    add_custom_target(gbBase_TestCoverage
    #            COMMAND ${GCOV_COMMAND} -o CMakeFiles/gbBase.dir/src ${GB_BASE_SOURCE_FILES}
    #            COMMAND ${GCOV_COMMAND} -o CMakeFiles/gbBase_Test.dir/test ${GB_BASE_TEST_SOURCES}
    #            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    #            COMMENT "Collecting gcov coverage information"
    #            )
    #endif()
endif()