workspace "Render3D"
		architecture "x86"

		configurations
		{
			"Debug",
			"Release"
		}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Render3D"
	location "Render3D"
	kind "ConsoleApp"
	language "c++"

targetdir ("%{prj.name}/bin/bin-out/" .. outputdir .. "/%{prj.name}/")
objdir ("%{prj.name}/bin/bin-int/" .. outputdir .. "/%{prj.name}/")

pchheader "pch.h"
pchsource "Render3D/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Application.h",
		"%{prj.name}/Application.cpp",

		"%{prj.name}/ThirdParty/stb_image/**.cpp",
		"%{prj.name}/ThirdParty/stb_image/**.h",
		"%{prj.name}/ThirdParty/glad/src/**.c"
	}

	buildoptions
	{
		"/W2",
		"/MD"
	}

	includedirs
	{
		"%{prj.name}",
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/glfw/include",
		"%{prj.name}/ThirdParty/glad/include",
		"%{prj.name}/ThirdParty/spdlog/include",
		"%{prj.name}/ThirdParty/stb_image"
	}

	libdirs
	{
		"%{prj.name}/ThirdParty/glfw/lib"
	}

	links
	{
		"glfw3.lib",
		"opengl32.lib"
	}

	filter "files:Render3D/ThirdParty/glad/src/**.c"
		flags
		{
			"NoPCH"
		}

	filter "files:Render3D/ThirdParty/stb_image/**.cpp"
		flags
		{
			"NoPCH"
		}


	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"R3D_WINDOWS"
		}

		filter "configurations:Debug"
			defines "R3D_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "R3D_RELEASE"
			optimize "On"