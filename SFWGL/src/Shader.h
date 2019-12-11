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


// This shader class can only load on shader at a time, you need more classes for more shaders
class LShader
{
private:
	// Shader file location and file contents 
	File shaderFile;

	// misc
	int ShaderId = NULL; // We are null pointing this so we dont have a pre-undefined
	int ProgramId = NULL;

public:

	// basic constuctors for initing the main class
	LShader(std::string FileName);
	
	
	// Loading shader
	void LoadShader(std::string FileName);

	// compiling shader
	void CompileShader(GLenum shadertype);

	// misc
	void Bind();
	void UnBind();
	int GetProgramID();

	// Printing the log
	void PrintProgramLog();
	void PrintCompileLog();

};

