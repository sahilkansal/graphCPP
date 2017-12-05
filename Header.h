#include<iostream>
#include<list>
#include<queue>

using namespace std;

class vertices{
	int node;
	bool explode;
	list<vertices*> *head;
public:
	bool operator ==(const vertices &v)const;
	vertices() :node(0),explode(false){ head = new list<vertices*>(); }
	vertices(int val){
		node = val;
		head = new list<vertices*>();
	}
	void add_edge(vertices*);
	void remove_edge(int);
	void search_node(int val,vertices*);
	void print_node();
	void print_node_list();
};

class graph{
	list<vertices*> *g;
	void add_node(int);
public:
	graph(){
		g = new list<vertices*>();
	}
	void add_edge(int, int);
	void remove_edge(int, int);
	void search_node(int);
	void print_vertices();
	void print_ver_list(int);
};

