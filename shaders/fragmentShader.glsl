#version 330 core

in vec4 outFragColor;
out vec4 fragColor;

void main() {
    fragColor = outFragColor;
}