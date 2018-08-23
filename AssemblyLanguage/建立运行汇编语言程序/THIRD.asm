data segment
  string1 db 'This is my 3th assembly.'
  string2 db 'Move the cursor backward.'
  mess1 db 'Match.',13,10,'$'
  mess2 db 'No Match!',13,10,'$'
data ends

prog segment
  assume cs:prog,ds:data,es:data

start:
      mov ax,data       ;data segment addr
      mov ds,ax		    ;	into DS register
      mov es,ax		    ;	into ES register
      lea si,string1	;load string1 addr to SI
      lea di,string2	;load string2 addr to DI
      mov cx,25		    ;compare 25 times
      cld		        ;make offset addr add
      repe cmpsb	    ;if equal then continue
      jz match		    ;if equal then jump to match
      lea dx,mess2      ;       else load mess2 addr to dx
      jmp short disp
match:
      lea dx,mess1

disp:
      mov ah,09h	    ;output the string in (ds:dx)
      int 21h
      mov ah,4ch
      int 21h

prog ends

end start
