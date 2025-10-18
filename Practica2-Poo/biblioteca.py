import json
import os
from abc import ABC, abstractmethod
from enum import Enum
from typing import List, Optional

# ENUMS Y CLASES BASE
class Genero(Enum):
    FICCION = "Ficcion"
    NO_FICCION = "No Ficcion"
    CIENCIA = "Ciencia"
    HISTORIA = "Historia"
    FANTASIA = "Fantasia"
    BIOGRAFIA = "Biografia"
    OTRO = "Otro"

class ItemBiblioteca(ABC):
    """Clase abstracta base para todos los items de la biblioteca"""
    
    def __init__(self, id: int, titulo: str, año_publicacion: int, cantidad: int = 1):
        self._id = id
        self._titulo = titulo
        self._año_publicacion = año_publicacion
        self._cantidad = cantidad
    
    @abstractmethod
    def get_tipo(self) -> str:
        pass
    
    @property
    def id(self) -> int:
        return self._id
    
    @property
    def titulo(self) -> str:
        return self._titulo
    
    @property
    def año_publicacion(self) -> int:
        return self._año_publicacion
    
    @property
    def cantidad(self) -> int:
        return self._cantidad
    
    @cantidad.setter
    def cantidad(self, value: int):
        self._cantidad = value
    
    def to_dict(self) -> dict:
        return {
            'id': self._id,
            'titulo': self._titulo,
            'año_publicacion': self._año_publicacion,
            'cantidad': self._cantidad,
            'tipo': self.get_tipo()
        }

# CLASES CONCRETAS DE ITEMS
class Libro(ItemBiblioteca):
    """Clase que representa un libro en la biblioteca"""
    
    def __init__(self, id: int, titulo: str, autor: str, año_publicacion: int, 
                 genero: Genero, cantidad: int = 1):
        super().__init__(id, titulo, año_publicacion, cantidad)
        self._autor = autor
        self._genero = genero
    
    def get_tipo(self) -> str:
        return "Libro"
    
    @property
    def autor(self) -> str:
        return self._autor
    
    @property
    def genero(self) -> Genero:
        return self._genero
    
    def to_dict(self) -> dict:
        data = super().to_dict()
        data.update({
            'autor': self._autor,
            'genero': self._genero.value
        })
        return data
    
    def __str__(self) -> str:
        return f"Libro: {self._titulo} - {self._autor} ({self._año_publicacion})"

class Revista(ItemBiblioteca):
    """Clase que representa una revista en la biblioteca"""
    
    def __init__(self, id: int, titulo: str, editorial: str, 
                 año_publicacion: int, numero: int, cantidad: int = 1):
        super().__init__(id, titulo, año_publicacion, cantidad)
        self._editorial = editorial
        self._numero = numero
    
    def get_tipo(self) -> str:
        return "Revista"
    
    @property
    def editorial(self) -> str:
        return self._editorial
    
    @property
    def numero(self) -> int:
        return self._numero
    
    def to_dict(self) -> dict:
        data = super().to_dict()
        data.update({
            'editorial': self._editorial,
            'numero': self._numero
        })
        return data
    
    def __str__(self) -> str:
        return f"Revista: {self._titulo} - {self._editorial} (No. {self._numero})"

# CLASE USUARIO
class Usuario:
    """Clase que representa un usuario de la biblioteca"""
    
    def __init__(self, id: int, nombre: str):
        self._id = id
        self._nombre = nombre
        self._items_prestados: List[int] = []  # IDs de items prestados
    
    @property
    def id(self) -> int:
        return self._id
    
    @property
    def nombre(self) -> str:
        return self._nombre
    
    @property
    def items_prestados(self) -> List[int]:
        return self._items_prestados.copy()
    
    @property
    def cantidad_prestados(self) -> int:
        return len(self._items_prestados)
    
    def prestar_item(self, item_id: int) -> bool:
        if item_id not in self._items_prestados:
            self._items_prestados.append(item_id)
            return True
        return False
    
    def devolver_item(self, item_id: int) -> bool:
        if item_id in self._items_prestados:
            self._items_prestados.remove(item_id)
            return True
        return False
    
    def tiene_item(self, item_id: int) -> bool:
        return item_id in self._items_prestados
    
    def to_dict(self) -> dict:
        return {
            'id': self._id,
            'nombre': self._nombre,
            'items_prestados': self._items_prestados
        }
    
    def __str__(self) -> str:
        return f"Usuario: {self._nombre} (ID: {self._id})"

# CLASE BIBLIOTECA
class Biblioteca:
    """Clase principal que maneja toda la operación de la biblioteca"""
    
    def __init__(self):
        self._items: List[ItemBiblioteca] = []
        self._usuarios: List[Usuario] = []
        self._next_item_id = 1
        self._next_user_id = 1
    
    # MÉTODOS PARA ITEMS
    def agregar_item(self, item: ItemBiblioteca) -> bool:
        """Agrega un item a la biblioteca"""
        if self.buscar_item_por_id(item.id) is not None:
            return False
        self._items.append(item)
        return True
    
    def buscar_item_por_id(self, item_id: int) -> Optional[ItemBiblioteca]:
        """Busca un item por su ID"""
        for item in self._items:
            if item.id == item_id:
                return item
        return None
    
    def buscar_items_por_titulo(self, titulo: str) -> List[ItemBiblioteca]:
        """Busca items por título (búsqueda parcial)"""
        return [item for item in self._items if titulo.lower() in item.titulo.lower()]
    
    def mostrar_items(self) -> None:
        """Muestra todos los items disponibles"""
        if not self._items:
            print("\nNo hay items disponibles en la biblioteca.")
            return
        
        print(f"\n{'='*60}")
        print("ITEMS DISPONIBLES EN LA BIBLIOTECA")
        print(f"{'='*60}")
        for item in self._items:
            print(f"ID: {item.id} | {item} | Cantidad: {item.cantidad}")
    
    # MÉTODOS PARA USUARIOS
    def agregar_usuario(self, nombre: str) -> Usuario:
        """Agrega un nuevo usuario a la biblioteca"""
        usuario = Usuario(self._next_user_id, nombre)
        self._usuarios.append(usuario)
        self._next_user_id += 1
        return usuario
    
    def buscar_usuario_por_id(self, user_id: int) -> Optional[Usuario]:
        """Busca un usuario por su ID"""
        for usuario in self._usuarios:
            if usuario.id == user_id:
                return usuario
        return None
    
    def mostrar_usuarios(self) -> None:
        """Muestra todos los usuarios"""
        if not self._usuarios:
            print("\nNo hay usuarios registrados.")
            return
        
        print(f"\n{'='*50}")
        print("USUARIOS REGISTRADOS")
        print(f"{'='*50}")
        for usuario in self._usuarios:
            print(f"ID: {usuario.id} | {usuario} | Libros prestados: {usuario.cantidad_prestados}")
    
    # OPERACIONES DE PRÉSTAMO
    def prestar_item(self, user_id: int, item_id: int) -> bool:
        """Realiza el préstamo de un item a un usuario"""
        usuario = self.buscar_usuario_por_id(user_id)
        item = self.buscar_item_por_id(item_id)
        
        if not usuario or not item:
            return False
        
        if item.cantidad <= 0:
            return False
        
        if usuario.tiene_item(item_id):
            return False
        
        # Realizar préstamo
        item.cantidad -= 1
        usuario.prestar_item(item_id)
        return True
    
    def devolver_item(self, user_id: int, item_id: int) -> bool:
        """Realiza la devolución de un item por un usuario"""
        usuario = self.buscar_usuario_por_id(user_id)
        item = self.buscar_item_por_id(item_id)
        
        if not usuario or not item:
            return False
        
        if not usuario.tiene_item(item_id):
            return False
        
        # Realizar devolución
        item.cantidad += 1
        usuario.devolver_item(item_id)
        return True
    
    # PERSISTENCIA
    def guardar_datos(self, archivo_items: str = "biblioteca_items.json", 
                     archivo_usuarios: str = "biblioteca_usuarios.json") -> None:
        """Guarda los datos en archivos JSON"""
        # Guardar items
        items_data = [item.to_dict() for item in self._items]
        with open(archivo_items, 'w', encoding='utf-8') as f:
            json.dump(items_data, f, indent=2, ensure_ascii=False)
        
        # Guardar usuarios
        usuarios_data = [usuario.to_dict() for usuario in self._usuarios]
        with open(archivo_usuarios, 'w', encoding='utf-8') as f:
            json.dump(usuarios_data, f, indent=2, ensure_ascii=False)
        
        print(f"Datos guardados exitosamente!")
    
    def cargar_datos(self, archivo_items: str = "biblioteca_items.json", 
                    archivo_usuarios: str = "biblioteca_usuarios.json") -> None:
        """Carga los datos desde archivos JSON"""
        # Cargar items
        if os.path.exists(archivo_items):
            try:
                with open(archivo_items, 'r', encoding='utf-8') as f:
                    items_data = json.load(f)
                
                for item_data in items_data:
                    if item_data['tipo'] == 'Libro':
                        item = Libro(
                            item_data['id'],
                            item_data['titulo'],
                            item_data['autor'],
                            item_data['año_publicacion'],
                            Genero(item_data['genero']),
                            item_data['cantidad']
                        )
                    else:  # Revista
                        item = Revista(
                            item_data['id'],
                            item_data['titulo'],
                            item_data['editorial'],
                            item_data['año_publicacion'],
                            item_data['numero'],
                            item_data['cantidad']
                        )
                    self.agregar_item(item)
                    self._next_item_id = max(self._next_item_id, item_data['id'] + 1)
            except Exception as e:
                print(f"Error cargando items: {e}")
        
        # Cargar usuarios
        if os.path.exists(archivo_usuarios):
            try:
                with open(archivo_usuarios, 'r', encoding='utf-8') as f:
                    usuarios_data = json.load(f)
                
                for user_data in usuarios_data:
                    usuario = Usuario(user_data['id'], user_data['nombre'])
                    for item_id in user_data['items_prestados']:
                        usuario.prestar_item(item_id)
                    self._usuarios.append(usuario)
                    self._next_user_id = max(self._next_user_id, user_data['id'] + 1)
            except Exception as e:
                print(f"Error cargando usuarios: {e}")

# INTERFAZ DE USUARIO
class MenuBiblioteca:
    """Clase para manejar la interfaz de usuario"""
    
    def __init__(self):
        self.biblioteca = Biblioteca()
    
    def mostrar_menu_principal(self) -> None:
        print(f"""
{'='*60}
         SISTEMA DE GESTIÓN DE BIBLIOTECA
{'='*60}
1. Agregar Libro
2. Agregar Revista
3. Mostrar Todos los Items
4. Buscar Item por Título
5. Agregar Usuario
6. Mostrar Usuarios
7. Prestar Item
8. Devolver Item
9. Buscar Usuario y Mostrar Items Prestados
10. Guardar y Salir
{'='*60}
        """)
    
    def ejecutar(self) -> None:
        """Método principal que ejecuta el menú"""
        # Cargar datos existentes
        self.biblioteca.cargar_datos()
        
        while True:
            self.mostrar_menu_principal()
            try:
                opcion = input("Seleccione una opción (1-10): ").strip()
                
                if opcion == '1':
                    self.agregar_libro()
                elif opcion == '2':
                    self.agregar_revista()
                elif opcion == '3':
                    self.biblioteca.mostrar_items()
                elif opcion == '4':
                    self.buscar_item_titulo()
                elif opcion == '5':
                    self.agregar_usuario()
                elif opcion == '6':
                    self.biblioteca.mostrar_usuarios()
                elif opcion == '7':
                    self.prestar_item()
                elif opcion == '8':
                    self.devolver_item()
                elif opcion == '9':
                    self.buscar_usuario()
                elif opcion == '10':
                    self.biblioteca.guardar_datos()
                    print("¡Gracias por usar el sistema de biblioteca!")
                    break
                else:
                    print("Opción no válida. Por favor, seleccione 1-10.")
                
                input("\nPresione Enter para continuar...")
                
            except KeyboardInterrupt:
                print("\n\nSaliendo del programa...")
                self.biblioteca.guardar_datos()
                break
            except Exception as e:
                print(f"Error: {e}")
    
    def agregar_libro(self) -> None:
        print("\n--- AGREGAR NUEVO LIBRO ---")
        try:
            titulo = input("Título: ")
            autor = input("Autor: ")
            año = int(input("Año de publicación: "))
            print("Géneros disponibles:")
            for i, genero in enumerate(Genero):
                print(f"{i}. {genero.value}")
            genero_idx = int(input("Seleccione género (0-6): "))
            cantidad = int(input("Cantidad: "))
            
            libro = Libro(
                self.biblioteca._next_item_id,
                titulo,
                autor,
                año,
                list(Genero)[genero_idx],
                cantidad
            )
            
            if self.biblioteca.agregar_item(libro):
                print(f" Libro '{titulo}' agregado exitosamente (ID: {libro.id})")
            else:
                print(" Error al agregar el libro")
                
        except ValueError:
            print(" Error: Ingrese valores válidos")
        except IndexError:
            print(" Error: Género no válido")
    
    def agregar_revista(self) -> None:
        print("\n--- AGREGAR NUEVA REVISTA ---")
        try:
            titulo = input("Título: ")
            editorial = input("Editorial: ")
            año = int(input("Año de publicación: "))
            numero = int(input("Número de revista: "))
            cantidad = int(input("Cantidad: "))
            
            revista = Revista(
                self.biblioteca._next_item_id,
                titulo,
                editorial,
                año,
                numero,
                cantidad
            )
            
            if self.biblioteca.agregar_item(revista):
                print(f" Revista '{titulo}' agregada exitosamente (ID: {revista.id})")
            else:
                print(" Error al agregar la revista")
                
        except ValueError:
            print(" Error: Ingrese valores válidos")
    
    def agregar_usuario(self) -> None:
        print("\n--- AGREGAR NUEVO USUARIO ---")
        nombre = input("Nombre del usuario: ")
        usuario = self.biblioteca.agregar_usuario(nombre)
        print(f" Usuario '{nombre}' agregado exitosamente (ID: {usuario.id})")
    
    def prestar_item(self) -> None:
        print("\n--- PRESTAR ITEM ---")
        try:
            user_id = int(input("ID del usuario: "))
            item_id = int(input("ID del item: "))
            
            if self.biblioteca.prestar_item(user_id, item_id):
                print(" Item prestado exitosamente")
            else:
                print(" Error al prestar el item")
                
        except ValueError:
            print(" Error: Ingrese IDs válidos")
    
    def devolver_item(self) -> None:
        print("\n--- DEVOLVER ITEM ---")
        try:
            user_id = int(input("ID del usuario: "))
            item_id = int(input("ID del item: "))
            
            if self.biblioteca.devolver_item(user_id, item_id):
                print(" Item devuelto exitosamente")
            else:
                print(" Error al devolver el item")
                
        except ValueError:
            print(" Error: Ingrese IDs válidos")
    
    def buscar_item_titulo(self) -> None:
        print("\n--- BUSCAR ITEM POR TÍTULO ---")
        titulo = input("Título a buscar: ")
        items = self.biblioteca.buscar_items_por_titulo(titulo)
        
        if items:
            print(f"\nSe encontraron {len(items)} items:")
            for item in items:
                print(f"ID: {item.id} | {item} | Cantidad: {item.cantidad}")
        else:
            print(" No se encontraron items con ese título")
    
    def buscar_usuario(self) -> None:
        print("\n--- BUSCAR USUARIO ---")
        try:
            user_id = int(input("ID del usuario: "))
            usuario = self.biblioteca.buscar_usuario_por_id(user_id)
            
            if usuario:
                print(f"\nUsuario encontrado:")
                print(f"ID: {usuario.id} | Nombre: {usuario.nombre}")
                print(f"Items prestados: {usuario.cantidad_prestados}")
                
                if usuario.items_prestados:
                    print("\nItems prestados:")
                    for item_id in usuario.items_prestados:
                        item = self.biblioteca.buscar_item_por_id(item_id)
                        if item:
                            print(f"  - {item}")
                else:
                    print("  No tiene items prestados")
            else:
                print(" Usuario no encontrado")
                
        except ValueError:
            print(" Error: Ingrese un ID válido")

# EJECUCIÓN PRINCIPAL
if __name__ == "__main__":
    menu = MenuBiblioteca()
    menu.ejecutar()