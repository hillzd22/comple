#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// una estructura que representa una arista sin peso
struct Arista
{
int fnt, dest;
};

// estructura que representa un grafo conectado, no dirigido y sin peso
// como una coleccion de aristas
struct Grafo
{
// V->  Numero de vertices, A-> Numero de aristas
    int V, A;
    Arista* arista;
};

// estructura que representa un subconjunto para la function union-encontrar
struct Subconjunto
{
    int padre;
    int rango;
};

// Funciones union-encontrar
// para kargerCorteMin() )
int Encontrar(struct Subconjunto subconjuntos[], int i);
void Union(struct Subconjunto subconjuntos[], int x, int y);

// Implementacion del argoritmo de karger
int kargerCorteMin(struct Grafo* grafo)
{
// Obtener data del grafo
    int V = grafo->V, A = grafo->A;
    Arista *arista = grafo->arista;

//Alocar memoria para los subconjuntos
struct Subconjunto *subconjuntos = new Subconjunto[V];

// Crear V subconjuntos con elementos unicos
    for (int v = 0; v < V; ++v)
    {
        subconjuntos[v].padre = v;
        subconjuntos[v].rango = 0;
    } 

// Inicialmente hay V vertices en el grafo contraido
int vertices = V;

// Seguir contrayendo hasta que haya 2 vertices.
while (vertices > 2)
{
    int i = rand() % A;

// Encontrar vertices (o conjuntos) en los extremos de la arista
    int subconjunto1 = Encontrar(subconjuntos, arista[i].fnt);
    int subconjunto2 = Encontrar(subconjuntos, arista[i].dest);

// Si dos esquinas pertenecen a el mismo subconjunto,
// no se considera
    if (subconjunto1 == subconjunto2)
        continue;

// De lo contrario contraer la arista (o combiner los
// extremos de la arista en un solo vertice)
    else
    {
        printf("Contrayendo arista %d-%d\n",
        arista[i].fnt, arista[i].dest);
        vertices--;
        Union(subconjuntos, subconjunto1, subconjunto2);

    }

// Ahora que tenemos dos vertices (o subconjuntos) en
// el grafo contraido, contamos las aristas entre los componentes
// y retornarmos las aristas contraidas
    int aristascontraidas = 0;
    for (int i=0; i<A; i++)
    {
        int subconjunto1 = Encontrar(subconjuntos, arista[i].fnt);
        int subconjunto2 = Encontrar(subconjuntos, arista[i].dest);
        if (subconjunto1 != subconjunto2)
            aristascontraidas++;
    }

return aristascontraidas;
    }
}

// Encontrar conjunto de un elemento i
int Encontrar(struct Subconjunto subconjuntos[], int i)
{
// encontrar raiz y hacer raiz como padre de i
if (subconjuntos[i].padre != i)
    subconjuntos[i].padre =
    Encontrar(subconjuntos, subconjuntos[i].padre);

    return subconjuntos[i].padre;
}

// Funcion que une dos conjuntos de x y y
void Union(struct Subconjunto subconjuntos[], int x, int y)
{
    int xraiz = Encontrar(subconjuntos, x);
    int yraiz = Encontrar(subconjuntos, y);

// Añadir el arbol de rango pequeño debajo de un arbol de rango alto
    if (subconjuntos[xraiz].rango < subconjuntos[yraiz].rango)
        subconjuntos[xraiz].padre = yraiz;
    else if (subconjuntos[xraiz].rango > subconjuntos[yraiz].rango)
        subconjuntos[yraiz].padre = xraiz;

// Si el rango es el mismo, hacer uno raiz e incrementar su rango por 1
    else
    {
        subconjuntos[yraiz].padre = xraiz;
        subconjuntos[xraiz].rango++;
    }
}

// Crear un grafo con V vertices y A aristas
struct Grafo* crearGrafo(int V, int A)
{
    Grafo* grafo = new Grafo;
    grafo->V = V;
    grafo->A = A;
    grafo->arista = new Arista[A];
    return grafo;
}

// Prueba del programa
int main()
{

int V = 4; 
int A = 5;

struct Grafo* grafo = crearGrafo(V, A);
// añadir arista 0-1
grafo->arista[0].fnt = 0;
grafo->arista[0].dest = 1;

// añadir arista 0-2
grafo->arista[1].fnt = 0;
grafo->arista[1].dest = 2;

// añadir arista 0-3
grafo->arista[2].fnt = 0;
grafo->arista[2].dest = 3;

// añadir arista 1-3
grafo->arista[3].fnt = 1;
grafo->arista[3].dest = 3;

grafo->arista[4].fnt = 2;
grafo->arista[4].dest = 3;

srand(time(NULL));

printf("\nCorte encontrado : %d\n"+ kargerCorteMin(grafo));

return 0;
    
}
