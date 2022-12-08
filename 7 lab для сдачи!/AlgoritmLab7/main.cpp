#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <time.h>
using namespace std;

int i, j,size;
bool *visited=new bool[200];
//матрица смежности 
int **graph;

int** create_mass(int size){
int **graph = (int**)malloc(sizeof(int*)*size);
for(int i=0;i<size;i++){
graph[i] = (int*)malloc(sizeof(int)*size);
}
return graph;
}

int** initializate(int** graph, int size){

srand(time(NULL));
for(int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
graph[i][j] = rand()%2;
}
}

for(int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if(i == j){
graph[i][j] = 0;

}
if(graph[i][j] = graph[j][i]){
graph[i][j] = graph[j][i];
}
}
}
return graph;
}
//поиск в глубину
void DFS(int st)
{
int r;
printf("%d",st+1);
visited[st]=true;
for (r=0; r<=size; r++)
if ((graph[st][r]!=0) && (!visited[r]))
DFS(r);
}

void main()
{
setlocale(LC_ALL, "Rus");
int start = 1;
printf("\nВведите количество вершин (больше 2):");
scanf("%d", &size);
graph = create_mass(size);
initializate(graph,size);
printf("\nМатрица смежности графа:");
for (i=0; i<size; i++){
printf("\n");
visited[i]=false;
for (j=0; j<size; j++){
printf("%d ",graph[i][j]);
}
}

bool *vis=new bool[size];
printf("\nПорядок обхода рекурсивной функции:");
DFS(start-1);
delete []visited;

printf("\nПорядок обхода нерекурсивной функции:");
stack <int> Stack;
int nodes[200];
for (int i = 0; i < size; i++) nodes[i] = 0;
Stack.push(0);
while (!Stack.empty()) // пока стек не пуст
{ 
int node = Stack.top();
Stack.pop();
if (nodes[node] == 2) continue;
nodes[node] = 2;
for (int j = size - 1; j >= 0; j--)
{
if (graph[node][j] == 1 && nodes[j] != 2)
{
Stack.push(j);
nodes[j] = 1;
}
}
printf("%d",node + 1);
}
printf("\n");
system("pause");
}