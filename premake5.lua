workspace "Ringo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ringo"
	location "Engine"
	kind "SharedLib"
	language "C++"

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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS",
			"RG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Templates/Sandbox/Binaries/" .. outputdir)
		}

	filter "configurations:Debug"
		defines "RG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RG_DIST"
		optimize "On"

project "Sandbox"
	location "Templates/Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RG_DIST"
		optimize "On"