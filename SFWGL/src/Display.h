/*=======================================================


Copyright (C) 2019  Snexus Software

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


=========================================================*/

#pragma once

// ============== MAIN LIB PACKAGING ABSTRACTION LAYER ============== \\

#include "Template.h"
#include "Vector.h"

#define CLOSE_MAIN     \
    exit(1);           \
    return 0;          \


class Display
{
private:
    std::chrono::steady_clock::time_point LastFrameTime = std::chrono::high_resolution_clock::now();
    std::chrono::steady_clock::time_point NewFrameTime = std::chrono::high_resolution_clock::now();
    void InitDisplay();
    //void framebuffer_size_callback(GLFWwindow* window, int width, int height);
public:
    Vector2 Size;
    GLFWwindow* __window;
    const char* WindowName = "NULL NAME";


    // initing
    Display(int SizeX, int SizeY, const char * WindowName);
    ~Display();

    // basic drawing
    void StartDrawing();
    void EndDrawing();
    float Ratio();

    // Get commands 
    bool WindowShouldClose();
    void DisableCursor();
    void EnableCursor();
    bool IsKeyDown(int key);
    Vector2 GetMousePos();
    int GetFPS();


};

