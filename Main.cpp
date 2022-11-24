#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> names{"yash","sid","reema","vinit"};
vector<ll> contacts{7709660260,7887439040,9657485942,8446152560};
vector<ll> freq{4,2,6,3};
ll cost[10000][10000];
ll order[10000][10000];
ll root[10000];

//Defining Node
class Node {
public:
    ll val;
    string name;
    Node* left;
    Node* right;
    Node(ll val,string name){
        this->val=val;
        this->name=name;
        left=NULL;
        right=NULL;
    }
};

//Searching key by Number and if not found, returning 0.
int SearchingByNumber(Node* RootNode,ll key,int lvl){
    if(RootNode == NULL){
        return 0;
    }
    if(RootNode->val==key){
        return lvl;
    }
    int nextlvl=SearchingByNumber(RootNode->left,key,lvl+1); 
    if(nextlvl !=0){
        return nextlvl;
    }
    nextlvl=SearchingByNumber(RootNode->right,key,lvl+1); 
    return nextlvl;
    
}

//Searching key by Name and if not found, returning 0.
int SearchingByName(Node* RootNode,string FindName,int lvl){
    if(RootNode == NULL){
        return 0;
    }
    if(RootNode->name==FindName){
        return lvl; 
    }
    int nextlvl=SearchingByName(RootNode->left,FindName,lvl+1); 
    if(nextlvl !=0){
        return nextlvl;
    }
    nextlvl=SearchingByName(RootNode->right,FindName,lvl+1); 
    return nextlvl;
    
}


// printing the node at current level
void printCurrentLevel(Node* RootNode, int level)
{
    if (RootNode == NULL){
        cout<<"NULL  ";
        return;
    }
    if (level == 1)
        cout << RootNode->val << "|"<<RootNode->name<<"  ";
    else if (level > 1) {
        printCurrentLevel(RootNode->left, level - 1);
        printCurrentLevel(RootNode->right, level - 1);
    }
}

//Calculating height of tree
int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        //computing height of left subtree and right subtree.
        int lheight = height(node->left);
        int rheight = height(node->right);

        //returning the greater one.
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

/* Function to print level order of Tree. It calls function printCurrentLevel
to print nodes at each level.*/
void printLevelOrder(Node* RootNode)
{
    int h = height(RootNode);
    int i;
    for (i = 1; i <= h; i++){
        printCurrentLevel(RootNode, i);
        cout<<"\n";
    }
}

//Function to calculate sum of frequencies from ith key to jth key.
ll sum(int i, int j)
{
	ll s = 0;
	for (int k = i; k < j; k++)
	s += freq[k];
	return s;
}

//Function that creates the OBS-tree using order and contacts array.
Node* MakeTree(Node* RootNode,int index,int i1,int i2){

    //Base condition
	if(i1==i2 || order[i1][i2]==0){
        Node* node = NULL;
		return node;
	}
    //storing the contacts according to order array in new Node. 
    Node* NewNode=new Node(contacts[order[i1][i2] -1 ], names[order[i1][i2] -1] );
    RootNode=NewNode;

    //storing the root at particular index
    root[index]=order[i1][i2]; 

    //Recursive call to left and right node
	RootNode->left= MakeTree(RootNode->left,2*index+1, i1 , root[index]-1 );
	RootNode->right=MakeTree(RootNode->right,2*index+2, root[index] , i2);
	return RootNode;
}

//Function that calculate cost matrix and Order matrix.
int optimalSearchTree(Node*& RootNode, int n)
{

    for (int i = 0; i < n; i++)
	{
        //Cost of Single Node is 0
        cost[i][i] =0;

        //storing freq in [i][i+1] index
        if(i+1<n){
            cost[i][i+1]=freq[i];
			order[i][i+1]=i+1;
		}

    }
    //L=number of nodes for which cost is being calculated.
	for (int L = 2; L < n; L++)
	{       
		for (int i = 0; i < n-L; i++)
		{   
            //finding appropriate column
			int j = i+L;
			cost[i][j] = INT_MAX;
			ll off_set_sum = sum(i, j);

            //Finding minimun cost for different root
			for (int r = i; r < j; r++)
			{
                ll c = ((r > i)? cost[i][r]:0) +
                        ((r < j)? cost[r+1][j]:0) +
                        off_set_sum;
						
				if (c < cost[i][j])
				{
					cost[i][j] = c;
                	order[i][j]=r+1;    //storing the root for minimum cost   
				}
			}
		}
	}
    //Call MakeTree to create tree
    RootNode=MakeTree(RootNode,0,0,n-1);

    //cost[0][n-1] represent minimum cost of OBST.
	return cost[0][n-1];
}


int main()
{
    ll choice,data,option;
    int temp;
    string FindName;

	int n = contacts.size() + 1;
	Node* RootNode = NULL;
    /*Calling optimalSearchTree function to calculate 'cost' and 'order' matrix
    for already stored elements in 'contacts' array*/
    optimalSearchTree(RootNode, n);

    cout<<"\n---WELCOME TO PHONE BOOK---\n";
    cout<<"\nOBST :\n\n";
    printLevelOrder(RootNode);
    while(true)
    {
        cout<<"\nChoose:\n";
        cout<<"\n1.Call Someone\n2.Create New Contact\n3.Print Tree\n4.Print cost and order matrix\n5.Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Choose:\n1.Call using Name\n";
                cout<<"2.Call using Number\n";
                cin>>option;

                //Searching key by Name and then incrementing frequency of that key.
                if(option==1)
                {
                    cout<<"\nEnter Name\n";
                    cin>>FindName;
    
                    //converting FindName to lowercase
                    transform(FindName.begin(), FindName.end(), FindName.begin(), ::tolower);
                    temp=SearchingByName(RootNode, FindName,1);
                    if(temp!=0)
                    {
                        cout<<"\nSuccessfully Called '"<<FindName<<"' !\n";
                        cout<<"Person '"<<FindName<<"' is found at level "<<temp<<endl;
                        int it = std::find(contacts.begin(), contacts.end(), data)-contacts.begin();
                        freq[it]++;
                        
                        RootNode=NULL;
                        optimalSearchTree(RootNode, n);
                    }
                    else{
                        cout<<FindName<<" cannot be found "<<endl;
                    }
                }
                //Searching key by Number and then incrementing frequency of that key.
                else if(option==2)
                {
                    cout<<"\nEnter Number\n";
                    cin>>data;
                    temp=SearchingByNumber(RootNode,data,1);
                    if(temp!=0)
                    {
                        cout<<"\nSuccessfully Called '"<<data<<"' !\n";
                        cout<<"Contact number '"<<data<<"' is found at level "<<temp<<endl;
                        int it = std::find(contacts.begin(), contacts.end(), data)-contacts.begin();
                        freq[it]++;
                        RootNode=NULL;
                        optimalSearchTree(RootNode, n);
                    }
                    else{
                        cout<<"Contact number "<<data<<" is not found "<<endl;
                    }
                }
                cout<<endl;
                break;

            case 2:
                cout<<"Creating new contact\n";
                cout<<"Enter the Name and Number of person you want to create\n";
                cin>>FindName;
                cin>>data;
                transform(FindName.begin(), FindName.end(), FindName.begin(), ::tolower);
                /*Appending the new values in names,contact,freq array and 
                calling optimalSearchTree() again for making new OBST*/
                names.push_back(FindName);
                contacts.push_back(data);
                freq.push_back(1);
                
                n=contacts.size()+1;
                RootNode=NULL;
                cout<<"Cost of New OBST: "<<optimalSearchTree(RootNode, n);
                break;
            case 3:
                
                cout<<"\nPrinting Optimal Binary Search Tree: \n\n";
                printLevelOrder(RootNode);
                cout<<"Cost of OBST: "<<optimalSearchTree(RootNode, n);
                break;
            case 4:
                //The commented code prints the cost and order matrix

                
                cout<<"\nCost Matrix:\n";
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++){
                        if(j<i)
                            cout<<"* ";
                        else
                            cout<<cost[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                cout<<"\n";
                cout<<"Matrix that store roots between ith to jth key: \n";
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(j<i)
                            cout<<"* ";
                        else
                            cout<<order[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                
                break;
            case 5:
                exit(0);

        }
    }
	
	return 0;
}
