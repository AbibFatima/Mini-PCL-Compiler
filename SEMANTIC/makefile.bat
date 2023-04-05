flex s.l
bison -d s.y
gcc lex.yy.c s.tab.c TS.c -o s.exe