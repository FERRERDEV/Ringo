#include <Ringo.h>

class Sandbox : public Ringo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Ringo::Application* Ringo::CreateApplication()
{
	RG_TRACE("Application initialized.");
	return new Sandbox();
}