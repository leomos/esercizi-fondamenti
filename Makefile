all:
	gcc conta-parole.c -o bin/conta-parole
	gcc dictionary.c -o bin/dictionary
	gcc string-sum.c -o bin/string-sum
	gcc syllables.c -o bin/syllables
.PHONY: all
