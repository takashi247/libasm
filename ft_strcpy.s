EXTERN  _ft_strlen

section .text
  global _ft_strcpy; char *ft_strcpy(char *dest, const char *src)

_ft_strcpy:
  mov r11, rdi; store rdi (=dest) in r11 temporarily
  mov rdi, rsi; set rsi (=src) to rdi to call strlen
  call _ft_strlen; call strlen to get the length of src
  mov rcx, rax; set returned value from strlen to rcx
  inc rcx; increment rcx to loop properly until null
  mov rdi, r11; restore the original dest
  mov rax, rdi; set dest as the returned value from strcpy
  cld; clear direction (=rcx will be decreased while rep)
  rep movsb; loop until rcx become zero
  ret
