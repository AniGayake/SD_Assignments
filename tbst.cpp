#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
	int lthread,rthread;
	public:
	node *createNode(int value);
	void insert(int value);
	void inoreder(node *);
	node *leftmost(node *);
	

};
node *root =NULL;
node *dummy = new node;


int main()
{
	node bt;
	int n,ele;
	dummy->data = (-999);
	
	cout<<"Number of Nodes : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element : ";
		cin>>ele;
		bt.insert(ele);
	}
	/*bt.inoreder(root);
	node *p = bt.leftmost(root);
	cout<<p->data;
	*/
			cout<<bt.leftmost(root)->right->data;

}




node *node ::createNode(int value)
{
	node* newNode = new node;
	newNode->data = value;
	newNode->left=NULL;
	newNode->right =NULL;
	newNode->lthread = 1;
	newNode->rthread = 1;
	return newNode;

}

void node :: insert(int value)
{
	node *newNode = createNode(value);
	
	if(root==NULL)
	{
		
		root = newNode;
		dummy->left = root;
		//dummy->data =(-999);
		dummy->right = dummy;
		root->left=dummy;
		root->right = dummy;
		
	}
	else
	{
		node *temp = root;
		node *parent=NULL;
		while()//temp!=dummy&&temp->right!=parent
		{
			parent = temp;
			if(value < temp->data)
			{
				temp = temp ->left;

			}
			else if(value > temp->data)
			{
				temp=temp->right;
			}
		}
		cout<<parent->data<<endl;
	if(value < parent->data&&parent->lthread == 1)
	{
		
		
			newNode->left=parent->left;
			newNode->right = parent;
			parent->left = newNode;
			parent->lthread= 0;
		
	}
	
		else if(value > parent->data&&parent->rthread==1)
		{
			
				newNode->right =parent->right;
				newNode->left=parent;
				parent->right  =newNode;
				parent->rthread =0;
			
		}
	
		
	}
	
}

void node ::inoreder(node *Root)
{
	node *temp = leftmost(Root);
		while(temp!=dummy)
		{
			if(temp->rthread==1)
			{
				cout<<temp->data;
				temp =temp->right;
				cout<<temp->data;
			}
			else
			{
				if(temp->rthread==0)
				{
					temp =leftmost(temp->right);
					if(temp->lthread==1&&temp->rthread==1)
					{
						cout<<temp->data;
						temp  = temp->right;
					}
				}
			}
		}
}

node *node ::leftmost(node *Root)
{
	node *temp = Root,*tp = NULL;
	if(temp==dummy)
		return 0;
	else
	{
	 while(temp!= dummy)
	 {
	 	tp = temp;
	 	temp =temp->left;
	 }
	 return tp;
	}
}