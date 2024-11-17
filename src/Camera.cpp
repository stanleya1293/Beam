#include "Camera.h"



Camera::Camera(float x, float y, float z) : cameraPosition(glm::vec3(x, y, z)), cameraView(glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp)), cameraSpeed(0.10) {
	

}

Camera::Camera() : cameraPosition(glm::vec3(0, 0, 3)), cameraView(glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp)), cameraSpeed(0.10){
	
}

Camera::~Camera() {};

void Camera::update() {
	cameraView = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
	int viewLocation = glGetUniformLocation(Renderer::getActiveShader().getShaderID(), "view");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(cameraView));
}

void Camera::move(Direction direction) {
	switch (direction) {
	case Forward:
		cameraPosition += cameraSpeed * cameraFront;
		break;
	case Backward:
		cameraPosition -= cameraSpeed * cameraFront;
		break;
	case Left:
		cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		break;
	case Right:
		cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		break;
	}
}
