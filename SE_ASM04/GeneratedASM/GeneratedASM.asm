.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
.STACK 4096

.CONST

.DATA

TEXT	DB "rtghjk", 0
INTEGER	DD 4567
.CODE

main PROC

START: 
	push 0
	call ExitProcess
main ENDP
end main
