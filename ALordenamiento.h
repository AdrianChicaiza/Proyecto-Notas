#include <iostream>
#include <fstream>

using namespace std;
namespace ordenamientos
{
 
  ///////////////Burbuja///////////////////////////////
void burbuja (int a[], int n)
{
  int i, j, aux;
    for (i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if (a[j]<a[i])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    
    

}
  ////////////////saleccion/////////////////////////////
void seleccion(int a[],int n)
{
  int i,j,aux,min;
  for (i=0;i<n;i++)
  {   
    min=i;    
    for(j=i;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
    aux=a[i];
    a[i]=a[min];
    a[min]=aux;
  }
}
//////////////////quicksort///////////////////////////////
int mitad (int arr[], int pinicial, int pfinal)
{
    return arr[(pinicial+pfinal)/2];
}


               //A     ,    0        ,  9
void ordenar (int arr[], int pinicial, int pfinal)
{
    int i = pinicial;
    int j = pfinal;
                   //A ,    0  ,  9
    int piv= mitad(arr,pinicial,pfinal);
    int temp;
    do
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while(arr[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp = arr[i];
            arr[i]= arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);
    if (pinicial<j)
        ordenar(arr,pinicial,j);
    if (i<pfinal)
        ordenar(arr,i,pfinal);
}
//////////////////////merge sort/////////////////////


void fusonar(int a[], int pinicial, int pfinal, int medio)
{
  int i,j,k,temp[pfinal-pinicial+1];
  i=pinicial;
  k=0;
  j=medio+1;

  while(i<=medio && j<=pfinal)
  {
    if(a[i]<a[j])
    {
      temp[k]=a[i];
      k++;
      i++;
    }
    else 
    {
      temp[k]=a[j];
      k++;
      j++;
    }
  }

  while(i<=medio)
  {
    temp[k]=a[i];
    k++;
    i++;
  }

  while(j<=pfinal)
  {
    temp[k]=a[j];
    k++;
    j++;
  }

  for(i=pinicial;i<=pfinal;i++)
  {
    a[i]=temp[i-pinicial];
    
  }
}

void dividir(int a[], int inicial, int final)
{
  int mitad;
  if(inicial<final)
  {
    mitad=(inicial+final)/2;
    dividir(a,inicial,mitad);
    dividir(a,mitad+1,final);
    fusonar(a,inicial,final,mitad);
  }
}
/////////////////Insercion////////////////////////////////
void algoritmoInserccion(int a[], int n)
{
    int pos,aux;
    for(int i=0; i<n; i++)
    {
        pos=i;

        aux=a[i];

        while((pos>0)&&(a[pos-1]>aux))
        {
            a[pos] = a[pos-1];

            pos--;

        }

        a[pos]=aux;
    }
}
////////////////////Heap sort*/////////////////////

void HeapSort(int a[],int n)
{
  int i,j,aux,min;
  for (i=0;i<n;i++)
  {   
    min=i;    
    for(j=i;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
    aux=a[i];
    a[i]=a[min];
    a[min]=aux;
  }
}
//////////////imprimir resultados////////////////
void imprimir(int a[], int n)
{
  int i;
  for (i=0; i<n; i++)
    {
      cout<<"|"<<a[i]<<"|";
    }
    cout<<endl;
}
}