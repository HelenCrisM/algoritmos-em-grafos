#include <iostream>
#include <vector>

using namespace std;

#define N 6 // Numero de vertices
#define M 7 // Numero de arestas

int A[N][N]; // Matriz de adjacencia
int I[N][M]; // Matriz de incidencia
vector<int> L[N]; // Lista de adjacencia

// Retorna o grau do vertice utilizando matriz de adjacencia
int grauMatrizAdjacencia(int u) {
    int soma = 0;
    for(int i = 0; i < N; i++){
        soma = soma + A[u][i];
    }
    return soma;
}

// Retorna o grau do vertice utilizando matriz de incidencia
int grauMatrizIncidencia(int u) {
    int soma = 0;
    for(int i = 0; i < M; i++){
        soma = soma + I[u][i];
    }
    return soma;
}

// Retorna o grau do vertice utilizando lista de adjacencia
int grauListaAdjacencia(int u) {
    return L[u].size();
}

// Imprime a vizinhança do vertice usando matriz de adjacencia
void imprimeVizinhosMatrizAdjacencia(int u) {
    for(int i = 0; i < N; i++){
        if(A[u][i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
}

// Imprime a vizinhança do vertice usando matriz de incidencia
void imprimeVizinhosMatrizIncidencia(int u) {
    for(int i = 0; i < M; i++){
        if(I[u][i] == 1){
            for(int j = 0; j < N; j++){
                if(I[j][i] == 1 && j != u){
                    cout << j << " ";
                }
            }
        }
    }
    cout << endl;
}

// Imprime a vizinhança do vertice usando lista de adjacencia
void imprimeVizinhosListaAdjacencia(int u) {
    for(int i = 0; i < L[u].size(); i++){
        cout << L[u][i] << " ";    
    }
    cout << endl;
}

// Retorna 1 se os vertices sao adjacentes e 0 caso contrario (Matriz de Adjacencia)
int adjacenteMatrizAdjacencia(int u, int v) {
    return A[u][v];
}

// Retorna 1 se os vertices sao adjacentes e 0 caso contrario (Matriz de Incidencia)
int adjacenteMatrizIncidencia(int u, int v) {
    for(int i = 0; i < M; i++){
        if(I[u][i] == 1 && I[v][i] == 1){
            return 1;
        }
    }
    return 0;
}

// Retorna 1 se os vertices sao adjacentes e 0 caso contrario (Lista de Adjacencia)
int adjacenteListadeAjacencia(int u, int v) {
    for(int i = 0; i < L[u].size(); i++){
        if(L[u][i] == v){
            return 1;
        }
    }
    return 0;
}

void menu() {
    int opcao, u, v;
    do{
        cout << "\nMenu:\n";
        cout << "1. Grau do vertice (Matriz de Adjacencia)\n";
        cout << "2. Grau do vertice (Matriz de Incidencia)\n";
        cout << "3. Grau do vertice (Lista de Adjacencia)\n";
        cout << "4. Imprimir vizinhos (Matriz de Adjacencia)\n";
        cout << "5. Imprimir vizinhos (Matriz de Incidencia)\n";
        cout << "6. Imprimir vizinhos (Lista de Adjacencia)\n";
        cout << "7. Verificar adjacencia (Matriz de Adjacencia)\n";
        cout << "8. Verificar adjacencia (Matriz de Incidencia)\n";
        cout << "9. Verificar adjacencia (Lista de Adjacencia)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao){
            case 1:
                cout << "Digite o vertice: ";
                cin >> u;
                cout << "Grau do vertice " << u << " (Matriz de Adjacencia): " << grauMatrizAdjacencia(u) << endl;
                break;
            case 2:
                cout << "Digite o vertice: ";
                cin >> u;
                cout << "Grau do vertice " << u << " (Matriz de Incidencia): " << grauMatrizIncidencia(u) << endl;
                break;
            case 3:
                cout << "Digite o vertice: ";
                cin >> u;
                cout << "Grau do vertice " << u << " (Lista de Adjacencia): " << grauListaAdjacencia(u) << endl;
                break;
            case 4:
                cout << "Digite o vertice: ";
                cin >> u;
                imprimeVizinhosMatrizAdjacencia(u);
                break;
            case 5:
                cout << "Digite o vertice: ";
                cin >> u;
                imprimeVizinhosMatrizIncidencia(u);
                break;
            case 6:
                cout << "Digite o vertice: ";
                cin >> u;
                imprimeVizinhosListaAdjacencia(u);
                break;
            case 7:
                cout << "Digite os vertices u e v: ";
                cin >> u >> v;
                cout << "Vertices " << u << " e " << v << " sao adjacentes (Matriz de Adjacencia): " << adjacenteMatrizAdjacencia(u, v) << endl;
                break;
            case 8:
                cout << "Digite os vertices u e v: ";
                cin >> u >> v;
                cout << "Vertices " << u << " e " << v << " sao adjacentes (Matriz de Incidencia): " << adjacenteMatrizIncidencia(u, v) << endl;
                break;
            case 9:
                cout << "Digite os vertices u e v: ";
                cin >> u >> v;
                cout << "Vertices " << u << " e " << v << " sao adjacentes (Lista de Adjacencia): " << adjacenteListadeAjacencia(u, v) << endl;
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while(opcao != 0);
}

int main(){
    
    A[0][1] = 1;
    A[1][0] = 1;
    A[0][2] = 1;
    A[2][0] = 1;
    A[1][2] = 1;
    A[2][1] = 1;
    A[1][3] = 1;
    A[3][1] = 1;
    A[2][5] = 1;
    A[5][2] = 1;
    A[3][4] = 1;
    A[4][3] = 1;
    A[5][4] = 1;
    A[4][5] = 1;

    I[0][0] = 1;
    I[1][0] = 1;
    I[0][1] = 1;
    I[2][1] = 1;
    I[1][2] = 1;
    I[2][2] = 1;
    I[1][3] = 1;
    I[3][3] = 1;
    I[2][4] = 1;
    I[5][4] = 1;
    I[3][5] = 1;
    I[4][5] = 1;
    I[4][6] = 1;
    I[5][6] = 1;
    
    L[0].push_back(1);
    L[0].push_back(2);
    L[1].push_back(0);
    L[1].push_back(2);
    L[1].push_back(3);
    L[2].push_back(0);
    L[2].push_back(1);
    L[2].push_back(5);
    L[3].push_back(1);
    L[3].push_back(4);
    L[4].push_back(3);
    L[4].push_back(5);
    L[5].push_back(4);
    L[5].push_back(2);
    
    menu();

    return 0;
}
