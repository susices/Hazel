#include "hzpch.h"
#include "ImGuiLayer.h"

#include "GLFW/glfw3.h"
#include "Hazel/Application.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

namespace Hazel
{

    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
    {
        
    }

    ImGuiLayer::~ImGuiLayer()
    {
        
    }

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;


        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        
    }

    void ImGuiLayer::OnUpdate()
    {
        Application& app =  Application::Get();
        auto& window =  app.GetWindow();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(window.GetWidth(),window.GetHeight());
        
        float time = (float) glfwGetTime();
        
        io.DeltaTime = m_Time > 0 ? (time-m_Time) : (1.0f / 60.0f); 
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        
    }
}
