#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;

            if(pq[childIndex]>pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    } 

    int RemoveMax(){
        if(isEmpty())
        {
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int pi=0;
        int lci=2*pi+1;
        int rci=2*pi+2;

        while(lci<pq.size()){
            int maxindex=pi;
            if(pq[lci]>pq[maxindex]){
                maxindex=lci;
            }

            if(rci<pq.size() && pq[rci]>pq[maxindex]){
                maxindex=rci;
            }

            if(maxindex==pi){
                break;
            }

            int temp=pq[maxindex];
            pq[maxindex]=pq[pi];
            pq[pi]=temp;

            pi=maxindex;
            lci=2*pi+1;
            rci=2*pi+2;
        }
    return ans;
    }
};



int main(){
    PriorityQueue P;
    P.insert(100);
    P.insert(10);
    P.insert(15);
    P.insert(4);
    P.insert(17);
    P.insert(21);
    P.insert(67);

    cout<<P.getSize()<<endl;
    cout<<P.getMax()<<endl;
    while(!P.isEmpty()){
        cout<<P.RemoveMax()<<" ";
    }
}