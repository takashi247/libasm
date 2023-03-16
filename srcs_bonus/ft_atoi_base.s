section .text
  global _ft_atoi_base; int ft_atoi_base(char *str, char *base)
  extern _ft_strlen
  extern _ft_strchr
  extern _ft_strchr_index
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

.loop_sign:
  mov dil, BYTE [r10 + rdx]
  cmp dil, 0
  je  .no_sign
  cmp dil, 0x2b; '+'
  je  .invalid
  cmp dil, 0x2d; '-'
  je  .invalid
  call _ft_isspace
  cmp rax, 1
  je  .invalid
  inc rdx
  jmp .loop_sign

.no_sign:
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
  xor rax, rax; reset rax
  xor rdi, rdi; reset rdi
  xor r11, r11; reset r11 to store number
  mov rcx, 1; initiate sign variable (rcx) with 1
  xor rdx, rdx

; r8: original 1st arg
; r9: len of 2nd arg
; r10: original 2nd arg
; r11: final output number
; rcx: sign variable

.loop_space:
  mov dil, BYTE [r8 + rdx]
  call _ft_isspace
  cmp rax, 1
  jne .check_sign
  inc rdx
  jmp .loop_space

.check_sign:
  cmp dil, 0x2b; '+'
  je  .has_plus
  cmp dil, 0x2d; '-'
  je  .has_minus
  jmp .compute_value

.has_plus:
  inc rdx
  jmp .compute_value

.has_minus:
  mov rcx, -1
  inc rdx
  jmp .compute_value

.compute_value:
  xor rdi, rdi
  mov rdi, r10
  xor rsi, rsi; reset rsi

.loop_numbers:
  mov sil, BYTE [r8 + rdx]
  cmp rsi, 0
  je .exit
  push rdx; need to temporarily store rdx in stack as rdx will be used in ft_strchr_index
  call _ft_strchr_index
  pop rdx; restore rdx
  cmp rax, r9
  je  .exit
  imul r11, r9
  add r11, rax
  inc rdx
  jmp .loop_numbers

.exit:
  imul r11, rcx
  mov rax, r11
  ret
