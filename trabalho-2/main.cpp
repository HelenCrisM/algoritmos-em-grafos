#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem, destino, peso;

    // Operador para ordenar as arestas por peso
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

// Função para inicializar um conjunto com um elemento
void makeSet(vector<int>& pai, vector<int>& rank, int v) {
    pai[v] = v;
    rank[v] = 0;
}

// Função para encontrar o conjunto ao qual um elemento pertence (usando compressão de caminho)
int findSet(vector<int>& pai, int v) {
    if (pai[v] != v) {
        pai[v] = findSet(pai, pai[v]);
    }
    return pai[v];
}

// Função para unir dois conjuntos
void unionSets(vector<int>& pai, vector<int>& rank, int u, int v) {
    int raizU = findSet(pai, u);
    int raizV = findSet(pai, v);

    if (raizU != raizV) {
        if (rank[raizU] < rank[raizV]) {
            pai[raizU] = raizV;
        } else if (rank[raizU] > rank[raizV]) {
            pai[raizV] = raizU;
        } else {
            pai[raizV] = raizU;
            rank[raizU]++;
        }
    }
}

// Função que implementa o algoritmo de Kruskal
void mstKruskal(int numVertices, int numArestas, vector<Aresta>& arestas) {
    vector<Aresta> A; // Conjunto de arestas da AGM
    vector<int> pai(numVertices); // Vetor para armazenar os pais dos conjuntos
    vector<int> rank(numVertices); // Vetor para armazenar a altura das árvores

    // Inicializa os conjuntos
    for (int v = 0; v < numVertices; ++v) {
        makeSet(pai, rank, v);
    }

    // Ordena as arestas pelo peso
    sort(arestas.begin(), arestas.end());

    // Processa cada aresta em ordem crescente de peso
    for (const auto& aresta : arestas) {
        if (findSet(pai, aresta.origem) != findSet(pai, aresta.destino)) {
            A.push_back(aresta); // Adiciona a aresta à árvore geradora mínima
            unionSets(pai, rank, aresta.origem, aresta.destino); // Une os conjuntos
        }
    }

    // Calcula o peso total da árvore geradora mínima
    int pesoTotal = 0;
    for (const auto& aresta : A) {
        pesoTotal += aresta.peso;
    }

    // Imprime as arestas da árvore geradora mínima e o peso total
    cout << "Arestas da Árvore Geradora Mínima:\n";
    for (const auto& aresta : A) {
        cout << aresta.origem << " -- " << aresta.destino << " == " << aresta.peso << endl;
    }
    cout << "Peso total da AGM: " << pesoTotal << endl;
}

int main() {
    int numVertices, numArestas;

    // Entrada: número de vértices e arestas
    cout << "Digite o número de vértices: ";
    cin >> numVertices;
    cout << "Digite o número de arestas: ";
    cin >> numArestas;

    vector<Aresta> arestas(numArestas);

    // Entrada: as arestas no formato (origem, destino, peso)
    cout << "Digite as arestas no formato (origem destino peso):\n";
    for (int i = 0; i < numArestas; ++i) {
        cin >> arestas[i].origem >> arestas[i].destino >> arestas[i].peso;
    }

    // Entrada do vértice inicial (não utilizado no algoritmo de Kruskal)
    int verticeInicial;
    cout << "Digite o vértice inicial (não utilizado no algoritmo de Kruskal): ";
    cin >> verticeInicial;

    // Chama a função que implementa o algoritmo de Kruskal
    mstKruskal(numVertices, numArestas, arestas);

    return 0;
}