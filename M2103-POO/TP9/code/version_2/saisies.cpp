#include <iostream>
#include "Point.h"
#include "saisies.h"
#include "Color.h"
#include <map>

using namespace std;

istream & operator >> (istream &in, Point & p) 
{
  int x, y;
  in >> x >> y;
  p = Point(x,y);
  return in;
}

istream & operator >> (istream &in, Color & col) 
{
  static const map<string, Color> namesToColors =
    { 
      {"black", Color::BLACK},
      {"red", Color::RED},
      {"blue", Color::BLUE},
      {"green", Color::GREEN},
      {"white", Color::WHITE},
      {"noir", Color::BLACK},
      {"rouge", Color::RED},
      {"bleu", Color::BLUE},
      {"vert", Color::GREEN},
      {"blanc", Color::WHITE},
    };
  bool found = false;
  string choice;
  do {
    cin >> choice;
    auto it = namesToColors.find(choice);
    if (it == namesToColors.end()) {
      cerr << "Couleur " << choice 
	   <<" inconnue. Valides :";
      for (auto pair : namesToColors) {
	cerr << " " << pair.first;
      }
      cerr << endl;
    } else {
      col = it->second;
      found = true;
    }

  } while (! found);
  return in;
}

void
cinLine( Color & col, Point & sw, Point & ne )
{
  cout << "Saisie de Line" << endl;
  cout << "Couleur : ";
  cin >>  col ;
  cout << "Point sw (abcisse puis ordonnée) ?  ";
  cin >>  sw ;
  cout << "Point ne ?  ";
  cin >> ne;
}

void
cinLineHoriz( Color & col, Point & sw, int & w )
{
  cout << "Saisie de Line horizontale" << endl;
  cout << "Couleur : ";
  cin >>  col ;
  cout << "Point gauche (abcisse puis ordonnée) ?  ";
  cin >>  sw ;
  cout << "Longueur :";
  cin >> w;
}

void 
cinRectangle( Color & col, Point & sw, Point & ne )
{
  cout << "Saisie de Rectangle" << endl;
  cout << "Couleur : ";
  cin >>  col ;
  cout << "Point sw (abcisse puis ordonnée) ?  ";
  cin >>  sw ;
  cout << "Point ne ?  ";
  cin >> ne;
}

void 
cinCircle( Color & col, Point & c, int & r )
{
  cout << "Saisie de Circle" << endl;
  cin >> col;
  cout << "Centre du cercle ?  ";
  cin >> c;
  cout << "radius ?" << endl;
  cin >> r;
}
