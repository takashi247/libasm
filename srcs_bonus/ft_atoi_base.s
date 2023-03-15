section .text
  global _ft_atoi_base; int ft_atoi_base(char *str, char *base)
  extern _ft_strlen
  extern _ft_strchr

; rdi = pointer to the string to be converted
; rsi = pointer to the base string

_ft_atoi_base:
  cmp rdi, 0; check if str is null pointer
  je .invalid
  cmp rsi, 0; check if base is null pointer
  je .invalid
  mov r8, rdi
  xchg rdi, rsi

  ; call _validate_n_get_len_of_base

  ; validate base
  ; check if base is longer than 1
  call _ft_strlen
  cmp rax, 1
  jle .invalid; if len of base is less than or equal to 1, check failed
  mov r9, rax; push len of base to be returned at the end of this function

  ; check if base contains '+'. '-', or white spaces
  mov rsi, 43; set '+' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 45; set '-' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x20; set ' ' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x09; set '\t' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x0a; set '\n' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x0b; set '\v' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x0c; set '\f' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  mov rsi, 0x0d; set '\r' as second arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid

  ; check if base contains the same character more than once
  mov r10, rdi; store the pointer to rdi in r10
  xor rsi, rsi
  jmp .loop

.loop:
  cmp BYTE [rdi + 1], 0
  je  .valid
  mov esi, DWORD [rdi]; store the first character of the string in second arg as int
  inc rdi; increment pointer of the first arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  jmp .loop

.invalid:
  xor rax, rax
  ret

.valid:
  mov rdi, r8
  mov rax, r9
  mov rsi, r10
  ret
