section .text
  global _ft_isspace; int ft_isspace(int c)

_ft_isspace:
  cmp rdi, 0x20; ' '
  je  .true
  cmp rdi, 0x09; '\t'
  je  .true
  cmp rdi, 0x0a; '\n'
  je  .true
  cmp rdi, 0x0b; '\v'
  je  .true
  cmp rdi, 0x0c; '\f'
  je  .true
  cmp rdi, 0x0d; '\r'
  je  .true
  xor rax, rax
  ret

.true:
  mov rax, 1
  ret
