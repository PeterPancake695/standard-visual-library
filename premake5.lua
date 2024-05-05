workspace "svl"
  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "svl"
  kind "SharedLib"
  language "C++"
	cppdialect "C++17"
	staticruntime "off"
  architecture "x86_64"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

  files {
    "src/**.hpp",
    "src/**.cpp"
  }

  includedirs {
    "vendor/spdlog/include"
  }

  defines {
    "SVL_BUILD_LIB"
  }

  postbuildcommands {
    ("{MKDIR} bin/" .. outputdir .. "/Sandbox"),
    ("{COPY} %{cfg.buildtarget.relpath} bin/".. outputdir .. "/Sandbox")
  }

  filter "system:windows"
    systemversion "latest"

    defines {}

  filter "configurations:Debug"
    defines "SVL_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "SVL_RELEASE"
    runtime "Release"
    optimize "on"

  filter "configurations:Dist"
    defines "SVL_DIST"
    runtime "Release"
    optimize "on"

project "Sandbox"
  location "tests/Sandbox"
  kind "ConsoleApp"
  language "C++"
	cppdialect "C++17"
  architecture "x86_64"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

  includedirs {
    "vendor/spdlog/include",
    "src"
  }

  files {
    "tests/Sandbox/**.cpp",
    "tests/Sandbox/**.hpp"
  }

  links {
    "svl"
  }

  filter "system:windows"
    systemversion "latest"

    defines {}

  filter "configurations:Debug"
    defines "SVL_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "SVL_RELEASE"
    runtime "Release"
    optimize "on"

  filter "configurations:Dist"
    defines "SVL_DIST"
    runtime "Release"
    optimize "on"
