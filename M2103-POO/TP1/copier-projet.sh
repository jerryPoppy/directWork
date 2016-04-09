#
# Copie de projet qt
#

if [ ! -d $1 ] ; then 
  echo "ERREUR : le projet $1 n'existe pas"
  exit 1
fi

if [ -d $2 ] ; then
  echo "ERREUR le répertoire $2 existe déjà"
  exit 1
fi

cp -r $1 $2
rm -f $2/*.user     # si il existe
mv $2/*.pro $2/$2.pro

tree $2

