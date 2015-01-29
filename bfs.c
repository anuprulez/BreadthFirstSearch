#include<stdlib.h>
#include<stdio.h>

int front = 0, rear = 0, number_nodes;
char bfs_array[20];
char adjacency_matrix[20][20];
char nodes[20];
int node_counter = 0;
char queue[20];

// Prints the BFS result
void print_bfs_result()
{
    int i = 0;
    printf("Breadth First Search of the Graph : ");
    for(i=0; i<number_nodes; i++){
		printf("%c ", bfs_array[i]);
	}
}

// Creates the Graph and returns the number of nodes
int create_graph(){
    int counter_nodes, j;
    char v;
    printf("Enter the number of nodes: \n");
    scanf("%d",&number_nodes);
    printf("Enter all the nodes: \n");

    for(counter_nodes = 0; counter_nodes < number_nodes; counter_nodes++){
        scanf("%s",&nodes[counter_nodes]);
    }
    for(counter_nodes = 0; counter_nodes < number_nodes; counter_nodes++){
		printf("  %c", nodes[counter_nodes]);
	}

    for(counter_nodes = 0;counter_nodes < number_nodes; counter_nodes++){
        printf("\n%c", nodes[counter_nodes]);
        for(j=0; j < number_nodes; j++){
             printf("  %c",v=getch());
             adjacency_matrix[counter_nodes][j]=v;
        }
        printf("\n");
    }
    return number_nodes;
}

int main()
{
    int j;
    create_graph();
    for(j=0;j<number_nodes; j++){
		binary_first_search(j);
	}
    print_bfs_result();
    getch();
}

// Enqueues the visited nodes
void enqueue(char val)
{
    queue[rear]=val;
    rear++;
}

// Checks if the node is already visited
int is_visited(char val)
{
    int i;
    for(i=0; i<rear; i++)
    {
         if(val == queue[i]){
			return 0;
		 }
    }
	return 1;
}

// Performs the BFS of the Graph
int binary_first_search(int i)
{
     char node_name;
	 int j = 0;
     if(rear==0)
     {
         enqueue(nodes[i]);
		 bfs_array[node_counter] = nodes[j];
	     node_counter++;
     }

     for(j=0; j<number_nodes; j++)
     {
         if(adjacency_matrix[i][j] == 'y')
         {
              if(is_visited(nodes[j]) == 1)
              {
                   enqueue(nodes[j]);
				   bfs_array[node_counter] = nodes[j];
				   node_counter++;
              }
         }
     }
     return 0;
}
