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

// ============== VECTOR ABSTRACTION LAYER ============== \\

#include "Template.h"

#ifndef _STD
#define _STD ::std::
#endif // !_STD

#define print <<

class Vector2 {
private:
	Vector2 ReturnSelf() {
		Vector2 r;
		r.x = x;
		r.y = y;
		return r;
	}
public:
	float x = 0, y = 0;

	// Self Commands
	void operator +=(Vector2 e) {
		x += e.x;
		y += e.y;
	}

	void operator *=(Vector2 e) {
		x *= e.x;
		y *= e.y;
	}

	void operator /=(Vector2 e) {
		x /= e.x;
		y /= e.y;
	}

	void operator -=(Vector2 e) {
		x -= e.x;
		y -= e.y;
	}

	// Other Commands
	Vector2 operator +(Vector2 e) {
		Vector2 Self = ReturnSelf();
		Vector2 ReturningVec;
		ReturningVec.x = Self.x + e.x;
		ReturningVec.y = Self.y + e.y;
		return ReturningVec;
	}

	Vector2 operator *(Vector2 e) {
		Vector2 Self = ReturnSelf();
		Vector2 ReturningVec;
		ReturningVec.x = Self.x * e.x;
		ReturningVec.y = Self.y * e.y;
		return ReturningVec;
	}

	Vector2 operator /(Vector2 e) {
		Vector2 Self = ReturnSelf();
		Vector2 ReturningVec;
		ReturningVec.x = Self.x / e.x;
		ReturningVec.y = Self.y / e.y;
		return ReturningVec;
	}

	Vector2 operator -(Vector2 e) {
		Vector2 Self = ReturnSelf();
		Vector2 ReturningVec;
		ReturningVec.x = Self.x - e.x;
		ReturningVec.y = Self.y - e.y;
		return ReturningVec;
	}

	bool operator ==(Vector2 e) {
		if ((x == e.x) && (y == e.y)) {
			return true;
		}
		return false;
	}

	// Prints the vector with a name
	void operator <<(std::string Outputname) {
		std::cout << Outputname << ", X: " << x << " Y: " << y << std::endl;
	}
};

class Vector3 {
private:
	Vector3 ReturnSelf() {
		Vector3 r;
		r.x = x;
		r.y = y;
		r.z = z;
		return r;
	}
public:
	float x = 0, y = 0, z = 0;

	// Self Commands
	void operator +=(Vector3 e) {
		x += e.x;
		y += e.y;
		z += e.z;
	}

	void operator *=(Vector3 e) {
		x *= e.x;
		y *= e.y;
		z *= e.z;
	}

	void operator /=(Vector3 e) {
		x /= e.x;
		y /= e.y;
		z /= e.z;
	}

	void operator -=(Vector3 e) {
		x -= e.x;
		y -= e.y;
		z -= e.z;
	}

	// Other Commands
	Vector3 operator +(Vector3 e) {
		Vector3 Self = ReturnSelf();
		Vector3 ReturningVec;
		ReturningVec.x = Self.x + e.x;
		ReturningVec.y = Self.y + e.y;
		ReturningVec.z = Self.z + e.z;
		return ReturningVec;
	}

	Vector3 operator *(Vector3 e) {
		Vector3 Self = ReturnSelf();
		Vector3 ReturningVec;
		ReturningVec.x = Self.x * e.x;
		ReturningVec.y = Self.y * e.y;
		ReturningVec.z = Self.z * e.z;
		return ReturningVec;
	}

	Vector3 operator /(Vector3 e) {
		Vector3 Self = ReturnSelf();
		Vector3 ReturningVec;
		ReturningVec.x = Self.x / e.x;
		ReturningVec.y = Self.y / e.y;
		ReturningVec.z = Self.z / e.z;
		return ReturningVec;
	}

	Vector3 operator -(Vector3 e) {
		Vector3 Self = ReturnSelf();
		Vector3 ReturningVec;
		ReturningVec.x = Self.x - e.x;
		ReturningVec.y = Self.y - e.y;
		ReturningVec.z = Self.z - e.z;
		return ReturningVec;
	}

	bool operator ==(Vector3 e) {
		if ((x == e.x) && (y == e.y) && (z = e.z)) {
			return true;
		}
		return false;
	}

	// Prints the vector with a name
	void operator <<(std::string Outputname) {
		std::cout << Outputname << ", X: " << x << " Y: " << y << " Z: " << y << std::endl;
	}
};

class Vector4 {
private:
	Vector4 ReturnSelf() {
		Vector4 r;
		r.x = x;
		r.y = y;
		r.z = z;
		r.w = w;
		return r;
	}
public:
	float x = 0, y = 0, z = 0, w = 0;

	// Self Commands
	void operator +=(Vector4 e) {
		x += e.x;
		y += e.y;
		z += e.z;
		w += e.w;
	}

	void operator *=(Vector4 e) {
		x *= e.x;
		y *= e.y;
		z *= e.z;
		w *= e.w;
	}

	void operator /=(Vector4 e) {
		x /= e.x;
		y /= e.y;
		z /= e.z;
		w /= e.w;
	}

	void operator -=(Vector4 e) {
		x -= e.x;
		y -= e.y;
		z -= e.z;
		w -= e.w;
	}

	// Other Commands
	Vector4 operator +(Vector4 e) {
		Vector4 Self = ReturnSelf();
		Vector4 ReturningVec;
		ReturningVec.x = Self.x + e.x;
		ReturningVec.y = Self.y + e.y;
		ReturningVec.z = Self.z + e.z;
		ReturningVec.w = Self.z + e.w;
		return ReturningVec;
	}

	Vector4 operator *(Vector4 e) {
		Vector4 Self = ReturnSelf();
		Vector4 ReturningVec;
		ReturningVec.x = Self.x * e.x;
		ReturningVec.y = Self.y * e.y;
		ReturningVec.z = Self.z * e.z;
		ReturningVec.w = Self.z * e.w;
		return ReturningVec;
	}

	Vector4 operator /(Vector4 e) {
		Vector4 Self = ReturnSelf();
		Vector4 ReturningVec;
		ReturningVec.x = Self.x / e.x;
		ReturningVec.y = Self.y / e.y;
		ReturningVec.z = Self.z / e.z;
		ReturningVec.w = Self.z / e.w;
		return ReturningVec;
	}

	Vector4 operator -(Vector4 e) {
		Vector4 Self = ReturnSelf();
		Vector4 ReturningVec;
		ReturningVec.x = Self.x - e.x;
		ReturningVec.y = Self.y - e.y;
		ReturningVec.z = Self.z - e.z;
		ReturningVec.w = Self.z - e.w;
		return ReturningVec;
	}

	bool operator ==(Vector4 e) {
		if ((x == e.x) && (y == e.y) && (z = e.z) && (w == e.w)) {
			return true;
		}
		return false;
	}

	// Prints the vector with a name
	void operator <<(std::string Outputname) {
		std::cout << Outputname << ", X: " << x << " Y: " << y << " Z: " << y << " W: " << w << std::endl;
	}


};

// holds colors in int format (0 - 255)
typedef struct Colori {
	int r = 0,
		g = 0,
		b = 0,
		a = 0;
};

// holds colors in float format (0.f - 1.f)
typedef struct Colorf {
	float r = 0.f,
		g = 0.f,
		b = 0.f,
		a = 0.f;
};


// splits a vector
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
	std::stringstream ss(strToSplit);
	std::string item;
	std::vector<std::string> splittedStrings;
	while (std::getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

