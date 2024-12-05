.586P
.model flat, stdcall
includelib kernel32.lib
includelib user32.lib
ExitProcess PROTO : dword
includelib D:\Poman\prog\C++\3_SEM\SE_3SEM\SE_Asm01\Debug\SE_asm01a.lib
getmin PROTO : dword, :dword
getmax PROTO : dword, :dword
SetConsoleTitleA PROTO:DWORD
GetStdHandle PROTO:DWORD
WriteConsoleA PROTO:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetConsoleOutputCP PROTO:DWORD
SetConsoleCP PROTO:DWORD
printconsole PROTO:DWORD,:DWORD
.stack 4096
.const
.data
ddArr dword 19,23,3,46,5,63,-1,75,8,12
result byte "getmin+getmax=",0
resultl equ $-(result+1)
consTitle byte "Result of operation",0
consolehandle dword 0h
resulting byte 40 dup(0)
number dword ?
.CODE
main PROC
	push lengthof ddArr-1
	push offset ddArr
	call getmin
	mov edx,ebx
	push lengthof ddArr-1
	push offset ddArr
	call getmax
	add edx,eax
	mov number, edx
	push number
	push offset resulting
	call int_to_char
	push offset consTitle
	push offset result
	call printconsole
	push offset consTitle
	push offset resulting
	call printconsole
	push 0
call ExitProcess
main ENDP
printconsole PROC uses eax ebx ecx edx esi edi, pstr:dword, pd:dword
	push pd
	call SetConsoleTitleA
	push -11
	call GetStdHandle
	mov esi,pstr
	mov edi,-1
	count:
		inc edi
		cmp byte ptr[esi+edi],0
		jne count
		push 0
		push 0
		push edi
		push pstr
		push eax
		call WriteConsoleA
		ret
printconsole ENDP
int_to_char PROC uses eax ebx ecx edx esi edi, pstr:dword, pd:dword
	mov edi, pstr
	mov esi, 0
    mov eax,pd
	cdq
	mov ebx,10
	idiv ebx
	test eax,200000h
	jz plus
	neg edx
	neg eax
	mov cl,'-'
	mov [edi],cl
	inc edi
plus:
	push dx
	inc esi
	test eax,eax
	jz fin
	cdq
	idiv ebx
	jmp plus
fin:
	mov ecx,esi
write:
	pop bx
	add bl, '0'
	mov[edi],bl
	inc edi
	loop write
	ret
int_to_char ENDP
end main