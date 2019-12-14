#include "src/SFWGL.h"


using namespace std;

int main() {
	Display display(480, 480, "My window");
	LShader Lshader("shader.glsl");

	Lshader.LCompileShader(GL_FRAGMENT_SHADER);
	Lshader.LBind();

	while (!display.WindowShouldClose()) {
		display.StartDrawing();
		glClearColor(0, 255, 0, 255); 




		display.EndDrawing();
	}
	
	CLOSE_MAIN
}

