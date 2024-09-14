#include <iostream>
#include <vector>
#include <queue> //fila

#define N_MAX 1000
#define INF   1000000 // infinito

using namespace std;

vector<int> G[N_MAX]; // Grafo (Lista de Adjacencia)
bool visitado[N_MAX];
int dist[N_MAX]; // diatancia

int n; // Quantidade de vertices
int m; // Quantidade de arestas

void BuscaEmLargura(int s){
    for(int u = 0; u < n; u++){
        visitado[u] = false;
        dist[u] = INF;
    }
    queue<int> Fila; // criaçao da fila
    visitado[s] = true;
    dist[s] = 0;
    Fila.push(s);
    while(Fila.empty() == false){
        int u = Fila.front(); // pega o primeiro item da fila

        cout << "v" << u << endl;
        cout << "dist[" << u << "] = " << dist[u] << endl;

        Fila.pop(); // remove o primeiro item da fila
        for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                if(visitado[v] == false){
                    visitado[v] = true;
                    dist[v] = dist[u] + 1;
                    Fila.push(v);
                }
            }
    }
    
    bool conexo = true;
    for(int i = 0; i < n; i++){
        if(visitado[i] == false){
            conexo = false;
        }
    }
    
    if(conexo == true){
        cout << "Grafo conexo" << endl;
    }else{
        cout << "Grafo nao conexo" << endl;
    }
}

int main(){
    /*
    n = 7; // inicia a quantidade de vertices
    
    // Criar grafo
    
    G[0].push_back(1);
    G[0].push_back(2);
    G[1].push_back(0);
    G[1].push_back(3);
    G[2].push_back(0);
    G[2].push_back(3);
    G[2].push_back(4);
    G[3].push_back(1);
    G[3].push_back(2);
    G[3].push_back(4);
    G[4].push_back(2);
    G[4].push_back(3);
    
    G[5].push_back(6);
    G[6].push_back(5);
    */
    
    cout << "Digite a quantidade de vertices: ";
    cin >> n;
    cout << "Digite a quantidade de arestas: ";
    cin >> m;
    
    int u, v;
    for(int i = 0; i < m; i++){
        cout << "Digite a aresta " << i + 1 << ": ";
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int s;
    
    cout << "Digite o vertice inicial: ";
    cin >> s;
    
    // Fazer a busca
    
    BuscaEmLargura(s);    
    
    return 0;
}