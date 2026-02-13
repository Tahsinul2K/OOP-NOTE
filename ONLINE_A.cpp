#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double dist(const Point &other)
    {
        double dist = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
        return dist;
    }
    void show()
    {
        cout << "x: " << x << " y: " << y <<endl;
    }

    Point translate(double dx, double dy)
    {
        Point temp;
        temp.x = this->x +dx;
        temp.y = this->y +dy;
        return temp;
    }

};

class Polygon{
    Point* vertices;
    int numVertices;
    int cur;
    public:
    Polygon()
    {
        numVertices = 0;
        vertices = nullptr;
        cur = 0;
    }
    Polygon(Point* vertices, int n)
    {
        this->vertices = (Point*)malloc(sizeof(Point)*n);

        for(int i = 0 ; i< n ; i++)
        {
            this->vertices[i] = vertices[i];
        }
        this->numVertices = n;
    }
    Polygon(const Polygon& other)
    {
        this->vertices = (Point*)malloc(sizeof(Point) * other.numVertices);
        this->numVertices = other.numVertices;
        this->cur = 0;
        for(int i = 0 ; i < other.numVertices ; i++)
        {
            this->vertices[i] = other.vertices[i];
        }
    }
    ~Polygon()
    {
        free(this->vertices);
        numVertices = 0;
        cur = 0;
    }
    Polygon Translate(double dx , double dy)
    {
        Polygon temp;
        temp.numVertices = this->numVertices;

        temp.vertices = (Point*)malloc(sizeof(Point)*numVertices);

    }

    void addVertex(Point P)
    {
        this->vertices[cur] = P;
        cur++;
    }

    double getPerimeter()
    {
        double perimeter=0;
        for(int i = 1 ; i<numVertices ; i++)
        {
            perimeter += vertices[i].dist(vertices[i-1]);
        }
        return perimeter;
    }
};