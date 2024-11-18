#include "Application.h"

Application::Application() {}

Application::~Application() {}

void mouseCallBack(GLFWwindow* window, double xPos, double yPos) 
{
    static float lastX = 400;
    static float lastY = 300;
    static bool firstMouse = true;
    if (firstMouse) 
    {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    Camera* camera = (Camera*)glfwGetWindowUserPointer(window);
    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos;
    lastX = xPos;
    lastY = yPos;
    const float sensitivity = 0.1f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    camera->rotate(xOffset, yOffset);

}

void scrollCallBack(GLFWwindow* window, double xOffset, double yOffset) 
{
    Camera* camera = (Camera*)glfwGetWindowUserPointer(window);
    camera->zoom(yOffset);
}

void Application::handleInput() 
{
    glfwSetInputMode(window.getWindowID(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetWindowUserPointer(window.getWindowID(), &camera);
    glfwSetCursorPosCallback(window.getWindowID(), mouseCallBack);
    glfwSetScrollCallback(window.getWindowID(), scrollCallBack);

    static bool keyHeldW = false;
    static bool keyHeldA = false;
    static bool keyHeldS = false;
    static bool keyHeldD = false;

    static float lastFrame = 0.0f;
    float deltaTime = 0.0f;
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    camera.setSpeed(deltaTime * 5.0f);

    if (glfwGetKey(window.getWindowID(), GLFW_KEY_W) == GLFW_PRESS || keyHeldW == true) 
    {
        camera.move(Camera::Forward);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_A) == GLFW_PRESS || keyHeldA == true) 
    {
        camera.move(Camera::Left);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_S) == GLFW_PRESS || keyHeldS == true) 
    {
        camera.move(Camera::Backward);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_D) == GLFW_PRESS || keyHeldD == true) 
    {
        camera.move(Camera::Right);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_W) == GLFW_RELEASE) 
    {
        keyHeldW = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_A) == GLFW_RELEASE) 
    {
        keyHeldA = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_S) == GLFW_RELEASE) 
    {
        keyHeldS = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_D) == GLFW_RELEASE) 
    {
        keyHeldD = false;
    }
}

void Application::start() 
{
    
    while (window.isRunning()) 
    {
        handleInput();
        camera.update();


        int objectColorLocation = glGetUniformLocation(renderer.getActiveShader().getShaderID(), "objectColor");
        glUniform3fv(objectColorLocation, 1, glm::value_ptr(glm::vec3(1.0f, 0.5f, 0.31f)));
        int lightColorLocation = glGetUniformLocation(renderer.getActiveShader().getShaderID(), "lightColor");
        glUniform3fv(lightColorLocation, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
        glm::mat4 cubeModel = glm::mat4(1.0f);
        cubeModel = glm::translate(cubeModel, glm::vec3(0.0f, 0.0f, 0.0f));      
        renderer.draw(0, cubeModel);

        camera.update();

        glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
        glm::mat4 lightCubeModel = glm::mat4(1.0f);
        lightCubeModel = glm::translate(lightCubeModel, lightPos);
        lightCubeModel = glm::scale(lightCubeModel, glm::vec3(0.2f));
        renderer.draw(1, lightCubeModel);


        window.update();
	}
}