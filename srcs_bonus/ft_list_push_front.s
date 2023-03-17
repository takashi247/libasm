section .text
  global  _ft_list_push_front; void ft_list_push_front(t_list **begin_list, void *data)
  extern  _ft_create_elem

; rdi: double pointer to head of list
; rsi: data for new elem

; rbp - 8: *elem
; rbp - 24: **begin_list (double pointer)
; rbp - 32: *data

_ft_list_push_front:
  push  rbp; push current base pointer
  mov   rbp, rsp; raise base pointer to the current stack pointer
  sub   rsp, 32; secure 4 * 8 byte
  mov   QWORD [rbp - 24], rdi; store first arg
  mov   QWORD [rbp - 32], rsi; store second arg
  cmp   QWORD [rbp - 24], 0
  je    .exit
  cmp   QWORD [rbp - 32], 0
  je    .exit
  mov   rdi, QWORD [rbp - 32]; set data as first arg of ft_create_elem
  call  _ft_create_elem
  cmp   rax, 0
  je    .exit
  mov   QWORD [rbp - 8], rax; store the pointer to newly-created elem
  mov   rax, QWORD [rbp - 24]; fetch pointer to pointer to head of list
  mov   rdi, QWORD [rax]; copy pointer to head of list
  cmp   rdi, 0; check if *begin_list is null
  jne   .replace_head
  mov   rdi, QWORD [rbp - 8]
  mov   QWORD [rax], rdi; if null, set pointer to elem
  jmp   .exit

; rdi: *(begin_list)
; rax: begin_list
; rbp - 16: *tmp

.replace_head:
  ; store current head of list to tmp
  mov   QWORD [rbp - 16], rdi
  ; replace head with new elem
  mov   rax, QWORD [rbp - 24]
  mov   rdx, QWORD [rbp - 8]
  mov   QWORD [rax], rdx
  ; set previous head of list as next elem
  mov   rax, QWORD [rbp - 8]
  mov   rdx, QWORD [rbp - 16]
  mov   QWORD [rax + 8], rdx

.exit:
  leave
  ret
