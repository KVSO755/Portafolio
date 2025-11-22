---
title: "Práctica 3"
date: 2025-09-26
draft: false
--- 
# Reporte: Instalación del Entorno de Desarrollo Haskell y Funcionamiento de la Aplicación TODO

## 1. Primera sesión — Instalación del entorno de desarrollo

Para trabajar con Haskell de forma adecuada, es necesario instalar varias herramientas fundamentales. La forma recomendada para hacerlo es mediante **GHCup**, un instalador que administra compiladores, intérpretes y herramientas relacionadas.

### 1.1. Descarga e instalación mediante GHCup

1. Acceder a la página oficial de Haskell en el apartado **Downloads**.
2. Seleccionar instalar mediante **GHCup**.
3. Abrir el enlace de GHCup.
4. Copiar el comando de instalación para Windows.
5. Abrir **PowerShell (sin modo administrador)**.
6. Pegar y ejecutar el comando.

GHCup descargará e instalará automáticamente las herramientas necesarias.

---

### 1.2. Herramientas instaladas

#### ✔ GHCup
Instalador y gestor del entorno. Maneja versiones de GHC, HLS, Cabal y Stack.

#### ✔ GHC (Glasgow Haskell Compiler)
Compilador principal del lenguaje Haskell. Convierte programas `.hs` en ejecutables.

#### ✔ Hugs
Intérprete interactivo de Haskell, útil para probar expresiones rápidamente.

#### ✔ HLS (Haskell Language Server)
Proporciona autocompletado, diagnósticos y soporte para editores como VS Code.

#### ✔ Stack
Administrador de paquetes y proyectos, similar a:
- pip (Python)
- npm (JavaScript)
- apt-get (Ubuntu)

#### ✔ Cabal
Herramienta de compilación y empaquetado, que utiliza Stack y GHC.

#### ✔ Archivos `.hs`
Extensión para los programas escritos en Haskell.

---

### 1.3. Confirmación de la instalación

La guía oficial **Get Started** permite:
- Ejecutar ejemplos básicos
- Probar el compilador
- Usar GHCi (intérprete interactivo)
- Crear un proyecto inicial

Esto confirma que la instalación de Haskell fue exitosa.

---

## 2. Segunda sesión

### 2.1. Revisión previa recomendada

Se recomienda revisar:

**Haskell Tutorial for C Programmers**, el cual compara conceptos entre C y Haskell.  
Incluye un tour de sintaxis elaborado por el departamento de CSE de Chalmers, ideal para comprender la estructura funcional.

**Objetivo del curso:**  
No convertir al estudiante en experto, sino comprender:
- la sintaxis básica
- el paradigma funcional
- aplicaciones simples usando Haskell

---

## 3. Funcionamiento de la aplicación TODO en Haskell

El reporte requiere describir la aplicación **TODO** desarrollada usando Stack, disponible en el ejemplo:

**Haskell/examples/blog/todo**

Además, se complementa con la entrada del blog:

**How to use Haskell to build a todo app with Stack**

---

### 3.1. Descripción general

La aplicación es un programa en consola que permite:
- agregar tareas  
- listar tareas  
- marcar tareas como completadas  
- eliminar tareas  

Utiliza archivos de texto y aplica principios funcionales.

---

### 3.2. Funcionamiento interno

#### a) Definición de un tipo de dato
```haskell
data Todo = Todo {
    title :: String,
    done :: Bool
}
```

#### b) Manejo de archivos
Cada tarea se almacena como una línea de texto con su estado.

#### c) Funciones puras
Se implementan funciones como:
- `addTodo`
- `listTodos`
- `removeTodo`
- `toggleTodo`

#### d) Función principal `main`
Lee instrucciones del usuario, por ejemplo:
```
todo add "comprar leche"
todo list
todo done 1
todo remove 2
```

---

### 3.3. Uso de Stack

#### Crear un proyecto:
```
stack new todo
```

#### Compilar el proyecto:
```
stack build
```

#### Ejecutarlo:
```
stack run
```

Stack administra dependencias, construcción y ejecución de la aplicación.

---

## 4. Conclusiones

- GHCup simplifica en gran medida la instalación del ecosistema Haskell.
- Haskell utiliza varias herramientas interconectadas para compilar y administrar proyectos.
- La aplicación TODO introduce al paradigma funcional mediante un ejemplo práctico y sencillo.
- Aunque Haskell es un lenguaje diferente a los lenguajes imperativos, su sintaxis es potente y elegante.
- El propósito del curso es ofrecer una visión del paradigma funcional, no dominar completamente el lenguaje.
