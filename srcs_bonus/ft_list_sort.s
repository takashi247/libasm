section .text
  global  _ft_list_sort; void ft_list_sort(t_list **begin_list, int (*cmp()))

; rbp - 8: t_list *current
; rbp - 16: t_list *prev
; rbp - 24: rdi (**begin_list)
; rbp - 32: rsi (int (*cmp()))

_ft_list_sort:
  push  rbp
  mov   rbp, rsp
  sub   rsp, 32
  mov   QWORD [rbp - 24], rdi
  mov   QWORD [rbp - 32], rsi
  cmp   QWORD [rbp - 24], 0
  je    .exit
  mov   rax, QWORD [rbp - 24]
  mov   rax, QWORD [rax]
  cmp   rax, 0
  je    .exit
  cmp   QWORD [rbp - 32], 0
  je    .exit
  ; prev = NULL
  mov   QWORD [rbp - 16], 0
  ; current = *begin_list
  mov   rax, QWORD [rbp - 24]
  mov   rax, QWORD [rax]
  mov   QWORD [rbp - 8], rax

.loop_list:
  ; check if current->next is null. if yes, exit the loop
  mov   rax, QWORD [rbp - 8]
  mov   rax, QWORD [rax + 8]; store pointer to next in rax
  cmp   rax, 0; check if current->next is null
  je    .exit
  ; check if (0 < (*cmp)(current->data, current->next->data))
  mov   rdx, QWORD [rax]; rdx = current->next->data
  mov   rax, QWORD [rbp - 8]; rax = current
  mov   rax, QWORD [rax]; rax = current->data
  mov   rcx, QWORD [rbp - 32]; rcx is the pointer to cmp function
  mov   rdi, rax
  mov   rsi, rdx
  xor   rax, rax
  call  rcx
  cmp   rax, 0
  jle   .next_elem
  ; check if (current == *begin_list)
  mov   rax, QWORD [rbp - 24]
  mov   rax, QWORD [rax]
  cmp   QWORD [rbp - 8], rax
  je    .head_of_list
  jmp   .middle_of_list

.head_of_list:
  ; *begin_list = current->next;
  mov   rax, QWORD [rbp - 8]
  mov   rdx, QWORD [rax + 8]
  mov   rax, QWORD [rbp - 24]
  mov   QWORD [rax], rdx
  ; current->next = current->next->next;
  mov   rax, QWORD [rbp - 8]
  mov   rax, QWORD [rax + 8]
  mov   rax, QWORD [rax + 8]
  mov   rdx, QWORD [rbp - 8]
  mov   QWORD [rdx + 8], rax
  ; (*begin_list)->next = current;
  mov   rax, QWORD [rbp - 24]
  mov   rax, QWORD [rax]
  mov   rdx, QWORD [rbp - 8]
  mov   QWORD [rax + 8], rdx
  jmp   .back_to_head

.middle_of_list:
  ; prev->next = current->next;
  mov   rax, QWORD [rbp - 16]
  mov   rdx, QWORD [rbp - 8]
  mov   rdx, QWORD [rdx + 8]
  mov   QWORD [rax + 8], rdx
  ; current->next = current->next->next;
  mov   rax, QWORD [rbp - 8]
  mov   rax, QWORD [rax + 8]
  mov   rdx, QWORD [rax + 8]
  mov   rax, QWORD [rbp - 8]
  mov   QWORD [rax + 8], rdx
  ; prev->next->next = current;
  mov   rax, QWORD [rbp - 16]
  mov   rax, QWORD [rax + 8]
  mov   rdx, QWORD [rbp - 8]
  mov   QWORD [rax + 8], rdx

.back_to_head:
  ; prev = NULL
  mov   QWORD [rbp - 16], 0
  ; current = *begin_list
  mov   rax, QWORD [rbp - 24]
  mov   rax, QWORD [rax]
  mov   QWORD [rbp - 8], rax
  jmp   .loop_list

.next_elem:
  mov   rax, QWORD [rbp - 8]
  mov   QWORD [rbp - 16], rax
  mov   rax, QWORD [rax + 8]
  mov   QWORD [rbp - 8], rax
  jmp   .loop_list

.exit:
  leave
  ret
