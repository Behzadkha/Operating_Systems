//Author: Behzad Khamneli
//400123835
//Khamnelb
#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
// refrence to the head of the list
struct node *head = NULL;
// Sequence counter of next available thread identifier
int nextTid = 0;

Task *pickNextTask();

void add(char *name, int priority, int burst){
	Task *newTask = (Task *) malloc(sizeof(Task));

	newTask->name = name;
	newTask->tid = nextTid++;
	newTask->priority = priority;
	newTask->burst = burst;
	
	//insert the new task into the list of tasks
	insert(&head, newTask);
}
// run the sjf
void schedule()
{
	Task *current;
	traverse(head);
	while(head != NULL){
		current = pickNextTask();
		run(current, current->burst);
		delete(&head, current);
	}
}
	
//return the next task selected to run.
Task *pickNextTask()
{
	struct node *newHead = head;
	int burstT = 2147483647; //big number like intmax
	Task *t = NULL;
	while(newHead !=NULL){
		if(burstT > newHead->task->burst){
			burstT = newHead->task->burst;
			t = newHead->task;
		}
		newHead = newHead->next;
	}
	return t;
}

