#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit {
 protected:
  unsigned int m_identifiant;
  std::string m_marque; // marque du produit
  float m_prix;           // prix du produit en euros
  unsigned int m_calories;        // nombre de calories contenues dans le produit

 public:
  Produit(unsigned int identifiant, std::string marque, float prix, unsigned int calories);

  //Destructeur
  virtual ~Produit();

  // Accesseur en lecture
  unsigned int identifiant() const;
  std::string marque() const;
  float prix() const;
  int calories() const;

  virtual std::string description() const;
  
};
#endif

