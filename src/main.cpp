#include <iostream>

#include "raylib.h"

using namespace std;

int main()
{
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGTH = 720;
    const int MAX_FPS = 60;

    const string PROGRAM_TITLE = "TP 1 Algebra";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, PROGRAM_TITLE.c_str());

    SetTargetFPS(MAX_FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        DrawText("TP 1 - Algebra", 0, 0, 24, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}