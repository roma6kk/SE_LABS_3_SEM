.586P
.model flat, stdcall
ExitProcess PROTO : dword
.stack 4096
.DATA
	ddArr dword 1,2,3,4,5,6,7,8,9,3
.CODE
START:
getmin PROC uses eax ebx ecx esi, parm:dword, parm1:dword
	mov ecx, parm1
	mov eax, parm
	mov ebx, [eax]
	cycle:
		mov esi, [eax]
		add eax, 4
		cmp esi, ebx
		jl con1
		jmp con2
		con1:
			mov ebx, esi
		con2:
			loop cycle
			mov eax, ebx
		ret
getmin ENDP
main PROC
	push lengthof ddArr-1
	push offset ddArr
	call getmin
main ENDP
push 0
call ExitProcess
end main