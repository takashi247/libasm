section .text
  global _ft_strchr; char *strchr(const char *s, int c)

_ft_strchr:
  xor rdx, rdx

.loop:
  cmp BYTE [rdi + rdx], 0
  je  .exit
  cmp BYTE [rdi + rdx], sil
  je  .found
  inc rdx
  jmp .loop

.exit:
  xor rax, rax
  ret

.found:
  add rdi, rdx
  mov rax, rdi
  ret
