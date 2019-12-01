/*++++++++++++

GLFW packager

copyright (c) Gavin Kellam (Snexus Software)
++++++++++++*/
#pragma once


#ifndef SNEXUS_GLFW_HANDLER
#define SNEXUS_GLFW_HANDLER



#ifdef _WIN32
#pragma comment(lib, "winmm.lib")
#endif // _WIN32

#if !defined(_WIN32) && !defined(__linux)
#error Platform WIN32 or linux is only supported!
#endif


#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#include "GL/glew.h"

//#include "glad.h"
#include "dirent.h"
#include "miniaudio.h"
#include "tinyobj_loader_c.h"
#include "External/GLFW/glfw3.h"



#endif // !SNEXUS_GLFW_HANDLER