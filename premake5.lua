workspace "Kairos"

    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kairos"
    location "Kairos"
    kind "SharedLib"
    language "c++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/thirdparty/spdlog/include;"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {  
            "KR_PLATFORM_WINDOWS",
            "KR_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "KR_DEBUG"
        symbols "On"
    filter "configurations:Debug"
        defines "KR_RELEASE"
        optimize "On"

        filter "configurations:Dist"
        defines "KR_DIST"
        optimize "On"
    -- ��� ���� ������������ (Debug/Release)
    filter { "action:vs2019" }  -- ���������, ��� ��� ��� VS2019
        buildoptions { "/utf-8" }  -- ��������� ���� � ��������� ������ �����������

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "c++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Kairos/thirdparty/spdlog/include;",
        "Kairos/src"
    }

    links
    {
        "Kairos"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {  
            "KR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "KR_DEBUG"
        symbols "On"
    filter "configurations:Debug"
        defines "KR_RELEASE"
        optimize "On"

        filter "configurations:Dist"
        defines "KR_DIST"
        optimize "On"

    filter { "action:vs2019" }  -- ��� ��� VS2019
        buildoptions { "/utf-8" }  -- ��������� ���� � ��������� ������ �����������

    filter { "action:vs2022" }  -- ��� ��� VS2022
        buildoptions { "/utf-8" }  -- ��������� ���� � ��������� ������ �����������