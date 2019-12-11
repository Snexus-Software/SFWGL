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

#include "Shader.h"




// basic constuctors for initing the main class
LShader::LShader(std::string FileName) {
	this->shaderFile = GetF(FileName);

	if (this->shaderFile.Data.size() > 0) {
		displayout(D_INFO, "Loaded in to Shader class");
	}
}


// Loading shader
void LShader::LoadShader(std::string FileName) {
	this->shaderFile = GetF(FileName);

	if (this->shaderFile.Data.size() > 0)
		displayout(D_INFO, "Loaded %s in to Shader class");
}

// compiling shader
void LShader::CompileShader(GLenum shadertype) {
	this->ShaderId = glCreateShader(shadertype);

	std::string LShaderString  = "";

	for (auto& i : this->shaderFile.Data) {
		LShaderString += i;
	}

	glShaderSource(this->ShaderId, 1, (const char**)(LShaderString.c_str()), NULL); // turn the shader string to something that opengl can read and compile

	// Compile the Shader
	glCompileShader(ShaderId);

	// Check the shader for those errors
	int DidShaderCompile = GL_FALSE;
	glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &DidShaderCompile);

	if (DidShaderCompile == GL_TRUE) {
		displayout(D_ERROR, "Unable to compile shader %d!\nFileName: %s", this->ShaderId, this->shaderFile.Name);
		PrintCompileLog();
		glDeleteShader(this->ShaderId);
		ShaderId = NULL; // unload the shader id number so the shader is no longer in mem
	}
	else {
		displayout(D_INFO, "Compiled Shader! ID:%d", this->ShaderId);
	}

	this->ProgramId = glCreateProgram();

	glAttachShader(this->ProgramId, this->ShaderId);
	glLinkProgram(this->ProgramId);

	GLint programSuccess = GL_TRUE;
	glGetProgramiv(this->ProgramId, GL_LINK_STATUS, &programSuccess);
	if (programSuccess != GL_TRUE)
	{
		printf("Error linking program %d!\n", this->ProgramId);
		PrintProgramLog();
		glDeleteProgram(this->ProgramId);
		this->ProgramId = 0;
	}
}

// misc
void LShader::Bind() {
	glUseProgram(this->ShaderId);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		displayout(D_ERROR, "Error binding shader! %d\n", this->ShaderId);
		PrintCompileLog();
	}

}

void LShader::UnBind() {
	//Use default program
	glUseProgram(NULL);
}

int LShader::GetProgramID() {
	return this->ShaderId;
}

// Printing the log
void LShader::PrintProgramLog() {
	// Make sure name is shader
		if (glIsProgram(this->ProgramId))
		{
			//Program log length
			int infoLogLength = 0;
			int maxLength = infoLogLength;

			//Get info string length
			glGetProgramiv(this->ProgramId, GL_INFO_LOG_LENGTH, &maxLength);

			//Allocate string
			char* infoLog = new char[maxLength];

			//Get info log
			glGetProgramInfoLog(this->ProgramId, maxLength, &infoLogLength, infoLog);
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
			displayout(D_WARNING, "Name %d is not a program\n", this->ProgramId);
		}
}

void LShader::PrintCompileLog() {
	//Make sure name is shader
	if (glIsShader(this->ShaderId))
	{
		//Shader log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		//Get info string length
		glGetShaderiv(this->ShaderId, GL_INFO_LOG_LENGTH, &maxLength);

		//Allocate string
		char* infoLog = new char[maxLength];

		//Get info log
		glGetShaderInfoLog(this->ShaderId, maxLength, &infoLogLength, infoLog);
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
		displayout(D_WARNING, "Name %d is not a shader\n", this->ShaderId);
	}
}