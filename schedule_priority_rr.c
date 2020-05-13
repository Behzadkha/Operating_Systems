//Author: Behzad Khamneli
//400123835
//Khamnelb
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
//refrence to the head of the list
struct node *head = NULL;
//holds task ids with equal priority
int TWEP[100];
//sequence counter of next available thread identifier
int nextTid = 0;
//add a new task to the list of tasks
void add(char *name, int priority, int burst){
	Task *newTask = (Task *) malloc(sizeof(Task));
	newTask->tid = nextTid++;
	newTask->name = name;
	newTask->priority = priority;
	newTask->burst = burst;
	insert(&head, newTask);
}
int found = 0;
//fills the TWEP array if tasks have the same priority
void fill(){
	struct node *newHead = head;
	struct node *sHead = head;	
	int rpriority = 0;
	int i = 0;
	while(newHead != NULL){
		if(rpriority < newHead->task->priority){
			 rpriority = newHead->task->priority;
		}
		newHead = newHead->next;
	}
	while(sHead != NULL){
		if(rpriority == sHead->task->priority){
			TWEP[i] = sHead->task->tid;
			i++;
		}
		sHead = sHead->next;
	}
	found = i;
}
int start = 0;
//runs the rr scheduler
void schedule(){
	Task *current;
	while(head != NULL){
		fill();
		if (start >= found - 1){
			start = 0;
		}
		else{
			start++;
		}
		struct node *nhead = head;
		//change current
		while(nhead != NULL){
			if(nhead->task->tid == TWEP[start]){
				current = nhead->task;
				break;
			}
			nhead = nhead->next;
		}
		if (found > 1 && current->burst > QUANTUM){
			run(current, QUANTUM);
			current->burst -= QUANTUM;
		}
		//else, task is finished
		else{
			run(current, current->burst);
			current->burst = 0;
			printf("Task %s is finished.\n", current->name);
			delete(&head, current);
		}
	}
}
