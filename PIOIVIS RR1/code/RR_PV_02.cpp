#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Selection of file with graph
string tests(int num) {
    string path;
    switch (num) {
    case 1: { path = "graph1.txt"; }
          break;
    case 2: { path = "graph2.txt"; }
          break;
    case 3: { path = "graph3.txt"; }
          break;
    case 4: { path = "graph4.txt"; }
          break;
    case 5: { path = "graph5.txt"; }
          break;
    default: cout << "Input error";
    }
    return path;
}

// Convertor from incidence_list into adjacency_list
void convertor(int size, vector <vector<int> >& adjacency_list, vector <vector<int> >& incidence_list) {
    for (size_t i = 0; i < size; i++) {
        adjacency_list.push_back(vector<int>());
        adjacency_list[i].push_back(incidence_list[i][0]);
        for (size_t j = 1; j < incidence_list[i].size(); j++) {
            for (size_t k = 0; k < size; k++) {
                for (size_t m = 1; m < incidence_list[k].size(); m++) {
                    if (i == k && j == m)
                        continue;
                    else {
                        if (incidence_list[i][j] == incidence_list[k][m])
                            adjacency_list[i].push_back(incidence_list[k][0]);
                    }
                }
            }
        }
    }
    cout << "\nAdjacency list:\n";
    for (size_t i = 0; i < adjacency_list.size(); i++) {
        for (size_t j = 0; j < adjacency_list[i].size(); j++) {
            cout << adjacency_list[i][j] << " ";
        }
        cout << "\n";
    }
}

// Getting graph from a file
void graph_into_incidence_list(vector <vector<int> >& incidence_list, vector<vector<int>>& adjacency_list, string& path, int& size) {
    ifstream file(path);
    string s;
    getline(file, s);
    size = stoi(s);
    for (size_t i = 0; i < size; i++) {
        incidence_list.push_back(vector<int>());
        getline(file, s);
        string tmp;
        for (char j : s) {
            if (j != ' ') {
                tmp += j;
            }
            else {
                incidence_list[i].push_back(stoi(tmp));
                tmp = "";
            }
        }
        incidence_list[i].push_back(stoi(tmp));
    }
    file.close();
    cout << "\nIncidence list:\n";
    for (size_t i = 0; i < incidence_list.size(); i++) {
        for (size_t j = 0; j < incidence_list[i].size(); j++) {
            cout << incidence_list[i][j] << " ";
        }
        cout << "\n";
    }
    convertor(size, adjacency_list, incidence_list);
}

//Deep-first search with vertex coloring(for duplicity checkout)
void dfs(int v, int &q, vector <vector<int> >& adjacency_list, vector <bool>& used, vector<int>& color)
{
    used.at(v) = true;
    if (q == 0) { 
        color.at(v) = 0;
        q++;
    }
    else {
        color.at(v) = 1;
        q = 0;
    }
    for (size_t i = 1; i < adjacency_list[v].size(); i++)
        if (!used.at(adjacency_list[v].at(i) - 1)) {
            dfs(adjacency_list[v].at(i) - 1, q, adjacency_list, used, color);

        }
}

//Checking if a graph is a Pappus graph
int graph_checkout(vector<vector<int>>& adjacency_list, int& size) {
    //Чей папа?
    vector<int> color;
    color.assign(size, 0);
    if (size != 18) {                                              //Checkout for number of vertices
        cout << "\nIt isn't graph Papppa\n";
    }
    else {
        int q = 0;
        for (size_t i = 0; i < adjacency_list.size(); i++)
            if (adjacency_list[i].size() != 4) {                   //Vertex degree checkout + Checkout for the number of edges
                cout << "\nIt isn't graph Papppa\n";
                return 0;
            }
            else {
                for (size_t j = 1; j < adjacency_list[i].size(); j++) {
                    if (adjacency_list[i][j] == adjacency_list[i][0]) {               //Loop checkout
                        cout << "\nIt isn't graph Papppa\n";
                        return 0;
                    }
                }
            }
        vector <bool> used;
        used.assign(size, false);
        for (size_t i = 0; i < adjacency_list.size(); i++) {
            if (!used.at(i)) {
                dfs(i, q, adjacency_list, used, color);            //Deep-first search with vertex coloring(for duplicity checkout)
            }
        }
        for (size_t i = 0; i < adjacency_list.size(); i++) {
            for (size_t j = 1; j < adjacency_list[i].size(); j++) {
                if (color.at(i) == color[adjacency_list[i][j] - 1]) {                 //Duplicity checkout
                    cout << "\nIt isn't graph Papppa\n";
                    return 0;
                }
            }
        }
        cout << "\nIt is graph Papppa\n";
    }
    return 0;
}

int main()
{
    int size = 0, num = 0;
    vector <vector<int> > adjacency_list;
    vector <vector<int> > incidence_list;
    string s;
    cout << "Choose graph(from 1 to 5): \n";
    cin >> num;
    string path = tests(num);
    graph_into_incidence_list(incidence_list, adjacency_list, path, size);
    graph_checkout(adjacency_list, size);
    return 0;
}
