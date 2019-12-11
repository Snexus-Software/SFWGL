#include "src/SFWGL.h"


using namespace std;

int main() {
	Display display(480, 480, "My window");
	LShader shader("shader.glsl");

	shader.CompileShader(GL_FRAGMENT_SHADER);
	shader.Bind();

	while (!display.WindowShouldClose()) {
		display.StartDrawing();
		glClearColor(0, 255, 0, 255); 




		display.EndDrawing();
	}
	
	CLOSE_MAIN
}

