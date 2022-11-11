#pragma once
#include "Core.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {
	class Layer;

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_layerStack;
	};

	// To be define in Client
	Application* CreateApplication();
}


