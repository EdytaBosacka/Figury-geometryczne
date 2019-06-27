#ifndef FIGURY_H
#define FIGURY_H
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;


struct point
{  double  x;
   double y;
};

ostream& operator<<(ostream&stream_out, point p)
{
    stream_out<< p.x << " , " << p.y;
    return stream_out;
}


class Figure
{
    public:
        Figure() {}
        virtual double area()=0;
        virtual double perimeter()=0;
        virtual void points()=0;
};


class Square: public Figure
{
private:
    point a;
    point b;
    point c;
    point d;
    double side, d1, d2;
    double perimeter_result, area_result;
    static const int angle=90;

public:
    Square(point a, point b, point c, point d);
    double area();
    double perimeter();

    void points()
        {
            cout << "Wierzcholki KWADRATU:\n";
            cout << "A=(" << a << ") \n" ;
            cout << "B=(" << b << ") \n";
            cout << "C=(" << c << ") \n";
            cout << "D=(" << d << ") \n";
        }
        static int sum()
        {
            return (4*angle);
        }



};



Square::Square(point a, point b, point c, point d ): Figure()
{
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
}

double Square::perimeter()
{
    d1=fabs(sqrt((b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y)));
    d2=fabs(sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y)));
    side=fabs(sqrt((b.x-a.x)*(b.x-a.x)+ (b.y-a.y)*(b.y-a.y)));

    if( d1 == (side*sqrt(2)) && d2 == (side*sqrt(2)) && d1 == d2)
    {
        perimeter_result = 4* side;
        return perimeter_result;
    }
    else
        cout<< "Blad. Wierzcholki nie tworza kwadratu. \n";
        return 0;
}


double Square::area()
{
    if (d1 == (side*sqrt(2)) && d2 == (side*sqrt(2)) && d1 == d2)
    {
        area_result = side*side;
        return area_result;
    }
    else
        return 0;
}




class Triangle: public Figure
{
  private:
    point a;
    point b;
    point c;
    double p, sideA, sideB, sideC;
    double perimeter_result, area_result;
    static const int angles=180;

   public:
    Triangle(point a, point b, point c);
    double area();
    friend int equilateral(Triangle&);
    double perimeter();
    void points()
    {
       cout << "Wierzcholki TROJKATA:";
       cout << "A=(" << a << ")\n";
       cout << "B=(" << b << ")\n";
       cout << "C=(" << c << ")\n";
    }
    static int sum()
        {
            return angles;
        }

};



Triangle::Triangle(point a, point b, point c) :Figure()
{
    this->a=a;
    this->b=b;
    this->c=c;
}

double Triangle::perimeter()
{
    sideA=fabs(sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)));
    sideB=fabs(sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y)));
    sideC=fabs(sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y)));

 if (sideA<(sideB+sideC)&& sideB<(sideA+sideC)&&sideC<(sideA+sideB))
   {
    perimeter_result = sideA + sideB + sideC;
    return perimeter_result;
   }
   cout<< "Blad. Wierzcholki nie tworza trojkata. \n";
   return 0;
}
double Triangle::area()
{
  if (sideA<=(sideB+sideC)&& sideB<=(sideA+sideC)&&sideC<=(sideA+sideB))
    {
      p=(sideA+sideB+sideC)/2;
      area_result = sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
      return area_result;
    }
    else
        return 0;
}

class Circle: public Figure
{
  public:
    point a;
    point b;
    double pi=3.14;
    double ray;
    double perimeter_result, area_result;

    Circle(point a, point b);
    double area();
    double perimeter();
    void points()
    {
       cout << "Promien OKREGU:";
       cout << "A=(" << a << ")\n";
       cout << "B=(" << b << ")\n";

    }

};

Circle::Circle(point a, point b) :Figure()
{
    this->a=a;
    this->b=b;

}

double Circle::perimeter()
{
    ray = fabs(sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)));
    perimeter_result = 2*pi*ray;
    return perimeter_result;
}
double Circle::area()
{

    area_result = pi*ray*ray;
    return area_result;
}

class SquareFormulas
{
private:
    string m_strNapis;
public:
    SquareFormulas()    {m_strNapis = "KWADRAT:\n Wzor na pole kwadratu to: P=a*a \n Wzor na obwod kwadratu to: Ob= 4*a\n";}
   friend void display(SquareFormulas*);
};

void display(SquareFormulas* pSquareFormulas)
{
    cout << pSquareFormulas->m_strNapis;
}

class TriangleFormulas
{
private:
    string m_strNapis;
public:
    TriangleFormulas()    {m_strNapis = "TROJKAT:\n Wzor na pole trojkata to: P=(a*h)/2 \n Wzor na obwod trojkata to: Ob= a+b+c \n" ;}
   friend void displayt(TriangleFormulas*);
};

void displayt(TriangleFormulas* pTriangleFormulas)
{
    cout << pTriangleFormulas->m_strNapis;
}

class CircleFormulas
{
private:
    string m_strNapis;
public:
    CircleFormulas()    {m_strNapis = "KOLO:\n Wzor na pole kola to: P=pi*(r^2) \n Wzor na obwod kola to: Ob= 2*pi*r \n" ;}
   friend void displayk(CircleFormulas*);
};

void displayk(CircleFormulas* pCircleFormulas)
{
    cout << pCircleFormulas->m_strNapis;
}


#endif // FIGURY_H
