flex s.l
bison -d s.y
gcc lex.yy.c s.tab.c TS.c RS.c -o s.exe