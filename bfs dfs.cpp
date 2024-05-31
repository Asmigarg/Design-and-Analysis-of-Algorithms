#include<stdio.h>
#include<stdlib.h>
struct Node{
    int vertex;
    struct Node* next;
};
struct Graph{
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Node* createNode(int vertex){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=vertex;
    newNode->next=NULL;
    return newNode;
}
struct Graph* createGraph(int numVertices){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=numVertices;
    graph->adjLists=(struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited=(int*)malloc(numVertices * sizeof(int));
	for(int i=0;i<numVertices;i++){
        graph->adjLists[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}
void addEdge(struct Graph* graph,int src,int dest){
    struct Node* newNode=createNode(dest);
    newNode->next=graph->adjLists[src];
    graph->adjLists[src]=newNode;
}
void BFS(struct Graph* graph,int startVertex){
    int* queue=(int*)malloc(graph->numVertices * sizeof(int));
    int front=0,rear=0;
    graph->visited[startVertex]=1;
    queue[rear++]=startVertex;
	printf("Nodes reachable from vertex %d using BFS: ", startVertex);
	while (front<rear){
        int currentVertex=queue[front++];
        printf("%d ",currentVertex);
        struct Node* temp=graph->adjLists[currentVertex];
        while(temp){
            int adjVertex=temp->vertex;
            if (!graph->visited[adjVertex]){
                graph->visited[adjVertex]=1;
                queue[rear++]=adjVertex;
            }
            temp=temp->next;
        }
    }
    free(queue);
    printf("\n");
}
void DFSUtil(struct Graph* graph,int vertex){
    graph->visited[vertex]=1;
    struct Node* temp=graph->adjLists[vertex];
	while(temp){
        int adjVertex=temp->vertex;
        if (!graph->visited[adjVertex]){
            DFSUtil(graph,adjVertex);
        }
        temp=temp->next;
    }
}
int isConnected(struct Graph* graph){
    DFSUtil(graph,0);
    for (int i=0;i<graph->numVertices;i++){
        if (!graph->visited[i]){
            return 0;
        }
    }
    return 1;
}
int main(void){
    struct Graph* graph=createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,1);
    addEdge(graph,3,2);
    BFS(graph,0);
    if(isConnected(graph)){
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
	return 0;
}

