#version 330 core

in vec2 uv;
uniform sampler2D myAwesomeTexture;

out vec4 FragColor;

void main() {
    FragColor = texture(myAwesomeTexture, uv);
} 