#include "rgpch.h"
#include "EditorWindow.h"

namespace Ringo
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new EditorWindow(props);
	}

	EditorWindow::EditorWindow(const WindowProps& props)
	{
		Init(props);
	}

	EditorWindow::~EditorWindow()
	{
		Shutdown();
	}

	void EditorWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void EditorWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool EditorWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void EditorWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			RG_ENGINE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		m_Data.Width = mode->width;
		m_Data.Height = mode->height;

		RG_ENGINE_INFO("Creating window {0} ({1}, {2})", props.Title, m_Data.Width, m_Data.Height);

		m_Window = glfwCreateWindow(mode->width, mode->height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMaximizeWindow(m_Window);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void Ringo::EditorWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
