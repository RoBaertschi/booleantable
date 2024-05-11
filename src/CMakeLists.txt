add_executable(booleantable main.cpp
        Window.cpp
        Window.h
        Logging.h
        Logging.cpp
        nodes/InputNode.cpp
        nodes/InputNode.h
        TruthTable.cpp
        TruthTable.h
        nodes/AndNode.cpp
        nodes/AndNode.h)
target_link_libraries(booleantable PRIVATE
        imgui::imgui imgui::ImNodeFlow imgui::opengl3 imgui::sdl3 # imgui
        SDL3::SDL3 # windowing
        glad::opengl # opengl loader
        spdlog::spdlog # logger
        fmt::fmt # formating
)
add_dependencies(booleantable sdl-copy-dll)
add_dependencies(sdl-copy-dll SDL3::SDL3)
