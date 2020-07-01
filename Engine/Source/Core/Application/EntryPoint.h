#pragma once

#ifdef RG_PLATFORM_WINDOWS

#include "rgpch.h"

extern Ringo::Application* Ringo::CreateApplication();

int main(int argc, char** argv)
{
	Ringo::Log::Init();
	RG_ENGINE_WARNING("Engine initialized.");

	auto app = Ringo::CreateApplication();
	app->Run();
	delete app;
}

#endif