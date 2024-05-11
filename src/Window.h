//
// Created by Robin on 07.05.2024.
//

#ifndef BOOLEANTABLE_WINDOW_H
#define BOOLEANTABLE_WINDOW_H

#include <stdexcept>


#include <SDL3/SDL.h>
#include <glad/gl.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>
#include <ImNodeFlow.h>
#include "TruthTable.h"

const int cWinHeight = 400;
const int cWinWidth = 600;

class CWindow {
    SDL_Window* window;
    SDL_GLContext context;

    bool running = true;
    size_t currentRow = 0;

    std::shared_ptr<ImFlow::ImNodeFlow> imNodeFlow;
    std::shared_ptr<CTruthTable> currentTruthTable;
    std::vector<std::string> variables;

public:
    explicit CWindow();
    ~CWindow();

    void run();
};


#endif //BOOLEANTABLE_WINDOW_H
