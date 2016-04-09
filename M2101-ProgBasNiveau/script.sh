#!/bin/bash -x

# l'image de disque amoureusement préparée
# master=~/VMs/PPC/debian_wheezy_powerpc_standard_avec_gcc_fr.qcow2
master=~/VMs/PPC/debianFinal.qcow2

# la copie (différentiel) avec laquelle l'étudiant va faire sa session

copie=/tmp/macopie.qcow2

# le répertoire partagé
partage=~

# -----------------------------------------

qemu-img create -f qcow2 ${copie} -b ${master}

qemu-system-ppc -hda ${copie} \
      -virtfs local,path=${partage},security_model=none,mount_tag=share

rm ${copie}

