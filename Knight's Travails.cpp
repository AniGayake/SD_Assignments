#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


// queue node used in BFS
struct Node
{
	// (x, y) represents coordinates of a cell in matrix
	int x, y;

	// path stores complete path from source cell to cell (x, y)
	vector<pair<int, int>> path;

	// As we are using struct as a key in a std::map,
	// we need to overload below operators

	bool const operator==(const Node& ob) const
	{
		return x == ob.x && y == ob.y;
	}

	bool operator<(const Node& ob) const
	{
		return x < ob.x || (x == ob.x && y < ob.y);
	}
};

// Below arrays details all 4 possible movements from a cell
int row[] =  {-2, -1, 1, 2, -2, -1, 1, 2};
int col[]= {-1, -2, -2, -1, 1, 2, 2, 1};


// The function returns false if pt is not a valid position
bool isValid(int x, int y,int N)
{
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

// Function to print the complete path from source to destination
void printPath(int x,int y,vector<pair<int, int>> path)
{
	cout << "Destination Found.\n";
	cout<<"The path that the Knight will travel is :\t";
	cout<<"("<< x<<", "<<y<<")";
	for (pair<int, int> p: path)
		cout << " -->(" << p.first << ", " << p.second << ")";
	cout << '\n';
}

// Find shortest route in the matrix from source cell (x, y) to
// destination cell (p,q)
int findPath(int N, int x, int y,int p,int q)
{
	vector<pair<int, int>> path;
	//path.push_back({x, y});

	// create a queue and enqueue first node
	queue<Node> Q;
	Node src = {x, y, path};
	Q.push(src);

	// map to check if matrix cell is visited before or not
	map<Node, bool> visited;
	visited[src] = true;

	// run till queue is not empty
	while (!Q.empty())
	{
		// pop front node from queue and process it
		Node curr = Q.front();
		Q.pop();

		int i = curr.x, j = curr.y;
		path = curr.path;

		// if destination is found, return true
		if (i == p && j == q)
		{
			printPath(x,y,path);
			return path.size();
		}

		// value of current cell


		// check all 8 possible movements from current cell
		// and recurse for each valid movement
		for (int k = 0; k < 8; k++)
		{
			// get next position coordinates using value of current cell
			int x = i + row[k] ;
			int y = j + col[k] ;

			// check if it is possible to go to next position
			// from current position
			if (isValid(x, y,N))
			{
				// include next vertex in the path
				path.push_back({x, y});

				// construct next cell node
				Node next = {x, y, path};

				if (!visited.count(next))
				{
					Q.push(next);
					visited[next] = true;
				}

				// exclude next vertex in the path
				path.pop_back();
			}
		}
	}

	// return INFINITY if path is not possible
	return INT_MAX;
}

// main function
int main()
{
    int a,b,p,q;
	int N ;
	cout<<"Enter the dimensions of the chessboard :\n";
	cin>>N;
	cout<<"Enter the starting position of the Knight :\n";
	cin>>a;
	cin>>b;
	if(a>=N||a<0||b>=N||b<0)
    {
        cout<<"Enter the correct starting position .";
        return 0;
    }
    cout<<"Enter the ending position of the Knight :\n";
	cin>>p;
	cin>>q;
    if(p>=N||p<0||q>=N||q<0)
    {
        cout<<"Enter the correct ending position .";
        return 0;
    }
    int len = findPath(N,a,b,p,q);

    cout <<"The Knight will travel from position ("<<a<<" , "<<b<<") to position ("<<p<<" , "<<q<<") in "<<len <<" steps.";
	return 0;
	if (len != INT_MAX)
		cout << "Shortest Path length is " << len;

	return 0;
}
