#version 330 core
out vec4 FragColor;  
uniform vec3 Color;
uniform float time;


void main()
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = gl_FragCoord.xy / vec2(100, 100);

    // Time varying pixel color
    vec3 col = 0.5 + 0.5 * cos( time + uv.xyx + vec3(0,2,4) );

    // Output to screen
    FragColor = vec4(col,1.0);
}