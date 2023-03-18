section .text
  global  _ft_list_remove_if; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
  extern  _free

; rbp - 8: t_list *current
; rbp - 16: t_list *prev
; rbp - 24: t_list *tmp
; rbp - 32: **begin_list
; rbp - 40: data_ref
; rbp - 48: int (*cmp)()
; rbp - 56: void (*free_fct)(void *)

_ft_list_remove_if:
  ; set up stack frame
  push  rbp
  mov   rbp, rsp
  sub   rsp, 56
  mov   QWORD [rbp - 32], rdi
  mov   QWORD [rbp - 40], rsi
  mov   QWORD [rbp - 48], rdx
  mov   QWORD [rbp - 56], rcx
  ; check validity of args
  cmp   QWORD [rbp - 32], 0
  je    .exit
  mov   rax, QWORD [rbp - 32]
  mov   rax, QWORD [rax]
  cmp   rax, 0
  je    .exit
  cmp   QWORD [rbp - 40], 0
  je    .exit
  cmp   QWORD [rbp - 48], 0
  je    .exit
  cmp   QWORD [rbp - 56], 0
  je    .exit
  ; tmp = NULL
  mov   QWORD [rbp - 24], 0
  ; prev = NULL
  mov   QWORD [rbp - 16], 0
  ; current = *begin_list
  mov   rax, QWORD [rbp - 32]
  mov   rax, QWORD [rax]
  mov   QWORD [rbp - 8], rax

.loop_list:
  ; check if current != NULL
  mov   rax, QWORD [rbp - 8]
  cmp   rax, 0
  je    .exit
  ; check if (*cmp)(current->data, data_ref) != 0
  mov   rdi, QWORD [rbp - 8]
  mov   rdi, QWORD [rdi]
  mov   rsi, QWORD [rbp - 40]
  mov   rdx, QWORD [rbp - 48]
  xor   rax, rax
  call  rdx
  cmp   rax, 0
  jne   .next_elem
  ; check if current is head of list
  mov   rax, QWORD [rbp - 32]
  mov   rax, QWORD [rax]
  cmp   QWORD [rbp - 8], rax
  je    .head_of_list
  jmp   .middle_of_list

.head_of_list:
  ; *begin_list = current->next
  mov   rax, QWORD [rbp - 32]
  mov   rdi, QWORD [rbp - 8]
  mov   rdi, QWORD [rdi + 8]
  mov   QWORD [rax], rdi
  jmp   .free_tmp

.middle_of_list:
  ; prev->next = current->next
  mov   rax, QWORD [rbp - 16]
  mov   rdi, QWORD [rbp - 8]
  mov   rdi, QWORD [rdi + 8]
  mov   QWORD [rax + 8], rdi

.free_tmp:
  ; tmp = current
  mov   rax, QWORD [rbp - 8]
  mov   QWORD [rbp - 24], rax
  ; current = current->next
  mov   rax, QWORD [rax + 8]
  mov   QWORD [rbp - 8], rax
  ; call free_fct to free tmp->data
  mov   rdi, QWORD [rbp - 24]
  mov   rdi, QWORD [rdi]
  mov   rcx, QWORD [rbp - 56]
  xor   rax, rax
  call  rcx
  mov   rdi, QWORD [rbp - 24]
  xor   rax, rax
  call  _free
  mov   QWORD [rbp - 24], 0
  jmp   .loop_list


.next_elem:
  ; prev = current
  mov   rax, QWORD [rbp - 8]
  mov   QWORD [rbp - 16], rax
  ; current = current->next
  mov   rax, QWORD [rax + 8]
  mov   QWORD [rbp - 8], rax
  jmp   .loop_list

.exit:
  leave
  ret
