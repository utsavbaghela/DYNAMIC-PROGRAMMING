
#include <iostream>
using namespace std;
class node{
public:
	int data;
	node*left,*right;
	node (int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
pair <int,int> maxsumhelper(node* root)
{
	if(root==NULL)
		{
		pair <int ,int> sum(0,0);
		return sum;
		}
	pair<int,int> sum1=maxsumhelper(root->left);
	pair<int,int> sum2=maxsumhelper(root->right);
	pair<int,int> sum;

	sum.first=sum1.second +  sum2.second   +   root->data;
	sum.second=max(sum1.first,sum1.second)+max(sum2.first,sum2.second);

	return sum;
}

int maxsum(node* root)
{
	pair<int,int> res=maxsumhelper(root);
	return max(res.first,res.second);
}


int main()
{
	node *root= new node(10);
	root->left= new node(1);
	root->left->left= new node(2);
	root->left->left->left= new node(1);
	root->left->right= new node(3);
	root->left->right->left= new node(4);
	root->left->right->right= new node(5);
	cout<<maxsum(root);
	return 0;
}



