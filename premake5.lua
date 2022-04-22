workspace "IFS"
    architecture "x64"
    configurations {"Debug", "Release"}
project "IFS"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files{"**.h","**.cpp"}

    filter "configurations:Debug"
        defines {"DEBUG","_CRT_SECURE_NO_WARNINGS"}
        symbols "On"
    filter "configurations:Release"
        defines {"NDEBUG","_CRT_SECURE_NO_WARNINGS"}
        optimize "On"