#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kairos::Application* Kairos::CreateApplication();

int main(int argc, char** argv) {
	auto app = Kairos::CreateApplication();
	app->Run();
	delete app;
}

#endif 
