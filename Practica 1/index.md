# Práctica 1 - Paradigmas de Programación  

**Alumno:** Kevin Humberto Soto Ortiz  
**Profesor:** Carlos Gallegos  
**Fecha:** 26/09/2025  

---

## 📖 Introducción
En esta primera práctica se revisan conceptos esenciales dentro de los lenguajes de programación y cómo se aplican en un sistema desarrollado en C. Entre los puntos tratados se encuentran:  

- Uso de nombres e identificadores.  
- Funcionamiento de los marcos de activación.  
- Manejo de bloques de alcance.  
- Esquemas de administración de memoria.  
- Expresiones y comandos.  
- Control de flujo mediante selección, iteración y recursión.  
- Definición y uso de subprogramas.  
- Implementación de distintos tipos de datos.  

El objetivo es reconocer estos elementos dentro del código de una aplicación para gestión de biblioteca, mostrando cómo se relacionan entre sí y permiten organizar un sistema modular y eficiente.  

---

## 🎯 Instrucciones
La práctica consiste en:  

1. Identificar los componentes fundamentales de un lenguaje de programación (nombres, bloques de alcance, administración de memoria, etc.).  
2. Localizar estos conceptos en el código de la aplicación de biblioteca.  
3. Entregar un reporte en PDF generado a partir del portafolio, acompañado de enlaces al repositorio y al sitio estático del proyecto.  

Repositorio de referencia: [https://github.com/gallegosj89/portafolio](https://github.com/gallegosj89/portafolio)  

---

## 📂 Resultados

### 1. Nombres
Se utilizaron nombres como identificadores de variables, funciones, estructuras, enumeraciones y constantes.  
- **Variables:**  
  - Globales: `static_var` (segmento de datos), `bss_var` (BSS, no inicializada).  
  - Locales: `library`, `members`, `bookCount`, `choice`, `new_book`, `current`, `bookFound`, `memberFound`, etc.  
- **Campos de estructuras:**  
  - `book_t`: `id`, `title`, `author`, `publication_year`, `genre`, `quantity`, `next`.  
  - `member_t`: `id`, `name`, `issued_count`, `issued_books`, `next`.  
- **Funciones:** `genreToString`, `addBook`, `findBookById`, `displayBooksRecursive`, `issueBook`, `returnBook`, `saveLibraryToFile`, `loadMembersFromFile`, `main`.  
- **Tipos definidos:** `genre_t`, `book_t`, `member_t`.  
- **Constantes:** enumeradores (`FICTION`, `SCIENCE`, etc.) y cadenas literales (`"Error al asignar memoria"`, `"library.txt"`).  

---

### 2. Marcos de activación
Los marcos de activación se crean en el stack con cada llamada a función, almacenando parámetros, variables locales y valores de retorno.  
- Ejemplo:  
  - En `addBook`: parámetros (`library`, `count`) y locales (`new_book`, `genre`).  
  - En `main`: locales como `bookCount`, `members`, `choice`.  

---

### 3. Bloques de alcance
Definen la visibilidad de los nombres:  
- **Globales:** variables como `static_var`, `bss_var`, tipos y enumeraciones.  
- **Locales de función:** `new_book` en `addBook`, `current` en `findBookById`.  
- **De bloque:** índices de bucles como `i` en `for`.  
- **Estáticos:** variables como `static_var` que existen durante toda la ejecución.  

---

### 4. Administración de memoria
El código utiliza varios esquemas:  
- **Segmento de datos:** `static_var`, literales de cadenas.  
- **BSS:** variables globales no inicializadas.  
- **Stack:** variables locales y parámetros.  
- **Heap:**  
  - Asignación dinámica (`malloc`, `realloc`).  
  - Liberación explícita (`free`).  
  - Listas enlazadas para manejar `book_t` y `member_t`.  
- **Seguimiento de memoria:** funciones como `incrementHeapAllocations` registran asignaciones y liberaciones.  

---

### 5. Expresiones
Ejemplos encontrados:  
- **Aritméticas:** `(*count)++`, `bookFound->quantity--`.  
- **Lógicas:** `if (bookFound && memberFound)`.  
- **Asignación:** `new_book->next = *library`.  
- **Comparación:** `if (current->id == bookID)`.  
- **Llamadas a funciones:** `malloc(sizeof(book_t))`, `genreToString(...)`.  

---

### 6. Comandos
Incluyen asignaciones, entrada/salida, flujo de control y llamadas a funciones:  
- **Asignación:** `memberFound->issued_books = realloc(...)`.  
- **Entrada/Salida:** `printf("Ingresa ID del libro: ")`, `fscanf(file, "%d\n", &new_book->id)`.  
- **Flujo:** `if`, `switch`, `while`, `for`, `return`.  

---

### 7. Control de secuencia
- **Selección:**  
  - `if-else` para validar memoria asignada.  
  - `switch` para mapear géneros en `genreToString`.  
- **Iteración:**  
  - `while (current)` para recorrer listas.  
  - `for (int i = 0; i < count; i++)`.  
- **Recursión:**  
  - `displayBooksRecursive` para recorrer la lista de libros.  

---

### 8. Subprogramas
Funciones modulares que encapsulan tareas específicas:  
- `addBook`, `findBookById`, `displayBooksRecursive`, `issueBook`, `returnBook`, `freeLibrary`, `freeMembers`, `main`.  
- Parámetros por valor y puntero, retornos diversos (`void`, `book_t*`, `const char*`).  

---

### 9. Tipos de datos
- **Primitivos:** `int`, `char`, `FILE*`.  
- **Definidos por el usuario:**  
  - **Enumeraciones:** `genre_t` con géneros de libros.  
  - **Estructuras:**  
    - `book_t` → describe libros con un puntero al siguiente.  
    - `member_t` → describe miembros con puntero al siguiente.  
  - **Punteros:** dinámicos para `issued_books`.  

---

## 📂 Análisis de memory_management.c

### Nombres
- **Variables:**  
  - Globales: `heap_allocations`, `heap_deallocations`, `stack_allocations`, `stack_deallocations`.  
  - Locales: `record`, `current`, `to_free`.  
- **Funciones:** `addMemoryRecord`, `removeMemoryRecord`, `displayMemoryUsage`, `incrementHeapAllocations`.  
- **Estructuras:** `MemoryRecord`.  
- **Constantes:** `MEMORY_MANAGEMENT_DISPLAY`.  

### Marcos de activación
Ejemplo:  
- En `addMemoryRecord`: parámetros (`pointer`, `size`), variable local (`record`).  
- En `removeMemoryRecord`: parámetros (`pointer`), variables locales (`current`, `to_free`).  

### Bloques de alcance
- Globales (contadores de memoria).  
- Locales en cada función.  
- Bloques condicionales controlados por macros (`#if`).  

### Administración de memoria
- **Heap:** asignación de registros (`malloc`), liberación con `free`.  
- **Listas enlazadas:** para registrar punteros y tamaños de memoria.  
- **Seguimiento:** contadores de asignaciones/liberaciones.  
- **Condicionalidad:** impresión controlada con `MEMORY_MANAGEMENT_DISPLAY`.  

### Expresiones
- Asignación: `record->pointer = pointer`.  
- Desreferenciación: `(*current)->pointer == pointer`.  
- Incremento: `heap_allocations++`.  
- Formato de cadenas: `printf("| 0x%-14p | %-27zu |\n", current->pointer, current->size)`.  

### Comandos
- `record->next = heap_memory_records`.  
- Entrada/salida: `printf(...)`.  
- Liberación: `free(to_free)`.  

### Control de secuencia
- **If:** eliminar un nodo si coincide el puntero.  
- **While:** recorrer lista enlazada de registros.  
- **Macros:** condicionales de preprocesador para depuración.  

### Subprogramas
- `addMemoryRecord` → agrega un nodo.  
- `removeMemoryRecord` → elimina un nodo específico.  
- `displayMemoryUsage` → muestra estadísticas.  
- `incrementHeapAllocations` / `incrementHeapDeallocations` → actualizan contadores.  

### Tipos de datos
- **Primitivos:** `int`, `size_t`, `void*`.  
- **Definidos por usuario:**  
  - `struct MemoryRecord` con punteros y tamaño.  
  - Punteros simples y dobles (`MemoryRecord*`, `MemoryRecord**`).  

---

## ✅ Conclusión
El sistema de biblioteca implementado en C refleja cómo los principios de la programación estructurada permiten diseñar aplicaciones claras, modulares y eficientes.  
El manejo de memoria dinámica, uso de estructuras enlazadas y separación de funciones muestran un diseño sólido. Además, el módulo de administración de memoria ilustra cómo registrar y controlar asignaciones, reforzando la importancia del buen manejo de recursos.  

---

## 🔗 Referencias
- [Repositorio Kevin Soto](https://github.com/KVSO755/Portafolio )
- [Sitio estático del portafolio](https://papux100.github.io/Portafolio/)  
 
