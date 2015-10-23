yacc -y -d yacc_expl.y
lex lex_expl.l
gcc -g y.tab.c lex.yy.c
