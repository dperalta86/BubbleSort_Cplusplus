/*
 * Ejercicio de LISTAS SE
 *
 * Realizar una función para ordenar una lista por metodo burbuja (Bubble Sort).
 * (Ejercicio 4 - Listas)
 *
 */

#include <iostream>
using namespace std;

struct NodoSE
{
    int info;        // Datos de el nodo
    NodoSE   *sgte;  // Puntero al siguiente nodo

};

//Declaracion de subprogramas
void InsertarSiguiente (NodoSE*& n, int x);
NodoSE *ObtenerUltimo(NodoSE* p);
void InsertarAlFinal (NodoSE*& n, int x);
void BorrarSiguiente(NodoSE* n);
NodoSE* BuscarNodo(NodoSE* raiz, int infobuscada);
void borrarNodo(NodoSE*& raiz, NodoSE* aborrar);
void burbujaListas(NodoSE*& lista);
void MostrarLista(NodoSE* lista);


int main()
{
    NodoSE *lista1= NULL;
    int i;
    for (i=0;i<=50;i++)
    {
        if (i%3)
            InsertarAlFinal(lista1,100-i);
        InsertarSiguiente(lista1, i*10-4);
    }
    cout << "Lista original:" << endl;
    MostrarLista(lista1);
    burbujaListas(lista1);
    cout << "Lista ordenada de manera creciente:" << endl;
    MostrarLista(lista1);
    return 0;
}

void InsertarSiguiente (NodoSE  *&n, int x)
{
    NodoSE *nuevo= new NodoSE();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }
}

NodoSE *ObtenerUltimo(NodoSE * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}

void InsertarAlFinal (NodoSE  *&n, int x)
{
    NodoSE *nuevo= new NodoSE();
    NodoSE *ultimo= NULL;
    nuevo->info=x;
    nuevo->sgte= NULL;
	if (n!=NULL)
    {

        ultimo = ObtenerUltimo(n);
        ultimo->sgte = nuevo;
    }
    else
    {
        n= nuevo;
    }
}

void BorrarSiguiente(NodoSE  *n)
{
    NodoSE  *aborrar = n->sgte;
    NodoSE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
}

NodoSE* BuscarNodo(NodoSE * raiz, int infobuscada)
{
    NodoSE *p=raiz;
    while (p && (p->info != infobuscada))
    {
        p = p->sgte;
    }
    return p;
}


NodoSE* BuscarNodoAnterior(NodoSE * raiz, NodoSE * anterior_a)
{
    NodoSE *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    return NULL;
}

/*
BorrarNodo: recibe por parámetro lista y el puntero a borrar
*/
void borrarNodo(NodoSE*& raiz, NodoSE* aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar=raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoSE *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
}

void MostrarLista(NodoSE* lista)
{
    while (lista)
    {
        cout << lista->info << " | ";
        if (lista != nullptr)
            lista = lista ->sgte;
    }
    cout << endl;
}

int ContarNodos(NodoSE *lista)
{
    int cont=0;
    while (lista)
    {
        cont++;
        if (lista != nullptr)
            lista = lista->sgte;
    }
    return cont;
}


void burbujaListas(NodoSE*& lista)
{
    int n,i,j;
    NodoSE *aux;
    NodoSE *anterior;
    NodoSE *proximo;
    bool inter; //Para ver si hubo intercambio  o no
    n= ContarNodos(lista);
    for (i=0;i<=n-2;i++)
    {
        aux= lista;//Arranca desde el principio
        for (j=0;j<=n-2-i;j++)
        {
            if (aux->sgte->info < aux->info)
            {
                inter= true;
                if (aux==lista)
                {
                    lista= aux->sgte;
                    proximo= lista->sgte;
                    lista->sgte=aux;
                    aux->sgte=proximo;
                }
                else
                {
                    anterior=BuscarNodoAnterior(lista,aux);
                    proximo=aux->sgte;
                    anterior->sgte= proximo;
                    aux->sgte= proximo->sgte;
                    proximo->sgte= aux;
                }
            }
            else
                inter=false;
            if (!inter)
            {
                aux= aux->sgte;
            }
        }
    }
}
