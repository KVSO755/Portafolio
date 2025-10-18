# Programación Orientada a Objetos (POO)

## 1. Conceptos Fundamentales

### **Clase**
Una **clase** es un modelo o plantilla que define atributos (características) y métodos (comportamientos) de un tipo de objeto.  
Es como un plano de construcción.

**Ejemplo en Python:**
```python
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def saludar(self):
        print(f"Hola, soy {self.nombre} y tengo {self.edad} años.")
```

---

### **Objeto**
Un **objeto** es una instancia de una clase. Es el resultado de crear algo a partir de la plantilla.

**Ejemplo en Python:**
```python
p1 = Persona("Kevin", 20)
p1.saludar()  # Salida: Hola, soy Kevin y tengo 20 años.
```

---

### **Herencia**
La **herencia** permite que una clase (hija) herede atributos y métodos de otra clase (padre), evitando repetir código.

**Ejemplo en Python:**
```python
class Estudiante(Persona):
    def __init__(self, nombre, edad, carrera):
        super().__init__(nombre, edad)
        self.carrera = carrera

    def estudiar(self):
        print(f"{self.nombre} está estudiando {self.carrera}.")

e1 = Estudiante("Ana", 22, "Ingeniería")
e1.saludar()
e1.estudiar()
```

---

### **Encapsulamiento**
El **encapsulamiento** restringe el acceso directo a ciertos atributos o métodos de un objeto, protegiendo su información interna.

**Ejemplo en Python:**
```python
class CuentaBancaria:
    def __init__(self, saldo):
        self.__saldo = saldo  # Atributo privado

    def depositar(self, cantidad):
        self.__saldo += cantidad

    def obtener_saldo(self):
        return self.__saldo

cuenta = CuentaBancaria(1000)
cuenta.depositar(500)
print(cuenta.obtener_saldo())  # 1500
```

---

### **Abstracción**
La **abstracción** consiste en mostrar solo la información esencial y ocultar los detalles complejos.  
Permite usar objetos sin saber exactamente cómo están implementados.

**Ejemplo en Python:**
```python
class Auto:
    def encender(self):
        print("El auto está encendido.")

    def conducir(self):
        print("Conduciendo...")

# No necesitamos saber cómo funciona el motor internamente
carro = Auto()
carro.encender()
carro.conducir()
```

---

### **Polimorfismo**
El **polimorfismo** permite usar el mismo método en diferentes clases, cambiando su comportamiento según el objeto que lo use.

**Ejemplo en Python:**
```python
class Perro:
    def hablar(self):
        print("Guau!")

class Gato:
    def hablar(self):
        print("Miau!")

def hacer_hablar(animal):
    animal.hablar()

hacer_hablar(Perro())  # Guau!
hacer_hablar(Gato())   # Miau!
```

---

## 2. Comparación entre C y Python en POO

| Característica                | C (Estructurado)                                         | Python (Orientado a Objetos)                                    |
|-------------------------------|-----------------------------------------------------------|------------------------------------------------------------------|
| **Soporte nativo POO**        | No tiene soporte nativo para clases y objetos.            | Totalmente orientado a objetos.                                 |
| **Clases y objetos**          | Se simulan con `struct` y funciones.                      | Definidos con `class` y métodos.                                |
| **Herencia**                  | No soportada directamente.                               | Soportada con facilidad usando clases base e hijas.             |
| **Encapsulamiento**           | Limitado (puede hacerse con funciones privadas en archivos separados). | Se logra con atributos privados (`__atributo`).         |
| **Abstracción**               | Manual y menos intuitiva.                                | Integrada en el diseño de clases.                               |
| **Polimorfismo**              | Se puede simular con punteros a funciones.               | Implementado de forma sencilla con herencia y métodos.          |
| **Código**                    | Más largo y complejo para estructuras POO.               | Más limpio y legible.                                          |

---

## 3. Conclusiones sobre las Ventajas de POO

- **Organización:** El código se estructura de forma más clara y modular.  
- **Reutilización:** Gracias a la herencia y composición, se evita duplicar código.  
- **Mantenimiento:** Cambiar o mejorar una clase no afecta a todo el sistema.  
- **Escalabilidad:** Facilita construir programas grandes y complejos.  
- **Seguridad:** El encapsulamiento protege datos internos.  
- **Flexibilidad:** El polimorfismo permite adaptar comportamientos fácilmente.

> 💡 **En resumen:** La Programación Orientada a Objetos es una poderosa forma de desarrollar software más claro, reutilizable y fácil de mantener, especialmente en lenguajes modernos como Python.
