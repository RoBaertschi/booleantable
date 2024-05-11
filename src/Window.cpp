//
// Created by Robin on 07.05.2024.
//

#include "Window.h"
#include "nodes/AndNode.h"

CWindow::CWindow() : imNodeFlow(std::make_shared<ImFlow::ImNodeFlow>("Main Grid")) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMEPAD) != 0) {
        throw std::runtime_error("Could not initialize SDL3");
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    window = SDL_CreateWindow("Boolean Tables", cWinWidth, cWinHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        throw std::runtime_error("Could not create a SDL3 Window");
    }

    context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
        throw std::runtime_error("Could not create a OpenGL Context");
    }
    SDL_GL_MakeCurrent(window, context);

    SDL_GL_SetSwapInterval(1);

    int gl_version = gladLoadGL(SDL_GL_GetProcAddress);
    if (gl_version == 0) {
        throw std::runtime_error("Could not initialize OpenGL context");
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplSDL3_InitForOpenGL(window,context);
    ImGui_ImplOpenGL3_Init();



    imNodeFlow->addNode<CAndNode>(ImVec2{2, 2});

    imNodeFlow->droppedLinkPopUpContent([this](ImFlow::Pin *pin) {

        if (ImGui::Button("And")) {
            auto node = this->imNodeFlow->addNode<CAndNode>(this->imNodeFlow->screen2grid(ImGui::GetMousePos()));
            pin->createLink(node->first.get());
        }
    });
}


CWindow::~CWindow() {
    imNodeFlow.reset();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void CWindow::run() {
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    while(running) {
        for(SDL_Event event; SDL_PollEvent(&event);) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    return;
                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                    if (event.window.windowID == SDL_GetWindowID(window)) {
                        running = false;
                        return;
                    }
                    break;
                default:
                    break;
            }

        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Boolean Editor");
            imNodeFlow->update();
        ImGui::End();


        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
            SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
        }

        SDL_GL_SwapWindow(window);
    }
}
