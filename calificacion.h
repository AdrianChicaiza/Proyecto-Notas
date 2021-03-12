#include <iostream>
#include <fstream>

using namespace std;
namespace calificacionesc
{
  string doc,apell;
int ced;
int j;
string nombre[30],apellido[30],correo[50],materia;
  void ingresar (int a[], int n)
{
  ofstream archivo;
  archivo.open("Calificaciones.txt",ios::app);
  
  int n1[10],n2[10];
  float r,acu2=0;
  cout<<"Materia:  ";
  cin>>materia;
  for(int j=0;j<n;j++)
  {
    
    cout<<"Estudiante "<<j+1<<endl;
    cout<<"Nombre:  ";cin>>nombre[j];
    cout<<"Apellido:  ";cin>>apellido[j];
    cout<<"Correo:  ";cin>>correo[j];
    cout<<"N1:  ";cin>>n1[j];
    cout<<"N2:  ";cin>>n2[j];
    while (( n1[j] < 0 || n1[j] > 20 ) || (n2[j] < 0 || n2[j] > 20))
    {
        cout<<"ERROR nota permitida de [0-20]"<<endl;
        cout<<"N1:  ";cin>>n1[j];
        cout<<"N2:  ";cin>>n2[j];
    }

    a[j]=(n1[j]+n2[j])/2;
     
    
       
  
  }
  cout<<"**********COLEGIO XYZ**********"<<endl;  
  cout<<"REPORTE DE CALIFICACIONES"<<endl;
  cout<<"Año Lectivo: 2020-2021"<<endl;
  cout<<"Materia: "<<materia<<endl;
  cout<<"N*  Nombre  Apellido  Correo           Nota1  Nota2  Total"<<endl;
  archivo<<"**********COLEGIO XYZ**********"<<endl;
  archivo<<"REPORTE DE CALIFICACIONES"<<endl;
  archivo<<"Año Lectivo: 2020-2021"<<endl;
  archivo<<"Materia: "<<materia<<endl;
  archivo<<"N*  Nombre  Apellido  Correo           Nota1  Nota2  Total"<<endl;
  for(int j=0;j<n;j++)
  {
    cout<<""<<j<<"\t"<<nombre[j] <<"  "<<apellido[j]<<"  "<<correo[j]<<"\t\t"<<n1[j]<<"\t\t"<<n2[j]<<"\t\t"<<a[j]<<endl;

    archivo<<"\t"<<j<<"\t\t"<<nombre[j]<<"  "<<apellido[j]<<"  "<<correo[j]<<"\t\t"<<n1[j]<<"\t\t"<<n2[j]<<"\t\t"<<a[j]<<endl; 
  }
  cout<<endl;
  archivo<<endl;


  for(int j=0;j<n;j++)
  {
    cout<<"|"<<a[j]<<"|";
    acu2=acu2+a[j];
    r=acu2/n;
  }
  cout<<endl;
  cout<<"Sub del curso: "<<acu2<<endl;
  cout<<"Promedio del curso: "<<r<<endl;
  archivo<<"Sub del curso: "<<acu2<<endl;
  archivo<<"Promedio del curso: "<<r<<endl;
  int i=0,d=0,e=0,f=0;

  for(int i=0; i<n; i++)
  {
    if(a[i]>=14 & a[i]<=20)
    {
      d++;
    }
    else if (a[i]>=9 & a[i]<=13)
    {
      e++;
    }
    else if (a[i]>=1 & a[i]<=8)
    {
      f++;
    }

  }
  cout<<"APROBADOS [14-20] SON: "<<d<<endl;
  cout<<"SUSPENSO  [09-13] SON: "<<e<<endl;
  cout<<"REPROBADO [01-08] SON: "<<f<<endl<<endl;
  cout<<"____________________"<<endl;
  cout<<"      Docente"<<endl;
  cout<<""<<doc<<""<<apell<<endl;
  cout<<""<<ced<<endl;

  archivo<<"APROBADOS [14-20] SON: "<<d<<endl;
  archivo<<"SUSPENSO  [09-13] SON: "<<e<<endl;
  archivo<<"REPROBADO [01-08] SON: "<<f<<endl<<endl;
  archivo<<"____________________"<<endl;
  archivo<<"      Docente"<<endl;
  archivo<<"\t"<<doc<<""<<apell<<endl;
  archivo<<"\t"<<ced<<endl;
  archivo<<endl;
  archivo.close();
  
}
}