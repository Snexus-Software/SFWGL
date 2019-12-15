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

#include "Camera.h"

Camera::Camera(Vector3 Pos, Vector3 up) {
    this->position = Pos;
    this->up = up;

    vtShader = "vertexshader.glsl";
    vtShader.compile(GL_VERTEX_SHADER);
    vtShader.bind();

}



Camera::Camera() {
    this->up = { 0, 1.0f, 0 };
    vtShader = "vertexshader.glsl";
    vtShader.compile(GL_VERTEX_SHADER);
    vtShader.bind();

}

void Camera::Set(Vector3 Pos) {
    this->position = Pos;
}

void Camera::Set(Vector3 Pos, Vector3 up) {
    this->position = Pos;
    this->up = up;
}

void Camera::Set(Vector3 Pos, Vector3 Target, Vector3 up) {
    this->position = Pos;
    this->target = Target;
    this->up = up;
}

Camera::~Camera() {
    displayout(D_WARNING, "Camera Deconstructed!");
}

void Camera::CameraCalculate() {
    Vector3 v1 = this->position;
    Vector3 v2 = this->target;

    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    cameraTargetDistance = sqrtf(dx * dx + dy * dy + dz * dz); 

    Vector2 distance = { 0.0f, 0.0f };
    distance.x = sqrtf(dx * dx + dz * dz);
    distance.y = sqrtf(dx * dx + dy * dy);

    // Camera angle calculation
    cameraAngle.x = asinf((float)fabs(dx) / distance.x);  // Camera angle in plane XZ (0 aligned with Z, move positive CCW)
    cameraAngle.y = -asinf((float)fabs(dy) / distance.y); // Camera angle in plane XY (0 aligned with X, move positive CW)

    this->playerEyesPosition = this->position.y;

    
}

void Camera::ChangeKeys(int Forward, int Left, int Backwards, int Right) {
    this->Keys[0] = Forward;
    this->Keys[1] = Left;
    this->Keys[2] = Backwards;
    this->Keys[3] = Right;
}

void Camera::Update(Display &display) {

    static int swingCounter = 0;    // Used for 1st person swinging movement
    static Vector2 previousMousePosition = { 0.0f, 0.0f };

    // TODO: Compute cameraTargetDistance and cameraAngle here
    display.DisableCursor();

    // Mouse movement detection
    Vector2 mousePositionDelta = { 0.0f, 0.0f };
    Vector2 mousePosition = display.GetMousePos();



    bool direction[6] = { display.IsKeyDown(Keys[MOVE_FRONT]),
                          display.IsKeyDown(Keys[MOVE_BACK]),
                          display.IsKeyDown(Keys[MOVE_RIGHT]),
                          display.IsKeyDown(Keys[MOVE_LEFT]),
                          display.IsKeyDown(Keys[MOVE_UP]),
                          display.IsKeyDown(Keys[MOVE_DOWN]) };

    // TODO: Consider touch inputs for camera


    mousePositionDelta.x = mousePosition.x - previousMousePosition.x;
    mousePositionDelta.y = mousePosition.y - previousMousePosition.y;

    previousMousePosition = mousePosition;


    // Support for multiple automatic camera modes

    this->position.x += (sinf(cameraAngle.x) * direction[MOVE_BACK] -
        sinf(cameraAngle.x) * direction[MOVE_FRONT] -
        cosf(cameraAngle.x) * direction[MOVE_LEFT] +
        cosf(cameraAngle.x) * direction[MOVE_RIGHT]) / PLAYER_MOVEMENT_SENSITIVITY;


    this->position.z += (cosf(cameraAngle.x) * direction[MOVE_BACK] -
        cosf(cameraAngle.x) * direction[MOVE_FRONT] +
        sinf(cameraAngle.x) * direction[MOVE_LEFT] -
        sinf(cameraAngle.x) * direction[MOVE_RIGHT]) / PLAYER_MOVEMENT_SENSITIVITY;

    bool isMoving = false;  // Required for swinging

    for (int i = 0; i < 6; i++) if (direction[i]) { isMoving = true; break; }

    // Camera orientation calculation
    cameraAngle.x += (mousePositionDelta.x * -CAMERA_MOUSE_MOVE_SENSITIVITY);
    cameraAngle.y += (mousePositionDelta.y * -CAMERA_MOUSE_MOVE_SENSITIVITY);

    // Angle clamp
    if (cameraAngle.y > CAMERA_FIRST_PERSON_MIN_CLAMP* DEG2RAD) cameraAngle.y = CAMERA_FIRST_PERSON_MIN_CLAMP * DEG2RAD;
    else if (cameraAngle.y < CAMERA_FIRST_PERSON_MAX_CLAMP * DEG2RAD) cameraAngle.y = CAMERA_FIRST_PERSON_MAX_CLAMP * DEG2RAD;

    // Camera is always looking at player
    this->target.x = this->position.x - sinf(cameraAngle.x) * CAMERA_FIRST_PERSON_FOCUS_DISTANCE;
    this->target.y = this->position.y + sinf(cameraAngle.y) * CAMERA_FIRST_PERSON_FOCUS_DISTANCE;
    this->target.z = this->position.z - cosf(cameraAngle.x) * CAMERA_FIRST_PERSON_FOCUS_DISTANCE;


    this->up.x = sinf(swingCounter / (CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER * 2)) / CAMERA_FIRST_PERSON_WAVING_DIVIDER;
    this->up.z = -sinf(swingCounter / (CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER * 2)) / CAMERA_FIRST_PERSON_WAVING_DIVIDER;
    
    Projection = glm::perspective(fov, display.Ratio(), 0.001f, 1000.0f);
    glm::vec3 Pos = glm::vec3(this->position.x, this->position.y, this->position.z);
    glm::vec3 Target = glm::vec3(this->target.x, this->target.y, this->target.z);
    glm::vec3 Up = glm::vec3(this->up.x, this->up.y, this->up.z);
    CamLook = this->Projection * glm::lookAt(Pos, Target, Up);
    position << "Pos";
    target << "Target";

    int posid = glGetUniformLocation(vtShader.ProgramCLId, "camera");
    glUniform4fv(posid, 1, &CamLook[0][0]);

    


}