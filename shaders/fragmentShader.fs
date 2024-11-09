#version 330 core
	out vec4 color;
	in vec3 ourColor;
	uniform float fadeScalar;
	void main() {
	    color = fadeScalar * vec4(ourColor, 1.0f);
	}
