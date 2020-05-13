# 1. Shortest_job_first(SJF) scheduler

## Module description:

This module has an algorithm in which the process having the smallest execution time will be chosen for
the next execution. In this module schedules are based on the order of the length of the tasks’ next CPU
burst (shortest first). This module has some of the schedule_fcfs.c functions (add and schedule).
PickNextTask is different. First we continiusly check if our new head is not NULL, if it is not null then it
checks if the next burst time is smaller, it changes the time to the new small time and goes to the next
task. If there is no task left, it returns ‘t’ which is a pointer to a Task.
Source code: schedule_sjf.c

# 2. Priority with round-robin scheduler

## Module description:

This module does the Round-Robin scheduler with priority. TWEP is an array that is used to hold tids
with the same priority. In the fills function, it checks if there are two tasks with the same priority. If yes,
it appends it to the TWEP array and finally sets the value of the variable found to i. Found will be used
later in the the schedule function. The schedule function calls the fills function as long as head is not
empty (there is still a task). It sets the pointer current (current is pointer to a Task) to the task where its
id is equal to the task in TWEP at index start. Finally, it will print out a message indicating that a task is
finished.
Source code: schedule_priority_rr.c
