#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "stack.h"


int main(){
	printf("Testing\n\n");
	
	//char x[] = "7.2";
	//printf("RESULT: %f\n\n", compute_rpn(x));
	
	char *y = get_expressions("sample_in.txt");
	process_expressions(y, "bro.txt");
}
