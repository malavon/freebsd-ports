--- src/share/poudriere/common.sh.orig	2026-03-03 15:30:28 UTC
+++ src/share/poudriere/common.sh
@@ -1489,6 +1489,7 @@ siginfo_handler() {
 	local now
 	local j elapsed elapsed_phase job_id_color
 	local pkgname origin phase buildtime buildtime_phase started
+	local category # separate line = easier to merge
 	local started_phase format_origin_phase format_phase sep
 	local tmpfs cpu mem
 	local -
@@ -1518,7 +1519,7 @@ siginfo_handler() {
 	# reasons.
 	format_origin_phase="%%c \b%%s \b%%-%ds${COLOR_RESET} \b%%c %%-%ds ${COLOR_PORT}%%%ds %%c %%-%ds${COLOR_RESET} ${COLOR_PHASE}%%%ds${COLOR_RESET} %%-%ds %%-%ds %%%ds %%%ds"
 	display_setup "${format_origin_phase}"
-	display_add " " "" "ID" " " "TOTAL" "ORIGIN" " " "PKGNAME" "PHASE" \
+	display_add " " "" "ID" " " "TOTAL" "CATEGORY" " " "PKGNAME" "PHASE" \
 	            "PHASE" "TMPFS" "CPU%" "MEM%"
 
 	# Skip if stopping or starting jobs or stopped.
@@ -1598,6 +1599,7 @@ siginfo_handler() {
 			esac
 
 			origin="${2-}"
+			category="${origin%/*}"
 			pkgname="${3-}"
 			started="${4-}"
 			started_phase="${5-}"
@@ -1608,7 +1610,7 @@ siginfo_handler() {
 				elapsed_phase=$((now - started_phase))
 				calculate_duration buildtime_phase \
 				    "${elapsed_phase}"
-				sep="|"
+				sep="/"
 				hash_remove siginfo_cpu "${j}" cpu || cpu=
 				hash_remove siginfo_mem "${j}" mem || mem=
 				hash_remove siginfo_tmpfs "${j}" tmpfs || tmpfs=
@@ -1624,7 +1626,7 @@ siginfo_handler() {
 			display_add \
 			    "[" "${job_id_color}" "${j}" "]" \
 			    "${buildtime-}" \
-			    "${origin-}" "${sep:- }" "${pkgname-}" "${phase-}" \
+			    "${category-}" "${sep:- }" "${pkgname-}" "${phase-}" \
 			    "${buildtime_phase-}" \
 			    "${tmpfs}" \
 			    "${cpu:+${cpu}%}" \
