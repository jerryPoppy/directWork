#include "Produit.h"
#include <sstream>
using namespace std;

Produit::Produit(unsigned int identifiant, string marque, float prix, unsigned int calories)
  :  m_identifiant{identifiant}, m_marque{marque}, m_prix{prix}, m_calories{calories}
{}


Produit::~Produit()
{}

unsigned int Produit::identifiant() const
{
    return m_identifiant;
}

string Produit::marque() const
{
  return m_marque;
}

float Produit::prix() const
{
  return m_prix;
}

int Produit::calories() const
{
  return m_calories;
}

string Produit::description() const
{
  return ("Identifiant Produit : " + to_string(m_identifiant) + "\n"
          + "\tMarque : " + m_marque + "\n"
          + "\tPrix : " + to_string(m_prix) + "\n"
          + "\tNombre de calories : " + to_string(m_calories) + "\n");
}

