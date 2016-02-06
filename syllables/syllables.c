/*
		text: |
			Scrivere una funzione `sillaba` che, presa in
			ingresso una stringa,
			la divida in sillabe. La regola è: se la parola
			è del tipo "cvcvcv...." (dove 'c' rappresenta una consonante e 'v' una vocale) , i gruppi 'cv' formano una sillaba.
			Se la parola è del tipo 'vcvcvcv....' la prima vocale fa
			sillaba a sé, e per le altre vale la regola di sopra
		esempi:
			- e-va-de-re
			- a-si-no
			- ca-sa
			- di-va-ga-va-no
		test: |
			assert(strcmp("evadere","e-va-de-re")==0)
			assert(strcmp("asino,"a-si-no")==0)
			assert(strcmp("casa","ca-sa")==0)
*/


#include "dict.h"

int is_vowel(char c) {
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
			c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int is_consonant(char c){
	return ((c > 'a') && (c <= 'z')) || ((c>'A') && (c <= 'Z')) && !is_vowel(c);
}

char *extract_first_syllable_starting_from_vowel(char *chunk){
	char *result = (char *)malloc(sizeof(char) * 2);
	result[0] = *chunk;
	result[1] = '\0';
	return result;
}
char *extract_first_syllable_starting_from_consonant(char *chunk){
	char *result = (char *)malloc(sizeof(char) * 2);
	result[0] = chunk[0];
	result[1] = chunk[1];
	result[2] = '\0';
	return result;
}

char *extract_first_syllable(char *chunk){
	char *result = strdup(".");
	if(is_vowel(*chunk)){
		return extract_first_syllable_starting_from_vowel(chunk);
	} else {
		return extract_first_syllable_starting_from_consonant(chunk);
	}
	return result;
}

char *syllablize(char *string){
	char *result = (char *) malloc(sizeof(char) * strlen(string) * 2);
	char *syllable = (char *) malloc(sizeof(char) * 2);
	while(*string){
		syllable = extract_first_syllable(string);
		strcat(result, syllable);
		strcat(result, "-");
		string += strlen(syllable);
	}
	result[strlen(result)-1] = '\0';
	return result;
}

/*
 * This function returns an array of syllables,
 * following the rules of the previous functions. (extract_first_syllable, ecc.)
*/
char **split_in_syllables(char *string){
	/*
	 * syllables is the array of strings that will be returned.
	 * It will look like this: {"ab","ca","no"},
	 * where "ab", "ca" and "no" are arbitrary syllables.
	 * The problem is that we don't previously know how many syllables
	 * the string is going to have, so we are also unable to allocate the right
	 * amount of memory for the array.
	 * Given that this is not the best way to solve this problem,
	 * i'm going to assume that the maximum number of bytes of memory
	 * needed for the array is strictly minor than the number of characters in the string.
	 * That's because a syllable can be no smaller than just a character.
	*/
	char **syllables = malloc(strlen(string)+1);

	/*
	 * Putting every syllable in an element of the array.
	*/
	int i = 0;
	char *tmp;
	while(*string){
		if(syllables[i] = (char *) malloc(sizeof(char) * 3)){
			printf("ok: ");
			syllables[i] = extract_first_syllable(string);
		}
		else {
			printf("no");
			return syllables;
		}
		tmp=syllables[0];
		printf("%s | %s | %s\n", syllables[i], string, tmp);
		string += strlen(syllables[i]);

		i++;
	}
	//printf("%s %s", syllables[1], tmp);
	return syllables;
}


elem *store_syllables_ordered(char *string){
	elem *head = NULL;
	char **r = split_in_syllables(string);
	while(*r){
		inc(&head, *r);
		r++;
	}
	return head;
}

int main(){
	char *s = strdup("divagavanovavavavavavanonononono");
	char **r = split_in_syllables(s);
	char *c = r[0];
	//printf("%s\n",c);
	while(*r){
		//printf("%s\n", *r);
		r++;
	}
	//print_dict(store_syllables_ordered(s));
}
