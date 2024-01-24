workspace "MAT-CPP"  
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
    files { "**.h", "**.cpp" } 

    filter "configurations:Test"
        defines { "Test" }  
        symbols "On"
        optimize "On" 