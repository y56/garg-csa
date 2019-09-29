# README

## try to interpret `lw r1,r0,0`
###
The corresponding binary in the given instructioin memory is 
```
10001100
00000001
00000000
00000000
```
or
```
opcode  rs     rt     immediate
100011  00000  00001  0000000000000000
```
###
The syntax for `lw` is 
```
R[rt] = M[R[rs] + SignExtImm]
###
```
`lw` is of I-type.
###
The opcode of `lw` is 23(hex) = 35(dec) = 32+2+1 =  100011(binary)

