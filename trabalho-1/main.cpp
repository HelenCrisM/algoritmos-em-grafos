#include <iostream>
#include <vector>
#include <stack>   
#include <limits> 

using namespace std;

void buscaEmProfundidade(int verticeInicial, vector<vector<int>>& listaDeAdjacencia, vector<bool>& visitado, vector<int>& distanciaDosVertices) {
    stack<int> Pilha;
    
    visitado[verticeInicial] = false;
    distanciaDosVertices[verticeInicial] = 0;
    Pilha.push(verticeInicial);
    
    while (!Pilha.empty()) {
        int u = Pilha.top();  
        Pilha.pop();       
        
        for (int v : listaDeAdjacencia[u]) {
            if (!visitado[v]) {
                visitado[v] = true;       
                distanciaDosVertices[v] = distanciaDosVertices[u] + 1;   
                Pilha.push(v);           
            }
        }
    }
}

int main() {
    int numVertices, numArestas, verticeInicial;
    cout << "Informe o número de vértices: ";
    cin >> numVertices;
    cout << "Informe o número de arestas: ";
    cin >> numArestas;
    
    vector<vector<int>> listaDeAdjacencia(numVertices + 1);
    
    cout << "Informe as arestas direcionadas (formato: u v):" << endl;
    for (int i = 0; i < numArestas; i++) {
        int u, v;
        cin >> u >> v;
        listaDeAdjacencia[u].push_back(v);  
    }
    
    cout << "Informe o vértice inicial: ";
    cin >> verticeInicial;
    
    vector<bool> visitado(numVertices + 1, false);
    
    vector<int> distanciaDosVertices(numVertices + 1, numeric_limits<int>::max());
    
    buscaEmProfundidade(verticeInicial, listaDeAdjacencia, visitado, distanciaDosVertices);
    
    bool isConexo = true;
    for (int i = 1; i <= numVertices; i++) {
        if (!visitado[i]) {
            isConexo = false;
            break;
        }
    }
    
    if (isConexo) {
        cout << "O grafo é conexo." << endl;
    } else {
        cout << "O grafo não é conexo." << endl;
    }

    return 0;
}
