#version 330 core

uniform vec4 inFragColor;

out vec4 fragColor;

void main() {
    fragColor = inFragColor;
}