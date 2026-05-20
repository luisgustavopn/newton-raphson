#include <iostream>
#include <cmath>

using namespace std;

// =====================================================
// FUNÇÃO f(x)
// f(x) = x^3 - 6x + sqrt(x+5) - cos(x)
// =====================================================

double f(double x) {

    return pow(x, 3)
           - 6 * x
           + sqrt(x + 5)
           - cos(x);
}

// =====================================================
// DERIVADA f'(x)
// f'(x) = 3x² - 6 + 1/(2*sqrt(x+5)) + sin(x)
// =====================================================

double df(double x) {

    return 3 * pow(x, 2)
           - 6
           + (1.0 / (2 * sqrt(x + 5)))
           + sin(x);
}

// =====================================================
// MÉTODO DE NEWTON-RAPHSON
// =====================================================

double newtonRaphson(double x0, double tolerancia, int &iteracoes) {

    double x1;
    double fx;
    double dfx;

    iteracoes = 0;

    while (true) {

        // Calcula f(x)
        fx = f(x0);

        // Calcula f'(x)
        dfx = df(x0);

        // Evita divisão por zero
        if (fabs(dfx) < 1e-12) {

            cout << "\nErro: derivada muito próxima de zero.\n";
            return x0;
        }

        // Fórmula de Newton-Raphson:
        // x(n+1) = x(n) - f(x)/f'(x)

        x1 = x0 - (fx / dfx);

        iteracoes++;

        // Mostra valores da iteração
        cout << "Iteracao " << iteracoes
             << " -> x = " << x1
             << " | f(x) = " << f(x1)
             << endl;

        // Critério de parada
        if (fabs(f(x1)) < tolerancia) {

            return x1;
        }

        // Atualiza valor para próxima iteração
        x0 = x1;
    }
}