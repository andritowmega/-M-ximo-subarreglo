#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

// 1) CÚBICA: O(n^3)
long long maxSubarrayCubic(const vector<int>& a) {
    int n = (int)a.size();
    long long best = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;

            for (int k = i; k <= j; k++) {
                sum += a[k];
            }

            if (sum > best)
                best = sum;
        }
    }

    return best;
}

// 2) CUADRÁTICA: O(n^2)
long long maxSubarrayQuadratic(const vector<int>& a) {
    int n = (int)a.size();
    long long best = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i; j < n; j++) {
            sum += a[j];

            if (sum > best)
                best = sum;
        }
    }

    return best;
}

// 3) Kadane: O(n)
long long maxSubarrayKadane(const vector<int>& a) {
    int n = (int)a.size();
    long long best = LLONG_MIN;
    long long current = 0;

    for (int i = 0; i < n; i++) {
        current = max<long long>(a[i], current + a[i]);
        best = max(best, current);
    }

    return best;
}

// Generar arreglo aleatorio
vector<int> generarArreglo(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-100, 100);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = dist(gen);
    }

    return a;
}

// Medir tiempo de una función
template <typename Funcion>
double medirTiempo(Funcion funcion, const vector<int>& a) {

    auto inicio = chrono::high_resolution_clock::now();

    volatile long long resultado = funcion(a);

    auto fin = chrono::high_resolution_clock::now();

    chrono::duration<double> tiempo = fin - inicio;

    return tiempo.count();
}

int main() {

    vector<int> tamanios = {
        1000,
        2000,
        4000,
        8000
    };

    cout << fixed << setprecision(6);

    double anteriorCubica = 0;
    double anteriorCuadratica = 0;
    double anteriorKadane = 0;

    for (int n : tamanios) {

        cout << "---------------------------------------------\n";
        cout << "n = " << n << "\n";
        cout << "Generando arreglo...\n";

        vector<int> a = generarArreglo(n);

        // CUBICA
        cout << "Ejecutando Cubica...\n";

        double tiempoCubica = medirTiempo(maxSubarrayCubic, a);

        cout << "  Cubica     : "
             << tiempoCubica << " segundos";

        if (anteriorCubica > 0) {
            cout << " | razon: "
                 << tiempoCubica / anteriorCubica;
        }

        cout << "\n";

        // CUADRATICA
        cout << "Ejecutando Cuadratica...\n";

        double tiempoCuadratica =
            medirTiempo(maxSubarrayQuadratic, a);

        cout << "  Cuadratica : "
             << tiempoCuadratica << " segundos";

        if (anteriorCuadratica > 0) {
            cout << " | razon: "
                 << tiempoCuadratica / anteriorCuadratica;
        }

        cout << "\n";

        // KADANE
        cout << "Ejecutando Kadane...\n";

        double tiempoKadane =
            medirTiempo(maxSubarrayKadane, a);

        cout << "  Kadane     : "
             << tiempoKadane << " segundos";

        if (anteriorKadane > 0) {
            cout << " | razon: "
                 << tiempoKadane / anteriorKadane;
        }

        cout << "\n\n";

        anteriorCubica = tiempoCubica;
        anteriorCuadratica = tiempoCuadratica;
        anteriorKadane = tiempoKadane;
    }

    return 0;
}