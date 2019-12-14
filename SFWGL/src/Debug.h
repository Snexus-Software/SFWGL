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
#include <stdarg.h>

#ifndef _STD
#define _STD ::std::
#endif // !_STD

#ifndef Debug_H_SNEXUS
#define Debug_H_SENXUS
// Defines the color output for the console
namespace ColorM {
	enum Code {
		FG_RED = 31,
		FG_GREEN = 32,
		FG_BLUE = 34,
		FG_YELLOW = 33,
		FG_DEFAULT = 39,
		FG_MAGENTA = 35,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_BLUE = 44,
		BG_DEFAULT = 49

	};
	class Modifier {
		Code code;
	public:
		Modifier(Code pCode) : code(pCode) {}
		friend std::ostream&
			operator<<(std::ostream& os, const Modifier& mod) {
			return os << "\033[" << mod.code << "m";
		}
	};
}
ColorM::Modifier redM(ColorM::FG_RED);
ColorM::Modifier greenM(ColorM::FG_GREEN);
ColorM::Modifier blueM(ColorM::FG_BLUE);
ColorM::Modifier magentaM(ColorM::FG_MAGENTA);
ColorM::Modifier yellowM(ColorM::FG_YELLOW);
ColorM::Modifier defM(ColorM::FG_DEFAULT);

// defines the log types for outputting
enum Debug
{
	D_LOG = 1,
	D_FILE,
	D_DEBUG,
	D_ERROR,
	D_INFO,
	D_WARNING,
};

_STD string debugstring[] = { "NULL", "LOG", "FILE", "DEBUG", "ERROR", "INFO", "WARNING" };
ColorM::Modifier debugcolor[] = { defM, blueM, greenM, redM, redM, magentaM, yellowM };


// displays out the log
inline void displayout(int msgType, const char* text, ...)
{
	std::cout << debugcolor[msgType];
	
	va_list args;
	va_start(args, text);
	fprintf(stdout, (debugstring[msgType] + ": ").c_str());
	vfprintf(stdout, text, args);
	va_end(args);


	fprintf(stdout, "\n");
	std::cout << debugcolor[0];

}

// Defining Helpful macros 
#define FOR(varname, iterations) for (int varname = 0; varname < iterations; varname++)
#define xstr(x) str(x)
#define str(x) #x
#define glue(x, y) x ## y


#endif // !Debug_H_SENXUS


