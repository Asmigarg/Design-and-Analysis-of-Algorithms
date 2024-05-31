#include <stdio.h>
#include <stdlib.h>
struct Job {
    int id;
    int startTime;
    int processingTime;
};
struct PQNode {
    struct Job job;
    struct PQNode* next;
};
struct PQNode* createNode(struct Job job) {
    struct PQNode* newNode = (struct PQNode*)malloc(sizeof(struct PQNode));
    newNode->job = job;
    newNode->next = NULL;
    return newNode;
}
void enqueue(struct PQNode** front, struct PQNode** rear, struct Job job) {
    struct PQNode* newNode = createNode(job);

    if (*front == NULL) {
        *front = *rear = newNode;
        return;
    }

    if (job.startTime < (*front)->job.startTime) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct PQNode* temp = *front;
        while (temp->next != NULL && temp->next->job.startTime <= job.startTime)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL)
            *rear = newNode;
    }
}
struct Job dequeue(struct PQNode** front) {
    if (*front == NULL) {
        struct Job dummyJob = {-1, -1, -1};
        return dummyJob;
    }
	struct Job job = (*front)->job;
    struct PQNode* temp = *front;
    *front = (*front)->next;
    free(temp);
	return job;
}
void preemptiveSchedule(struct Job jobs[], int n) {
    struct PQNode* front = NULL;
    struct PQNode* rear = NULL;
	int currentTime = 0;
    int totalCompletionTime = 0;
	for (int i = 0; i < n || front != NULL; ) {
        while (i < n && jobs[i].startTime <= currentTime) {
            enqueue(&front, &rear, jobs[i]);
            i++;
        }
		if (front == NULL) {
            currentTime = jobs[i].startTime;
        } else {
            struct Job currentJob = dequeue(&front);
            printf("Job %d: %d to %d\n", currentJob.id, currentTime, currentTime + 1);
            currentTime++;
            currentJob.processingTime--;

            if (currentJob.processingTime > 0) {
                enqueue(&front, &rear, currentJob);
            } else {
                totalCompletionTime += currentTime;
            }
        }
    }
	printf("Total Completion Time: %d\n", totalCompletionTime);
}
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
	struct Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter start time and processing time for Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].startTime, &jobs[i].processingTime);
        jobs[i].id = i + 1;
    }
	preemptiveSchedule(jobs, n);
	return 0;
}

