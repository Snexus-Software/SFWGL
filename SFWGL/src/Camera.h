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
#include "Debug.h"
#include "Display.h"
#include "ShaderCL.h"

#ifndef CAMERA_H_SNEXUS
#define CAMERA_H_SNEXUS

#ifndef PI
#define PI 3.14159265358979323846
#endif
#ifndef DEG2RAD
#define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
#define RAD2DEG (180.0f/PI)
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
#define CAMERA_MOUSE_SCROLL_SENSITIVITY                 1.5f
#define CAMERA_FREE_MOUSE_SENSITIVITY                   1.00f
#define CAMERA_FREE_DISTANCE_MIN_CLAMP                  0.3f
#define CAMERA_FREE_DISTANCE_MAX_CLAMP                  120.0f
#define CAMERA_FREE_MIN_CLAMP                           85.0f
#define CAMERA_FREE_MAX_CLAMP                          -85.0f
#define CAMERA_FREE_SMOOTH_ZOOM_SENSITIVITY             0.05f
#define CAMERA_FREE_PANNING_DIVIDER                     5.1f
#define CAMERA_ORBITAL_SPEED                            0.01f       // Radians per frame
#define CAMERA_FIRST_PERSON_FOCUS_DISTANCE              25.0f
#define CAMERA_FIRST_PERSON_MIN_CLAMP                   105.0f
#define CAMERA_FIRST_PERSON_MAX_CLAMP                  -105.0f
#define CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER  5.0f
#define CAMERA_FIRST_PERSON_STEP_DIVIDER                30.0f
#define CAMERA_FIRST_PERSON_WAVING_DIVIDER              200.0f
#define CAMERA_THIRD_PERSON_DISTANCE_CLAMP              1.2f
#define CAMERA_THIRD_PERSON_MIN_CLAMP                   5.0f
#define CAMERA_THIRD_PERSON_MAX_CLAMP                  -85.0f
#define CAMERA_THIRD_PERSON_OFFSET                      (Vector3){ 0.4f, 0.0f, 0.0f }
#define PLAYER_MOVEMENT_SENSITIVITY                     100.0f // speed (LOWER = FASTER)
#define CAMERA_MOUSE_MOVE_SENSITIVITY 0.003f


#ifndef SF_FREE(x)
#define SF_FREE(x) free(&x)
#endif // !SF_FREE(x)



typedef enum {
	MOVE_FRONT = 0,
	MOVE_BACK = 2,
	MOVE_RIGHT = 3,
	MOVE_LEFT = 1,
	MOVE_UP = 4,
	MOVE_DOWN = 5
} CameraMove;

class Camera
{
private:
	int Keys[6] = { GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D, 0, 0 };  // Keyboard key mapping
	float cameraTargetDistance = 0.0f;								         // Camera distance from position to target 
	float playerEyesPosition = 1.85f;										 // Default player eyes position from ground (in meters) 
	Vector2 cameraAngle = { 0.0f, 0.0f };									 // Camera angle in plane XZ
	glm::mat4 Projection;
	ShaderCL vtShader;
	glm::mat4 CamLook;

	// Sets calculates the camera and its angle for the given input values
	void CameraCalculate();


public:
	Vector3 position;
	Vector3 target;
	Vector3 up;
	float fov = 60;
	

	// initializers for basic construction
	Camera(Vector3 Pos, Vector3 up);
	Camera();
	~Camera();

	// Basic 
	void Set(Vector3 Pos);
	void Set(Vector3 Pos, Vector3 up);
	void Set(Vector3 Pos, Vector3 Target, Vector3 up);

	//updating
	void Update(Display &display);
	void Look();

	// remaping keys
	void ChangeKeys(int Forward, int Left, int Backwards, int Right);

	
};


#endif