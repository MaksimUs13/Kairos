#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kairos::Application* Kairos::CreateApplication();

int main(int argc, char** argv) {
	Kairos::Log::Init();
	KR_CORE_WARN("Initializeted Log!");
	int a = 15;
	KR_INFO("Hello! Var={0}", a);

	auto app = Kairos::CreateApplication();
	app->Run();
	delete app;
}

#endif 
