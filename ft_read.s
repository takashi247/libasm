section .text
  global _ft_read; ssize_t read(int fildes, void *buf, size_t nbyte)
  extern ___error

; see detailed comments in ft_write.s as well

_ft_read:
  mov rax, 0x2000003; syscall number for read in MacOS
  syscall
  jc error
  ret

error:
  mov rdi, rax
  call ___error
  mov [rax], rdi
  mov rax, -1
  ret
