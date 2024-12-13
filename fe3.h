#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fe3.h"
typedef struct _P
{
    char nombre[50];
    char apellido[50];
    int id;
    float horas;
}Profesor;
typedef struct _A
{
    char nombre[50];
    char apellido[50];
    float *parciales[4];
    float promedio;
}Alumno;

typedef struct _M
{
    char nombre[50];
    Profesor profe;
    Alumno *alumnos;
    int cant_alumnos;
    float promedio;
    float (*GetPromedio)(struct _M *);
    Alumno* (*GetListaAprobados)(struct _M *, int *);
    Alumno* (*GetListaReprobados)(struct _M *, int *);
    void (*PrintMateria)(struct _M *);
}Materia;

void print_M(Materia *m);
Alumno* aprobados(Materia *m, int *c);
Alumno* reprobados(Materia *m, int *c);
float promedio(Materia *m);

//auxiliares
void MateriaAutoLLenado(Materia *m);
void RandomAlumno(Alumno *a);
void RandomParciales(Alumno *a, int cuantos);
float promedioAlumno(Alumno *a);
void printAlumno(Alumno *a);


