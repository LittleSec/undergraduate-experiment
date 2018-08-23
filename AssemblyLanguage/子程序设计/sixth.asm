data segment
  val1 dw 520
  crlf dw 0ah,0dh,'$'
data ends

code segment

bando proc far               ;main program
   assume cs:code,ds:data
   start: push ds            ;set to return dos
          sub ax,ax
          push ax
          mov ax,data
          mov ds,ax          ;move data's address to ds
          push val1
          call pairs
          ret
 bando endp

 pairs proc near             ;paris program
          push bp
          mov bp,sp
          push bx
          mov bx,[bp+4]      ;put val1 to bx from stack
                             ;because have been pushed bp&bx, so add 4
          call outbin        ;call outbin program to output the binary
          mov cx,8           ;output 8 space
   space: mov dl,' '
          mov ah,2
          int 21h
          loop space

          call outoct        ;call outoct program to output the octal
          call disp_crlf     ;call disp_crlf program to line feed and carriage return
          pop bx
          pop bp
          ret 2
pairs endp

;-------------------program to output the binary------------------------
outbin proc near
      push bx                ;to protect the (bx)
	  mov cx,16
p:	  rol bx,1
	  mov dx,bx
	  and dx,1
	  add dx,30h             ;digit 0~9 ASCII is 30h~39h
	  mov ah,2
	  int 21h
	  loop p

	  pop bx                 ;recovery the (bx)
	  ret
outbin endp

;------------------program to output the octal--------------------------
outoct proc near             ;16 binary change into octal must be 6
                             ;the highest binary is the highest octal too
	  rol bx,1
	  mov dx,bx
	  and dx,1
	  add dx,30h
	  mov ah,2
	  int 21h
	  mov cx,5
pp:	  push cx                ;shift instruct should use cl,so protect the cx
	  mov cl,3
	  rol bx,cl
	  mov dx,bx
	  and dx,07h             ;111b=7h,to just retain low 3 binary,which is 1 octal,too
	  add dx,30h
	  mov ah,2
	  int 21h
	  pop cx
	  loop pp

      ret
outoct endp

;------------------program to line feed and carriage return-------------
disp_crlf proc near
     lea dx,crlf
     mov ah,09h
     int 21h
	 ret
disp_crlf endp

code ends

end start
