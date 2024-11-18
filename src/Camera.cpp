#include "Camera.h"

Camera::Camera(float x, float y, float z)
	: cameraPosition(glm::vec3(x, y, z)),
	cameraView(glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp)),
	cameraSpeed(0.10),
	cameraDirection(glm::vec3(0, 0, 0)),
	cameraYaw(-90.0f),
	cameraPitch(0.0f),
	cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
	cameraProjection(glm::perspective(glm::radians(60.0f), 800.0f / 800.0f, 0.1f, 100.0f)),
	cameraFOV(60.0f)
{
	setDirection(cameraYaw, cameraPitch);
}

Camera::Camera()
	: cameraPosition(glm::vec3(0, 0, 3)),
	cameraView(glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp)),
	cameraSpeed(0.10),
	cameraDirection(glm::vec3(0, 0, 0)),
	cameraYaw(-90.0f),
	cameraPitch(0.0f),
	cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
	cameraProjection(glm::perspective(glm::radians(60.0f), 800.0f / 800.0f, 0.1f, 100.0f)),
	cameraFOV(60.0f)
{
	setDirection(cameraYaw, cameraPitch);
}

Camera::~Camera() {}

void Camera::update() 
{
	cameraView = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
	int viewLocation = glGetUniformLocation(Renderer::getActiveShader().getShaderID(), "view");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(cameraView));

	int projectionLocation = glGetUniformLocation(Renderer::getActiveShader().getShaderID(), "projection");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(cameraProjection));
}

void Camera::move(Direction direction) 
{
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

void Camera::setZoom(float fov) 
{
	if (fov < 1.0f) 
	{
		cameraFOV = 1.0f;
	}
	else if (fov > 60.0f)
	{
		cameraFOV = 60.0f;
	}
	else
	{
		cameraFOV = fov;
	}
	cameraProjection = glm::perspective(glm::radians(cameraFOV), 800.0f / 800.0f, 0.1f, 100.0f);
}

void Camera::setDirection(float yaw, float pitch) 
{
	cameraYaw = yaw;
	cameraPitch = pitch;
	if (cameraPitch > 89.0f) 
	{
		cameraPitch = 89.0f;
	}
	else if (cameraPitch < -89.0f) 
	{
		cameraPitch = -89.0f;
	}
	cameraDirection =
		glm::vec3
		(
			cos(glm::radians(cameraYaw) * cos(glm::radians(cameraPitch))),
			sin(glm::radians(cameraPitch)),
			sin(glm::radians(cameraYaw) * cos(glm::radians(cameraPitch)))
		);
	cameraFront = glm::normalize(cameraDirection);
}
