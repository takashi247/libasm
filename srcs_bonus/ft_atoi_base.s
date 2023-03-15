section .text
  global _ft_atoi_base; int ft_atoi_base(char *str, char *base)
  extern _ft_strlen
  extern _ft_strchr
  extern _ft_isspace

; rdi = pointer to the string to be converted
; rsi = pointer to the base string

_ft_atoi_base:
  cmp rdi, 0; check if str is null pointer
  je .invalid
  cmp rsi, 0; check if base is null pointer
  je .invalid
  mov r8, rdi
  xchg rdi, rsi

  ; validate base
  ; check if base is longer than 1
  call _ft_strlen
  cmp rax, 1
  jle .invalid; if len of base is less than or equal to 1, check failed
  mov r9, rax; push len of base to be returned at the end of this function

  ; check if base contains '+'. '-', or white spaces
  xor rdx, rdx
  mov r10, rdi; copy rdi to r10
  xor rdi, rdi; reset rdi to use this register for ft_isspace

.loop_sp:
  mov dil, BYTE [r10 + rdx]
  cmp dil, 0
  je  .no_sp
  cmp dil, 0x2b; '+'
  je  .invalid
  cmp dil, 0x2d; '-'
  je  .invalid
  call _ft_isspace
  cmp rax, 1
  je  .invalid
  inc rdx
  jmp .loop_sp

.no_sp:
  ; check if base contains the same character more than once
  mov rdi, r10; restore rdi from r10
  xor rsi, rsi

.loop_dup:
  cmp BYTE [rdi + 1], 0
  je  .no_dup
  mov esi, DWORD [rdi]; store the first character of the string in second arg as int
  inc rdi; increment pointer of the first arg
  call _ft_strchr
  cmp rax, 0
  jne .invalid
  jmp .loop_dup

.invalid:
  xor rax, rax
  ret

.no_dup:
  mov rdi, r8
  mov rax, r9
  mov rsi, r10
  ret
