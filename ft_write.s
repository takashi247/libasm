section .text
  global _ft_write; ssize_t write(int fildes, const void *buf, size_t nbyte)
  extern ___error

; rdi = file descripter
; rsi = pointer to buffer
; rdx = max. number of bytes to be read

_ft_write:
  mov rax, 0x2000004; syscall number for write in MacOS
  syscall
  jc error; in MacOS, carry flag will be set when error occurs in syscall and error number will be set in rax
  ret

error:
  mov rdi, rax; temporarily store errno stored in rax in rdi
  call ___error; helper function to get address of errno
  mov [rax], rdi; set errno in the address obtained from ___error
  mov rax, -1; set returned value
  ret
