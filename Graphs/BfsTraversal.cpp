#include<iostream>
#include<queue>
using namespace std;

void printBFS(int**edges,int n,int sv,bool*visited){
  queue<int> pending;
  pending.push(sv);
  visited[sv]=true;
  
  while (!pending.empty())
  {
      int currentVertex=pending.front();
      pending.pop();
      cout<<currentVertex<<" ";
        for(int i=0;i<n;i++){
          if(i==currentVertex){
              continue;
          }
          if(edges[currentVertex][i]==1 && !visited[i]){
              pending.push(i);
              visited[i]=true;
          }
      }
  }
}


int main(){
    int n;
    int e;
    cin>>n;
    cin>>e;
    
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
        bool*visited=new bool[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        printBFS(edges,n,0,visited);

        return 0;
}