datarea    segment               ;define data segment
  grade   dw          56,69,84,82,73,88,99,63,100,80
  s5      dw          0
  s6      dw          0
  s7      dw          0
  s8      dw          0
  s9      dw          0
  s10     dw          0
datarea  ends

prognam segment                  ;define code segment

main      proc      far          ;main part of program
assume  cs:prognam, ds:datarea
start:                           ;starting execution address
; set up stack for return
    push     ds                  ;save old data segment
    sub      ax,ax               ;put zero in AX
    push     ax                  ;save it on stack
; set DS register to current data segment
    mov      ax,datarea          ;datarea segment addr
    mov      ds,ax               ;into DS register
; MAIN PART OF PROGRAM GOES HERE
    mov cx,10
    mov bx,0
s:	call compare
    add bx,2
    loop s

    ret                          ;return to DOS
main endp                        ;end of main part of program

compare proc near
     cmp word ptr[bx],60         ;defined grade is a word
                                 ;so we should explain the [bx] we need is a word
	 jb bujige
	 cmp word ptr[bx],70
     jb jige
	 cmp word ptr[bx],80
     jb lianghao
     cmp word ptr[bx],90
	 jb youxiu
	 cmp word ptr[bx],100
	 jb youyi
	 inc s10                     ;=100
	 ret
bujige:	 inc s5                  ;<60
         ret
jige:    inc s6                  ;<70
         ret
lianghao:inc s7                  ;<80
         ret
youxiu:  inc s8                  ;<90
         ret
youyi:	 inc s9                  ;<100
         ret
compare endp

prognam  ends

end     start                 ; end assembly
