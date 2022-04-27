#include <iostream>
#include <bits/stdc++.h>
#define INFINITY 1000000
using namespace std;
vector<pair<int,pair<int,int>>>adjacencyList[100000];

void addEdge(vector<pair<int,pair<int,int>>>adj[],int firstNode,int secondNode,int weight,int cost)
{
    adj[firstNode].push_back({secondNode,make_pair(weight,cost)});
    adj[secondNode].push_back({firstNode,make_pair(weight,cost)});
}
void Dijkstra(int sourceCity,int destinationCity,int cites,int amount)
{
    priority_queue< pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > >pq;
    vector<pair<int,pair<int,int>>>distance(cites+1,make_pair(INFINITY,make_pair(INFINITY,0)));
    int counter=-1;
    pq.push({0,sourceCity});
    int flag=destinationCity;
    distance[sourceCity].first=0;
    distance[sourceCity].second.first=sourceCity;



    while(!pq.empty())
    {
        int currentNode=pq.top().second;
        int currentNode_distance=pq.top().first;
        pq.pop();
        for(pair<int,pair<int,int>> child:adjacencyList[currentNode])
        {

            if(currentNode_distance+child.second.second+((child.second.first)*amount)<distance[child.first].first)
            {
                distance[child.first].first=currentNode_distance+child.second.second+((child.second.first)*100);
                distance[child.first].second.first=currentNode;
                distance[child.first].second.second=child.second.first+distance[currentNode].second.second;
                pq.push({make_pair(distance[child.first].first,child.first)});
            }


        }

    }
    stack<int>s;

     while(flag!=sourceCity){

        s.push(distance[flag].second.first);
        flag=distance[flag].second.first;
     }
     cout<<"The route with minimum cost is ";
     while(!s.empty()){
        counter ++;
        cout<<s.top();
        s.pop();
        cout<<"->";
     }
     cout<<destinationCity;
     cout<<"\n";
     cout<<"Total Time : "<<(distance[destinationCity].second.second+counter)<<" hours";
     cout<<"\n";
     cout<<"Total Cost : "<<(distance[destinationCity].first+counter*amount)<<"$";
}

int main()
{
    int cites,routes,source,destination,time,sourceCity,destinationCity,cost,amount;
    cout<<"please enter amount M : ";
    cin>>amount;
    cout << "please enter number of cites : ";
    cin>>cites;
    cout << "please enter number of routes : ";
    cin>>routes;
    for(int i=1; i<=routes; i++)
    {
        cout << "please enter "<<i<<" source destination time cost : ";
        cin>>source>>destination>>time>>cost;

        addEdge(adjacencyList,source,destination,time,cost);
    }
    cout << "please enter source city : ";
    cin>>sourceCity;
    cout << "please enter destination city : ";
    cin>>destinationCity;

    Dijkstra(sourceCity,destinationCity,cites,amount);

    return 0;
}
