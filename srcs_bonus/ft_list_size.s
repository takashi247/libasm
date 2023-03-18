section .text
  global  _ft_list_size; int ft_list_size(t_list *begin_list)

_ft_list_size:
  push  rbp
  mov   rbp, rsp
  sub   rsp, 8
  mov   QWORD [rbp - 8], rdi
  xor   rax, rax

.loop_list:
  cmp   rdi, 0
  je    .exit
  mov   rdi, QWORD [rbp - 8]
  mov   rdi, QWORD [rdi + 8]
  mov   QWORD [rbp - 8], rdi
  inc   rax
  jmp   .loop_list

.exit:
  leave
  ret
