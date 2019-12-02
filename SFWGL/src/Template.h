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

// ============== LIB INCLUDE ABSTRACTION LAYER ============== \\

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string>
#include <vector>
#include <chrono>
#include <math.h> 
#include <sstream>
#include "external/glm/glm.hpp"
#include "external/glm/gtx/transform.hpp"

#include "external/SGL.h"


#ifdef  _WIN32
#include <conio.h>
#include <thread>
#endif //  _WIN32

#ifdef __linux
#include <termios.h>
#include <pthread>
#include <unistd.h>
#endif // __linux

/*===================================================================================================================================

________/\\\\\\\\\____________________________________/\\\\\_______________________________________________________________
 _____/\\\////////___________________________________/\\\///________________________________________________________________
  ___/\\\/___________________________________________/\\\_______/\\\___/\\\\\\\\_____________________________________________
   __/\\\_________________/\\\\\_____/\\/\\\\\\____/\\\\\\\\\___\///___/\\\////\\\__/\\\____/\\\__/\\/\\\\\\\______/\\\\\\\\__
    _\/\\\_______________/\\\///\\\__\/\\\////\\\__\////\\\//_____/\\\_\//\\\\\\\\\_\/\\\___\/\\\_\/\\\/////\\\___/\\\/////\\\_
     _\//\\\_____________/\\\__\//\\\_\/\\\__\//\\\____\/\\\______\/\\\__\///////\\\_\/\\\___\/\\\_\/\\\___\///___/\\\\\\\\\\\__
      __\///\\\__________\//\\\__/\\\__\/\\\___\/\\\____\/\\\______\/\\\__/\\_____\\\_\/\\\___\/\\\_\/\\\_________\//\\///////___
       ____\////\\\\\\\\\__\///\\\\\/___\/\\\___\/\\\____\/\\\______\/\\\_\//\\\\\\\\__\//\\\\\\\\\__\/\\\__________\//\\\\\\\\\\_
        _______\/////////_____\/////_____\///____\///_____\///_______\///___\////////____\/////////___\///____________\//////////__

        Config Settings for SFWGL.lib
        copyright (c) 2019 Snexus Software
===================================================================================================================================*/


