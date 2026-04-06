--- premake4.lua.orig	2019-09-13 09:46:14 UTC
+++ premake4.lua
@@ -28,11 +28,6 @@ solution "TEngine"
 			"/usr/i686-pc-mingw32/usr/include/",
 			"/usr/i686-pc-mingw32/usr/include/GL/",
 		}
-	else
-		includedirs {
-			"/opt/SDL-2.0/include/SDL2",
-			"/usr/include/GL",
-		}
 	end
 	if _OPTIONS.lua == "default" then includedirs{"src/lua"}
 	elseif _OPTIONS.lua == "jit2" then includedirs{"src/luajit2/src", "src/luajit2/dynasm",}
@@ -44,11 +39,14 @@ configuration "bsd"
 
 configuration "bsd"
 	libdirs {
-		"/usr/local/lib",
+		"bin/Release", "/usr/local/lib",
 	}
 	includedirs {
 		"/usr/local/include",
 	}
+	buildoptions {
+		"-pthread",
+	}
 
 if _OPTIONS.wincross then
 configuration "windows"
@@ -99,7 +97,7 @@ configuration "Debug"
 	defines { }
 	flags { "Symbols" }
 	buildoptions { "-ggdb" }
---	buildoptions { "-O3" }
+	buildoptions { "-Og" }
 	targetdir "bin/Debug"
 	if _OPTIONS.luaassert then defines {"LUA_USE_APICHECK"} end
 	if _OPTIONS.pedantic then buildoptions { "-Wall" } end
@@ -107,8 +105,6 @@ configuration "Release"
 
 configuration "Release"
 	defines { "NDEBUG=1" }
-	flags { "Optimize", "NoFramePointer" }
-	buildoptions { "-O2" }
 	targetdir "bin/Release"
 
 
