#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <cstdio>
#include "Figury2000.h"

int main()
{
    vector <Figure*> figures;
    point A, B, C, D;

    char napis[100];


    int dl=0;
    cout<< "Wybierz figure geometryczna (k-kwadrat, t-trojkat, o-okrag):\n";
    cin>> napis;
    dl=strlen(napis);

    for(int i=0; i <= dl; i++)
  {
    switch(napis[i])
    {

     case 'k':
        system("cls");
        cout << "Wpisz 4 punkty tworzace kwadrat.\n";
        cout << "Wpisz wspolrzedne punktu A:\n";
        cout << "x= ";
        cin >> A.x;
        cout << "y= ";
        cin >> A.y;
        cout << "Wpisz wspolrzedne punktu B:\n";
        cout << "x= ";
        cin >> B.x;
        cout << "y= ";
        cin >> B.y;
        cout << "Wpisz wspolrzedne punktu C:\n";
        cout << "x= ";
        cin >> C.x;
        cout << "y= ";
        cin >> C.y;
        cout << "Podaj wspolrzedne punktu D:\n";
        cout << "x= ";
        cin >> D.x;
        cout << "y= ";
        cin >> D.y;
        figures.push_back(new Square(A, B, C, D));

        break;
     case 't':
        system("cls");
        cout << "Wpisz 3 punkty tworzace trojkat.\n";
        cout << "Wpisz wspolrzedne punktu A:\n";
        cout << "x= ";
        cin >> A.x;
        cout << "y= ";
        cin >> A.y;
        cout << "Wpisz wspolrzedne punktu B:\n";
        cout << "x= ";
        cin >> B.x;
        cout << "y= ";
        cin >> B.y;
        cout << "Wpisz wspolrzedne punktu C:\n";
        cout << "x= ";
        cin >> C.x;
        cout << "y= ";
        cin >> C.y;
        figures.push_back(new Triangle(A, B, C));
        break;
     case 'o':
        system("cls");
        cout << "Wpisz 2 punkty tworzace promien okregu. \n";
        cout << "Wpisz wspolrzedne punktu A:\n";
        cout << "x= ";
        cin >> A.x;
        cout << "y= ";
        cin >> A.y;
        cout << "Wpisz wspolrzedne punktu B:\n";
        cout << "x= ";
        cin >> B.x;
        cout << "y= ";
        cin >> B.y;
        figures.push_back(new Circle(A, B));
        break;
     default:
        break;

    }
  }

    system("cls");
    if (figures.size() == 0)
        cout << "Blad. Nieprawidowe kombinacje figur. \n";
        else   cout << " POLE I OBWOD FIGURY:\n\n";

     for(int i=0; i < figures.size(); i++)
     {
         printf("%d. ", i); figures[i]->points();
         cout << "Obwod: " << figures[i]-> perimeter() << endl;
         cout << "Pole: " << figures[i]->area() << endl << endl;
		 cout << "Kolor" << figures[i] ->color() << endl << endl;
         cout << "   MIARY KATOW W FIGURACH GEOMETYCZNYCH \n"<< endl;
         cout << "Suma miar katow w kazdym kwadracie wynosi:  \n" <<    Square::sum() <<endl;
         cout << "Suma miar katow w kazdym trojkacie wynosi:  \n" << Triangle::sum() <<endl;
         SquareFormulas kwadrat;
         display(&kwadrat);
         TriangleFormulas trojkat;
         displayt(&trojkat);
         CircleFormulas kolo;
         displayk(&kolo);
       }

     cout << endl;

     system("PAUSE");
     return 0;
}

