section .text
  global _ft_strlen; size_t strlen(const char *s)

_ft_strlen:
  push rdx; keep current rdx in stack
  xor rdx, rdx; i = 0

.loop:
  cmp BYTE [rdi + rdx], 0; if (*(s + i) == '\0)
  je  .exit; jump to .exit if the condition above is true
  inc rdx; ++i
  jmp .loop; back to the start of the loop

.exit:
  mov rax, rdx; rax = rdx
  pop rdx; restore original rdx from stack
  ret
