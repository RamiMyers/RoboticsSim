#version 330 core

uniform vec4 inFragColor;

layout (location=0) in vec3 pos;

out vec4 outFragColor;

void main() {
   gl_Position = vec4(pos, 1.0f);
   outFragColor = inFragColor;
}