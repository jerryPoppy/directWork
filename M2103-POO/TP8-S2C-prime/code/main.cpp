#include<iostream>
#include<string>
#include <assert.h>

using namespace std;

#include "Produit.h"
#include "Friandise.h"
#include "Boisson.h"
#include "Distributeur.h"

int main()
{

//    cout << "------------- convertir Friandise -------------" << endl;
   Produit *f1 = new Friandise {01, "Murs", 1.10, 120, 50};
   cout << f1->description() << endl;
   

   Produit *b1 = new Boisson  {11, "Caco", 1.10, 190, 0.33};
   cout << b1->description() << endl;

//    cout << "------------- Exemple ajouter -------------" << endl;

   /*
   Distributeur d {5, 5};
   d.ajouter(f1);
   d.ajouter(b1);

   */
   /*
   Produit *b2 = new Boisson{11,"Caco", 1.10, 190, 0.33};

   cout << d.description() << endl;
   cout << d.valeurEnCaisse() << endl;
   */

   //    cout << "------------- Exemple retirerProduit -------------" << endl;
//    // retrait valide (le produit d'identifiant 01 et présent dans le distributeur et coute bien 1.10
//    Produit *p = d.demander(01, 1.10);
//    assert(p != nullptr);
//    cout << d.description() << endl;
//    Produit *p2 = d.demander(11, 2.10);
//    assert(p2 == nullptr);
//    cout << d.description() << endl;
//    cout << d.valeurEnCaisse() << endl;


    return 0;
}

