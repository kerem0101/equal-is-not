#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define true 1
#define false 0

uint8_t equalIsNot(char* str);
void test(void);

int main()
{
	test();
	
	return 0;
}

uint8_t equalIsNot(char* str)
{
	uint8_t status = false;
	int8_t isCount = 0;
	int8_t notCount = 0;
	int8_t len = strlen(str);
	
	while(len--){
		
		/* find is */
		if(((*str) == 'i') && ((*(str+1)) == 's')){
			isCount++; // increase is count
			str+=1;    // increase str by 1 because do not need to control 's' after 'i' 
			len-=1;    // decrease len by 1 because do not need to control 's' after 'i' 
		}
		/* find not */
		/* use "else if" instead of "if" because if you find "is" this means this can't be "not" */
		else if(((*str) == 'n') && ((*(str+1)) == 'o') && ((*(str+2)) == 't')){
			notCount++; // incerase not count
			str+=2;     // increase str by 2 because do not need to control 'o' and 't' after 'n' 
			len-=2;     // decrease len by 2 because do not need to control 'o' and 't' after 'n'
		}
		
		str++;
	}
	/* if "is" and "not" count are equal return true else return false */
	if(isCount == notCount){  
		status = true;
	}
	return status;
}
void test(void){
    uint8_t status = false;
	
	status = equalIsNot("This is not");
	printf("equalIsNot('This is not') -> ");
	if(1 == status){ // writing constant first more safe
		printf("true");
	}else{
		printf("false");
	}
	
	status = equalIsNot("This is notnot");
	printf("\nequalIsNot('This is notnot') -> ");
	if(1 == status){
		printf("true");
	}else{
		printf("false");
	}
	
	status = equalIsNot("noisxxnotyynotxisi");
	printf("\nequalIsNot('noisxxnotyynotxisi') -> ");
	if(1 == status){
		printf("true");
	}else{
		printf("false");
	}
}
