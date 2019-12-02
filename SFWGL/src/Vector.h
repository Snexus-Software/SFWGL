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

// world position vector to quaternion
typedef Vector4 Quaternion;

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


// Rectangle type
typedef struct Rectangle {
	float x;
	float y;
	float width;
	float height;
} Rectangle;

typedef struct Image {
	void* data;             // Image raw data
	int width;              // Image base width
	int height;             // Image base height
	int mipmaps;            // Mipmap levels, 1 by default
	int format;             // Data format (PixelFormat type)
} Image;

// Texture2D type
// NOTE: Data stored in GPU memory
typedef struct Texture2D {
	unsigned int id;        // OpenGL texture id
	int width;              // Texture base width
	int height;             // Texture base height
	int mipmaps;            // Mipmap levels, 1 by default
	int format;             // Data format (PixelFormat type)
} Texture2D;

// Texture type, same as Texture2D
typedef Texture2D Texture;

typedef unsigned char byte;

// Color type, RGBA (32bit)
typedef struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} Color;



// TextureCubemap type, actually, same as Texture2D
typedef Texture2D TextureCubemap;

// RenderTexture2D type, for texture rendering
typedef struct RenderTexture2D {
	unsigned int id;        // OpenGL frame buffer (fbo) id
	Texture2D texture;      // Color buffer attachment texture
	Texture2D depth;        // Depth buffer attachment texture
	bool depthTexture;      // Track if depth attachment is a texture or render buffer
} RenderTexture2D;

// RenderTexture type, same as RenderTexture2D
typedef RenderTexture2D RenderTexture;

// Vertex data definning a mesh
typedef struct Mesh {
	int vertexCount;        // number of vertices's stored in arrays
	int triangleCount;      // number of triangles stored (indexed or not)
	float* vertices;        // vertex position (XYZ - 3 components per vertex) (shader-location = 0)
	float* texcoords;       // vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
	float* texcoords2;      // vertex second texture coordinates (useful for light maps) (shader-location = 5)
	float* normals;         // vertex normals (XYZ - 3 components per vertex) (shader-location = 2)
	float* tangents;        // vertex tangents (XYZW - 4 components per vertex) (shader-location = 4)
	unsigned char* colors;  // vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
	unsigned short* indices;// vertex indices (in case vertex data comes indexed)

	// Animation vertex data
	float* animVertices;    // Animated vertex positions (after bones transformations)
	float* animNormals;     // Animated normals (after bones transformations)
	int* boneIds;           // Vertex bone ids, up to 4 bones influence by vertex (skinning)
	float* boneWeights;     // Vertex bone weight, up to 4 bones influence by vertex (skinning)

	// OpenGL identifiers
	unsigned int vaoId;     // OpenGL Vertex Array Object id
	unsigned int vboId[7];  // OpenGL Vertex Buffer Objects id (7 types of vertex data)
} Mesh;

// Shader and material limits
#define MAX_SHADER_LOCATIONS    32
#define MAX_MATERIAL_MAPS       12

// Shader type (generic)
typedef struct Shader {
	unsigned int id;                // Shader program id
	int locs[MAX_SHADER_LOCATIONS]; // Shader locations array
} Shader;

// Material texture map
typedef struct MaterialMap {
	Texture2D texture;      // Material map texture
	Color color;            // Material map color
	float value;            // Material map value
} MaterialMap;

// Material type (generic)
typedef struct Material {
	Shader shader;          // Material shader
	MaterialMap maps[MAX_MATERIAL_MAPS]; // Material maps
	float* params;          // Material generic parameters (if required)
} Material;


// Font character info
typedef struct CharInfo {
	int value;              // Character value (Unicode)
	Rectangle rec;          // Character rectangle in sprite font
	int offsetX;            // Character offset X when drawing
	int offsetY;            // Character offset Y when drawing
	int advanceX;           // Character advance position X
	unsigned char* data;    // Character pixel data (grayscale)
} CharInfo;

// Font type, includes texture and charSet array data
typedef struct Font {
	Texture2D texture;      // Font texture
	int baseSize;           // Base size (default chars height)
	int charsCount;         // Number of characters
	CharInfo* chars;        // Characters info data
} Font;