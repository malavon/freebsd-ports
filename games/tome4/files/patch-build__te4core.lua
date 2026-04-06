--- build/te4core.lua.orig	2019-10-03 13:35:43 UTC
+++ build/te4core.lua
@@ -41,7 +41,7 @@ project "TEngine"
 	if _OPTIONS.discord then defines { "DISCORD_TE4" } end
 	defines { "_DEFAULT_VIDEOMODE_FLAGS_='SDL_HWSURFACE|SDL_DOUBLEBUF'" }
 	defines { [[TENGINE_HOME_PATH='".t-engine"']], "TE4CORE_VERSION="..TE4CORE_VERSION }
-	buildoptions { "-O3" }
+	buildoptions { "-Og" }
 
 	if _OPTIONS.relpath=="32" then linkoptions{"-Wl,-rpath -Wl,\\\$\$ORIGIN/lib "} end
 	if _OPTIONS.relpath=="64" then linkoptions{"-Wl,-rpath -Wl,\\\$\$ORIGIN/lib64 "} end
@@ -180,7 +180,7 @@ if _OPTIONS.lua == "default" then
 		kind "StaticLib"
 		language "C"
 		targetname "lua"
-		buildoptions{ "-O2" }
+		buildoptions{ "-Og" }
 
 		files { "../src/lua/*.c", }
 elseif _OPTIONS.lua == "jit2" then
@@ -199,7 +199,7 @@ elseif _OPTIONS.lua == "jit2" then
 		if _OPTIONS.wincross then
 			arch_test = os.capture("i686-pc-mingw32-gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		else
-			arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+			arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		end
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
@@ -258,7 +258,7 @@ elseif _OPTIONS.lua == "jit2" then
 		if _OPTIONS.wincross then
 			arch_test = os.capture("i686-pc-mingw32-gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		else
-			arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+			arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		end
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
@@ -362,7 +362,7 @@ elseif _OPTIONS.lua == "jit2" then
 		language "C"
 		targetname "lua"
 		links { "buildvm" }
-		buildoptions { "-O2", "-fomit-frame-pointer" }
+		buildoptions { "-Og", "-fomit-frame-pointer" }
 
 		files { "../src/luajit2/src/*.c", "../src/luajit2/src/*.s", "../src/luajit2/src/lj_vm.s", "../src/luajit2/src/lj_bcdef.h", "../src/luajit2/src/lj_ffdef.h", "../src/luajit2/src/lj_ffdef.h", "../src/luajit2/src/lj_libdef.h", "../src/luajit2/src/lj_recdef.h", "../src/luajit2/src/lj_folddef.h" }
 		excludes { "../src/luajit2/src/buildvm*.c", "../src/luajit2/src/luajit.c", "../src/luajit2/src/ljamalg.c" }
@@ -427,7 +427,7 @@ project "luasocket"
 	kind "StaticLib"
 	language "C"
 	targetname "luasocket"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	configuration "not windows"
 		files {
@@ -466,7 +466,7 @@ project "fov"
 	kind "StaticLib"
 	language "C"
 	targetname "fov"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/fov/*.c", }
 
@@ -474,7 +474,7 @@ project "lpeg"
 	kind "StaticLib"
 	language "C"
 	targetname "lpeg"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/lpeg/*.c", }
 
@@ -482,7 +482,7 @@ project "luaprofiler"
 	kind "StaticLib"
 	language "C"
 	targetname "luaprofiler"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/luaprofiler/*.c", }
 
@@ -490,7 +490,7 @@ project "tcodimport"
 	kind "StaticLib"
 	language "C"
 	targetname "tcodimport"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/libtcod_import/*.c", }
 
@@ -499,7 +499,7 @@ project "expatstatic"
 	language "C"
 	targetname "expatstatic"
 	defines{ "HAVE_MEMMOVE" }
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/expat/*.c", }
 
@@ -507,7 +507,7 @@ project "lxp"
 	kind "StaticLib"
 	language "C"
 	targetname "lxp"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/lxp/*.c", }
 
@@ -515,7 +515,7 @@ project "luamd5"
 	kind "StaticLib"
 	language "C"
 	targetname "luamd5"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/luamd5/*.c", }
 
@@ -523,7 +523,7 @@ project "luazlib"
 	kind "StaticLib"
 	language "C"
 	targetname "luazlib"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/lzlib/*.c", }
 
@@ -531,7 +531,7 @@ project "luabitop"
 	kind "StaticLib"
 	language "C"
 	targetname "luabitop"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/luabitop/*.c", }
 
@@ -539,7 +539,7 @@ project "te4-bzip"
 	kind "StaticLib"
 	language "C"
 	targetname "te4-bzip"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/bzip2/*.c", }
 
@@ -547,7 +547,7 @@ project "te4-wfc"
 	kind "StaticLib"
 	language "C++"
 	targetname "te4-wfc"
-	buildoptions { "-O3" }
+	buildoptions { "-Og" }
 	buildoptions { "-std=c++11" }
 	cppconfig()
 
@@ -557,7 +557,7 @@ project "utf8proc"
 	kind "StaticLib"
 	language "C"
 	targetname "utf8proc"
-	buildoptions { "-O2" }
+	buildoptions { "-Og" }
 
 	files { "../src/utf8proc/utf8proc.c", }
 
@@ -580,7 +580,7 @@ project "te4-web"
 	language "C++"
 	targetname "te4-web"
 
-	buildoptions { "-O3", "-std=c++11" }
+	buildoptions { "-Og", "-std=c++11" }
 	cppconfig("web")
 
 	if _OPTIONS.relpath=="32" then linkoptions{"-Wl,-rpath -Wl,\\\$\$ORIGIN "} end
@@ -610,7 +610,7 @@ project "cef3spawn"
 	language "C++"
 	targetname "cef3spawn"
 
-	buildoptions { "-O3" }
+	buildoptions { "-Og" }
 	buildoptions { "-std=c++11" }
 	cppconfig("web")
 
