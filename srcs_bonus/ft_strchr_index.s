section .text
  global _ft_strchr_index; int strchr(const char *s, int c)

_ft_strchr_index:
  xor rdx, rdx

.loop:
  cmp BYTE [rdi + rdx], 0
  je  .exit
  cmp BYTE [rdi + rdx], sil
  je  .exit
  inc rdx
  jmp .loop

.exit:
  mov rax, rdx
  ret
