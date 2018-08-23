assume cs:code

code segment
main proc far       ;main program
    push ds
    sub ax,ax
    push ax
begin:
    mov ah,1        ;input a minuscule
    int 21h
    cmp al,'a'      ;to compare with 'a' to 'z'
    jb stop
    cmp al,'z'
    ja stop

    sub al,20h      ;in ASCII,for example,'a'-20h='A'
    mov dl,al
    mov ah,2
    int 21h

    jmp begin
stop:
    ret             ;return to DOS

main endp

code ends

end
