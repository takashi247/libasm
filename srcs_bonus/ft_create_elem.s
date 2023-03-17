section .text
  global _ft_create_elem; t_list  *ft_create_elem(void *data)
  extern _malloc
  extern ___error

_ft_create_elem:
  push  rbp
  mov   rbp, rsp
  sub   rsp, 8
  mov   QWORD [rbp - 8], rdi
  cmp   QWORD [rbp - 8], 0
  jne   .allocate
  xor   rax, rax
  jmp   .exit

.allocate:
  mov   rdi, 16
  call  _malloc
  jnc   .create
  mov   rdi, rax
  call  ___error
  mov   [rax], rdi
  xor   rax, rax
  jmp   .exit

.create:
  mov   rdi, QWORD [rbp - 8]
  mov   QWORD [rax], rdi
  mov   QWORD [rax + 8], 0

.exit:
  leave
  ret
