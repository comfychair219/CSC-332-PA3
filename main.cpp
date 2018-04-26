// A simple representation of graph using STL
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void generateGraph(), adjList(), adjMatrix();
void choice(int i);
 
struct vertex {
    typedef pair<int, vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    string name;
    vertex(string s) : name(s) {}
};

class graph
{
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addvertex(const string&);
    void addedge(const string& from, const string& to, double cost);
};



void graph::addvertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double cost)
{
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
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
	graph usrgraph;

	usrgraph.addvertex("vert1");

	usrgraph.addvertex("vert2");

	usrgraph.addedge("vert1", "vert2", 2); //2 vertices connected by an edge of weight 2
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
