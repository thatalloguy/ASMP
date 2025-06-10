//
// Created by allos on 02/06/2025.
//

#include "Globals.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <imgui.h>

#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_opengl3.h>

namespace Globals {

    SDL_Window* window = nullptr;
    SDL_GLContext context{};
    SDL_Event event{};

    bool running = true;


    void initProject() {

        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        // We do opengl 4.2
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);



        window = SDL_CreateWindow("ASMP Project", 1280, 720, SDL_WINDOW_OPENGL);

        if (!window) {
            std::cerr << "Could not create Window: " << SDL_GetError() << "\n";
        }
        context = SDL_GL_CreateContext(window);
        SDL_GL_MakeCurrent(window, context);
        SDL_GL_SetSwapInterval(1);

        gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);

        ImGui::CreateContext();
        ImGui_ImplSDL3_InitForOpenGL(window, context);
        ImGui_ImplOpenGL3_Init("#version 440");
        ImGui::StyleColorsDark();



    }

    bool shouldClose() {
        return !running;
    }
    void updateProject() {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }


            ImGui_ImplSDL3_ProcessEvent(&event);
        }

        glClear(GL_COLOR_BUFFER_BIT);


        ImGui_ImplSDL3_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();


        auto draw = ImGui::GetForegroundDrawList();

        draw->AddText(ImGui::GetCursorPos(),  ImColor(255, 255, 255), "Hello World");

        ImGui::Render();


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(window);



    }

    void destroyProject() {

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL3_Shutdown();

        ImGui::DestroyContext();

        SDL_GL_DestroyContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


}
