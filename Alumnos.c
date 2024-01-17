#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, op, seguir=1, cont=0;
    struct Alumno// definimos el struct
    {
        int matricula;
        char nombre[50];
        char direccion[50];
        char carrera[50];
        float promedio;
    };
    printf("Escriba la cantidad de alumnos maxima:\n ");
    scanf("%d", &n);
    struct Alumno arreglo[n];//definimos el tamaño del arreglo.
    do
    {
        printf(" Para ver la lista de estudiantes [0]\n Para registrar un nuevo estudiante [1]\n Para terminar el programa [2]\n");
        scanf("%d", &op);
        switch (op)//por medio de un swich dividimos los casos posibles.
        {
        case 0:
            if (cont > 0)//imprimimos el interior del arreglo de existir.
            {
                for (int i = 0; i < cont; i++)
                {
                    puts("Datos del estudiante:");
                    printf("Matricula: %d\n", arreglo[i].matricula);
                    printf("Nombre: ");
                    puts(arreglo[i].nombre);
                    printf("Direccion: ");
                    puts(arreglo[i].direccion);
                    printf("Carrera: ");
                    puts(arreglo[i].carrera);
                    printf("Promedio: %.2f\n", arreglo[i].promedio);
                }
            }else{
                printf("No existe alumnos para mostrar\n");// de no existir imprimimos mensaje de error.
            }
            break;
        case 1:
            if (n!=cont)//condicion para que delimitar el arreglo.
            {
                do
                {
                    printf("Ingrese la matricula:\n ");
                    scanf("%d", &arreglo[cont].matricula);

                    getchar();
                    puts("Ingrese el nombre:");
                    fgets(arreglo[cont].nombre, sizeof(arreglo[cont].nombre), stdin);//pedimos el apartado .nombre del struct en el arrreglo, y solisitamos el tamaño en bites necesario en relacion 1=1.
                    arreglo[cont].nombre[strcspn(arreglo[cont].nombre, "\n")] = '\0';//reemplasamos el espaciado "\n" con "\0"

                    puts("Ingrese la direccion:");
                    fgets(arreglo[cont].direccion, sizeof(arreglo[cont].direccion), stdin);
                    arreglo[cont].direccion[strcspn(arreglo[cont].direccion, "\n")] = '\0';

                    puts("Ingrese la carrera:");
                    fgets(arreglo[cont].carrera, sizeof(arreglo[cont].carrera), stdin);
                    arreglo[cont].carrera[strcspn(arreglo[cont].carrera, "\n")] = '\0';

                    printf("Ingrese el promedio:\n ");
                    scanf("%f", &arreglo[cont].promedio);

                    cont++;

                    printf("¿Desea continuar? (1=si, 0=no): \n");
                    scanf("%d", &seguir);

                } while (seguir==1 && cont<n);//condicion para que delimitar el arreglo.
            }else{
                printf("limite de estudiantes alcansado\n");//mensaje de error para no exeder el limite.
            }
            break;
        default:
            break;
        }
    } while (op!=2);
    return 0;
}