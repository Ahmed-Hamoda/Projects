#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"
#include "stack.h"

double compute_rpn(char* rpn){
	struct stack* stack = create_stack();

	char* token = strtok(rpn, " ");

	while (token != NULL){

		if (unary_op(*token)){

			double val = pop(stack);

			if (*token == 's'){
				push(stack, sin(val));
			} else if (*token == 'c'){
				push(stack, cos(val));
			} else if (*token == 't'){
				push(stack, tan(val));
			} else if (*token == 'e'){
				push(stack, exp(val));
			} else if (*token == 'i' && val != 0){
				push(stack, 1/val);
			} else if (*token =='m'){
				push(stack, -1*val);
			} else if (*token == 'r'){
				push(stack, sqrt(val));
			}
		
		} else if (binary_op(*token)){
			
			double val1 = pop(stack);
			double val2 = pop(stack);

			if (*token == '+'){
				push(stack, val2 + val1);
			} else if (*token == '-'){
				push(stack, val2 - val1);
			} else if (*token == '*'){
				push(stack, val2 * val1);
			} else if (*token == '/' && val1 != 0){
				push(stack, val2 / val1);
			} else if (*token == '^'){
				push(stack, pow(val2, val1));
			} else if (*token == 'f'){
				push(stack, val1); push(stack, val2);
			}
		
		} else {
			push(stack, atof(token));
		}

		token = strtok(NULL, " ");
	}

	double result = (double)stack->top->value;
	delete_stack(stack);
	return result;
}

char* get_expressions(char* filename){
	FILE * file;
	file = fopen(filename, "r");
	
	long filesize = 0;

	fseek(file, 0L, SEEK_END);
	filesize = ftell(file);
	rewind(file);
	
	char *array = (char*)calloc(filesize, sizeof(char));
	fread(array, sizeof(char), filesize, file); 
	array[filesize] = 0;

	fclose(file);

	return array;
}

void process_expressions(char* expressions, char* filename){
	FILE *file;
	file = fopen(filename, "w");

	char *token;
	char *rest = expressions;
	char limit[69];

	while ((token = strtok_r(rest, "\n", &rest))){
		double result = compute_rpn(token);
		
		sprintf(limit, "%f\n", result);
		fputs(limit, file);
	}

	free(expressions);

	fclose(file);
}
