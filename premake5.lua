workspace "DATA-CPP"  
    configurations { "Test" } 
    language "C++"   
    cppdialect "C++20"
    architecture "x86_64"
    location ""
	startproject "Test"
    objdir ("bin")
    targetdir "Test" 
    debugdir "Test"

project "Test"  
    kind "ConsoleApp"
    links { "CPP-DATA" }
    files { "**.h", "**.cpp" } 

    filter "configurations:Test"
        defines { "Test" }  
        symbols "On"

project "CPP-DATA"
    kind "StaticLib"
    files { "CPP-DATA/**.h", "CPP-DATA/**.cpp", "CPP-DATA/**.c" }

    filter "configurations:Test"
        defines { "Test" }  
        symbols "On"