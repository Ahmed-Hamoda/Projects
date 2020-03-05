#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* create_stack(){
	struct stack* stack_ptr = malloc(sizeof(struct stack));
	stack_ptr->size = 0;
	stack_ptr->top = NULL;
	return stack_ptr;
}

void delete_stack(struct stack* s){
	if (s->size ==0){
		free(s);
	
	} else {
		struct stack_entry* last_element = s->top;
		
		for (int i = 0; i < s->size-1; i++){
			last_element = last_element->next;
		}
		
		free(last_element);
		s->size --;
		delete_stack(s);
	}
}

double pop(struct stack* s){
	if (s->size == 0 || s->top == NULL || s == NULL) return 0;
	
	else if (s->size == 1){
		struct stack_entry* temp = s->top;
		double value = temp->value;

		s->top = NULL;

		free(temp);
		s->size --;

		return value;

	} else {
		struct stack_entry* temp = s->top;
		double value = temp->value;
		
		s->top = s->top->next;
		free(temp);
		s->size --;
		
		return value;
	}
}

int push(struct stack* s, double e){
	if (s == NULL) return -1;
	
	else{
		if (s->size == 0){
			struct stack_entry* new_entry = malloc(sizeof(struct stack_entry));
			new_entry->value = e;
			s->top = new_entry;
		
		} else {
			struct stack_entry* new_entry = malloc(sizeof(struct stack_entry));
			new_entry->value = e;
			new_entry->next = s->top;
			s->top = new_entry;
		}
		
		s->size += 1;	
		return 0;
	}
}
