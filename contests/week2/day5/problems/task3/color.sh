if [ -z "${__COLOR_SH_INCLUDED__+x}" ]
then

__COLOR_SH_INCLUDED__=1

if [ -t 1 ]
then
	ESC="$(echo -e '\033')"
	S_NONE="${ESC}[0m"
	S_BOLD="${ESC}[1m"
	S_FAINT="${ESC}[2m"
	S_ITALIC="${ESC}[3m"
	S_UNDERLINE="${ESC}[4m"
	S_BLINK="${ESC}[5m"
	S_INVERSE="${ESC}[7m"
	S_CONCEAL="${ESC}[8m"
	S_CROSSED="${ESC}[9m"
	
	S_FG_BLACK="${ESC}[30m"
	S_FG_RED="${ESC}[31m"
	S_FG_GREEN="${ESC}[32m"
	S_FG_YELLOW="${ESC}[33m"
	S_FG_BLUE="${ESC}[34m"
	S_FG_MAGENTA="${ESC}[35m"
	S_FG_CYAN="${ESC}[36m"
	S_FG_WHITE="${ESC}[37m"
	S_FG_LTBLACK="${ESC}[90m"
	S_FG_LTRED="${ESC}[91m"
	S_FG_LTGREEN="${ESC}[92m"
	S_FG_LTYELLOW="${ESC}[93m"
	S_FG_LTBLUE="${ESC}[94m"
	S_FG_LTMAGENTA="${ESC}[95m"
	S_FG_LTCYAN="${ESC}[96m"
	S_FG_LTWHITE="${ESC}[97m"
	
	S_BG_BLACK="${ESC}[40m"
	S_BG_RED="${ESC}[41m"
	S_BG_GREEN="${ESC}[42m"
	S_BG_YELLOW="${ESC}[43m"
	S_BG_BLUE="${ESC}[44m"
	S_BG_MAGENTA="${ESC}[45m"
	S_BG_CYAN="${ESC}[46m"
	S_BG_WHITE="${ESC}[47m"
	S_BG_LTBLACK="${ESC}[100m"
	S_BG_LTRED="${ESC}[101m"
	S_BG_LTGREEN="${ESC}[102m"
	S_BG_LTYELLOW="${ESC}[103m"
	S_BG_LTBLUE="${ESC}[104m"
	S_BG_LTMAGENTA="${ESC}[105m"
	S_BG_LTCYAN="${ESC}[106m"
	S_BG_LTWHITE="${ESC}[107m"
fi

fi
