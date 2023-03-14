section .text
  global _ft_atoi_base; int ft_atoi_base(char *str, char *base)
  extern _ft_strlen

; rdi = pointer to the string to be converted
; rsi = pointer to the base string

_check_base:; function to validate base
  call _ft_strlen
  cmp rax, 1
  jle .check_failed; if len of base is less than or equal to 1, check failed
  ret

.check_failed:
  xor rax, rax
  ret

_ft_atoi_base:
  xchg rdi, rsi
  call _check_base
  cmp rax, 0; if check failed, returned value will be 0
  je .invalid_base
  ret

.invalid_base:
  xor rax, rax
  ret
