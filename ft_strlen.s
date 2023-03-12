section .text
  global _ft_strlen

_ft_strlen:
  xor rdx, rdx
.loop:
  cmp BYTE[rdi + rdx], 0
  je  .exit
  inc rdx
  jmp .loop
.exit:
  mov rax, rdx
  ret
