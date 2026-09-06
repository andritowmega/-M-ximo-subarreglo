#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// ---------------------------------------------------------------------
// 1) Fuerza bruta CÚBICA: O(n^3)
//    Para cada par (i, j) se recalcula la suma del subarreglo [i..j]
//    recorriéndolo por completo (un tercer bucle interno).
// ---------------------------------------------------------------------
long long maxSubarrayCubic(const vector<int>& a) {
    int n = (int)a.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            if (sum > best) best = sum;
        }
    }
    return best;
}

// ---------------------------------------------------------------------
// 2) Fuerza bruta mejorada CUADRÁTICA: O(n^2)
//    Para cada i, se acumula la suma incrementalmente al mover j,
//    evitando el tercer bucle.
// ---------------------------------------------------------------------
long long maxSubarrayQuadratic(const vector<int>& a) {
    int n = (int)a.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum > best) best = sum;
        }
    }
    return best;
}

// ---------------------------------------------------------------------
// 3) Algoritmo de Kadane: O(n)
//    Programación dinámica: en cada posición se decide si conviene
//    extender el subarreglo anterior o comenzar uno nuevo desde ahí.
// ---------------------------------------------------------------------
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

// ---------------------------------------------------------------------
// main: prueba las tres funciones con un arreglo de ejemplo y muestra
// los resultados.
// ---------------------------------------------------------------------
int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Arreglo: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    long long r1 = maxSubarrayCubic(a);
    long long r2 = maxSubarrayQuadratic(a);
    long long r3 = maxSubarrayKadane(a);

    cout << "Cubica     -> suma maxima: " << r1 << endl;
    cout << "Cuadratica -> suma maxima: " << r2 << endl;
    cout << "Kadane     -> suma maxima: " << r3 << endl;

    return 0;
}