#version 150 core


uniform mat4 camera;
//out vec2 fragTextCoord;

void main() {

    gl_Position = camera * vec4(1, 1, 1, 1);
    //fragTextCoord = vec2(0.0, 0.0); 
}