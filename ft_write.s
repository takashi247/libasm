section .text
  global _ft_write; ssize_t write(int fildes, const void *buf, size_t nbyte)
  extern ___error

; rdi = file descripter
; rsi = pointer to buffer
; rdx = max. number of bytes to be read

_ft_write:
  mov rax, 0x2000004; syscall number for write in MacOS
  syscall
  jc error
  ret

error:
  mov rdi, rax
  call ___error
  mov [rax], rdi
  mov rax, -1
  ret
