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
	void display(node *);
	node *next_inorder(node *);
	

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
	//bt.inoreder(root);
	//node *p = bt.leftmost(root->right);
	//cout<<p->data;
	bt.display(root);
		//	cout<<bt.leftmost(root)->right->data;

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
		while(temp!=dummy)//temp!=dummy&&temp->right!=parent
		{
			parent = temp;
			if(value < temp->data)
			{
				if(temp->lthread==0)
				{
					temp = temp ->left;
				}else
				break;

			}
			else if(value > temp->data)
			{
				if(temp->rthread==0)
				{
					temp=temp->right;
				}
				else
					break;
			}
		}
	//	cout<<parent->data<<endl;
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

/*void node ::inoreder(node *Root)
{
	node *temp ,*Troot =Root;
	temp = leftmost(Troot);
	while(true)
	{
		cout<<temp->data<<endl;
		if(temp->right==dummy)
			break;
		temp =temp->right;
		if(temp->rthread)
			temp =temp->right;
		if(!temp->lthread)
		{
			temp= leftmost(temp->right);
		}	
		
	}
}
*/

node *node ::leftmost(node *Root)
{
	node *temp = Root;
	while(!temp->lthread)
	{
		temp=temp->left;
	}
	return temp;
}
void node :: display(node* r)
{
	if(r == NULL)
	{
		cout<<"\n********No Tree present*********\n";
		return;
	}
	node *cur = r;
	while(cur->left != dummy)
			cur = cur->left;
		
	cout<<"\nInorder traversal using Threads : ";	
	while(true)
	{
		cout<<cur->data<<"\t";
		if(cur->right == dummy)	
			break;
		cur = next_inorder(cur);
	}
	cout<<endl;
}

node* node :: next_inorder(node *r)
{
    //sends the next inorder node
	if(r->rthread)
		return r->right;
	
	r = r->right;
	while(!r->lthread)
	{
		r = r->left;
	}	
	return r;
}
