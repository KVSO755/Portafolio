#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// PROTOTIPOS
//  Funciones de limpieza y presentacion
void cls();
void pause();
void titulo();
void mensajeria(int estado);

// Funciones validar
int validar_fecha(char num[]);
int validar_texto(char text[]);
void validar_estado(int cod_estado, char estado[]);
void validar_sexo(int cod_sexo, char sexo[]);

// Funciones especificas para curp
void cat_die(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char cat_die_i[]);
void diescisiete(char fecha[], char diescisiete_i[]);
void diesciocho(char fecha[], char diesciocho_i[]);
char retorna_consonante_interna(char text[]);
char retorna_vocal_interna(char text[]);

// Funciones de excepciones y verificaciones
int excepcion_mariajose(char primer_nombre[]);
int excepcion_compuestos(char texto[]);
int excepcion_altisonantes(char curp[]);
int verifica_vacio(char text[]);
int verifica_vocal_interna(char text[]);

// Funciones principales
int msges();
void comenzar(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[]);
void genera_curp(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[]);
void imprimir_curp(char curp[]);

// desarrollo de funciones
void cls()
{
    system("cls");
}

void pause()
{
    system("pause");
}

void titulo()
{
    printf("\n");
    printf("                                                                                             \n");
    printf("                                         C U R P                                             \n");
    printf("                                                                                             \n");
}

void mensajeria(int estado)
{

    switch (estado)
    {
    case 0:
        printf("\n=================== BIENVENIDO ===================\n");
        printf("Este programa generar%c tu CURP.\n", 160);
        printf("==================================================\n\n");
        break;

    case 1:
        printf("\n[1] INGRESA TU PRIMER APELLIDO\n");
        printf("    - Solo letras A-Z\n");
        printf("    - Acepta: punto (.), diagonal (/), guion (-), apostrofe ('), dieresis = X\n");
        break;

    case 2:
        printf("\n[2] INGRESA TU SEGUNDO APELLIDO\n");
        printf("    - Solo letras A-Z\n");
        printf("    - Acepta: punto (.), diagonal (/), guion (-), apostrofe ('), dieresis = X\n");
        break;

    case 3:
        printf("\n[3] INGRESA TU PRIMER NOMBRE\n");
        printf("    - Solo letras A-Z\n");
        printf("    - Acepta: punto (.), diagonal (/), guion (-), apostrofe ('), dieresis = X\n");
        break;

    case 4:
        printf("\n[4] INGRESA TU SEGUNDO NOMBRE (si aplica)\n");
        printf("    - Letras A-Z y caracteres v%clidos mencionados antes\n", 160);
        printf("    - Si tienes m%cs de dos nombres, introd%ccelos juntos aqu%c\n", 160, 163, 161);
        break;
    case 5:
        printf("\n[5] INGRESA TU FECHA DE NACIMIENTO\n");
        printf("    - Formato: DD/MM/AAAA\n");
        printf("    - Solo n%cmeros y diagonales (/)\n", 163);
        break;

    case 6:
        printf("\n[6] SELECCIONA TU ESTADO DE NACIMIENTO (CODIGO)\n");
        printf("    Ingresa el n%cmero correspondiente al estado donde naciste:\n\n", 163);
        printf("    01 - Aguascalientes         17 - Morelos\n");
        printf("    02 - Baja California        18 - Nayarit\n");
        printf("    03 - Baja California Sur    19 - Nuevo Le%cn\n", 162);
        printf("    04 - Campeche               20 - Oaxaca\n");
        printf("    05 - Coahuila               21 - Puebla\n");
        printf("    06 - Colima                 22 - Quer%ctaro\n", 130);
        printf("    07 - Chiapas                23 - Quintana Roo\n");
        printf("    08 - Chihuahua              24 - San Luis Potos%c\n", 161);
        printf("    09 - Ciudad de M%cxico       25 - Sinaloa\n", 130);
        printf("    10 - Durango                26 - Sonora\n");
        printf("    11 - Guanajuato             27 - Tabasco\n");
        printf("    12 - Guerrero               28 - Tamaulipas\n");
        printf("    13 - Hidalgo                29 - Tlaxcala\n");
        printf("    14 - Jalisco                30 - Veracruz\n");
        printf("    15 - M%cxico                 31 - Yucat%cn\n", 130, 160);
        printf("    16 - Michoac%cn              32 - Zacatecas\n", 160);
        printf("                                33 - Nacido en el Extranjero\n");
        break;
    case 7:
        printf("|                                                                                             |\n");
        printf("|  Introduce tu SEXO:                                                                         |\n");
        printf("|  - 01: MUJER  02: HOMBRE  -                                                                 |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;
    }
}

/*
 * Funciones para validar
 * Valida la entrada de una fecha en el formato DD/MM/AAAA.
 * Se solciita  una fecha y verifica que cumpla con el formato y los rangos validos
 */

int validar_fecha(char fecha[])
{
    int valido = 0;

    do
    {
        valido = 1;
        printf(" -> : ");

        if (!my_gets(fecha, 11))
        {
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(fecha);

        if (fecha[longitud - 1] == '\n')
        {
            fecha[longitud - 1] = '\0';
        }

        if (longitud != 10 || fecha[2] != '/' || fecha[5] != '/')
        {
            printf("\nFormato de fecha incorrecto. Debe ser DD/MM/AAAA.\n");
            valido = 0;
            continue;
        }

        int dia = atoi(fecha);
        int mes = atoi(fecha + 3);
        int anio = atoi(fecha + 6);

        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900 || anio > 2025)
        {
            printf("\nFecha fuera de rango. Introduce una fecha valida.\n");
            valido = 0;
        }

    } while (!valido);

    return 1;
}
/*
 *Valida una cadena ingresada
 *Verifica que la cadena ingresada no contenga caracteres
 *no permitidos, espacios en blanco al inicio o al final, y transforma
 *caracteres con tilde en su equivalente sin ellos
 */

int validar_texto(char text[])
{
    int valido = 0;

    do
    {
        valido = 1;

        char a_t_min = 160;
        char e_t_min = 130;
        char i_t_min = 161;
        char o_t_min = 162;
        char u_t_min = 163;

        char a_t_may = 181;
        char e_t_may = 144;
        char i_t_may = 214;
        char o_t_may = 224;
        char u_t_may = 233;

        char enie_min = 164;
        char enie_may = 165;
        char x_may = 88;

        char punto = 46;
        char diagonal = 47;
        char guion = 45;
        char apost = 39;

        // char vocales_acent_min[] = {160, 130, 161, 162, 163};
        // char vocales_acent_may[] = {181, 144, 214, 224, 233};
        char vocales_min[] = {'a', 'e', 'i', 'o', 'u'};
        char vocales_may[] = {'A', 'E', 'I', 'O', 'U'};

        printf(" -> : ");
        if (!my_gets(text, 100))
        {
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(text);

        // Eliminar el caracter de nueva linea si existe
        if (text[longitud - 1] == '\n')
        {
            text[longitud - 1] = '\0';
        }

        // Verificar si el texto contiene espacios en blanco al inicio o al final
        if (isspace(text[0]) || isspace(text[longitud - 1]))
        {
            printf("\nEl texto no puede contener espacios en blanco al inicio o al final.\n");
            valido = 0;
        }

        // Verificar si el texto contiene caracteres no permitidos
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (!(isalpha(text[i]) || text[i] == ' ' || text[i] == enie_min || text[i] == enie_may || text[i] == '.' || text[i] == '/' || text[i] == '-' || text[i] == '\''))
            {
                printf("\nCaracter no permitido. Intentalo de nuevo.\n");
                valido = 0;
                break;
            }
        }

        // Cambios
        for (int i = 0; text[i] != '\0'; i++)
        {
            // De tildes
            if (text[i] == a_t_min || text[i] == a_t_may)
            {
                text[i] = vocales_may[0];
            }

            if (text[i] == e_t_min || text[i] == e_t_may)
            {
                text[i] = vocales_may[1];
            }

            if (text[i] == i_t_min || text[i] == i_t_may)
            {
                text[i] = vocales_may[2];
            }

            if (text[i] == o_t_min || text[i] == o_t_may)
            {
                text[i] = vocales_may[3];
            }

            if (text[i] == u_t_min || text[i] == u_t_may)
            {
                text[i] = vocales_may[4];
            }

            // De x
            if (text[i] == enie_min || text[i] == enie_may || text[i] == punto || text[i] == diagonal || text[i] == guion || text[i] == apost)
            {
                text[i] = x_may;
            }
        }

        // Mayusculas
        for (int i = 0; text[i] != '\0'; i++)
        {
            text[i] = toupper(text[i]);
        }

    } while (!valido);

    return 1;
}
/*
 * Valida un codigo de estado ingresado por el usuario
 * Verifica que el codigo de estado ingresado sea un numero
 * valido del 1 al 33 y asigna el codigo a estado[]
 */

void validar_estado(int cod_estado, char estado[])
{
    int valido = 0;

    do
    {
        valido = 1;
        printf(" -> : ");

        if (scanf("%d", &cod_estado) != 1 || cod_estado < 1 || cod_estado > 33)
        {
            printf("\nCodigo de estado no valido. Debe ser un numero del 1 al 33.\n");
            valido = 0;
        }

        else
        {
            switch (cod_estado)
            {
            case 1:
                strcpy(estado, "AS");
                break;
            case 2:
                strcpy(estado, "BC");
                break;
            case 3:
                strcpy(estado, "BS");
                break;
            case 4:
                strcpy(estado, "CC");
                break;
            case 5:
                strcpy(estado, "CL");
                break;
            case 6:
                strcpy(estado, "CM");
                break;
            case 7:
                strcpy(estado, "CS");
                break;
            case 8:
                strcpy(estado, "CH");
                break;
            case 9:
                strcpy(estado, "DF");
                break;
            case 10:
                strcpy(estado, "DG");
                break;
            case 11:
                strcpy(estado, "GT");
                break;
            case 12:
                strcpy(estado, "GR");
                break;
            case 13:
                strcpy(estado, "HG");
                break;
            case 14:
                strcpy(estado, "JC");
                break;
            case 15:
                strcpy(estado, "MC");
                break;
            case 16:
                strcpy(estado, "MN");
                break;
            case 17:
                strcpy(estado, "MS");
                break;
            case 18:
                strcpy(estado, "NT");
                break;
            case 19:
                strcpy(estado, "NL");
                break;
            case 20:
                strcpy(estado, "OC");
                break;
            case 21:
                strcpy(estado, "PL");
                break;
            case 22:
                strcpy(estado, "QT");
                break;
            case 23:
                strcpy(estado, "QR");
                break;
            case 24:
                strcpy(estado, "SP");
                break;
            case 25:
                strcpy(estado, "SL");
                break;
            case 26:
                strcpy(estado, "SR");
                break;
            case 27:
                strcpy(estado, "TC");
                break;
            case 28:
                strcpy(estado, "TS");
                break;
            case 29:
                strcpy(estado, "TL");
                break;
            case 30:
                strcpy(estado, "VZ");
                break;
            case 31:
                strcpy(estado, "YN");
                break;
            case 32:
                strcpy(estado, "ZS");
                break;
            case 33:
                strcpy(estado, "NE");
                break;
            }
        }

        while (getchar() != '\n')
            ;

    } while (!valido);
}

/*
 * Valida un codigo de sexo ingresado
 * Verifica que el codigo de sexo ingresado sea 1 para MUJER o 2 para HOMBRE
 * y asigna el codigo en sexo[]
 */

void validar_sexo(int cod_sexo, char sexo[])
{
    int valido = 0;

    do
    {
        valido = 1;
        printf(" -> : ");

        if (scanf("%d", &cod_sexo) != 1 || (cod_sexo != 1 && cod_sexo != 2))
        {
            printf("\nCodigo de sexo no valido. Debe ser: 1 para MUJER y 2 para HOMBRE.\n");
            valido = 0;
        }
        else
        {
            switch (cod_sexo)
            {
            case 1:
                strcpy(sexo, "M");
                break;

            case 2:
                strcpy(sexo, "H");
                break;
            }
        }

        while (getchar() != '\n')
            ;

    } while (!valido);
}

/*
 * Funciones especificas
 */

/*
 * Genera las primeras consonantes internas de los apellidos y nombres ingresados
 * Busca la primera consonante interna de cada componente (apellido paterno, apellido materno y nombre)
 * En caso de no encontrar consonantes internas se asigna una X
 */

void cat_die(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char cat_die_i[])
{
    int long_pa = strlen(primer_apellido);
    int long_sa = strlen(segundo_apellido);
    int long_pn = strlen(primer_nombre);

    for (int i = 1; i < long_pa; i++)
    {
        if (primer_apellido[i] != 'A' && primer_apellido[i] != 'E' && primer_apellido[i] != 'I' && primer_apellido[i] != 'O' && primer_apellido[i] != 'U')
        {
            cat_die_i[0] = primer_apellido[i];
            break;
        }

        cat_die_i[0] = 'X';
    }

    for (int i = 1; i < long_sa; i++)
    {
        if (segundo_apellido[i] != 'A' && segundo_apellido[i] != 'E' && segundo_apellido[i] != 'I' && segundo_apellido[i] != 'O' && segundo_apellido[i] != 'U')
        {
            cat_die_i[1] = segundo_apellido[i];
            break;
        }

        cat_die_i[1] = 'X';
    }

    for (int i = 1; i < long_pn; i++)
    {

        // Verificar si el primer nombre está en la lista de excepciones para usar el segundo nombre
        if (excepcion_mariajose(primer_nombre))
        {

            if (segundo_nombre[i] != 'A' && segundo_nombre[i] != 'E' && segundo_nombre[i] != 'I' && segundo_nombre[i] != 'O' && segundo_nombre[i] != 'U')
            {
                cat_die_i[2] = segundo_nombre[i];
                break;
            }

            cat_die_i[2] = 'X';
        }

        if (primer_nombre[i] != 'A' && primer_nombre[i] != 'E' && primer_nombre[i] != 'I' && primer_nombre[i] != 'O' && primer_nombre[i] != 'U')
        {
            cat_die_i[2] = primer_nombre[i];
            break;
        }

        cat_die_i[2] = 'X';
    }
}

/*
 * Genera el digito correspondiente al año de nacimiento
 * Asigna A si el año de nacimiento esta entre 2000 y 2010
 * B si esta entre 2011 y 2020 y C si esta entre 2021 y 2030
 * Si el año de nacimiento es anterior a 2000 o posterior a 2030 se asigna 0 en su lugar
 */

void diescisiete(char fecha[], char diescisiete_i[])
{
    int anio = atoi(fecha + 6);

    if (anio >= 1900 && anio <= 1999)
    {
        diescisiete_i[0] = '0';
    }
    else if (anio >= 2000 && anio <= 2028)
    {
        diescisiete_i[0] = 'A';
    }
    else
    {
        diescisiete_i[0] = '?'; // año no válido
    }
}

/*
 * Genera el digito correspondiente al año de nacimiento para la posicion 18 del CURP
 * Si el año de nacimiento es anterior a 2000 se asigna 0
 * si es 2000 se asigna 1 y se incrementa en 1 por cada 5 años desps del 2000
 */

void diesciocho(char fecha[], char diesciocho_i[])
{
    int anio = atoi(fecha + 6);

    if (anio < 2000)
    {
        diesciocho_i[0] = '0';
    }

    else
    {
        // Calcular el valor basado en la diferencia del año actual con 2000
        int valor = (anio - 2000) / 5 + 1;

        diesciocho_i[0] = valor + '0';
    }
}

char retorna_consonante_interna(char text[])
{
    char consonante = '\0';
    const char vocales[] = "AEIOU";

    for (int i = 1; text[i] != '\0'; i++)
    {
        int es_vocal = 0;

        for (int j = 0; vocales[j] != '\0'; j++)
        {
            if (text[i] == vocales[j])
            {
                es_vocal = 1;
                break;
            }
        }

        if (!es_vocal && isalpha(text[i]))
        {
            consonante = text[i];
            break;
        }
    }

    return consonante;
}

char retorna_vocal_interna(char text[])
{
    char vocal_interna = '\0';
    char vocales[] = "AEIOU";

    for (int i = 1; text[i] != '\0'; i++)
    {
        int es_consonante = 1;

        for (int j = 0; vocales[j] != '\0'; j++)
        {
            if (text[i] == vocales[j])
            {
                es_consonante = 0;
                break;
            }
        }

        if (!es_consonante && isalpha(text[i]))
        {
            vocal_interna = text[i];
            break;
        }
    }

    return vocal_interna;
}
/*
 * Funciones de excepcion y verificacion        *
 */

int excepcion_mariajose(char texto[])
{
    char excepciones[][10] = {"MARIA", "MARXA", "MA.", "MA", "M.", "M", "JOSE", "JOSX", "J.", "J"};
    int num_excepciones = 10;

    for (int i = 0; i < num_excepciones; i++)
    {
        if (strcmp(texto, excepciones[i]) == 0)
        {
            return 1; // excepcion encontrada
        }
    }

    return 0; // no es una excepcion
}

int excepcion_compuestos(char texto[])
{
    char excepciones[][20] = {"DA", "LOS", "LA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};
    int num_excepciones = sizeof(excepciones) / sizeof(excepciones[0]);

    for (int i = 0; i < num_excepciones; i++)
    {
        if (strcmp(texto, excepciones[i]) == 0)
        {
            return 1; // excepcion encontrada
        }
    }

    return 0; // no es una excepcion
}

int excepcion_altisonantes(char curp[])
{
    char lista[][5] = {
        "BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA",
        "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE",
        "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA",
        "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA",
        "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE",
        "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "MAME",
        "MAMO", "MEAR", "MEAS", "MEON", "MION", "MOCO", "MOKO",
        "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE",
        "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA",
        "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA",
        "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    int num_palabras = sizeof(lista) / sizeof(lista[0]);

    for (int i = 0; i < num_palabras; i++)
    {
        if (strncmp(curp, lista[i], 4) == 0)
        {
            return 1; // Es una palabra altisonante
        }
    }

    return 0; // No es una palabra altisonante
}

int verifica_vacio(char text[])
{
    int longitud = strlen(text);

    if (longitud == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int verifica_vocal_interna(char text[])
{
    char vocales[] = "AEIOU";
    int i, j;

    for (i = 1; text[i] != '\0'; i++)
    {
        for (j = 0; vocales[j] != '\0'; j++)
        {
            if (text[i] == vocales[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

/*
 * Funciones principales                        *
 */

void comenzar(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[])
{

    cls();
    titulo();
    mensajeria(0);
    pause();

    cls();
    titulo();
    mensajeria(1);
    validar_texto(primer_apellido);

    cls();
    titulo();
    mensajeria(2);
    validar_texto(segundo_apellido);

    cls();
    titulo();
    mensajeria(3);
    validar_texto(primer_nombre);

    cls();
    titulo();
    mensajeria(4);
    validar_texto(segundo_nombre);

    cls();
    titulo();
    mensajeria(5);
    validar_fecha(fecha);

    cls();
    titulo();
    mensajeria(6);
    validar_estado(cod_estado, estado);

    cls();
    titulo();
    mensajeria(7);
    validar_sexo(cod_sexo, sexo);

    cat_die(primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, cat_die_i);
    diescisiete(fecha, diescisiete_i);
    diesciocho(fecha, diesciocho_i);

    genera_curp(curp, primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, fecha, cod_estado, estado, cod_sexo, sexo, cat_die_i, diescisiete_i, diesciocho_i);

    cls();
    titulo();
    imprimir_curp(curp);

    pause();
}

void genera_curp(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[])
{

    // POSICION 0 Y 1
    // corresponde a los dos primeros elementos del primer apellido

    if (!verifica_vacio(primer_apellido))
    {
        // Identificar posiciones vacias en el apellido compuesto
        int posiciones_vacias_apellido[10];
        int cont = 0;

        for (int i = 0; primer_apellido[i] != '\0'; i++)
        {
            if (primer_apellido[i] == ' ')
            {
                posiciones_vacias_apellido[cont] = i;
                cont++;
            }
        }

        // Si hay posiciones vacias es compuesto
        if (cont > 0)
        {
            int inicio = 0;
            char apellido_parte[100] = {0};

            // Dividir el apellido en partes basadas en las posiciones vacias
            for (int i = 0; i <= cont; i++)
            {
                int fin;
                if (i == cont)
                {
                    fin = strlen(primer_apellido);
                }
                else
                {
                    fin = posiciones_vacias_apellido[i];
                }

                // Copiando
                for (int j = inicio; j < fin; j++)
                {
                    apellido_parte[j - inicio] = primer_apellido[j];
                }

                // Añadir el caracter nulo
                apellido_parte[fin - inicio] = '\0';

                // Verificar
                if (!excepcion_compuestos(apellido_parte))
                {

                    if (!verifica_vocal_interna(apellido_parte))
                    {
                        curp[0] = apellido_parte[0];
                        curp[1] = 'X';
                    }
                    else
                    {
                        // Copiar los primeros dos caracteres
                        curp[0] = apellido_parte[0];
                        curp[1] = apellido_parte[1];
                        break;
                    }
                }

                inicio = posiciones_vacias_apellido[i] + 1;
            }
        }

        else
        {
            // Si no hay posiciones vacias no es compuesto
            curp[0] = primer_apellido[0];
            curp[1] = primer_apellido[1];
        }
    }

    else
    {
        curp[0] = 'X';
        curp[1] = 'X';
    }

    // POSICION 2
    // corresponde al primer elemento del segundo apellido

    if (!verifica_vacio(segundo_apellido))
    {
        // Identificar posiciones vacias en el apellido compuesto
        int posiciones_vacias_apellido[10] = {0};
        int cont = 0;

        for (int i = 0; segundo_apellido[i] != '\0'; i++)
        {
            if (segundo_apellido[i] == ' ')
            {
                posiciones_vacias_apellido[cont] = i;
                cont++;
            }
        }

        // Si hay posiciones vacias es compuesto
        if (cont > 0)
        {
            int inicio = 0;
            char apellido_parte[100] = {0};

            // Dividir el apellido en partes basadas en las posiciones vacias
            for (int i = 0; i <= cont; i++)
            {
                int fin;

                if (i == cont)
                {
                    fin = strlen(segundo_apellido);
                }

                else
                {
                    fin = posiciones_vacias_apellido[i];
                }

                for (int j = inicio; j < fin; j++)
                {
                    apellido_parte[j - inicio] = segundo_apellido[j];
                }

                // Añadir el caracter nulo
                apellido_parte[fin - inicio] = '\0';

                // Verificar
                if (!excepcion_compuestos(apellido_parte))
                {

                    curp[2] = apellido_parte[0];
                    break;
                }

                inicio = posiciones_vacias_apellido[i] + 1;
            }
        }

        else
        {
            // Si no hay posiciones vacias no es compuesto
            curp[2] = segundo_apellido[0];
        }
    }

    else
    {
        // si esta vacio
        curp[2] = 'X';
    }

    // POSICION 3
    // corresponde al primer elemento del primer nombre

    // Verificar si el primer nombre está en la lista de excepciones para el segundo nombre
    if (excepcion_mariajose(primer_nombre))
    {
        // Si el primer nombre está en la lista de excepciones, usar el segundo nombre
        curp[3] = segundo_nombre[0];
    }
    else
    {
        // Si no esta en la lista de excepciones usar el primer nombre
        curp[3] = primer_nombre[0];
    }

    // Completar el resto de la CURP
    curp[4] = fecha[8];
    curp[5] = fecha[9];
    curp[6] = fecha[3];
    curp[7] = fecha[4];
    curp[8] = fecha[0];
    curp[9] = fecha[1];

    curp[10] = sexo[0];

    curp[11] = estado[0];
    curp[12] = estado[1];

    // POSICION 13

    // Identificar posiciones vacias en el apellido compuesto
    int posiciones_vacias_apellido[10] = {0};
    int cont = 0;

    for (int i = 0; primer_apellido[i] != '\0'; i++)
    {
        if (primer_apellido[i] == ' ')
        {
            posiciones_vacias_apellido[cont] = i;
            cont++;
        }
    }

    // Si hay posiciones vacias es compuesto
    if (cont > 0)
    {
        int inicio = 0;
        char apellido_parte[100] = {0};

        // Dividir el apellido en partes basadas en las posiciones vacias
        for (int i = 0; i <= cont; i++)
        {
            int fin;
            if (i == cont)
            {
                fin = strlen(primer_apellido);
            }

            else
            {
                fin = posiciones_vacias_apellido[i];
            }

            for (int j = inicio; j < fin; j++)
            {
                apellido_parte[j - inicio] = primer_apellido[j];
            }

            // Añadir el caracter nulo
            apellido_parte[fin - inicio] = '\0';

            // Verificar
            if (!excepcion_compuestos(apellido_parte))
            {

                curp[13] = retorna_consonante_interna(apellido_parte);
                break;
            }

            inicio = posiciones_vacias_apellido[i] + 1;
        }
    }

    else
    {
        // Si no hay posiciones vacias no es compuesto
        curp[13] = cat_die_i[0];
    }

    if (verifica_vacio(segundo_apellido))
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = cat_die_i[1];
    }

    // POSICION 15

    curp[15] = cat_die_i[2];

    curp[16] = diescisiete_i[0];
    curp[17] = diesciocho_i[0];
    curp[18] = '\0';

    // Verificar si la persona no tiene ningun apellido
    if (verifica_vacio(primer_apellido) && verifica_vacio(segundo_apellido))
    {
        strcpy(curp, "PERSONA DESCONOCIDA");
        curp[20] = '\0';
    }

    // Verificar altisonantes
    if (excepcion_altisonantes(curp))
    {
        curp[1] = 'X';
    }
}

void imprimir_curp(char curp[])
{
    printf("\n");
    printf("|                                                                                             |\n");
    printf("|        C U R P :  %s                                                         |\n", curp);
    printf("|                                                                                             |\n");
}