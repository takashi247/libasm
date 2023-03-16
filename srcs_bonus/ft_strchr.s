section .text
  global _ft_strchr; char *strchr(const char *s, int c)

_ft_strchr:
  push rdx; temporarily store rdx in stack
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
  pop rdx; restore rdx before returning to caller function
  ret

.found:
  add rdi, rdx
  mov rax, rdi
  pop rdx; restore rdx before returning to caller function
  ret
