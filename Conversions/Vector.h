#pragma once

//klasa reprezentująca n-wymiarowy wektor
class Vector{
  public:
    //konstruktor konwertujący explicit, inicjujący wektor n-wymiarowy
    explicit Vector(int);
    //konstruktor kopiujący
    Vector(Vector&);
    //konstruktor przenoszący
    Vector(Vector&&);
    //destrukor
    ~Vector();

    //funkcja zwracająca zawartość wektora pod wskazanym indeksem 
    double& at(int) const;
    //funkcja wypisująca wektor
    void print(std::string s = "") const;
    //funkcja zwracająca iloczyn skalarny dwóch wektorów
    static double dot(const Vector&, const Vector&);
    //funkcja konwertująca Vector na double zwracająca normę
    explicit operator double() const;
    //funkcja zwracająca normę wektora
    double norm() const;
    //funkcja zwracająca nowy wektor będący sumą dwóch wektorów
    static Vector sum(const Vector&, const Vector&);
    //funkcja zwracająca nowy wektor będący sumą wektora i liczby
    static Vector sum(const Vector&, int);
  private:
    //wektor
    double* _v;
    //wymiar wektora
    int _n;
};