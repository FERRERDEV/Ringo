#pragma once

#include "Core.h"

namespace Ringo {

	class RINGO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}