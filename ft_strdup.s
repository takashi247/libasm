section .text
  global _ft_strdup; char *strdup(const char *s1)
  extern _malloc
  extern ___error
  extern _ft_strlen
  extern _ft_strcpy

_ft_strdup:
  call _ft_strlen; get length of s1
  mov rcx, rax; store len of s1 in rcx
  inc rcx; increment rcx
  push rdi; store s1 in stack
  mov rdi, rcx; set 1st argument of malloc (= size of heap memory to be allocated)
  call _malloc; call malloc
  jc error; jump to error if malloc failed
  mov rdi, rax; set dest
  pop rsi; pop s1 and set as src
  call _ft_strcpy; copy s1 to malloced memory
  ret

error:
  mov rdi, rax
  call ___error
  mov [rax], rdi
  xor rax, rax
  ret
