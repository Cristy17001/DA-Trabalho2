#include "backtracking.h"
#include "2opt.h"
#include <fstream>
using namespace std;
int main(){
    ifstream edges;
    string str;
    Graph graph;
    edges.open("./data/extra/edges_15.csv");
    if (edges.is_open()) {
        //getline(edges,str);
    } else {
        cout << "Failed to open\n";
        return 1;
    }
    cout<<"lines\n";
    int i =1;
    while(!edges.eof()) {
        string line;
        int origin, destiny;
        double weight;
        getline(edges,line);
        ++i;
        if(line=="")
            continue;
        if(3 > sscanf(line.c_str(),"%i,%i,%lf",&origin,&destiny,&weight))
            cout<<"ERROR in line "<<i<<":" <<line<<".\n";
        graph.addVertex(origin);
        graph.addVertex(destiny);
        graph.addBidirectionalEdge(origin,destiny,weight);
    }
    edges.close();
    cout<<"edges\n";
    dijkstra(graph,0);
    for(auto v:graph.getVertexSet()){
        cout<< v->getId() << ":" << v->getDist()<<"\n";
    }
    std::vector<int> result;
    result.reserve(graph.getNumVertex());
    for(unsigned int i=0; i<graph.getNumVertex();++i)
        result.push_back(i);
    //double bestDistance=backtracking(graph,result);
    double bestDistance=two_opt(graph,result);
    cout<<"distance:" << bestDistance <<"\n";
    for(auto i : result)
        cout<< i<<",";
    cout<< "\n";
    return 0;
    
}