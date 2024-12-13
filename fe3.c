#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_M(Materia *m)
{
    printf("Nombre materia: %s\n",m->nombre);
    printf("Profesor: %s %s\n",m->profe.nombre, m->profe.apellido);
    printf("Alumnos %d\n",m->cant_alumnos);
    for (int i=0;i<m->cant_alumnos;++i)
    {
        printf("[%-2d] %-25s %-25s\t",i+1,m->alumnos[i].nombre, m->alumnos[i].apellido);
        for(int p=0;p<4;p++)
        {
            if(!m->alumnos[i].parciales[p])
                printf("%-5s  ","Null");
            else
                printf("%.2f  ",*m->alumnos[i].parciales[p]);
        }
        printf("  %.2f\n",m->alumnos[i].promedio);
    }
    printf("Promedio Grupo %.4f\n",m->promedio);
}

Alumno* aprobados(Materia *m, int *c)
{
    Alumno *lista =NULL;
    *c=0;
    for(int i=0;i<m->cant_alumnos;i++)
    {
        if(m->alumnos[i].promedio >=60)
        {
            lista = realloc(lista,(*c+1)*sizeof(Alumno));
            lista[*c]=m->alumnos[i];
            (*c)++;
        }
    }
    return lista;
}

Alumno* reprobados(Materia *m, int *c)
{
    Alumno *lista =NULL;
    *c=0;
    for(int i=0;i<m->cant_alumnos;i++)
    {
        if(m->alumnos[i].promedio <60)
        {
            lista = realloc(lista,(*c+1)*sizeof(Alumno));
            lista[*c]=m->alumnos[i];
            (*c)++;
        }
    }
    return lista;
}

float promedio(Materia *m)
{
    float p=0;
    for(int i=0;i<m->cant_alumnos;++i)
        p+=m->alumnos[i].promedio;
    return p/m->cant_alumnos;
}

//auxiliares

void printAlumno(Alumno *a)
{
    printf("%-25s %-25s %-.2f\n",a->nombre,a->apellido,a->promedio);
}

void MateriaAutoLLenado(Materia *m)
{
    const char *n[3] ={"Matematicas","Programacion","Ingles"};
    int id = rand()%3;
    strcpy(m->nombre,n[id]);
    int ca = rand()%41;
    m->cant_alumnos = ca;
    m->alumnos = calloc(ca,sizeof(Alumno));
    m->profe = (Profesor){"Omar","Zamarron",30198,25.f};
    for(int i=0;i<ca;i++)
    {
        RandomAlumno(&m->alumnos[i]);
        int p = 1+rand()%4;
        RandomParciales(&m->alumnos[i],p);
        m->alumnos[i].promedio = promedioAlumno(&m->alumnos[i]);
    }
    m->promedio = m->GetPromedio(m);
}

void RandomAlumno(Alumno *a)
{

    const char *nombres[10] ={
        "Omar",
        "Gustavo",
        "Roberto",
        "Jessica",
        "Sarahi",
        "Isabel",
        "Ione",
        "Mauricio",
        "Miguel",
        "Letticia"
    };
    const char *apellidos[10]={
        "Garza",
        "Gonzales",
        "Rodriguez",
        "Sanchez",
        "Perez",
        "Lopez",
        "Martinez",
        "Morales",
        "Hernandez",
        "Reyes"
    };

    int idn = rand()%10;
    int idp = rand()%10;
    strcpy(a->nombre, nombres[idn]);
    strcpy(a->apellido, apellidos[idp]);

    for(int i=0;i<4;i++)
    {
        a->parciales[i] = NULL;
    }
    a->promedio =0;
}

void RandomParciales(Alumno *a, int cuantos)
{
    for(int i=0;i<cuantos;i++)
    {
        a->parciales[i] = malloc(sizeof(float));
        *a->parciales[i] = 10+((float)rand()/RAND_MAX)*(100-10);
    }
}

float promedioAlumno(Alumno *a)
{
    float s=0;
    
    for(int i=0;i<4;i++)
    {
        if(!a->parciales[i])
            continue;
        s+=*a->parciales[i];
    }
    return s/4.f;
}
