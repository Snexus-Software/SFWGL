#include "src/SFWGL.h"


using namespace std;

void DrawCube(Vector3 position, float width, float height, float length, Color color)
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;


    glPushMatrix();
    // NOTE: Transformation is applied in inverse order (scale -> rotate -> translate)
    glTranslatef(position.x, position.y, position.z);
    //glRotatef(45, 0, 1, 0);
    //glScalef(1.0f, 1.0f, 1.0f);   // NOTE: Vertices are directly scaled on definition

    glBegin(GL_TRIANGLES);
    glColor4ub(color.r, color.g, color.b, color.a);

    // Front face
    glVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Left
    glVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right
    glVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left

    glVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Right
    glVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left
    glVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right

    // Back face
    glVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Left
    glVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left
    glVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right

    glVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right
    glVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right
    glVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left

    // Top face
    glVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left
    glVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Bottom Left
    glVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Bottom Right

    glVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right
    glVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left
    glVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Bottom Right

    // Bottom face
    glVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Top Left
    glVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right
    glVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Left

    glVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Top Right
    glVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right
    glVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Top Left

    // Right face
    glVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right
    glVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right
    glVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Left

    glVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Left
    glVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right
    glVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Left

    // Left face
    glVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Right
    glVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left
    glVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Right

    glVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Left
    glVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left
    glVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Right
    glEnd();
    glPopMatrix();
}


int main() {
	Display display(480, 480, "My window");
	ShaderCL FragmentShader("shader.glsl");
	FragmentShader.compile(GL_FRAGMENT_SHADER);

	while (!display.WindowShouldClose()) {
		display.StartDrawing();
		glClearColor(0, 0, 0, 255); 

		FragmentShader.bind();
        FragmentShader.SendVar("Color", UNIFORM_VER3, { 1.0, 1.0, 0.0 });
        FragmentShader.SendVar("time", UNIFORM_1F, { float(glfwGetTime()) });
        

        DrawCube({ 0, 0, 0 }, 1, 1, 1, { 100, 100, 100, 255 });
		


		display.EndDrawing();
	}
	
}

