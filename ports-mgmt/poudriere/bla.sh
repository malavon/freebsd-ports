ps -ax -o jail,%cpu,%mem |
		    awk -v MASTERNAME=blabla '\
			$1 ~ "^" MASTERNAME "(-job-[0-9]+)?(-n)?$" \
			{ \
				gsub(/-n$/, "", $1); \
				cpu[$1] += $2; \
				mem[$1] += $3; \
			} \
			END { \
				for (jail in cpu) { \
					print jail, cpu[jail], mem[jail]; \
				} \
			} \
		    '
