#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include "Renderer.h"


class Camera {
public:
	enum Direction {
		Left, Right, Forward, Backward
	};
	Camera(float x, float y, float z);
	Camera();
	~Camera();
	void update();
	void move(Direction dir);
private:
	const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	const glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraPosition;
	glm::mat4 cameraView;
	float cameraSpeed;
};


#endif