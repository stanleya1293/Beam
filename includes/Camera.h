#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include "Renderer.h"


class Camera 
{
public:
	enum Direction 
	{
		Left, Right, Forward, Backward
	};
	Camera(float x, float y, float z);
	Camera();
	~Camera();
	void update();
	void move(Direction dir);
	void setZoom(float fov);
	void setDirection(float yaw, float pitch);
	inline void rotate(float xOffset, float yOffset) { setDirection((cameraYaw + xOffset), (cameraPitch + yOffset)); };
	inline void zoom(float offset) { setZoom(cameraFOV - offset); };
	inline void setSpeed(float speed) { cameraSpeed = speed;  };
private:
	float cameraYaw;
	float cameraPitch;
	float cameraSpeed;
	float cameraFOV;
	const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraFront;
	glm::vec3 cameraPosition;
	glm::vec3 cameraDirection;
	glm::mat4 cameraView;
	glm::mat4 cameraProjection;
};


#endif