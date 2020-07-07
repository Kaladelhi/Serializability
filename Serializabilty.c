#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int check=0;
int num;

//To check serial schedule.
void serial_schedule(char schedule[][3],int n)
{
	int count=0,t;
	int i, j=1, k, flag=0;
	while(t<n && count<num)
	{
		char ch=schedule[count][j];
		for(i=count;i<num;i++)
		{
			if(ch==schedule[i][j])
			{
				continue;
			}
			else
			{
				break;
			}
		}
		count=i;
		for(k=i;k<num;k++)
		{
			if(ch==schedule[k][j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			check=1;
			return;
		//serializability_test(schedule,num);
		}
		
		t++;
	}
}


//Graph
struct ListNode 
{ 
    int dest;
	//char data_item; 
    struct ListNode* next; 
}; 

struct AdjList 
{ 
    struct ListNode *head;  
}; 

struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
struct ListNode* createListNode(int dest) 
{ 
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode)); 
    node->dest = dest; 
    //newNode->data_item=x;
    node->next = NULL; 
    return node; 
} 

struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
int flag=0;
//printf("1\t");
    
    //printf("2\t");
	struct ListNode* node_x =graph->array[src].head;
    //node_x=node_x->next;
    //printf("3\t");
    if(node_x==NULL)
    {
  //  	printf("4\n");
			struct ListNode* node = createListNode(dest); 
    		node->next = graph->array[src].head; 
    		graph->array[src].head = node; 
	}
    //printf("4");
    else
    {
	
	while(node_x!=NULL)
	{
		if(node_x->dest==dest)
		{
//			printf("5\n");
			flag=0;
			//continue;	
		}	
		else
		{
			flag=1;
		}
		node_x=node_x->next;
	} 
}
if(flag==1)
{
//	printf("6\n");
			struct ListNode* node = createListNode(dest); 
    		node->next = graph->array[src].head; 
    		graph->array[src].head = node; 
}
} 
 
 bool isCycleEdge(int v, bool visited[], bool *stack, struct Graph *graph)
{//printf("B\t");
	if(visited[v]==false)
	{//printf("C\t");
		visited[v]=true;
		stack[v]=true;
		//printf("D\t");
		struct ListNode* temp=graph->array[v].head;
		//printf("E\t");
		while(temp!=NULL)
		{//printf("F\t");
			if(!visited[temp->dest] && isCycleEdge(temp->dest, visited, stack,graph))
				return true;
			
			else if(stack[temp->dest])
				return true;
			//	printf("H\t");
			temp=temp->next;
		}//printf("G\t");
	}
	stack[v]=false;
	return false;
}

bool isCyclic(struct Graph *graph, int n)
{//printf("Hello\n");
	bool visited[n];
	bool stack[n];
	
	int i;
//	printf("Welcome\n");
	for(i=0;i<n;i++)
	{//printf("hi\n");
		visited[i]=false;
		stack[i]=false;
	}
	
	for(i=0;i<n;i++)
	{
		if(isCycleEdge(i,visited,stack,graph))
		{//printf("A\t");
			return true;
		}
		
	}
	return false;
}
 
nonserial_schedule(char schedule[][3],int n)
{
	struct Graph* graph = createGraph(n); 
	int i,j;
	int a=0, b=1, c=2;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if((schedule[i][b]!=schedule[j][b]) && (schedule[i][a]==schedule[j][a]=='w' || schedule[i][a]!=schedule[j][a]) && (schedule[i][c]==schedule[j][c]))
			{
				//printf("%c->%c\n",schedule[i][c],schedule[j][c]);
				addEdge(graph, schedule[i][b]-49,schedule[j][b]-49);
				break;
			}
			else
			{
				continue;
			}
		}
	}
	//printGraph(graph);
	bool cycle_check=isCyclic(graph,n);
	return cycle_check;
}

/*void printGraph(struct Graph* graph) 
{ 
    int i; 
    for (i = 0; i < graph->V; ++i) 
    { 
        struct AdjListNode* temp = graph->array[i].head; 
        printf("\n Adjacency list of vertex %d head ", i); 
        while (temp) 
        { 
            printf("-> %d", temp->dest); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
} */
int main()
{
	int choice;
	int i,j,n;
	do
	{
		
	printf("Enter the number of transactions\n");
	scanf("%d",&n);
	
	printf("Enter the number of operations in schedule\n");
	scanf("%d",&num);
	
	char schedule[num][3];
	printf("Enter schedule\n");
	/*for(i=0;i<num;i++)
	{
		for(j=0;j<3;j++)
		{
				scanf("%s",&schedule[i][j]);	
		}
	}*/
	//printf("%d",n);
	for(i=0;i<num;i++)
	{
		scanf("%s",&schedule[i]);
	}
	serial_schedule(schedule,n);
	
	if(check==0)
	{
		printf("Serial schedule\n");
	}
	else
	{
		check=0;
		if(nonserial_schedule(schedule,n))
		{
			printf("Non-serial, Not serializable Schedule\n");
		}
		else
		{
			printf("Serializable Schedule\n");
		}
	}
		printf("\nWant to continue\n1 for Yes\n2 for No\n");
		scanf("%d",&choice);
	}while(choice==1);
}
