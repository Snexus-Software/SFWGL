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

#include "Display.h"
#include "Debug.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void Display::InitDisplay() {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	__window = glfwCreateWindow(this->Size.x, this->Size.y, this->WindowName, NULL, NULL);

	if (!__window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(__window);
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(__window, framebuffer_size_callback);

	displayout(D_INFO, "Display Ready!");

	glewInit();
}

 // initing
Display::Display(int SizeX, int SizeY, const char* WindowName = "NULL NAME") {
	this->Size = {(float)SizeX, (float)SizeY};
	this->WindowName = WindowName;
	InitDisplay();
}

Display::~Display() {
	glfwDestroyWindow(__window);
	glfwTerminate();
}

// basic drawing
void Display::StartDrawing() {
	int w = this->Size.x, h = this->Size.y;
	glfwGetFramebufferSize(__window, &w, &h);


	int ratio = (float)w / (float)h;
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT);

	this->Size.x = (float)w;
	this->Size.y = (float)h;
	this->LastFrameTime = std::chrono::high_resolution_clock::now();
}

void Display::EndDrawing() {
	glfwSwapBuffers(__window);
	glfwPollEvents();
	this->NewFrameTime = std::chrono::high_resolution_clock::now();
}

// Get commands 
bool Display::WindowShouldClose() {
	return glfwWindowShouldClose(__window);
}

void Display::DisableCursor() {
	glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Display::EnableCursor() {
	glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool Display::IsKeyDown(int key) {
	return glfwGetKey(__window, key);
}

Vector2 Display::GetMousePos() {
	double mouseX, mouseY;
	glfwGetCursorPos(__window, &mouseX, &mouseY);

	return { (float)mouseX, (float)mouseY };
}

int Display::GetFPS() {
	std::chrono::duration<double, std::milli> ep = this->NewFrameTime - this->LastFrameTime;
	return int(1000.f / float(ep.count()));
}

