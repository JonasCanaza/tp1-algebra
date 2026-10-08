#include <iostream>
#include <vector>

#include "raylib.h"

using namespace std;

const int MAX_VERTICES = 4;
const int CIRCLE_RADIUS = 5;

struct MyVector2
{
    int x;
    int y;
};

struct Quadrilateral
{
    MyVector2 vertices[MAX_VERTICES];
};

void DrawAllQuadrilaterals(vector<Quadrilateral> quadrilaterals);

int main()
{
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGTH = 720;
    const int MAX_FPS = 60;

    const string PROGRAM_TITLE = "TP 1 Algebra";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, PROGRAM_TITLE.c_str());
    SetTargetFPS(MAX_FPS);

    vector<Quadrilateral> quadrilaterals;

    Quadrilateral tempQuadrilateral = Quadrilateral();

    tempQuadrilateral.vertices[0].x = 100;
    tempQuadrilateral.vertices[0].y = 100;

    tempQuadrilateral.vertices[1].x = 200;
    tempQuadrilateral.vertices[1].y = 100;

    tempQuadrilateral.vertices[2].x = 200;
    tempQuadrilateral.vertices[2].y = 400;

    tempQuadrilateral.vertices[3].x = 100;
    tempQuadrilateral.vertices[3].y = 400;

    quadrilaterals.push_back(tempQuadrilateral);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("TP 1 - Algebra", 0, 0, 24, WHITE);
        DrawAllQuadrilaterals(quadrilaterals);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawAllQuadrilaterals(vector<Quadrilateral> quadrilaterals)
{
    for (int i = 0; i < static_cast<int>(quadrilaterals.size()); i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            int posX = quadrilaterals[i].vertices[j].x;
            int posY = quadrilaterals[i].vertices[j].y;

            DrawCircle(posX, posY, static_cast<int>(CIRCLE_RADIUS), RED);
        }
    }
}