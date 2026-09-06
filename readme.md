# Máximo Subarreglo

Implementación de tres soluciones para el problema del máximo subarreglo:

- **Cúbica:** O(n³)
- **Cuadrática:** O(n²)
- **Kadane:** O(n)

## 1. Medición de tiempos

Se realizaron pruebas utilizando arreglos de enteros positivos y negativos generados aleatoriamente. Para cada prueba se duplicó el tamaño del arreglo:

`1000 → 2000 → 4000 → 8000`

Los tiempos se midieron en segundos.

### Resultados

| n | Cúbica (s) | Razón | Cuadrática (s) | Razón | Kadane (s) | Razón |
|---:|---:|---:|---:|---:|---:|---:|
| 1000 | 0.070705 | — | 0.000252 | — | 0.000001 | — |
| 2000 | 0.496585 | 7.023 | 0.001012 | 4.017 | 0.000002 | 1.800 |
| 4000 | 3.968679 | 7.992 | 0.004352 | 4.302 | 0.000004 | 2.222 |
| 8000 | 32.529288 | 8.197 | 0.016445 | 3.779 | 0.000011 | 2.700 |

La razón se calculó mediante:

**Razón = T(n) / T(n/2)**

Por ejemplo, para la versión cúbica entre `n = 1000` y `n = 2000`:

**0.496585 / 0.070705 ≈ 7.023**

## 2. Análisis de los resultados

### Algoritmo cúbico

Al duplicar el tamaño del arreglo, los tiempos obtenidos fueron:

- 7.023
- 7.992
- 8.197

Estos valores se aproximan a **8**.

Para un algoritmo O(n³), al duplicar `n` se espera aproximadamente:

\[
2^3 = 8
\]

Por lo tanto, los resultados experimentales son consistentes con un crecimiento **O(n³)**.

Además, se puede observar claramente el rápido aumento del tiempo:

- `n = 1000` → 0.070705 s
- `n = 2000` → 0.496585 s
- `n = 4000` → 3.968679 s
- `n = 8000` → 32.529288 s

En la última prueba, solamente al duplicar de 4000 a 8000 elementos, el tiempo pasó de aproximadamente 4 segundos a más de 32 segundos.

### Algoritmo cuadrático

Las razones obtenidas fueron:

- 4.017
- 4.302
- 3.779

Estos valores se encuentran alrededor de **4**.

Para un algoritmo O(n²), al duplicar `n` se espera:

\[
2^2 = 4
\]

Por lo tanto, las mediciones son consistentes con un crecimiento **O(n²)**.

La versión cuadrática aumenta su tiempo mucho más lentamente que la cúbica.

### Algoritmo de Kadane

Las razones obtenidas fueron:

- 1.800
- 2.222
- 2.700

Aunque existe cierta variación, los valores se encuentran alrededor de **2**, especialmente considerando que los tiempos son extremadamente pequeños y las mediciones están afectadas por la precisión del cronómetro y otros procesos del sistema.

Para un algoritmo O(n), al duplicar `n` se espera:

\[
2^1 = 2
\]

Por lo tanto, la tendencia observada es consistente con un crecimiento **O(n)**.

## 3. Comparación

Los resultados experimentales coinciden con el comportamiento teórico esperado:

| Algoritmo | Complejidad | Razón esperada al duplicar n | Razones observadas |
|---|---|---:|---:|
| Cúbica | O(n³) | ≈ 8 | 7.023 – 8.197 |
| Cuadrática | O(n²) | ≈ 4 | 3.779 – 4.302 |
| Kadane | O(n) | ≈ 2 | 1.800 – 2.700 |

Las pequeñas diferencias respecto a los valores teóricos pueden deberse a factores externos como el sistema operativo, otros procesos ejecutándose en el equipo, la precisión del temporizador y el tiempo de ejecución tan pequeño de Kadane.

## 4. Conclusión

Las mediciones permiten comprobar experimentalmente la diferencia entre las tres soluciones.

La versión cúbica presenta el crecimiento más rápido. Al duplicar el tamaño del arreglo, su tiempo aumenta aproximadamente ocho veces. Esto coincide con su complejidad O(n³).

La versión cuadrática aumenta aproximadamente cuatro veces al duplicar `n`, lo que coincide con O(n²).

Finalmente, Kadane presenta un crecimiento aproximadamente lineal. Al duplicar el tamaño del arreglo, su tiempo tiende a duplicarse, coincidiendo con O(n).

Por lo tanto, aunque las tres soluciones obtienen la misma suma máxima, **Kadane es considerablemente más eficiente para arreglos grandes**, debido a que reduce la complejidad de O(n³) a O(n).