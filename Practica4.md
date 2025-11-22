---
title: "Práctica 4"
date: 2025-11-21
draft: false
--- 
# Práctica 4 - Paradigma Logico 

**Alumno:** Kevin Humberto Soto Ortiz  
**Profesor:** Carlos Gallegos  
**Fecha:** 21/11/2025  

Introducción

El paradigma lógico es un estilo de programación donde los problemas se representan mediante hechos, reglas y consultas, permitiendo que el lenguaje determine las respuestas utilizando procesos de inferencia.

En esta práctica se trabajó con Prolog, un lenguaje especialmente adecuado para definir relaciones, manejar bases de conocimiento y resolver problemas a partir de lógica declarativa.

Primera sesión – Hechos, reglas y bases de conocimiento (reescrito)

Durante la primera sesión se revisaron los conceptos esenciales del paradigma lógico y la estructura fundamental de Prolog. Los temas principales abarcaron:

1 Hechos

Los hechos son afirmaciones que describen relaciones o propiedades que se consideran verdaderas dentro de la base de conocimiento.
Su forma general es: relación(objeto1, objeto2).

Entre los ejemplos incluidos estuvieron:
cat(tom).
lazy(juan).
loves_to_eat(jorge, pasta).

También se mencionaron las reglas básicas para escribir hechos:

Los nombres deben ir en minúsculas.

Los argumentos se separan con comas.

Cada hecho finaliza con un punto.

2 Reglas

Se estudió la forma en que se definen reglas utilizando los operadores:

, para indicar conjunción

; para representar disyunción

Código de la práctica 
% Base de conocimiento
girl(priya).
girl(natasha).
girl(jasmin).
can_cook(priya).


Consultas realizadas:

?- girl(priya).
true.

?- girl(X).
X = priya ;
X = natasha ;
X = jasmin ;
false.

?- can_cook(priya).
true.

?- can_cook(X).
X = priya ;
false.

?- girl(X), can_cook(X).
X = priya ;
false.

?- can_cook(natasha).
false.

?- girl(jasmin).
true.

?- girl(maria).
false.

?- girl(X), \+ can_cook(X).
X = natasha ;
X = jasmin ;
false.

Conclusiones (reescritas)

El paradigma lógico facilita la resolución de problemas mediante la definición de relaciones y reglas, delegando al motor lógico la tarea de buscar soluciones automáticamente.

Prolog resulta especialmente útil para:

crear y gestionar bases de conocimiento,

aplicar razonamiento lógico,

explorar respuestas mediante backtracking,

trabajar con listas, estructuras y funciones recursivas.


[Github](https://github.com/KVSO755/Portafolio "Repositorio De Github")

![Pagina Hugo](https://kvso755.github.io/Pagina-Hugo/)
