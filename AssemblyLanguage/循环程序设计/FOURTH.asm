assume cs:codesg

codesg segment

begin:
     mov bx,0		;to record 16 binary
     mov ch,4		;control the input times
     mov cl,4		;shift 4 bits a time,a hexadecimal 4 bits
input:
     shl bx,cl		;to give space to next hexadecimal
     mov ah,1		;input a char
     int 21h
     cmp al,'0'		;'0'ASCII is 30H
     jb input		;	if<0 input again
     cmp al,'9'		;'9'ASCII is 39h
     ja AtoF		;	if>9 jump to AtoF

;-----------------when the char is 0~9--------------------
     and al,0fh		;make digit into ASCII
     jmp integrate
;---------------------------------------------------------

;--------------------------AtoF---------------------------
AtoF:
     cmp al,'A'		;'A'ASCII is 41H
     jb input		;	if<'A' input again
     cmp al,'F'		;'F'ASCII is 46H
     ja input		;	if>'F' input again
     and al,0fh		;make digit into ASCII
     add al,09h		;or you can:sub al,37h
                    ;	        and al,0fh
;---------------------------------------------------------

;----------------------integrate BX-----------------------
integrate:
     or bl,al		;move low 4 bit
     dec ch		    ;decrease input times
     jnz input
;---------------------------------------------------------

;----------------------begin to output---------------------
     mov cx,16
     mov ah,02		;for easy to look,
     mov dl,10		;	line feed
     int 21h
     mov dl,13		;	carriage return
     int 21h
next:
     shl bx,1
     jc outone		;if CF==1
     mov dl,30h	    ;   '0' ASCII is 30h
     jmp printf
outone:
     mov dl,31h     ;   '1' ASCII is 31h
printf:
     mov ah,2
     int 21h
     loop next

     mov ah,4ch
     int 21h
codesg ends

end begin


