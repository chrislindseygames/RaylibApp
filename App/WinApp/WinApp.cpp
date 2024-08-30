#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

// Program main entry point
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 800;

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);    // Window configuration flags
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    rlImGuiSetup(true);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    bool bShowDemo = false;
    bool bShowFPS = false;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlImGuiBegin();
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Options"))
            {
                ImGui::MenuItem("Show FPS", nullptr, &bShowFPS);
                ImGui::MenuItem("Show Demo ImGui Window", nullptr, &bShowDemo);
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        if (bShowDemo)
        {
            ImGui::ShowDemoWindow(&bShowDemo);
        }

        rlImGuiEnd();

        if (bShowFPS)
        {
            DrawFPS(GetScreenWidth() - 100, 50);
        }
        EndDrawing();
    }

    // De-Initialization
    rlImGuiShutdown();
    CloseWindow();        // Close window and OpenGL context

    return 0;
}