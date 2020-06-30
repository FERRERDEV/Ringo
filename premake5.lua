workspace "Ringo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ringo"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("Engine/Binaries/" .. outputdir )
	objdir ("Engine/Intermediates/" .. outputdir )

	pchheader "rgpch.h"
	pchsource "%{prj.location}/Source/rgpch.cpp"

	files
	{
		"%{prj.location}/Source/**.h",
		"%{prj.location}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.location}/Source",
		"%{prj.location}/Third-party/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS",
			"RG_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "RG_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RG_RELEASE"
		optimize "on"

project "Sandbox"
	location "Templates/Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{prj.location}/Binaries/" .. outputdir)
	objdir ("%{prj.location}/Intermediates/" .. outputdir)

	files
	{
		"%{prj.location}/Source/**.h",
		"%{prj.location}/Source/**.cpp"
	}

	includedirs
	{
		"Engine/Third-party/spdlog/include",
		"Engine/Source"
	}

	links
	{
		"Ringo"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RG_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RG_RELEASE"
		optimize "on"