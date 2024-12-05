.586
.model flat,stdcall
includelib kernel32.lib
includelib libucrt.lib
includelib  D:\Poman\prog\C++\3_SEM\SE_3SEM\SE_Asm01\Debug\SE_asm01d.lib
ExitProcess PROTO:DWORD
SetConsoleTitleA PROTO:DWORD
GetStdHandle PROTO:DWORD
WriteConsoleA PROTO:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetConsoleOutputCP PROTO:DWORD
SetConsoleCP PROTO:DWORD
printconsole PROTO:DWORD,:DWORD
.stack 4096
getmin PROTO:DWORD,:DWORD
getmax PROTO:DWORD,:DWORD
.data
ddArr dword 7,2,3,4,5,6,7,8,9,6
result byte "getmin+getmax=",0
resultl equ $-(result+1)
consTitle byte "Result of operation",0
consolehandle dword 0h
resulting byte 40 dup(0)
number dword ?
.code
START:
main PROC
	mov ecx,lengthof ddArr
	push lengthof ddArr
	mov eax, offset ddArr
	push offset ddArr
	call getmin
	mov ebx,edx
	mov ecx,lengthof ddArr
	push lengthof ddArr
	mov eax, offset ddArr
	push offset ddArr
	call getmax
	add ebx,edx
	mov number, ebx
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