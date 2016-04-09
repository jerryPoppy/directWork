
--------------------------
Challenge de reverse engineering
--------------------------

Le challenge est composé de deux exécutables PowerPC : challenge0,
challenge1 et challenge1.1; ils contiennent chacun un secret. 
- Le but de l'exercice est de trouver ces secrets -

Vous pouvez tester challenge0 et challenge1 sur info-stykades.

----------
Challenge 0 :
----------

challenge0 attend un argument: la clé pour délivrer son secret. Cette
clé est un nombre entier.  

- Méthode 1: vous pouvez tenter de découvrir la clé par une méthode de
"brute force". Il s'agit de tester toutes les clés
possibles. Cependant, on ne connait pas les bornes pour la clé.

- Méthode 2: une méthode plus subtile est de tenter de découvrir la
  clé en désassemblant challenge0 et en examinant le code
  attentivement.  Une technique de simple pour examiner le code est
  d'utiliser la commande
  > objdump -D challenge0 | less
  Vous pourrez alors trouver la fonction main de challenge0 est 
  découvrir la clé.

----------
Challenge 1 et challenge 1.1 :
----------

Le challenge 1 est un peu plus compliqué. Comme challenge0, challenge1
attend un argument: la clé. Mais cette fois, la clé est un mot en
lettres alphabetiques minuscules.

La méthode "brute force" est toujours possible, mais désespérée tant
le nombre de possibilités est grand.

Comme pour le challenge 0, vous pouvez examiner le code avec
objdump. En revanche, la clé est beaucoup moins facile à trouver dans
ce cas. Une espérance aurait été que la clé soit visible en clair dans
le code. En fait, c'est le cas :) Cependant, il est difficile de savoir
où. En effet, la chaine de caractère constituant la clé existe bien
dans le code. Mais objdump, ne sachant pas qu'il s'agit d'une chaine
de caractère, l'a désassemblé comme tout le reste de
l'exécutable. Ainsi la chaine de caractère se retrouve malheureusement
noyée dans le fichier, interprétée comme une suite d'instructions
assembleur. Il est possible de la trouver, mais c'est difficile.

Methode:
-------

Une indication est que challenge1 compare l'entrée avec la clé,
caractère par caractère dans une fonction spéciale (dont le nom est
explicite ;) ). La méthode consiste à trouver cette fonction et à
déterminer les endroits où les caractères de la clé sont chargés
(attention: de façon plus précise, le premier caractère est chargé à
un endroit, et les suivants sont chargés à un autre endroit). Ensuite,
à l'aide du debugger (gdb), en plaçant des points d'arrêt à ces
endroits, vous pourrez trouver ces caractères, un à un.

Remarque: il faudra manier l'hexadécimal et les codes ascii.

Remarque: en vérité, le developpeur a été bien négligeant, il y a
un moyen simple de trouver la clé sans passer par cette méthode...
Mais l'erreur est corrigée dans le challenge1.1
