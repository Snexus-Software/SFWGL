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

#include "LShader.h"



// basic constuctors for initing the main class
LShader::LShader(std::string FileName) {
	this->shaderFile = GetF(FileName);

	if (this->shaderFile.Data.size() > 0) {
		displayout(D_INFO, "Loaded in to Shader obj");
	}
}


// Loading shader
void LShader::LShaderFromFile(std::string FileName) {
	this->shaderFile = GetF(FileName);

	if (this->shaderFile.Data.size() > 0)
		displayout(D_INFO, "Loaded in to Shader obj");
}

// compiling shader
void LShader::LCompileShader(GLenum Lshadertype = GL_FRAGMENT_SHADER) {

	LShaderId = glCreateShader(Lshadertype);

	
	std::string LShaderString;


	for (auto& i : shaderFile.Data) {
		LShaderString += i;
	}

	glShaderSource(this->LShaderId, 1, (const char**)(LShaderString.c_str()), NULL); // turn the shader string to something that opengl can read and compile

	// Compile the Shader
	glCompileShader(LShaderId);

	// Check the shader for those errors
	int DidShaderCompile = GL_FALSE;
	glGetShaderiv(LShaderId, GL_COMPILE_STATUS, &DidShaderCompile);

	if (DidShaderCompile == GL_TRUE) {
		displayout(D_ERROR, "Unable to compile shader %d!\nFileName: %s", this->LShaderId, this->shaderFile.Name);
		PrintCompileLog();
		glDeleteShader(this->LShaderId);
		LShaderId = NULL; // unload the shader id number so the shader is no longer in mem
	}
	else {
		displayout(D_INFO, "Compiled Shader! ID:%d", this->LShaderId);
	}

	this->LProgramId = glCreateProgram();

	glAttachShader(this->LProgramId, this->LShaderId);
	glLinkProgram(this->LProgramId);

	GLint programSuccess = GL_TRUE;
	glGetProgramiv(this->LProgramId, GL_LINK_STATUS, &programSuccess);
	if (programSuccess != GL_TRUE)
	{
		printf("Error linking program %d!\n", this->LProgramId);
		PrintProgramLog();
		glDeleteProgram(this->LProgramId);
		this->LProgramId = 0;
	}
}

// misc
void LShader::LBind() {
	glUseProgram(this->LShaderId);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		displayout(D_ERROR, "Error binding shader! %d\n", this->LShaderId);
		PrintCompileLog();
	}

}

void LShader::LUnBind() {
	//Use default program
	glUseProgram(NULL);
}

int LShader::LGetProgramID() {
	return this->LShaderId;
}

// Printing the log
void LShader::PrintProgramLog() {
	// Make sure name is shader
		if (glIsProgram(this->LProgramId))
		{
			//Program log length
			int infoLogLength = 0;
			int maxLength = infoLogLength;

			//Get info string length
			glGetProgramiv(this->LProgramId, GL_INFO_LOG_LENGTH, &maxLength);

			//Allocate string
			char* infoLog = new char[maxLength];

			//Get info log
			glGetProgramInfoLog(this->LProgramId, maxLength, &infoLogLength, infoLog);
			if (infoLogLength > 0)
			{
				//Print Log
				displayout(D_INFO, "%s\n", infoLog);
			}

			//Deallocate string
			delete[] infoLog;
		}
		else
		{
			displayout(D_WARNING, "Name %d is not a program\n", this->LProgramId);
		}
}

void LShader::PrintCompileLog() {
	//Make sure name is shader
	if (glIsShader(this->LShaderId))
	{
		//Shader log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		//Get info string length
		glGetShaderiv(this->LShaderId, GL_INFO_LOG_LENGTH, &maxLength);

		//Allocate string
		char* infoLog = new char[maxLength];

		//Get info log
		glGetShaderInfoLog(this->LShaderId, maxLength, &infoLogLength, infoLog);
		if (infoLogLength > 0)
		{
			//Print Log
			displayout(D_INFO, "%s\n", infoLog);
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
		displayout(D_WARNING, "Name %d is not a shader\n", this->LShaderId);
	}
}