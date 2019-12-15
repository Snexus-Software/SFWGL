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
#include "FileW.h"
#include "Debug.h"
#include "Vector.h"

enum UniformType {
    UNIFORM_1F = 1,
    UNIFORM_1I,
    UNIFORM_VER2,
    UNIFORM_VER3,
    UNIFORM_VER4

};

class ShaderCL
{
private:

    FILEw file;
    GLuint ShaderCLId = { 0 };
    GLuint ProgramCLId = { 0 };


public:

    // loading the shader
    ShaderCL(std::string);
    void load(std::string);

    // compile the shader
    virtual void compile(GLenum);
    void bind();
    void unbind();
    
    void SendVar(std::string, UniformType, Vector4);





};

