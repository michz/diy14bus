//TODO: length of arrays


// value for characters:

// 0 : null '\0'
// 1...10 : number
// 11...36 : letter
// 37...39 : 4 special characters: " ", "@", "_"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>


uint8_t char_to_value(char in){

	if(in == '\0'){ // special character
		return 0;
	}
	else if(('0' <= in) && (in <= '9')){ //number
		return in - '0' + 1;
	}
	else if(('a' <= in) && (in <= 'z')){ //letter
		return in - 'a' + 11;
	}
	else if(('A' <= in) && (in <= 'Z')){ //letter
		return in - 'A' + 11;
	}
	else if(in == ' '){ // special character
		return 37;
	}
	else if(in == '@'){ // special character
		return 38;
	}
	else if(in == '_'){ // special character
		return 39;
	}

	
	printf("char_to_value: invalid input argument\n");

	return 39; //underscore

}

char value_to_char(uint8_t in){


	if(in == 0){ // special character
		return '\0';
	}
	else if((1 <= in) && (in <= 10)){ //number
		return in + '0' - 1;
	}
	else if(in == 37){ // special character
		return ' ';
	}
	else if(in == 38){ // special character
		return '@';
	}
	else if(in == 39){ // special character
		return '_';
	}

	else{ //letter
		return in - 11 + 'a';
	}
}


int digits_to_twoBytes(char x1, char x2, char x3, uint8_t *out1, uint8_t *out2){
	
	uint16_t symbol = char_to_value(x1) + char_to_value(x2)*40 + char_to_value(x3)*40*40;

	//printf("symbol generated: %d\n", symbol); //just for debug

	*out1 = (char) (symbol >> 8) & 0xff;
	*out2 = (char) symbol & 0xff;

	return 0; //TODO
}

int twoBytes_to_digits(uint8_t in1, uint8_t in2, char *x1, char *x2, char *x3){

	uint16_t symbol = ((uint16_t)in1 << 8) | in2; //warum geht & nicht?

	//printf("symbol reconstructed: %d\n", symbol); //just for debug

	uint8_t tmp1 = symbol %40;
	uint8_t tmp2 = ((symbol-tmp1)/40) %40;
	uint8_t tmp3 = ((symbol-(tmp1+40*tmp2))/(40*40)) %40;

	*x1 = value_to_char(tmp1);
	*x2 = value_to_char(tmp2);
	*x3 = value_to_char(tmp3);

	return 0; //TODO
}


int string_to_byteArray(char *string, uint8_t* array){

	if(strlen(string) > 39){
		printf("string_to_byteArray: Warning: input string too long!\n");
	}

	char x1;
	char x2;
	char x3;
	uint8_t sym1; 
	uint8_t sym2; 
	uint8_t array_index = 0;

	for(int i = 0; (i<strlen(string)+1)&(i<=36); i=i+3){ 
		if(i < strlen(string)){
			x1 = string[i];
			if(i+1 < strlen(string)){
				x2 = string[i+1];
				if(i+2 < strlen(string)){
					x3 = string[i+2];
				}
				else{
					x3 = '\0';
				}
			}
			else{
				x2 = '\0';
				x3 = '\0';
			}
		}	
		else{
			x1 = '\0';
			x2 = '\0';
			x3 = '\0';
		}			

		digits_to_twoBytes(x1, x2, x3, &sym1, &sym2);
		array[array_index++] = sym1;
		array[array_index++] = sym2;
	}

	return 0;
}


int byteArray_to_string(uint8_t *array, char *string){
	char x1;
	char x2;
	char x3;

	int string_index = 0;

	for(int i = 0; i < 26; i=i+2){ 
		twoBytes_to_digits(array[i], array[i+1], &x1, &x2, &x3);
		
		string[string_index++] = x1;
		string[string_index++] = x2;
		string[string_index++] = x3;

		if(x1 == '\0' | x2 == '\0' | x3 == '\0'){
			break;
		}
	}
	return 0;
}




int main(){

	printf("hallo\n");

	uint8_t array[26];

	//encode
	char *input_string = "1234567890aBcDeFgHiJkLmNoPqRsTuVwXyZ$@_"; //'$' wird nicht unterstuetzt
	string_to_byteArray(input_string, array);

	//decode
	char output_string[100];
	byteArray_to_string(array, output_string);


	printf("decoded_string: %s\n", output_string);

	return 0;

} 


