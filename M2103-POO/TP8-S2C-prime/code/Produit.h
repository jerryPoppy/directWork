#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit {
 protected:
  unsigned int m_identifiant;
  std::string  m_marque;     
  float        m_prix;        //en euros
  unsigned int m_calories;   

 public:
  Produit(unsigned int identifiant, std::string marque,
	  float prix, unsigned int calories);

  //Destructeur virtuel pur
  virtual ~Produit() = 0;

  // Accesseur en lecture
  unsigned int identifiant() const;
  std::string  marque()      const;
  float        prix()        const;
  int calories()             const;

  virtual std::string description() const;
};
#endif

