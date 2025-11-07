
#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

#define NOMBRE_ARCHIVO_BINARIO "datos.dat"
#define NOMBRE_ARCHIVO_RESPALDO "respaldo.dat"

typedef int Tkey;
typedef struct _wrkr
{
    int status;
    Tkey enrollment;
    char name[30];
    char last_name_1[50];
    char last_name_2[50];
    char sex[15];
    char job_pstion[30];
    char state[30];
    int age;
    Tkey cell_phone;
} Twrkr;

typedef struct users
{
    int status;
    char usuario[20];
    char contrasenia[20];
    int nivel_usuario;
} Tusuario;

char *my_gets(char *cadena, int tamano);
int validar(int ri, int rf, const char *msge);
void convercionmayusculas(char *cadena);
void sinespacios(char *cadena, char *sinespacio);
void burbuja(Twrkr vect[], int tamanio);
void seleccion(Twrkr vect[], int tamanio);
void quicksort(Twrkr vec[], int inicio, int fin);
void shellSort(Twrkr vect[], int tamanio);
void merge(Twrkr vect[], int l, int m, int r);
void mergesort(Twrkr vect[], int l, int r);
int busquedasecuencial(Twrkr vector[], int tamanio, int claveBuscada);
int busquedabinaria(Twrkr vect[], int claveBuscada, int min, int max);
// Prototipos de archivos
int tamanio();
int cargararchivo(Twrkr vector[], int m);
Twrkr agregar_random(Twrkr vector[], int tamanio);
int no_repeticion(Twrkr vector[], int inicio, int clave);
void elimina_reg(Twrkr vector[], int *m);
void crearArchivoBinario(Twrkr *registros, int totalRegistros);
void generar_archivotxt_de_bin(const char nombre_archivo_binario[]);
void busqueda_secuencial(Twrkr vector[], int m);
void agregar_usuario_manual(Twrkr vector[], int tamanio);
int leer_archivo_bin(Twrkr vector[], int m);
void eliminar_registro(Twrkr vector[], int *num_registros);
void imprimir_archivo_binario(Twrkr vector, int tamanio);
void guardar_archivo(Twrkr *vector, int num_registros, const char *nombre);
void imprimir_arch_ordenado(Twrkr vector[], int tamanio);
void generar_archivo_binario(Twrkr vector[], int tamanio);
// Prototipos de usuarios
Tusuario iniciar_sesion();
void inicializar_claves();
void verificarOCrearArchivoDatos(const char *nombreArchivo);
void agregar_usuario_manual(Tusuario vector[], int *tamanio);
void eliminar_registro(Tusuario vector[], int *tamanio);
void modificar_nivel(Tusuario vector[], int tamanio);
void quitar_bloqueo(Tusuario vector[], int tamanio);
void leer_contrasenia(char *cadena, int caracteres);
int tamanio2();

char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    fgets(cadena, tamano, stdin);
    if (cadena)
    {
        longitud = strlen(cadena);
        if (longitud > 0)
        {
            if (cadena[longitud - 1] == '\n')
            {
                cadena[longitud - 1] = '\0';
            }
        }
        return cadena;
    }
    return NULL;
}
int validar(int ri, int rf, const char *msge)
{
    int num;
    char strnum[30];
    do
    {
        printf("%sEntre el %d y %d\n", msge, ri, rf);
        my_gets(strnum, 30);
        num = atoi(strnum);
        if (num < ri || num > rf)
        {
            printf("Dame lo que se pide...\n");
        }
    } while (num < ri || num > rf);
    return num;
}
void convercionmayusculas(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] -= 32;
            }
        }
    }
}
void contarcaracter(char *cadena)
{
    int contador = 0;
    while (cadena[contador] != '\0')
    {
        contador++;
    }
}
void sinespacios(char *cadena, char *sinespacio)
{
    int numero = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            sinespacio[numero] = cadena[i];
            numero++;
        }
    }
    sinespacio[numero] = '\0';
}
void burbuja(Twrkr vect[], int tamanio)
{
    Twrkr temp;
    for (int i = 0; i < tamanio - 1; i++)
    {
        for (int j = 0; j < tamanio - i - 1; j++)
        {
            if (vect[j].enrollment > vect[j + 1].enrollment)
            {
                temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}
void seleccion(Twrkr vect[], int tamanio)
{
    for (int i = 0; i < tamanio - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < tamanio; j++)
        {
            if (vect[j].enrollment < vect[min_idx].enrollment)
            {
                min_idx = j;
            }
        }
        Twrkr temp = vect[min_idx];
        vect[min_idx] = vect[i];
        vect[i] = temp;
    }
}
void quicksort(Twrkr vec[], int inicio, int fin)
{
    if (inicio >= fin)
        return;

    int izq = inicio, der = fin;
    int piv = vec[(inicio + fin) / 2].enrollment;
    Twrkr aux;

    while (izq <= der)
    {
        while (vec[izq].enrollment < piv)
            izq++;
        while (vec[der].enrollment > piv)
            der--;

        if (izq <= der)
        {
            aux = vec[izq];
            vec[izq] = vec[der];
            vec[der] = aux;
            izq++;
            der--;
        }
    }

    quicksort(vec, inicio, der);
    quicksort(vec, izq, fin);
}
void shellSort(Twrkr vect[], int tamanio)
{
    for (int intervalo = tamanio / 2; intervalo > 0; intervalo /= 2)
    {
        for (int i = intervalo; i < tamanio; i++)
        {
            Twrkr temp = vect[i];
            int j;
            for (j = i; j >= intervalo && vect[j - intervalo].enrollment > temp.enrollment; j -= intervalo)
            {
                vect[j] = vect[j - intervalo];
            }
            vect[j] = temp;
        }
    }
}
void merge(Twrkr vect[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    Twrkr L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vect[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vect[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].enrollment <= R[j].enrollment)
            vect[k++] = L[i++];
        else
            vect[k++] = R[j++];
    }
    while (i < n1)
        vect[k++] = L[i++];
    while (j < n2)
        vect[k++] = R[j++];
}
void mergesort(Twrkr vect[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(vect, l, m);
        mergesort(vect, m + 1, r);
        merge(vect, l, m, r);
    }
}
int busquedasecuencial(Twrkr vector[], int tamanio, int claveBuscada)
{
    for (int i = 0; i < tamanio; i++)
    {
        if (vector[i].enrollment == claveBuscada)
        {
            printf("Registro encontrado:\n");
            printf("Matricula: %d\n", vector[i].enrollment);
            printf("Nombre: %s %s %s\n", vector[i].name, vector[i].last_name_1, vector[i].last_name_2);
            printf("Sexo: %s\n", vector[i].sex);
            printf("Telefono: %lld\n", vector[i].cell_phone);
            printf("Estado: %s\n", vector[i].state);
            printf("Puesto: %s\n", vector[i].job_pstion);
            printf("Edad: %d\n", vector[i].age);
            return i;
        }
    }
    return -1;
}
// Prototipos de archivos
int busquedabinaria(Twrkr vect[], int claveBuscada, int min, int max)
{
    while (min <= max)
    {
        int mid = min + (max - min) / 2;

        if (vect[mid].enrollment == claveBuscada)
            return mid;
        if (vect[mid].enrollment < claveBuscada)
            min = mid + 1;
        else
            max = mid - 1;
    }

    return -1;
}
int tamanio()
{
    FILE *fa = fopen("registros.dat", "rb");
    int t_reg = 0;
    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        int tam = ftell(fa);
        int total = tam / sizeof(Twrkr); // se sca el total
        if (total < 4)
        {
            t_reg = 100;
        }
        else
        {
            t_reg = (int)(total * 1.25) + 100;
        }
        fclose(fa);
    }
    else
    {
        t_reg = 100;
    }
    return t_reg;
}
int cargararchivo(Twrkr vector[], int m)
{
    FILE *fa = fopen("registros.dat", "rb");
    if (fa == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return m;
    }

    int i = m;
    while (i < tamanio() && fread(&vector[i], sizeof(Twrkr), 1, fa) == 1)
    {
        i++;
    }

    fclose(fa);
    return i;
}
Twrkr agregar_random(Twrkr vector[], int tamanio)
{
    Twrkr reg;
    char estado[32][3] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG",
                          "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC",
                          "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
                          "YN", "ZS"};
    char trabajo[12][10] = {"DevSoft", "TrabSoc", "Traduct", "ProfPrim", "IngRed", "AsistAdm",
                            "IngElec", "InvCien", "AnlSist", "IngCivil", "ChefEje", "AsServ"};
    char nombre_hombre[20][20] = {"Juan", "Pedro", "Luis", "Carlos", "Javier", "Andres", "Fernando", "Diego", "Alejandro", "David",
                                  "Ricardo", "Sergio", "Hector", "Victor", "Manuel", "Arturo", "Mario", "Pablo", "Raul",
                                  "Jorge"};
    char nombre_mujer[20][20] = {"Maria", "Ana", "Laura", "Patricia", "Isabel", "Carmen", "Sofia", "Lucia", "Claudia",
                                 "Veronica", "Gabriela", "Monica", "Sandra", "Elena", "Teresa", "Rosa", "Adriana",
                                 "Carolina", "Natalia", "Vanessa"};
    char apellido[20][20] = {"Gonzalez", "Hernandez", "Lopez", "Martinez", "Perez", "Garcia", "Rodriguez", "Sanchez",
                             "Ramirez", "Torres", "Flores", "Rivera", "Cruz", "Morales", "Reyes", "Gutierrez",
                             "Jimenez", "Mendoza", "Castillo", "Ortega"};
    int sexo[2] = {0, 1};
    reg.status = 1;
    reg.enrollment = (rand() % 9999999) + 300000;

    while (no_repeticion(vector, tamanio, reg.enrollment))
    {
        reg.enrollment = (rand() % 9999999) + 300000;
    }

    reg.cell_phone = 1000000 + rand() % 9000000;
    strcpy(reg.last_name_1, apellido[rand() % 20]);
    strcpy(reg.last_name_2, apellido[rand() % 20]);

    if ((rand() % 2) == 0)
    {
        strcpy(reg.name, nombre_hombre[rand() % 20]);
        strcpy(reg.sex, "Hombre");
    }
    else
    {
        strcpy(reg.name, nombre_mujer[rand() % 20]);
        strcpy(reg.sex, "Mujer");
    }

    reg.age = 18 + rand() % 50;
    strcpy(reg.job_pstion, trabajo[rand() % 12]);
    strcpy(reg.state, estado[rand() % 32]);

    return reg;
}
int no_repeticion(Twrkr vector[], int inicio, int clave)
{
    for (int i = 0; i < inicio; i++)
    {
        if (vector[i].enrollment == clave)
        {
            return 1;
        }
    }
    return 0;
}
void generar_archivotxt_de_bin(const char nombre_archivo_binario[])
{
    Twrkr reg;
    FILE *fa;
    int cont = 1;

    fa = fopen(nombre_archivo_binario, "rb");
    if (!fa)
    {
        printf("Error al abrir el archivo binario '%s'.\n", nombre_archivo_binario);
        return;
    }

    char nombreArchivoTxt[100];
    printf("\nIngrese el nombre del archivo de texto (sin extension): ");
    my_gets(nombreArchivoTxt, 100);
    strcat(nombreArchivoTxt, ".txt");

    FILE *archivoTxt = fopen(nombreArchivoTxt, "w");
    if (!archivoTxt)
    {
        printf("Error al crear el archivo de texto.\n");
        fclose(fa);
        return;
    }

    fprintf(archivoTxt, "| No. | STATUS | No.trabajador |     NOMBRE     |   APPAT    |   APMAT    | SEXO |  EDAD  | TELEFONO     | ESTADO   | PUESTO\n");
    fprintf(archivoTxt, "---------------------------------------------------------------------------------------------------------------\n");

    while (fread(&reg, sizeof(Twrkr), 1, fa) == 1)
    {
        if (reg.status == 1)
        {
            fprintf(archivoTxt, "| %-3d | %-6d | %-13d | %-13s | %-10s | %-10s | %-4s | %-6d | %-12lld | %-8s | %-s\n",
                    cont++,
                    reg.status,
                    reg.enrollment,
                    reg.name,
                    reg.last_name_1,
                    reg.last_name_2,
                    reg.sex,
                    reg.age,
                    reg.cell_phone,
                    reg.state,
                    reg.job_pstion);
        }
    }

    fclose(fa);
    fclose(archivoTxt);
    printf("\nArchivo de texto '%s' generado exitosamente.\n", nombreArchivoTxt);
}
void elimina_reg(Twrkr vector[], int *num_registros)
{
    int matricula = validar(300000, 3999999, "Ingrese la matrícula a eliminar: ");
    int pos = busquedasecuencial(vector, *num_registros, matricula);

    if (pos != -1)
    {
        printf("\nDatos del trabajador:\n");
        printf("Matrícula: %d\n", vector[pos].enrollment);
        printf("Nombre: %s %s %s\n", vector[pos].name, vector[pos].last_name_1, vector[pos].last_name_2);
        printf("Sexo: %c\n", vector[pos].sex);
        printf("Teléfono: %lld\n", vector[pos].cell_phone);

        int confirmacion = validar(0, 1, "¿Eliminar este registro? (1=Sí, 0=No): ");
        if (confirmacion == 1)
        {
            vector[pos].status = 0;
            printf("Registro marcado como eliminado.\n");
            for (int i = pos; i < *num_registros - 1; i++)
            {
                vector[i] = vector[i + 1];
            }
            (*num_registros)--;
        }
    }
    else
    {
        printf("No se encontró la matrícula especificada.\n");
    }
}
void busqueda_secuencial(Twrkr vector[], int m, int num)
{
    int pos;
    pos = busquedasecuencial(vector, m, num);
    if (pos != -1)
    {
        printf("El trabajador existe y esta en el indice %d\n", pos);
        printf("\n| STATUS  | No.TRabajador |  NOMBRE     |    APPAT     |   APMAT     |  SEXO  | Posicion |stado|edad |No.Telefono\n");
        printf("|  %d      |   %10d  |  %-10s |  %-11s | %11s | %6s | %8s |  %s | %d  | %d\n",
               vector[pos].status, vector[pos].enrollment, vector[pos].name, vector[pos].last_name_1,
               vector[pos].last_name_2, vector[pos].sex, vector[pos].job_pstion, vector[pos].state,
               vector[pos].age, vector[pos].cell_phone);
    }
}
void crearArchivoBinario(Twrkr *registros, int totalRegistros)
{
    if (totalRegistros == 0)
    {
        printf("\nNo hay registros para guardar.\n");
        return;
    }

    rename(NOMBRE_ARCHIVO_BINARIO, NOMBRE_ARCHIVO_RESPALDO);

    FILE *archivo = fopen(NOMBRE_ARCHIVO_BINARIO, "wb");
    if (archivo == NULL)
    {
        printf("\nError al crear el archivo binario.\n");
        rename(NOMBRE_ARCHIVO_RESPALDO, NOMBRE_ARCHIVO_BINARIO);
        return;
    }

    int registrosEscritos = 0;
    for (int i = 0; i < totalRegistros; i++)
    {
        if (registros[i].status == 1)
        {
            fwrite(&registros[i], sizeof(Twrkr), 1, archivo);
            registrosEscritos++;
        }
    }

    fclose(archivo);

    if (registrosEscritos > 0)
    {
        printf("\nArchivo binario '%s' creado correctamente con %d registros.\n",
               NOMBRE_ARCHIVO_BINARIO, registrosEscritos);
        if (registrosEscritos < totalRegistros)
        {
            printf("Se omitieron %d registros con status diferente de 1.\n",
                   totalRegistros - registrosEscritos);
        }
    }
    else
    {
        printf("\nNo se escribieron registros al archivo binario.\n");
        rename(NOMBRE_ARCHIVO_RESPALDO, NOMBRE_ARCHIVO_BINARIO);
    }
}
void agregar_usuario_manual(Twrkr vector[], int tamanio)
{
    printf("Nombre:");
    my_gets(vector[tamanio].name, 50);
    convercionmayusculas(vector[tamanio].name);
    printf("Apellido Paterno:");
    my_gets(vector[tamanio].last_name_1, 50);
    convercionmayusculas(vector[tamanio].last_name_1);
    printf("Apellido Materno:");
    my_gets(vector[tamanio].last_name_2, 50);
    convercionmayusculas(vector[tamanio].last_name_2);
    printf("Sexo:");
    my_gets(vector[tamanio].sex, 10);
    convercionmayusculas(vector[tamanio].sex);
    printf("Puesto:");
    my_gets(vector[tamanio].job_pstion, 50);
    convercionmayusculas(vector[tamanio].job_pstion);
    printf("Estado:");
    my_gets(vector[tamanio].state, 20);
    convercionmayusculas(vector[tamanio].state);
    printf("Edad:");
    vector[tamanio].age = validar(18, 99, "Ingrese la edad: ");
    printf("Telefono:");
    vector[tamanio].cell_phone = validar(1000000, 9999999, "Ingrese el telefono: ");
    vector[tamanio].status = 1;
    do
    {
        vector[tamanio].enrollment = (rand() % 9999999) + 300000;
    } while (no_repeticion(vector, tamanio, vector[tamanio].enrollment));
}
int leer_archivo_bin(Twrkr vector[], int m)
{
    int i = 0;
    FILE *fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        return 0; // No se pudo abrir el archivo
    }

    printf("|STATUS| No.trabajador|    NOMBRE    |     APPAT     | GENERO | EDAD | No.TELEFONO | ESTADO | PUESTO\n");
    printf("---------------------------------------------------------------------------------------------------\n");

    while (i < m && fread(&vector[i], sizeof(Twrkr), 1, fa) == 1)
    {
        printf(" %5d %13d %-12s %-14s %-7s %5d %12d %8s %-15s\n",
               vector[i].status,
               vector[i].enrollment,
               vector[i].name,
               vector[i].last_name_1,
               vector[i].sex,
               vector[i].age,
               vector[i].cell_phone,
               vector[i].state,
               vector[i].job_pstion);
        i++;
    }

    fclose(fa);
    return i;
}
void eliminar_registro(Twrkr vector[], int num_registros)
{
    int matricula = validar(300000, 3999999, "Ingrese la Clave a eliminar: ");
    int posicion = busquedasecuencial(vector, num_registros, matricula);
    int confirmacion;
    if (posicion != -1)
    {
        confirmacion = validar(0, 1, "Esta seguro de que desea eliminar este registro? (1=Si, 0=No): ");
        if (confirmacion == 1)
        {
            vector[posicion].status = 0;
            printf("Registro eliminado.\n");
        }
        else
        {
            printf("Eliminacion cancelada.\n");
        }
    }
    else
    {
        printf("Chalan no encontrado.\n");
    }
}
void imprimir_archivo_binario(Twrkr vector[], int tamanio)
{
    int cont = 1;
    printf("No.REG|STATUS| No.trabajador|    NOMBRE    |     APPAT     | GENERO | EDAD | No.TELEFONO | ESTADO | PUESTO\n");
    for (int i = 0; i < tamanio; i++)
    {
        if (vector[i].status == 1)
            printf("%d | %-1d | %-6d | %-12s | %-12s | %-12s | %-7s | %-10s | %-2s | %-2d | %-7d |\n",
                   cont++,
                   vector[i].status,
                   vector[i].enrollment,
                   vector[i].name,
                   vector[i].last_name_1,
                   vector[i].last_name_2,
                   vector[i].sex,
                   vector[i].job_pstion,
                   vector[i].state,
                   vector[i].age,
                   vector[i].cell_phone);
    }
}
void guardar_archivo(Twrkr *vector, int num_registros, const char *nombre)
{
    FILE *f = fopen(nombre, "wb");
    if (f)
    {
        fwrite(vector, sizeof(Twrkr), num_registros, f);
        fclose(f);
    }
}
void imprimir_arch_ordenado(Twrkr vector[], int tamanio)
{
    int contador = 1;
    printf("|STATUS| No.trabajador|    NOMBRE    |     APPAT     | GENERO | EDAD | No.TELEFONO | ESTADO | PUESTO\n");
    for (int i = 0; i < tamanio; i++)
    {
        if (vector[i].status == 1)
        {
            printf("%d |%-1d | %-6d | %-12s | %-12s | %-12s | %-7s | %-10s | %-2s | %-2d | %-7d |\n",
                   contador++,
                   vector[i].status,
                   vector[i].enrollment,
                   vector[i].name,
                   vector[i].last_name_1,
                   vector[i].last_name_2,
                   vector[i].sex,
                   vector[i].job_pstion,
                   vector[i].state,
                   vector[i].age,
                   vector[i].cell_phone);
        }
    }
}
void generar_archivo_binario(Twrkr vector[], int tamanio)
{
    FILE *fb;
    fb = fopen("registros.dat", "wb");
    if (fb == NULL)
    {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }
    for (int i = 0; i < tamanio; i++)
    {
        if (vector[i].status == 1)
        {
            fwrite(&vector[i], sizeof(Twrkr), 1, fb);
        }
    }
    fclose(fb);
    printf("Ya quedo mi valedor\n");
}
Tusuario iniciar_sesion()
{
    Tusuario reg;
    char usuario_ingresado[20], contrasenia_ingresada[20];
    int intentos = 0;
    bool encontrado = false;

    // Inicializar como inválido en caso de fallo
    reg.nivel_usuario = -1;
    reg.status = -1;

    while (intentos < 3)
    {
        FILE *fb = fopen("claves.dll", "rb+"); // abrir en lectura y escritura
        if (fb == NULL)
        {
            printf("No se pudo abrir el archivo de usuarios.\n");
            return reg;
        }

        printf("Ingrese su usuario: \n");
        my_gets(usuario_ingresado, 20);
        printf("Ingrese su contrasenia: \n");
        leer_contrasenia(contrasenia_ingresada, 20);

        int pos = 0;
        while (fread(&reg, sizeof(Tusuario), 1, fb) == 1)
        {
            if (strcmp(reg.usuario, usuario_ingresado) == 0)
            {
                encontrado = true;

                if (reg.status == 2)
                {
                    printf("Este usuario está bloqueado.\n");
                    fclose(fb);
                    exit(1);
                }

                if (strcmp(reg.contrasenia, contrasenia_ingresada) == 0)
                {
                    printf("Inicio de sesion exitoso. Nivel de acceso: %d\n", reg.nivel_usuario);
                    fclose(fb);
                    return reg;
                }
                else
                {
                    intentos++;
                    if (intentos >= 3)
                    {
                        printf("Demasiados intentos fallidos. Usuario bloqueado.\n");
                        reg.status = 2;
                        fseek(fb, pos * sizeof(Tusuario), SEEK_SET);
                        fwrite(&reg, sizeof(Tusuario), 1, fb);
                        fclose(fb);
                        exit(1);
                    }
                    else
                    {
                        printf("Contraseña incorrecta. Intentos restantes: %d\n", 3 - intentos);
                        fclose(fb);
                        break;
                    }
                }
            }
            pos++;
        }

        if (!encontrado)
        {
            printf("Usuario no encontrado. Intentos restantes: %d\n", 2 - intentos);
            intentos++;
        }
    }

    printf("Se han agotado los intentos.\n");
    return reg;
}
void inicializar_claves()
{
    FILE *archivo = fopen("claves.dll", "rb");
    if (archivo == NULL)
    {
        printf("Archivo 'claves.dll' no encontrado. Creando con usuarios por defecto...\n");

        archivo = fopen("claves.dll", "wb");
        if (archivo == NULL)
        {
            perror("Error al crear 'claves.dll'");
            exit(1);
        }

        Tusuario usuarios_iniciales[3] = {
            {1, "userN1", "ensenada", 1},
            {1, "userN2", "ensenada10", 2},
            {1, "userN3", "Ensenada-646", 3}};

        fwrite(usuarios_iniciales, sizeof(Tusuario), 3, archivo);
        fclose(archivo);
        printf("Usuarios iniciales guardados correctamente en 'claves.dll'.\n");
    }
    else
    {
        fclose(archivo);
        printf("Archivo 'claves.dll' ya existe.\n");
    }
}
void verificarOCrearArchivoDatos(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        printf("Archivo '%s' no existe. Creando reg archivo...\n", nombreArchivo);
        archivo = fopen(nombreArchivo, "wb"); // crea archivo en blanco
        if (archivo == NULL)
        {
            perror("Error al crear el archivo");
            exit(EXIT_FAILURE);
        }
        fclose(archivo);
        printf("Archivo '%s' creado correctamente.\n", nombreArchivo);
    }
    else
    {
        fclose(archivo);
        printf("Archivo '%s' encontrado.\n", nombreArchivo);
    }
}
void agregar_usuario_manual(Tusuario vector[], int *tamanio)
{
    Tusuario reg;
    FILE *fb = fopen("claves.dll", "rb");
    if (!fb)
    {
        printf("No se pudo abrir claves.dll para validación.\n");
        return;
    }

    printf("Ingrese nombre de usuario: ");
    my_gets(reg.usuario, 20);

    Tusuario tmp;
    while (fread(&tmp, sizeof(Tusuario), 1, fb) == 1)
    {
        if (strcmp(tmp.usuario, reg.usuario) == 0 && tmp.status != 0)
        {
            printf("El usuario ya existe.\n");
            fclose(fb);
            return;
        }
    }
    fclose(fb);

    printf("Ingrese contrasenia: ");
    my_gets(reg.contrasenia, 20);

    reg.nivel_usuario = validar(1, 3, "Nivel de acceso");
    reg.status = 1;

    // Guardar en archivo
    FILE *f = fopen("claves.dll", "ab");
    if (!f)
    {
        printf("Error al abrir claves.dll para escritura.\n");
        return;
    }
    fwrite(&reg, sizeof(Tusuario), 1, f);
    fclose(f);

    // Guardar también en el vector
    vector[*tamanio] = reg;
    (*tamanio)++;

    printf("Usuario agregado correctamente.\n");
}
int cargararchivo2(Tusuario vector[], int m)
{
    FILE *fa = fopen("claves.dll", "rb");
    if (fa == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return m;
    }

    int i = m;
    while (i < tamanio() && fread(&vector[i], sizeof(Tusuario), 1, fa) == 1)
    {
        i++;
    }

    fclose(fa);
    return i;
}
void eliminar_registro(Tusuario vector[], int *tamanio)
{
    char usuario[20];
    printf("Ingrese el nombre de usuario a eliminar: ");
    my_gets(usuario, 20);

    int pos = -1;
    for (int i = 0; i < *tamanio; i++)
    {
        if (strcmp(vector[i].usuario, usuario) == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        if (vector[pos].status == 0)
        {
            printf("El usuario '%s' ya está eliminado.\n", usuario);
            return;
        }

        int confirmacion = validar(0, 1, "Está seguro de que desea eliminar este usuario (1=Sí, 0=No): ");
        if (confirmacion == 1)
        {
            vector[pos].status = 0;
            FILE *f = fopen("claves.dll", "rb+");
            if (!f)
            {
                printf("Error al abrir claves.dll para escritura.\n");
                return;
            }

            fseek(f, pos * sizeof(Tusuario), SEEK_SET);
            fwrite(&vector[pos], sizeof(Tusuario), 1, f);
            fclose(f);

            printf("Usuario '%s' eliminado correctamente.\n", usuario);
        }
        else
        {
            printf("Eliminación cancelada.\n");
        }
    }
    else
    {
        printf("Usuario '%s' no encontrado.\n", usuario);
    }
}
void modificar_nivel(Tusuario vector[], int tamanio)
{
    char nombre[20];
    printf("Ingrese el nombre de usuario para modificar el nivel: ");
    my_gets(nombre, 20);

    int encontrado = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (strcmp(vector[i].usuario, nombre) == 0 && vector[i].status == 1)
        {
            int nuevo = validar(1, 3, "Nuevo nivel (1-Usuario, 2-Mod, 3-Admin): ");
            vector[i].nivel_usuario = nuevo;

            FILE *f = fopen("claves.dll", "rb+");
            if (!f)
            {
                printf("Error al abrir claves.dll.\n");
                return;
            }

            fseek(f, i * sizeof(Tusuario), SEEK_SET);
            fwrite(&vector[i], sizeof(Tusuario), 1, f);
            fclose(f);

            printf("Nivel actualizado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuario no encontrado o inactivo.\n");
    }
}
void quitar_bloqueo(Tusuario vector[], int tamanio)
{

    char nombre[20];
    printf("Ingrese el nombre de usuario a desbloquear: ");
    my_gets(nombre, 20);

    int encontrado = 0;

    for (int i = 0; i < tamanio; i++)
    {
        if (strcmp(vector[i].usuario, nombre) == 0 && vector[i].status == 2)
        {
            vector[i].status = 1;

            FILE *f = fopen("claves.dll", "rb+");
            if (!f)
            {
                printf("Error al abrir claves.dll.\n");
                return;
            }

            fseek(f, i * sizeof(Tusuario), SEEK_SET);
            fwrite(&vector[i], sizeof(Tusuario), 1, f);
            fclose(f);

            printf("Usuario desbloqueado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("no se encontro el usuario.\n");
    }
}
void leer_contrasenia(char *cadena, int caracteres)
{
    int posicion = 0;
    char caracter_actual;

    while ((caracter_actual = _getch()) != 13 && posicion < caracteres - 1)
    {
        if (caracter_actual == 8 && posicion > 0)
        {
            posicion--;
            printf("\b \b");
        }
        else if (caracter_actual >= 32 && caracter_actual <= 126)
        {
            cadena[posicion++] = caracter_actual;
            printf("*");
        }
    }

    cadena[posicion] = '\0';
}
int tamanio2()
{
    FILE *fa = fopen("claves.dll", "rb");
    int t_reg = 0;
    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        int tam = ftell(fa);
        int total = tam / sizeof(Twrkr); // se sca el total
        if (total < 4)
        {
            t_reg = 100;
        }
        else
        {
            t_reg = (int)(total * 1.25) + 100;
        }
        fclose(fa);
    }
    else
    {
        t_reg = 100;
    }
    return t_reg;
}
#endif