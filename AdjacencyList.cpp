/*#include<iostream>
using namespace std;
class Link;
class Vertex
{
	string city;
	Vertex *next;
	Link *adj;
	friend class Graph;
	public:
		Vertex(string city)
		{
			this->city=city;
			next=NULL;
			adj=NULL;
		}
};
class Link
{
	Vertex *vertex;
	Link *next_link;
	friend class Graph;
	public:
		Link(Vertex *v):vertex(v),next_link(NULL){
		}
};
class Graph
{
	Vertex *start,*end;
	bool isEmpty()
	{
		if(NULL==start)
			return true;
		return false;
	}
	Vertex* find_city(string city)
	{
		Vertex *temp=start;
		while(NULL!=temp)
		{
			if(temp->city==city)
				return temp;
			temp=temp->next;
		}
		return NULL;
	}
	public:
		Graph()
		{
			start=NULL;
			end=NULL;
		}
		~Graph()
		{
			Vertex *temp=start;
			while(NULL!=temp)
			{
				start=start->next;
				Link *temp_link1,*temp_link2;
				temp_link1=temp->adj;
				while(NULL!=temp_link1)
				{
					temp_link2=temp_link1;
					temp_link1=temp_link1->next_link;
					//cout<<"Link Deleted\n";
					delete temp_link2;
				}
				cout<<"Vertex deleted\n";
				//delete temp;
				temp=start;
			}
		}
		void add_city(string city)
		{
			if(find_city(city)!=NULL)
			{
				cout<<"City already exists in grpah\n";
				return;
			}
			Vertex *new_city=new Vertex(city);
			if(isEmpty())
			{
				start=end=new_city;
			}
			else
			{
				end->next=new_city;
				end=new_city;
			}
			cout<<"City added in grpah\n";
		}
		void add_edge(string src,string dest)
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			Vertex *src_city,*dest_city;
			src_city=find_city(src);
			if(NULL==src_city)
			{
				cout<<"source doesn't exist\n";
				return;
			}

			dest_city=find_city(dest);
			if(NULL==dest_city)
			{
				cout<<"Destination doesn't exist\n";
				return;
			}

			Link *new_link=new Link(dest_city);
			if(NULL==src_city->adj)
			{
				src_city->adj=new_link;
			}
			else
			{
				Link *temp=src_city->adj;
				while(NULL!=temp->next_link)
					temp=temp->next_link;
				temp->next_link=new_link;
			}
			cout<<"Edge added between "<<src<<" and "<<dest<<endl;
		}
		void show_cities()
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			Vertex *temp=start;
			cout<<"City of graph is/are:-\n";
			while(NULL!=temp)
			{
				cout<<temp->city<<",";
				temp=temp->next;
			}
			cout<<"\b \n";
		}
		void show_graph()
		{
			if(isEmpty())
			{
				cout<<"graph is empty\n";
				return;
			}
			show_cities();
			Vertex *temp_city=start;
			while(NULL!=temp_city)
			{
				if(NULL!=temp_city->adj)
				{
					cout<<"Adjacent city to "<<temp_city->city<<" is/are\n\t";
					Link *temp_link=temp_city->adj;
					while(NULL!=temp_link)
					{
						cout<<temp_link->vertex->city<<",";
						temp_link=temp_link->next_link;
					}
					cout<<"\b \n";
				}
				temp_city=temp_city->next;
			}
		}
		void remove_edge(string src,string dest)
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			Vertex *src_city,*dest_city;
			src_city=find_city(src);
			if(NULL==src_city)
			{
				cout<<"source doesn't exist\n";
				return;
			}

			dest_city=find_city(dest);
			if(NULL==dest_city)
			{
				cout<<"Destination doesn't exist\n";
				return;
			}

			Link *temp_link=src_city->adj;
			Link *prev_link=NULL;
			while(NULL!=temp_link)
			{
				if(temp_link->vertex==dest_city)
					break;
				prev_link=temp_link;
				temp_link=temp_link->next_link;
			}
			if(NULL==temp_link)
			{
				cout<<"Edge not found\n";
				return;
			}
			if(NULL==prev_link)
				src_city->adj=temp_link->next_link;
			else
				prev_link->next_link=temp_link->next_link;
			delete temp_link;
			cout<<"Edge is removed from "<<src<<" and "<<dest<<endl;
		}
		void remove_city(string city)
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			Vertex *city_vertex;
			city_vertex=find_city(city);
			if(NULL==city_vertex)
			{
				cout<<"City doesn't exists\n";
				return;
			}

			//all edges which are connected to this city
			Vertex *temp_vertex=start;
			while(NULL!=temp_vertex)
			{
				if(temp_vertex->city!=city)
					remove_edge(temp_vertex->city,city);
				temp_vertex=temp_vertex->next;
			}

			//remove all link from city
			Link *temp_link=city_vertex->adj;
			while(NULL!=temp_link)
			{
				city_vertex->adj=temp_link->next_link;
				delete temp_link;
				temp_link=city_vertex->adj;
			}

			//remove city from link
			if(start==city_vertex)
				start=start->next;
			else
			{
				temp_vertex=start;
				while(temp_vertex->next!=city_vertex)
					temp_vertex=temp_vertex->next;
				temp_vertex->next=city_vertex->next;
   			}
   			if(end==city_vertex)
				end=temp_vertex;
			delete city_vertex;
			cout<<"City is removed from graph\n";
		}
};
int main()
{
	Graph graph;
	int option;
	string city1,city2;
	while(true)
	{
		cout<<"\n---------------------------------\n";
		cout<<"1. Add City\n";
		cout<<"2. Add Edge\n";
		cout<<"3. Show City\n";
		cout<<"4. Show Graph\n";
		cout<<"5. Remove City\n";
		cout<<"6. Remove Edge\n";
		cout<<"7. Exit\n";
		cout<<"Enter your option\t";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"Enter City\t";
				cin>>city1;
				graph.add_city(city1);
				break;
			case 2:
				cout<<"Enter Source city\t";
				cin>>city1;
				cout<<"Enter Destination city\t";
				cin>>city2;
				graph.add_edge(city1,city2);
				break;
			case 3:
				graph.show_cities();
				break;
			case 4:
				graph.show_graph();
				break;
			case 5:
				cout<<"Enter City\t";
				cin>>city1;
				graph.remove_city(city1);
				break;
			case 6:
				cout<<"Enter Source city\t";
				cin>>city1;
				cout<<"Enter Destination city\t";
				cin>>city2;
				graph.remove_edge(city1,city2);
				break;
			default:
				return 0;
		}
	}
}*/
