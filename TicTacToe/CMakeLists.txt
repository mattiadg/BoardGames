cmake_minimum_required(VERSION 3.11)

project(TicTacToe)

set(project_sources
    backend/TicTacToe.cpp
    backend/TicTacToeBoard.cpp
    backend/TicTacToeBoardDescriptor.cpp
    engine/TicTacToePlayer.cpp
    presentation/TicTacToeDisplay.cpp
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

if(MSVC)
    set(USE_FOLDERS ON)
    source_group("Header Files\\Backend" FILES ${backend_headers})
    source_group("Header Files\\Engine" FILES ${engine_headers})
    source_group("Header Files\\Presentation" FILES ${presentation_headers})
endif(MSVC)

add_executable(${PROJECT_NAME}
    ${project_headers}
    ${project_sources})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

