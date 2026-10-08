/*
    Reference Links

        - https://matematix.org/que-es-un-segmento-en-matematicas/

        - https://humanidades.com/cuadrilateros/
*/

#include <iostream>
#include <vector>

#include "raylib.h"

using namespace std;

const int MAX_VERTICES = 4;
const float CIRCLE_RADIUS = 3.0f;

struct MyVector2
{
    int x;
    int y;

    bool isLocated;
};

struct Quadrilateral
{
    MyVector2 vertices[MAX_VERTICES];
};

void UpdateMouse(vector<Quadrilateral>& quadrilaterals, Quadrilateral& tempQuadrilateral, int& vertexCounter);

void DrawAllQuadrilaterals(vector<Quadrilateral> quadrilaterals);
void DrawTempQuadrilateral(Quadrilateral tempQuadrilateral, int vertexCounter);

int main()
{
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGTH = 720;
    const int MAX_FPS = 60;

    const string PROGRAM_TITLE = "TP 1 Algebra";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, PROGRAM_TITLE.c_str());
    SetTargetFPS(MAX_FPS);

    vector<Quadrilateral> quadrilaterals;
    int vertexCounter = 0;

    Quadrilateral tempQuadrilateral = Quadrilateral();

    while (!WindowShouldClose())
    {
        // UPDATE
        UpdateMouse(quadrilaterals, tempQuadrilateral, vertexCounter);

        // DRAW
        BeginDrawing();
        ClearBackground(BLACK);

        DrawAllQuadrilaterals(quadrilaterals);
        DrawTempQuadrilateral(tempQuadrilateral, vertexCounter);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void UpdateMouse(vector<Quadrilateral>& quadrilaterals, Quadrilateral& tempQuadrilateral, int& vertexCounter)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        tempQuadrilateral.vertices[vertexCounter].x = GetMouseX();
        tempQuadrilateral.vertices[vertexCounter].y = GetMouseY();
        tempQuadrilateral.vertices[vertexCounter].isLocated = true;

        vertexCounter++;

        if (vertexCounter == MAX_VERTICES)
        {
            quadrilaterals.push_back(tempQuadrilateral);
            vertexCounter = 0;
        }
    }
}

void DrawAllQuadrilaterals(vector<Quadrilateral> quadrilaterals)
{
    for (int i = 0; i < static_cast<int>(quadrilaterals.size()); i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            int nextIndex = j + 1;

            if (nextIndex >= MAX_VERTICES)
            {
                nextIndex = 0;
            }

            int currentPosX = quadrilaterals[i].vertices[j].x;
            int currentPosY = quadrilaterals[i].vertices[j].y;
            int nextPosX = quadrilaterals[i].vertices[nextIndex].x;
            int nextPosY = quadrilaterals[i].vertices[nextIndex].y;

            DrawLine(currentPosX, currentPosY, nextPosX, nextPosY, SKYBLUE);
        }

        for (int j = 0; j < MAX_VERTICES; j++)
        {
            int posX = quadrilaterals[i].vertices[j].x;
            int posY = quadrilaterals[i].vertices[j].y;

            DrawCircle(posX, posY, static_cast<float>(CIRCLE_RADIUS), YELLOW);
        }
    }
}

void DrawTempQuadrilateral(Quadrilateral tempQuadrilateral, int vertexCounter)
{
    int mousePosX = GetMouseX();
    int mousePosY = GetMouseY();

    DrawCircle(mousePosX, mousePosY, CIRCLE_RADIUS, WHITE);

    if (vertexCounter == 0)
    {
        return;
    }

    for (int i = 0; i < vertexCounter - 1; i++)
    {
        int startPosX = tempQuadrilateral.vertices[i].x;
        int startPosY = tempQuadrilateral.vertices[i].y;
        int endPosX = tempQuadrilateral.vertices[i + 1].x;
        int endPosY = tempQuadrilateral.vertices[i + 1].y;

        DrawLine(startPosX, startPosY, endPosX, endPosY, DARKGRAY);
    }

    int lastPosX = tempQuadrilateral.vertices[vertexCounter - 1].x;
    int lastPosY = tempQuadrilateral.vertices[vertexCounter - 1].y;

    DrawLine(lastPosX, lastPosY, mousePosX, mousePosY, DARKGRAY);

    for (int i = 0; i < vertexCounter; i++)
    {
        int posX = tempQuadrilateral.vertices[i].x;
        int posY = tempQuadrilateral.vertices[i].y;

        DrawCircle(posX, posY, CIRCLE_RADIUS, WHITE);
    }
}