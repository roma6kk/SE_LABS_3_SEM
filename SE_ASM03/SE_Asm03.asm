.586
.model flat, stdcall
.stack 4096

.data
    myBytes BYTE 10h, 20h, 30h, 40h
    myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
    myDoubles DWORD 1, 2, 3, 4, 5, 6
    myPointer DWORD myDoubles

    myArray DWORD 5, -3, 7, 0, 12, 8, -2

.code
main PROC
    mov ESI, OFFSET myBytes          
    mov AH, [ESI]                    
    mov AL, [ESI + 3]                

    xor EAX, EAX                     
    xor EBX, EBX                     
    mov ECX, LENGTHOF myArray        
    lea ESI, myArray                 

SumLoop:
    mov EDX, [ESI]                   
    add EAX, EDX                     
    test EDX, EDX                    
    jne SkipZero                     
    mov EBX, 0                       
    jmp ExitLoop                     

SkipZero:
    add ESI, TYPE DWORD              
    loop SumLoop                     

    mov EBX, 1                       

ExitLoop:
    mov EAX, 0                     
    ret
main ENDP
END main
