#include "hzpch.h"
#include "WindowsInput.h"

#include "GLFW/glfw3.h"
#include "Hazel/Application.h"

namespace Hazel
{
    bool WindowsInput::IsKeyPressedImpl(int keyCode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        auto state = glfwGetKey(window,keyCode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
}
