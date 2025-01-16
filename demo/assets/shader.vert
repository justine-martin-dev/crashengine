#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aUv;

uniform vec3 color;

uniform mat4 mvp;

out vec2 uv;

void main() {
	gl_Position = mvp * vec4(aPos, 1.0);

	uv = aUv;
}
