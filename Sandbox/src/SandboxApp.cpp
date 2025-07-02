#include <Kairos.h>

class Sandbox : public Kairos::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Kairos::Application* Kairos::CreateApplication()
{
	return new Sandbox();
}