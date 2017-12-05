#include<iostream>
#include"Header.h"

using namespace std;

int main(){
	graph g1;
	g1.add_edge(1, 2);
	g1.add_edge(1, 3);
	g1.add_edge(2, 1);
	g1.add_edge(3, 1);
	g1.add_edge(2, 4);
	g1.add_edge(4, 2);
	g1.add_edge(3, 4);
	g1.add_edge(3, 5);
	g1.add_edge(4, 3);
	g1.add_edge(5, 3);
	g1.add_edge(4, 5);
	g1.add_edge(4, 6);
	g1.add_edge(5, 4);
	g1.add_edge(6, 4);
	g1.add_edge(5, 6);
	g1.add_edge(6, 5);
	g1.search_node(5);
	cin.get();
}
