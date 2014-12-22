rm -f wrapper
lex wrapper.lex
g++ lex.yy.c -o wrapper -ll
./wrapper

