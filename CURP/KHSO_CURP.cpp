// Kevin Humberto Soto Ortiz MAT:377689 GPO:932
//
#include "Principal.h"
#include "validaciones.h"

// Funciones principales
int main();
int msges();

/* Funciones principales */

int main()
{
    int op;
    char curp[20];
    char primer_apellido[100];
    char segundo_apellido[100];
    char primer_nombre[100];
    char segundo_nombre[100];
    char fecha[11] = "00/00/0000";
    int cod_estado;
    char estado[10];
    int cod_sexo;
    char sexo[2];
    char cat_die_i[4];
    char diescisiete_i[5];
    char diesciocho_i[5];

    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            comenzar(curp, primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, fecha, cod_estado, estado, cod_sexo, sexo, cat_die_i, diescisiete_i, diesciocho_i);
            break;
        }

    } while (op != 0);
}

int msges()
{
    int op;
    printf("\n");
    printf("   M  E   N   U \n");
    printf("1.- OBTENER CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);

    while (getchar() != '\n')
        ;

    return op;
}

