#version 330 core

uniform vec4 transform;

layout (location=0) in vec3 pos;

out vec4 outFragColor;

void main() {
   gl_Position = transform * vec4(pos, 1.0f);
}