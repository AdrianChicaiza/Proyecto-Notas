#include <iostream>
#include <fstream>
#include "calificacion.h"
#include "ALordenamiento.h"
using namespace std;
using namespace ordenamientos;
using namespace calificacionesc;
#define tam 800
ofstream archivo2;
int bsecuencial (int a[], int n, int dato);
void busquedaBinaria (int arr[], int t, int dato);
void algoritmoInterpolacion (int a[], int n);

//////Funcion PRincipal///////////////////
int main()
{  
  int nestud,op,opro,obus,nbus;
  int arreglo[tam];
  do
  {
    ofstream archivo1;
    archivo1.open("ordenamiento.txt",ios::app);
    cout<<"COLEGIO XYZ"<<endl;
    cout<<"1. Ingreso de datos del docente"<<endl;
    cout<<"2. Registro de notas"<<endl;
    cout<<"3. Ordenamiento de notas"<<endl;
    cout<<"4. Busqueda de una nota"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Escoja una opcion:  ";
    cin>>op;
    switch(op)
    {
      case 1:
      cout<<"DATOS DOCENTE"<<endl;
      cout<<"Nombre:  ";cin>>doc;
      cout<<"Apellido:  ";cin>>apell;
      cout<<"Cedula:  ";cin>>ced;
      cout<<"Docente:  "<<doc<<" "<<apell <<"["<<ced<<"]"<<endl;     
      break;

      case 2:
      cout<<"REGISTRO DE NOTAS"<<endl;
      cout<<"Ingrese el numero de estudiantes:  ";
      cin>>nestud;
      ingresar(arreglo, nestud);      
      break;

      case 3:
      cout<<"Ordenar calificaciones"<<endl;
      cout<<"1. Burbuja"<<endl;
      cout<<"2. Seleccion"<<endl;
      cout<<"3. Quick Sort"<<endl;
      cout<<"4. Merge Sort"<<endl;
      cout<<"5. Heap Sort"<<endl;
      cout<<"6. Insercion"<<endl;
      cout<<"Escoja una opcion:  "; cin>>opro;
      switch(opro)
      {
        case 1:
        {
          cout<<"Ordenamiento Burbuja:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;
          burbuja(arreglo, nestud);
          imprimir(arreglo, nestud);

          break;
        }

        case 2:
        {
          cout<<"Ordenamiento Seleccion:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;
          seleccion(arreglo, nestud);
          imprimir(arreglo, nestud);

          break;
        }
        case 3:
        {
          cout<<"Ordenamiento Quick Sort:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;
          ordenar(arreglo,0,nestud-1);         
          imprimir(arreglo, nestud);

          break;
        }
        case 4:
        {
          cout<<"Ordenamiento Merge Sort:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;
          dividir(arreglo,0,nestud-1);         
          imprimir(arreglo, nestud);
          break;
        }
        case 5:
        {
          cout<<"Ordenamiento Heap Sort:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;            
            HeapSort(arreglo,nestud);
            imprimir(arreglo, nestud);

          break;
        }
        case 6:
        {
          cout<<"Ordenamiento Insercion:"<<endl;
          for(int i=0;i<nestud;i++)
           {
             cout<<"|"<<arreglo[i]<<"|";
            }
            cout<<endl;            
            algoritmoInserccion(arreglo, nestud);
            imprimir(arreglo, nestud);

          break;
        }
  
      }
      archivo1<<"**********COLEGIO XYZ**********"<<endl; archivo1<<"REPORTE DE CALIFICACIONES"<<endl;
        if(opro==1)
        {
          archivo1<<"Ordenamiento Burbuja"<<endl;
        }
        else if(opro==2)
        {
          archivo1<<"Ordenamiento Seleccion"<<endl;
        }
        else if(opro==3)
        {
          archivo1<<"Ordenamiento Quick Sort"<<endl;
        }
        else if(opro==4)
        {
          archivo1<<"Ordenamiento Merge Sort"<<endl;
        }
        else if(opro==5)
        {
          archivo1<<"Ordenamiento Heap Sort"<<endl;
        }
        else if(opro==6)
        {
          archivo1<<"Ordenamiento Insercion"<<endl;
        }
        archivo1<<"Notas ordenadas:  ";         
        for (int i=0; i<nestud; i++)
        {
        archivo1<<"|"<<arreglo[i]<<"|";
        }
        archivo1<<endl;        
        archivo1<<endl;
        archivo1<<"____________________"<<endl;
        archivo1<<"      Docente"<<endl;
        archivo1<<""<<doc<<""<<apell<<endl;
        archivo1<<""<<ced<<endl;
        archivo1.close();
      break;
//////////////////////////////////////////////////////////
      case 4:
      
      cout<<"Buscar calificaciones"<<endl;
      cout<<"1. Lineal"<<endl;
      cout<<"2. Binaria"<<endl;
      cout<<"3. Interpolacion"<<endl;
      cout<<"Escoja una opcion:  "; cin>>obus;
      switch(obus)
      {
        case 1:
        {
        archivo2.open("busqueda.txt",ios::app);
      archivo2<<"**********COLEGIO XYZ**********"<<endl;
  archivo2<<"REPORTE DE CALIFICACIONES"<<endl;
  
        cout<<"Busqueda Lineal"<<endl;
        archivo2<<"Busqueda Lineal"<<endl;
        imprimir(arreglo, nestud);
        cout<<"Que nota vas buscar:  ";
        cin>>nbus;
        bsecuencial(arreglo,nestud, nbus);
        if(bsecuencial(arreglo,nestud,nbus)==-1)
        {
        cout<<"NO EXISTE LA NOTA"<<endl;
        archivo2<<"NO EXISTE LA NOTA"<<endl;
        }
        else
        {
        cout<<"Nota buscada:  "<<nbus<<endl;
        cout<<"SI EXISTE LA NOTA"<<nbus<<endl;
        archivo2<<"La calificacion a buscar fue :  "<<nbus<<endl;
        archivo2<<"____________________"<<endl;
        archivo2<<"      Docente"<<endl;
        archivo2<<""<<doc<<""<<apell<<endl;
        archivo2<<""<<ced<<endl;
        archivo2.close();
        
        }
        break;
        }
        case 2:        
        cout<<"Busqueda Binaria"<<endl;        
        imprimir(arreglo, nestud);
        cout<<"Que nota vas buscar:  ";
        cin>>nbus;
        busquedaBinaria(arreglo, nestud, nbus);         
        break;

        case 3:
        cout<<"Busqueda Interpolacion"<<endl;        
        imprimir(arreglo, nestud);
        cout<<"Que nota vas buscar:  ";
        cin>>nbus;
        algoritmoInterpolacion(arreglo,nbus);
        break;     
      }
      break;

      case 5:
      cout<<"ADIOS"<<endl;
      break;

    }

  }while(op!=5);
}


/////////////////////busqueda secuencial////////////////
int bsecuencial (int a[], int n, int dato)
{
    bool c;
    c=false;
    for (int i=0; i<=n; i++)
    {
        if(a[i]==dato)
        {
            return i;
        }
    }
    
  
    
        return -1;
    
}
//////////////////////busqueda binaria//////////////////
void busquedaBinaria (int arr[], int t, int dato)
{
  archivo2.open("busqueda.txt",ios::app);
      archivo2<<"**********COLEGIO XYZ**********"<<endl;
  archivo2<<"REPORTE DE CALIFICACIONES"<<endl;
  archivo2<<"Busqueda Binaria"<<endl;
  
  int b,i,j,k;
  i=0;
  j= t - 1;

  b= dato;
  do
  {
    k=(i+j)/2;

    if(arr[k]<=b) 
    {
      i=k+1;  
    }
    if(arr[k]>=b)
    {
      j=k-1;  
    }

  }while(i<=j);
  if(arr[k]>=dato){  
  cout <<"Elemento buscado: "<<dato<<endl;
  cout<<"SI EXISTE LA NOTA "<<dato<<endl;
  archivo2<<"Elemento buscado: "<<dato<<endl;
  archivo2<<"SI EXISTE LA NOTA "<<dato<<endl;
  
  }
  else{
    cout <<"Elemento buscado: "<<dato<<endl;
    cout<<"NO EXISTE LA NOTA"<<endl;
    archivo2 <<"Elemento buscado: "<<dato<<endl;
    archivo2<<"NO EXISTE LA NOTA"<<endl;
     
  }
  archivo2<<"____________________"<<endl;
  archivo2<<"      Docente"<<endl;
  archivo2<<""<<doc<<""<<apell<<endl;
  archivo2<<""<<ced<<endl;
   archivo2.close();
  
  
}
///////////////////////Interpolacion/////////////////////
void algoritmoInterpolacion (int A[], int n)
{
  archivo2.open("busqueda.txt",ios::app);
  archivo2<<"**********COLEGIO XYZ**********"<<endl;
  archivo2<<"REPORTE DE CALIFICACIONES"<<endl;
  archivo2<<"Busqueda Interpolacion"<<endl;
    int primero=0;
    int ultimo=7-1;
    int medio;
    
    
    int contador=0;
    while(A[primero]!=n && contador<7)
    {   
      
    medio = primero + ((n-A[primero])*(ultimo-primero))/(A[ultimo]-A[primero]);
    
    if(A[medio]<n)
          primero = medio+1;
          
    else if(A[medio]>n)
    
          ultimo = medio-1;
    else
          primero = medio;
      
      contador++ ; 
      break;
    }
    
    if(A[primero]==n)
    {
        cout<<"SI EXISTE LA NOTA "<<n<<endl;
        archivo2<<"SI EXISTE LA NOTA "<<n<<endl;
    }
    else
    {
        cout<<"NO EXISTE LA NOTA "<<n<<endl;
        archivo2<<"NO EXISTE LA NOTA "<<n<<endl;
    }
    archivo2<<"____________________"<<endl;
  archivo2<<"      Docente"<<endl;
  archivo2<<""<<doc<<""<<apell<<endl;
  archivo2<<""<<ced<<endl;
archivo2.close();
}
//////////////////////////////////////////////////////////
