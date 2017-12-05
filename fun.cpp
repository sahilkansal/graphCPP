#include"Header.h"
#include<algorithm>

using namespace std;

bool vertices::operator ==(const vertices &v)const{
	if (node == v.node){
		return true;
	}
	return false;
}

struct compare_vertices{
	vertices *d;
	compare_vertices(vertices *d1) { d = d1; }
	bool operator () (const vertices *d2) { return *d2 == *d; }
};

void graph::add_node(int val){
	vertices *ptr = new vertices(val);
	list<vertices*>::iterator it = find_if(g->begin(), g->end(), compare_vertices(ptr));
	if (it == g->end()){
		g->push_back(ptr);
	}
}

void graph::add_edge(int source, int dest){
	add_node(source);
	add_node(dest);
	vertices *ptr = new vertices(source);
	vertices *ptr1 = new vertices(dest);
	list<vertices*>::iterator it = find_if(g->begin(), g->end(), compare_vertices(ptr));
	list<vertices*>::iterator it1 = find_if(g->begin(), g->end(), compare_vertices(ptr1));
	delete ptr, ptr1;
	(*it)->add_edge(*it1);
}

void vertices::add_edge(vertices *v){
		head->push_back(v);
}

void vertices::print_node(){
	cout << node << endl;
}

void graph::print_vertices(){
	list<vertices*>::iterator it = g->begin();
	for (; it != g->end(); it++){
		(*it)->print_node();
	}
}

void vertices::print_node_list(){
	list<vertices*>::iterator it = head->begin();
	cout <<"node"<< node << endl;
	for (; it != head->end(); it++){
		(*it)->print_node();
	}
}

void graph::print_ver_list(int val){
	vertices *ptr = new vertices(val);
	list<vertices*>::iterator it = find_if(g->begin(), g->end(), compare_vertices(ptr));
	if (it == g->end())
		cout << "node not exist" << endl;
	else{
		(*it)->print_node_list();
	}
}


void vertices::remove_edge(int node){
	vertices *ptr = new vertices(node);
	list<vertices*>::iterator it1 = find_if(head->begin(), head->end(), compare_vertices(ptr));
	if (it1 == head->end())
		cout << "dest node not found" << endl;
	else{
		//head->remove_if(it1 != head->end());
		head->remove(*it1);
	}
}

void graph::remove_edge(int source, int dest){
	vertices *ptr = new vertices(source);
	vertices *ptr1 = new vertices(dest);
	list<vertices*>::iterator it = find_if(g->begin(), g->end(), compare_vertices(ptr));
	//list<vertices*>::iterator it1 = find_if(g->begin(), g->end(), compare_vertices(ptr1));
	delete ptr;
	if (it == g->end())
		cout << "source node not exist" << endl;
	//else if (it1 == g->end())
	//	cout << "dest node not exist" << endl;
	else{
		(*it)->remove_edge(dest);
	}
}

void vertices::search_node(int val,vertices*it){
	it->explode = true;
	if (val == it->node)
		cout << "node found" <<val<< endl;
	else{
		list<vertices*>::iterator it1 = it->head->begin();
		for (; it1 != it->head->end(); it1++){
			if ((*it1)->explode == false){
				this->search_node(val,*it1);
			}
		}
	}
}

void graph::search_node(int val){
	list<vertices*>::iterator it = g->begin();
	(*it)->search_node(val,*it);
}

