#include "src/SFWGL.h"


using namespace std;

int main() {
	initSFGL(480, 480, "Title");


	while (!WindowShouldClose()) {
		StartDrawing();
		ClearToColor({255, 255, 255, 255});


		


		EndDrawing();
	}

	DestroySFGL();
	
}