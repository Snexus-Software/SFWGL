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

// ============== CORE ABSTRACTION LAYER ============== \\

#include "SFGL.h"

GLFWwindow* __window;
Vector2 WindowSize;

// To see if we are in the fullscreen mode 
bool fullscreen;

void initSFGL(int windowX, int windowY, const char* windowName) {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    __window = glfwCreateWindow(windowX, windowY, windowName, NULL, NULL);

    if (!__window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(__window);
    glfwSwapInterval(1);
}



void StartDrawing() {
    int w = WindowSize.x, h = WindowSize.y;
    glfwGetFramebufferSize(__window, &w, &h);


    int ratio = (float)w / (float)h;
    glViewport(0, 0, w, h);
    glClear(GL_COLOR_BUFFER_BIT);

    WindowSize.x = (float)w;
    WindowSize.y = (float)h;

    //wait(60 / 1000);
}

void EndDrawing() {
    glfwSwapBuffers(__window);
    glfwPollEvents();
}

bool WindowShouldClose() {
    return glfwWindowShouldClose(__window);
}

void DestroySFGL() {
    glfwDestroyWindow(__window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

// Main display input and pull

void DisableCursor() {
    glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void EnableCursor() {
    glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool IsKeyDown(int key) {
    return glfwGetKey(__window, key);
}

Vector2 GetMousePos() {
    double mouseX, mouseY;
    glfwGetCursorPos(__window, &mouseX, &mouseY);

    return { (float)mouseX, (float)mouseY };
}

void ClearToColor(Colori color) {
    SFGLClearColor(color.r, color.g, color.b, color.a);
}

const char* GetClipboardText(void)
{
    return glfwGetClipboardString(__window);
}

// Set window minimum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMinSize(int width, int height)
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowSizeLimits(__window, width, height, mode->width, mode->height);

}

// Set window dimensions
// TODO: Issues on HighDPI scaling
void SetWindowSize(int width, int height)
{
    glfwSetWindowSize(__window, width, height);
}

// Show the window
void UnhideWindow(void)
{
    glfwShowWindow(__window);
}

// Hide the window
void HideWindow(void)
{
    glfwHideWindow(__window);
}

// Toggle fullscreen mode (only PLATFORM_DESKTOP)
void ToggleFullscreen(void)
{
    fullscreen = !fullscreen;          // Toggle fullscreen flag

    // NOTE: glfwSetWindowMonitor() doesn't work properly (bugs)
    if (fullscreen) glfwSetWindowMonitor(__window, glfwGetPrimaryMonitor(), 0, 0, screenWidth, screenHeight, GLFW_DONT_CARE);
    else glfwSetWindowMonitor(__window, NULL, 0, 0, screenWidth, screenHeight, GLFW_DONT_CARE);

}

// Set icon for window (only PLATFORM_DESKTOP)
// NOTE: Image must be in RGBA format, 8bit per channel
void SetWindowIcon(Image image)
{
    if (image.format == UNCOMPRESSED_R8G8B8A8)
    {
        GLFWimage icon[1] = { 0 };

        icon[0].width = image.width;
        icon[0].height = image.height;
        icon[0].pixels = (unsigned char*)image.data;

        // NOTE 1: We only support one image icon
        // NOTE 2: The specified image data is copied before this function returns
        glfwSetWindowIcon(__window, 1, icon);
    }
    else displayout(D_WARNING, "Window icon image must be in R8G8B8A8 pixel format");
}

// Set title for window (only PLATFORM_DESKTOP)
void SetWindowTitle(const char* title)
{
    glfwSetWindowTitle(__window, title);
}

// Set window position on screen (windowed mode)
void SetWindowPosition(int x, int y)
{
    glfwSetWindowPos(__window, x, y);
}