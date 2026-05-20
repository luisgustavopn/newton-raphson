#include <iostream>

using namespace std;

// ==============================================
// DECLARAÇÃO DA FUNÇÃO
// (implementada em newton_raphson.cpp)
// ==============================================

double newtonRaphson(double x0,double tolerancia,int &iteracoes);

int main() {

    double x0;
    double raiz;

    int iteracoes;

    const double TOLERANCIA = 1e-6;

    cout << "Metodo de Newton-Raphson\n";
    cout << "Funcao: x^3 - 6x + sqrt(x+5) - cos(x)\n\n";

    // Entrada do valor inicial
    cout << "Digite o valor inicial x0: ";
    cin >> x0;

    // Executa o método
    raiz = newtonRaphson(x0, TOLERANCIA, iteracoes);

    // Resultado final
    cout << "\n=====================================\n";
    cout << "Raiz aproximada: " << raiz << endl;
    cout << "Numero de iteracoes: " << iteracoes << endl;
    cout << "=====================================\n";

    return 0;
}