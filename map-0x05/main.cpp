#include <iostream>
#include <map>
#include <string>
/*
Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:
    Wrocław (x = 17, y = 51)
    Moskwa (x = 37, y = 55)
    Nowy Jork (x = -74, y = 40)
    Sydney (x = 151, y = -33)

Część A - łatwiejsza

  1a. Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
  2a. Sprawdź czy w mapie jest element, który znajduje się w promieniu 70
      od środka układu współrzędnych (0, 0)
  3a. Pobierz i wypisz współrzędne Sydney

Część B - trudniejsza

  1b. Skopiuj te dane do mapy std::map<Point, std::string>
  2b. Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70
      od środka układu współrzędnych (0, 0)
  3b. Pobierz i wypisz współrzędne Sydney

*/

struct Point
{
    int x;
    int y;
};

int main(int argc, char const* argv[])
{
    return 0;
}
