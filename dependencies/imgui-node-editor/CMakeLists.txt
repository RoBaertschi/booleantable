message(STATUS "Fetching ImNodeFlow...")

FetchContent_Declare(
        imnodeflow
        GIT_REPOSITORY https://github.com/Fattorino/ImNodeFlow
)

FetchContent_MakeAvailable(imnodeflow)

add_library(imgui::ImNodeFlow ALIAS ImNodeFlow)