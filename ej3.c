#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fe3.h"

int main(void)
{
    srand(time(NULL));

    Materia m;
    m.GetPromedio = promedio;
    m.PrintMateria = print_M;
    m.GetListaAprobados = aprobados;
    m.GetListaReprobados = reprobados;

    MateriaAutoLLenado(&m);
    m.PrintMateria(&m);

    printf("Aprobados\n");
    int c;
    Alumno * ap = m.GetListaAprobados(&m,&c);
    for(int i=0;i<c;++i)
        printAlumno(&ap[i]);
    printf("ReAprobados\n");
    free(ap);
    ap = m.GetListaReprobados(&m,&c);
    for(int i=0;i<c;++i)
        printAlumno(&ap[i]);

    free(ap);
    for(int i=0;i<m.cant_alumnos;i++)
    {
        for(int p=0;p<4;p++)
            free(m.alumnos[i].parciales[p]);
    }
    free(m.alumnos);

    return 0;
}
