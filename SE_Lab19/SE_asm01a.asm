.586P
.model flat, stdcall
ExitProcess PROTO : dword
.stack 4096
.CODE
START:
getmin PROC uses ecx esi, parm:dword, parm1:dword
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
getmax PROC uses ecx esi, parm:dword, parm1:dword
	mov ecx, parm1
	mov eax, parm
	mov ebx,0
	cycle:
		mov esi, [eax]
		add eax, 4
		cmp esi, ebx
		jg con1
		jmp con2
		con1:
			mov ebx, esi
		con2:
			loop cycle
			mov eax, ebx
	ret
getmax ENDP
end
