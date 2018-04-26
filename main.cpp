// A simple representation of graph using STL
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<list>
using namespace std;

void generateGraph(), adjList(), adjMatrix();
void choice(int i);
 
class adjMatGraph {
private:
      bool** adjMatrix;
      int numVertices;
public:
      adjMatGraph(int numVertices) {
            this->numVertices = numVertices;
            adjMatrix = new bool*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                  adjMatrix[i] = new bool[numVertices];
                  for (int j = 0; j < numVertices; j++)
                        adjMatrix[i][j] = false;
          }
    }
 
      void addEdge(int i, int j) {
                  adjMatrix[i][j] = true;
                  adjMatrix[j][i] = true;
    }
 
      void removeEdge(int i, int j) {
                  adjMatrix[i][j] = false;
                  adjMatrix[j][i] = false;
    }
 
      bool isEdge(int i, int j) {
                  return adjMatrix[i][j];
    }

    void toString() {
      for (int i = 0; i < numVertices; i++) {
                  cout << i << " : ";
                  for (int j = 0; j < numVertices; j++)
                        cout << adjMatrix[i][j] << " ";
                  cout << "\n";
      }

    }
 
    ~adjMatGraph() {
            for (int i = 0; i < numVertices; i++)
                  delete[] adjMatrix[i];
            delete[] adjMatrix;
    }
};


struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
/*
 * Adjacency List
 */  
struct AdjList
{
    struct AdjListNode *head;
};
 
/*
 * Class Graph
 */ 
class adjListGraph
{
    private:
        int V;

        struct AdjList* array;
		
    public:

        adjListGraph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        }
        /*
         * Creating New Adjacency List Node
         */ 
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
        /*
         * Adding Edge to Graph
         */ 
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        /*
         * Print the graph
         */ 
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }


};



class DFSGraph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
 
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    DFSGraph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 


DFSGraph::DFSGraph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void DFSGraph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void DFSGraph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void DFSGraph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}


void menu() {
    int input;
    cout << "*CSC 332*\n"
         << "*MENU OPTIONS*\n\n";
    cout << "1 - Generate Graph\n"
         << "2 - View Adjacency List\n"
         << "3 - View Adjacency Matrix\n"
		 << "4 - View DFS\n";
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
				DFS();
                //exit(1);
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

	int vertNum;
	cout << "Enter number of Vertices: ";
	cin >> vertNum;

	
	int** arr = new int*[vertNum];

	

	cout << "Enter edges:" << endl;
	cout << "Enter q to quit" << endl;

	int vert1;
	int vert2;

	cin >> vert1;
	cin >> vert2;

	for(int i = 0; i < vertNum; ++i) {
    
		arr[vert1][vert2];

	}

	int quit;
	cin >> quit;
	if(quit == 9) {
	}

}

void adjList() {

	adjListGraph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

 
    // print the adjacency list representation of the above graph
    gh.printGraph();

	int input;
		cout << "9 to exit" << endl;
		cin >> input;
		if (input == 9) {
		}
	
}

void adjMatrix() {

	  adjMatGraph g(4);
 
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);

        g.toString();
        /* Outputs
           0: 0 1 1 0 
           1: 1 0 1 0 
           2: 1 1 0 1 
           3: 0 0 1 0 
          */

		int input;
		cout << "9 to exit" << endl;
		cin >> input;
		if (input == 9) {
		}

	
     
}

void DFS() {

    DFSGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex given) \n";

	cout << "Enter the node you want to start with" << endl;

	int start;

	cin >> start;

    g.DFS(start);

}
 
// Driver code
int main()
{

	menu();

    return 0;
}
