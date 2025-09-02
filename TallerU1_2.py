class Node:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

def insertar_nodo(cabeza, dato):
    nuevo_nodo = Node(dato)

    if cabeza is None:
        return nuevo_nodo
    else:
        actual = cabeza
        while actual.siguiente is not None:
            actual = actual.siguiente
        actual.siguiente = nuevo_nodo
        return cabeza

def imprimir_lista(cabeza):
    actual = cabeza
    print("HEAD -> ", end="")

    while actual is not None:
        print(f"{actual.dato} -> ", end="")
        actual = actual.siguiente
    print("NULL")

def main():
    cabeza = None

    cabeza = insertar_nodo(cabeza, 1)
    cabeza = insertar_nodo(cabeza, 3)
    cabeza = insertar_nodo(cabeza, 5)
    imprimir_lista(cabeza)

if __name__ == "__main__":
    main()