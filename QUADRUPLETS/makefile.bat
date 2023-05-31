flex s.l
bison -d s.y --report=states,itemsets --debug
gcc lex.yy.c s.tab.c TS.c RS.c quad.c -o s.exe