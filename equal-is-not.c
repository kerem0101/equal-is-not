#include <stdio.h>
#include <stdint.h>

#define true 1
#define false 0


uint8_t equalIsNot(char* str)
{
	uint8_t status = false;
	int8_t isCount = 0;
	int8_t dotCount = 0;
	int8_t len = strlen(str)+1;
	
	while(len--){
		
		if(((*str) == 'i') && ((*(str+1)) == 's')){
			isCount++;
		}
		
		if(((*str) == 'd') && ((*(str+1)) == 'o') && ((*(str+2)) == 't')){
			dotCount++;
		}
		
		str++;
	}
	
	if(isCount == dotCount){
		status = true;
	}
	return status;
}

int main()
{
	uint8_t status;
	
	status = equalIsNot("This is notnot");
	printf("%d",status);
	
	return 0;
}
