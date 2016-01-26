#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary {
	char *word;
	int occurences;
	struct dictionary *next;
};

struct dictionary *new_dictionary_element(char *w, int o){
	struct dictionary *tmp;
	tmp = (struct dictionary *) malloc( sizeof(struct dictionary));
	tmp->word = w;
	tmp->occurences = o;
	tmp->next = NULL;
}

int insert_word(struct dictionary *dict, char *w, int o){
	if(dict==NULL){
		dict = new_dictionary_element(w, o);
		return 0;
	}
	struct dictionary *tmp = dict;
	while(tmp->next != NULL){
		tmp = tmp->next; 
	}
	tmp->next = new_dictionary_element(w, o);
}

void print_dictionary(struct dictionary *dict){
	struct dictionary *tmp = dict;
	while (tmp != NULL){
		printf("%s %d\n", tmp->word, tmp->occurences);
		tmp = tmp->next; 
	} 
}

struct dictionary *search_word(struct dictionary *dict, char *w){
	struct dictionary *tmp = dict;
	while (tmp != NULL){
		if( strcmp(tmp->word, w) == 0){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

char *next_word(char *string){
	int i = 0;
	char *result;
	while(string[i] != ' ' && string[i] != '\0'){
		i++;
	}
	result = (char *) malloc( (sizeof(char) * i) + 1);
	strncpy(result, string, i);
	return result;
}

int main(){
	struct dictionary *d = NULL, *tmp;
	char *text = "Ciao a tutti ciao ciao a tutti tutti ciao ciao ciao tutti ciao a a";
	char *word;
	
	do{
		word = next_word(text);
		if(d==NULL)
			d=new_dictionary_element(word, 1);	
		if( (tmp = search_word(d, word)) != NULL){
			tmp->occurences++;
		} else {
			insert_word(d, word, 1);
		} 
		if(text=strchr(text, ' '))
			text++;
	}while( text != NULL );
	print_dictionary(d);
}


