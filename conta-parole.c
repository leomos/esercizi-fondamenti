#include <stdio.h>

int uguali(char *prima, char *seconda){
	int i=0;
	while(prima[i] != '\0' && prima[i] != ' '){
		if(prima[i]==seconda[i])
			i++;
		else
			return 0;
	}
	return 1;
}

char *prossima_frase(char *frase){
	int i = 0;
	while(frase[i]!=' ' && frase[i]!='\0'){
		i++;
	}
	if(frase[i]=='\0'){
		return NULL;
	}
	return &frase[i+1];
}

int conta_parole(char *frase, char *parola){
	int occorrenze = 0;
	while(frase!=NULL){
		if(uguali(frase, parola)){
			occorrenze++;
		}
		frase = prossima_frase(frase);
	}
	return occorrenze;
}

int main(){
	printf("%d\n", conta_parole("ciao ciao", "ciao") );
}
