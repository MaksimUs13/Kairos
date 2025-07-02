#pragma once

#include "Core.h"

namespace Kairos {

	class KAIROS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}