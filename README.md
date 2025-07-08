# Programación 2 - FING - UdelaR

En este repositorio se encuentran las soluciones de algunos ejercicios de los prácticos y parciales del curso de Programación 2 del primer semestre de 2025.

### 📚 Contenido

Los ejercicios están organizados por práctico y cubren los principales temas del curso, tales como:

- Abstracción y modularización en el desarrollo de programas de porte mediano.
- Análisis de algoritmos, especialmente en el peor caso, tanto iterativos como recursivos.
- Recursión: definición, esquemas, expansión de recurrencias y comparación con iteración.
- Pasaje de parámetros: por copia vs. por referencia y sus efectos.
- Funciones totales y parciales, considerando precondiciones.
- Tipos Abstractos de Datos (TADs):
  - Listas (simples, dobles, circulares, indizadas).
  - Pilas, colas, conjuntos, multiconjuntos, tablas, colas de prioridad.
- Estructuras dinámicas lineales y arborescentes:
  - Árboles binarios, árboles binarios de búsqueda, árboles generales, árboles AVL.
- Hashing, heaps y uso de multiestructuras para resolver problemas de forma eficiente.
- Diseño y especificación de TADs, con foco en eficiencia y desacople entre interfaz e implementación.

### 💻 Formas de compilar

- En caso de tener un solo archivo:  
```bash
g++ nombreArchivo.cpp -o nombreEjecutable
```

- En caso de tener varios archivos:  
Compilamos los archivos por separado y luego generamos un único ejecutable.
```bash
g++ -c nombreArchivo1.cpp
g++ -c nombreArchivo2.cpp
g++ nombreArchivo1.o nombreArchivo2.o -o nombreEjecutable
```

### ⚠️ Aclaración

Las guías teóricas y letras de los prácticos incluidas en este repositorio fueron elaboradas por los docentes del curso y se incluyen únicamente con fines educativos.

Yo no soy el autor de dicho material, y todo el crédito corresponde al equipo docente de la asignatura.
