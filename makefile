all: flex bison compile

flex: lex.l
	flex lex.l

bison: y.y
	bison -d y.y -Wnone

compile: lex.yy.c y.tab.c
	cc lex.yy.c y.tab.c -ll -ly
