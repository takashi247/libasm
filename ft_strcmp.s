EXTERN  _ft_strlen

section .text
  global _ft_strcmp; int strcmp(const char *s1, const char *s2)

_ft_strcmp:
  call _ft_strlen; call strlen to get the length of s1
  mov rcx, rax; set len of s1 to rcx
  mov rdx, rax; keep len of s1 in rdx as well
  xor rax, rax; reset rax
  mov r8, rdi; keep rdi's starting position in r8
  mov r9, rsi; keep rsi's starting position in r9
  inc rcx; increment rcx
  cld; clear direction (=rcx will be decreased while repz)
  repz cmpsb; compare s1 and s2 until rcx is not zero && ZF is set
  sub rdx, rcx; compute the index by subtracting rcx from rdx
  xor r10, r10; reset r10
  xor r11, r11; reset r11
  mov r10b, BYTE [r8 + rdx]; copy the byte where the loop stops
  mov r11b, BYTE [r9 + rdx]; same as above
  sub r10, r11; subtract s2 from s1
  mov rax, r10; set the returned value
  ret
