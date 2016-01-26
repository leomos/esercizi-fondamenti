#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *string){
	int l = strlen(string);
	char *result = malloc(l);
	int i = 0;
	for(i=0; i<l; i++){
		result[i] = string[l-i-1];
	}
	return result;
}

// char to int: 'n'-'0'
// int to char: n+'0'
char *sum_three_chars(char first, char second, char third) {
	int result;
	char *final = malloc(2);
	result = (first - '0') + (second - '0') + (third - '0');
	sprintf(final, "%02d", result);
	return final;
}

char *sum_two_strings(char *first, char *second) {
	int i = 0, fl = strlen(first), sl = strlen(second);
	char carry = '0';
	char *result; 
	char *tmp = malloc(3);
	if(fl < sl) result = malloc(sl+2);
	else result = malloc(fl+2);
	while( (first[i] != '\0') && (second[i] != '\0') ) {
		tmp = sum_three_chars(first[i], second[i], carry);
		result[i] = tmp[strlen(tmp)-1];
		carry = tmp[strlen(tmp)-2];
		i++;
	}
	if(fl > sl){
		while(first[i] != '\0'){
			tmp = sum_three_chars(first[i], '0', carry);
			result[i] = tmp[strlen(tmp)-1];
			carry = tmp[strlen(tmp)-2];	
			i++;
		}
		if(carry!='0') result[i] = carry;
	} else if(fl < sl){
		while(second[i] != '\0'){
			tmp = sum_three_chars(second[i], '0', carry);
			result[i] = tmp[strlen(tmp)-1];
			carry = tmp[strlen(tmp)-2];
			i++;
		}
		if(carry!='0') result[i] = carry;
	} else {
		if(carry != '0')
			result[i] = carry;
	}
	return result;
}

int main() {
	
	char *f = "45649841516518615151845664236889417533";
	char *s = "449849848494849841563348";
	printf("%s\n", strrev(sum_two_strings(strrev(f), strrev(s))));
}
