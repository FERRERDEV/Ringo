#pragma once

#include "Core/Core.h"
#include "Core/Application/Window.h"

namespace Ringo {

	class RINGO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}