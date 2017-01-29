/*#include<iostream>
#define SIZE 7
using namespace std;
class Graph
{
	int cur_vertices;
	string cities[SIZE];
	int distance[SIZE][SIZE]={};
	bool isEmpty()
	{
		if(0==cur_vertices)
			return true;
		return false;
	}
	bool isFull()
	{
		if(SIZE==cur_vertices)
			return true;
		return false;
	}
	int find_city(string city)
	{
		for(int i=0;i<cur_vertices;i++)
		{
			if(cities[i]==city)
				return i;
		}
		return -1;
	}
	public:
		Graph()
		{
			cur_vertices=0;
		}
		void add_city(string city)
		{
			if(isFull())
			{
				cout<<"Graph is Full\n";
				return;
			}
			int index=find_city(city);
			if(index>=0)
			{
				cout<<"City already added in graph\n";
				return;
			}
			cities[cur_vertices]=city;
			cur_vertices++;
			cout<<"City is added in graph\n";
		}
		void show_city()
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			cout<<"Cities in graph is/are:-\n";
			for(int i=0;i<cur_vertices;i++)
			{
				cout<<cities[i]<<",";
			}
			cout<<"\b \n";
		}
		void add_edge(string src,string dest,int dist)
		{
			int src_index,dest_index;
			if(src==dest)
			{
				cout<<"Source and destination are same\n";
				return;
			}
			src_index=find_city(src);
			if(src_index<0)
			{
				cout<<"Source doesn't exist\n";
				return;
			}
			dest_index=find_city(dest);
			if(dest_index<0)
			{
				cout<<"Destination doesn't exists\n";
				return;
			}
			if(dist<=0)
			{
				cout<<"Invalid distance\n";
				return;
			}
			distance[src_index][dest_index]=dist;
			//distance[dest_index][src_index]=dist;
			cout<<"Edge added between "<<src<<" and "<<dest<<"\n";
		}
		void show_graph()
		{
			if(isEmpty())
			{
				cout<<"Graph is empty\n";
				return;
			}
			show_city();
			for(int i=0;i<cur_vertices;i++)
			{
				cout<<"Adjacent cities to "<<cities[i]<<".\n";
				for(int j=0;j<cur_vertices;j++)
				{
					if(distance[i][j]>0)
						cout<<"\t"<<cities[j]<<" -> "<<distance[i][j]<<endl;
				}
			}
		}
};
int main()
{
	int option,dist;
	string src,dest;
	Graph graph;
	while(true)
	{
		cout<<"\n-----------------------------\n";
		cout<<"1. Add City\n";
		cout<<"2. Add Edge\n";
		cout<<"3. Show City\n";
		cout<<"4. Show Graph\n";
		cout<<"5. Exit\n";
		cout<<"Enter option\t";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"Enter City Name\t";
				cin>>src;
				graph.add_city(src);
				break;
			case 2:
				cout<<"Enter Source city\t";
				cin>>src;
				cout<<"Enter Destination City\t";
				cin>>dest;
				cout<<"Enter Distance\t";
				cin>>dist;
				graph.add_edge(src,dest,dist);
				break;
			case 3:
				graph.show_city();
				break;
			case 4:
				graph.show_graph();
				break;
			default:
				return 0;
		}
	}
}*/
