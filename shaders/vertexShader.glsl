#version 330 core

uniform float xOffset;

layout (location=0) in vec3 pos;

out vec4 outFragColor;

void main() {
   gl_Position = vec4(pos.x + xOffset, pos.y, pos.z, 1.0f);
}