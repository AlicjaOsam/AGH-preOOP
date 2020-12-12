#include <iostream>

class Vector2D{
  public:
    static int count;
    ~Vector2D();
    Vector2D(Vector2D &&v);
    Vector2D(const Vector2D &v);
    Vector2D& operator=(Vector2D&& v){
      if(this != &v){
        _name = std::move(v._name);
        _x = std::move(v._x);
        _y = std::move(v._y);
      }
      return *this;
    }
    static Vector2D fromCarthesian (std::string name, double x, double y);
    static Vector2D fromPolar (std::string name, double r, double phi);
    void print(std::string str) const;
    double dot(const Vector2D& v) const;
    Vector2D add(const Vector2D& v) const;
    static Vector2D fromCarthesian (double x, double y);
    Vector2D(std::string name="Vx", double x=0, double y=0);
  private:
    Vector2D(double x=0, double y=0);
    std::string _name;
    double _x;
    double _y;
};

inline Vector2D::Vector2D(std::string name, double x, double y) : _name(name), _x(x), _y(y)
{count += 1;}

inline Vector2D::Vector2D(double x, double y) : _x(x), _y(y)
{count += 1;}
