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

#include "ShaderCL.h"


void ShaderCL::load(std::string Filename) {
    this->file = GetF(Filename);
   
}

ShaderCL::ShaderCL(std::string Filename) {
    this->load(Filename);
}

ShaderCL::ShaderCL() {

}


void ShaderCL::compile(GLenum ShaderCLType) {
    std::string SCS = ""; // This is the Shader Construction String or SCS

    ShaderCLId = glCreateShader(ShaderCLType);


    for (auto& i : file.Data) {
        SCS += i + "\n"; // Add Each line to the SCS for the loading of the shader
    }
   
    const char* ShaderOLF = SCS.c_str();

    glShaderSource(ShaderCLId, 1, &ShaderOLF, NULL); // Turn the shader string into a opengl shader
    
    glCompileShader(ShaderCLId); // compile the shader to the gpu
   
    // Check the shader state
    int ShaderCompileState = 0;
    glGetShaderiv(ShaderCLId, GL_COMPILE_STATUS, &ShaderCompileState);

    if (ShaderCompileState != GL_TRUE) {
        displayout(D_ERROR, "Shader Could not be compiled, Try importing a diffrent file!");
        
        char infoLog[512];
        glGetShaderInfoLog(ShaderCLId, 512, NULL, infoLog);
       
        std::string Errorstring;

        for (int i = 0; i < 512; i++) {
            if (i != 0)
                Errorstring += infoLog[i];
        }

        std::string line;

        for (int i = 0; i < 512; i++) {
            if (infoLog[i] == '(') {
                for (int f = i + 1; f < 512; f++) {
                    if (infoLog[f] != ')') {
                        line += infoLog[f];
                    }
                    else {
                        break;
                    }
                }
                break;
            }
        }

        for (int i = 0; i < file.Data.size(); i++) {
            if (stoi(line) == i + 1) {
                file.Data[i].pop_back();
                std::string Mystr = infoLog;
                Mystr.pop_back();
               
                displayout(D_ERROR, "%d: %s  //%s", i + 1, file.Data[i].c_str(), Mystr.c_str() );
            }
            else 
                displayout(D_LOG, "  %d: %s", i+1, file.Data[i].c_str());
        }

        ShaderCLId = 0;
        return; // stop the loading/compiling
    }

    
    
    ProgramCLId = glCreateProgram();

    glAttachShader(ProgramCLId, ShaderCLId);
    glLinkProgram(ProgramCLId);

    int ProgramCompileState = 0;
    glGetProgramiv(ProgramCLId, GL_LINK_STATUS, &ProgramCompileState);
    if (ProgramCompileState != GL_TRUE) {
        displayout(D_ERROR, "Program for shader could not be created!");

        ProgramCLId = 0;
        ShaderCLId = 0;
    }

    displayout(D_INFO, "Shader Compiled!");


   
}

void ShaderCL::bind() {
    glUseProgram(ProgramCLId);
}

void ShaderCL::unbind() {
    glUseProgram(0);
}

void ShaderCL::SendVar(std::string VarName, UniformType type, Vector4 data) {
    int vertexShaderLocation = glGetUniformLocation(ProgramCLId, VarName.c_str());
    
    switch (type)
    {
    case UNIFORM_1F:
        glUniform1f(vertexShaderLocation, data.x);
        break;
    case UNIFORM_1I:
        glUniform1i(vertexShaderLocation, int(data.x));
        break;
    case UNIFORM_VER2:
        glUniform2f(vertexShaderLocation, data.x, data.y);
        break;
    case UNIFORM_VER3:
        glUniform3f(vertexShaderLocation, data.x, data.y, data.z);
        break;
    case UNIFORM_VER4:
        glUniform4f(vertexShaderLocation, data.x, data.y, data.z, data.w);
        break;
    default:
        break;
    }
}

void ShaderCL::operator =(std::string filename) {
    load(filename);
}
