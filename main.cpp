// A simple representation of graph using STL
#include <iostream>
#include <vector>
using namespace std;

void generateGraph(), adjList(), adjMatrix();
void choice(int i);
 
// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }

	//this part just forces the program to wait on you, push q to leave
	char answer;
	cin >> answer;
	if(answer == 'q') {

		cout << "yep" << endl;
	}
		
}

void menu() {
    int input;
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Generate Graph\n"
         << "2 - View Adjacency List\n"
         << "3 - View Adjacency Matrix\n"
		 << "4 - View Adjacency Matrix\n";
    cout << "Enter a menu option: ";
    cin >> input;
    cin.ignore();
    cout << endl;
    choice(input);
}

void returnMenu() {
    char input;
    cout << "Return to Main Menu? (y/n)\n";
    cin >> input;
    cout << endl;
    while (input) {
        switch (input) {
            case 'y':
                menu();
                break;

            case 'n':
                break;

            default:
                cout << "Invalid Input. Returning to main menu.\n";
                menu();
        }
        break;
    }
}

void choice(int input) {
    while (input) {
        switch (input) {
            case 1:
                generateGraph();
                returnMenu();
                break;
            case 2:
                adjList();
                returnMenu();
                break;
            case 3:
                adjMatrix();
                returnMenu();
                break;
            case 4:
                exit(1);
            default:
                cout << "Invalid Menu Option. Please enter new option: ";
                cin >> input;
                choice(input);
                cin.ignore();
                break;
        }
    }
}

void generateGraph() {
}

void adjList() {
	vector <int> adj[10];

	 int x, y, nodes, edges;
        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
        for(int i = 0;i < edges;++i)
        {
                cin >> x >> y;
            adj[x].push_back(y);        //Insert y in adjacency list of x
         }
    for(int i = 1;i <= nodes;++i)
    {   
            cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
            {
            if(j == adj[i].size() - 1)
                    cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
    }
    }
    
	int input;
		cout << "9 to exit" << endl;
		cin >> input;
		if (input == 9) {
		}

}

void adjMatrix() {

	bool A[10][10];

	int x, y, nodes, edges;
        
		for(int i = 0;i < 10;++i)
            for(int j = 0;j < 10;++j)
                A[i][j] = false;

        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            A[x][y] = true;     //Mark the edges from vertex x to vertex y
       }

		for(int i = 0;i < 10;++i) {
            for(int j = 0;j < 10;++j) {

				if(i || j == 10) {
				
					cout << "/n";
				}
                cout << A[i][j];
			}
		}
		int input;
		cout << "9 to exit" << endl;
		cin >> input;
		if (input == 9) {
		}
     
	}
 
// Driver code
int main()
{

//	menu();
	//adjMatrix();

	//adjList();

    return 0;
}
