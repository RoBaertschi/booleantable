message(STATUS "Fetching SDL3...")

FetchContent_Declare(
        sdl3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL/
        GIT_TAG prerelease-3.1.2
)

FetchContent_MakeAvailable(sdl3)

add_custom_target(sdl-copy-dll)
if (${WIN32})
    add_custom_command(
            TARGET sdl-copy-dll
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sdl3_BINARY_DIR}/SDL3.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif ()