#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *left,*right;
	public:
		Node(int e)
		{
			data=e;
			left=NULL;
			right=NULL;
		}
		friend class Tree;
};
class Tree
{
	Node *root;
	bool isEmpty()
	{
		if(NULL==root)
			return true;
		return false;
	}
	void preorder(Node *temp)
	{
		if(NULL==temp)
			return;
		cout<<temp->data<<",";
		preorder(temp->left);
		preorder(temp->right);
	}
	void inorder(Node *temp)
	{
		if(NULL==temp)
			return;
		inorder(temp->left);
		cout<<temp->data<<",";
		inorder(temp->right);
	}
	void postorder(Node *temp)
	{
		if(NULL==temp)
			return;
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<",";
	}
	void removeAllNodes(Node *temp)
	{
		if(NULL==temp)
			return;
		removeAllNodes(temp->left);
		removeAllNodes(temp->right);
		delete temp;
	}
	int height(Node *temp)
	{
		int h=0;
		if(NULL!=temp)
		{
			int l_height=height(temp->left);
			int r_height=height(temp->right);
			/*if(l_heigh>r_height)
				h=l_height;
			else
				h=r_height;*/
			h=(l_height > r_height)?l_height:r_height;
			h++;
		}
		return h;
	}
	int diff(Node *root)
	{
		int l_h,r_h,bal;
		l_h=height(root->left);
		r_h=height(root->right);
		bal=l_h - r_h;
		return bal;
	}
//left problem with left heavy
	Node* ll_rotation(Node *temp)
	{
		Node *cur;
		cur=temp->left;
		temp->left=cur->right;
		cur->right=temp;
		return cur;
	}
//right problem with right heavy
	Node* rr_rotation(Node *temp)
	{
		Node *cur;
		cur=temp->right;
		temp->right=cur->left;
		cur->left=temp;
		return cur;
	}
//left problem with right heavy
	Node* lr_rotation(Node *temp)
	{
		Node *cur;
		cur=temp->left;
		temp->left=rr_rotation(cur);
		return ll_rotation(temp);
	}
//right problem with left heavy
	Node* rl_rotation(Node *temp)
	{
		Node *cur;
		cur=temp->right;
		temp->right=ll_rotation(cur);
		return rr_rotation(temp);
	}
	Node* balance(Node* temp)
	{
		int bal=diff(temp);
		if(bal<-1)
		{
			if(diff(temp->right)>0)
				temp=rl_rotation(temp);
			else
				temp=rr_rotation(temp);
		}
		else if(bal>1)
		{
			if(diff(temp->left)<0)
				temp=lr_rotation(temp);
			else
				temp=ll_rotation(temp);
		}
		return temp;
	}
	Node* add(Node *temp,int e)
	{
		if(NULL==temp)
		{
			Node *new_node=new Node(e);
			temp=new_node;
			return temp;
		}
		else if(e < temp->data)
		{
			temp->left=add(temp->left,e);
			temp=balance(temp);
		}
		else
		{
			temp->right=add(temp->right,e);
			temp=balance(temp);
		}
		return temp;
	}
	public:
		Tree()
		{
			root=NULL;
		}
		~Tree()
		{
			removeAllNodes(root);
		}
		void addNode(int e)
		{
			root=add(root,e);
		}
		void preorder_traversal()
		{
			if(isEmpty())
			{
				cout<<"Tree is empty\n";
				return;
			}
			preorder(root);
			cout<<"\b \n";
		}
		void inorder_traversal()
		{
			if(isEmpty())
			{
				cout<<"Tree is empty\n";
				return;
			}
			inorder(root);
			cout<<"\b \n";
		}
		void postorder_traversal()
		{
			if(isEmpty())
			{
				cout<<"Tree is empty\n";
				return;
			}
			postorder(root);
			cout<<"\b \n";
		}
};
int main()
{
	Tree obj;
	obj.addNode(50);
	obj.addNode(40);
	obj.addNode(30);
	obj.addNode(60);
	obj.addNode(55);
	obj.addNode(80);
	obj.addNode(10);
	obj.addNode(35);
	obj.addNode(32);
	obj.preorder_traversal();
	obj.inorder_traversal();
	obj.postorder_traversal();
	return 0;
}
