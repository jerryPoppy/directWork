#include <stdio.h>

// code c
/*
int mystere(int i[], int t[], int n){
	int res = 0;
	int k=0;
	for (k=0; k<n; k++)
		res = res + t[i[k]];
	return res;
}
*/

asm("mystere: nop");
	// devrait retourner: t[0]+t[3]+t[4] = 10+40+50 = 100

	// R3: adresse de i[], R4: adresse de t[], R5: 3
	asm("mr 30,1"); 
	asm("stw 3,88(30)"); // on sauvegarde l'adresse i[] à l'adresse (R30)+88 : a
	asm("stw 4,92(30)"); // on sauvegarde l'adresse t[] à l'adresse (R30)+92 : b
	asm("li 0,0"); // R0 <- 0
	asm("stw 0,32(30)"); // (R30)+32 : c <- 0
	asm("stw 0,36(30)"); // (R30)+36 : d <- 0
asm("L2: nop");
	asm("lwz 0,36(30)"); // R0 <- d
	asm("cmpwi 7,0,3"); // d<3 ? 
	asm("blt 7,L5"); // oui aller en L5
	asm("b L3"); // non aller en L3
asm("L5: nop"); 
	asm("slwi 20,0,2"); // R20 <- d*4
	asm("lwz 0,88(30)"); // R0 <- &i[] (a)
	asm("add 20,20,0"); // R20 <- &i[d]
	asm("lwz 0,0(20)"); // R0 <- &i[d]
	asm("slwi 20,0,2"); // R20 <- &i[d]*4 ?! // il y a un probleme ici 
	asm("lwz 0,92(30)"); // R0 <- t[] (b)
	asm("add 20,20,0"); // R20 <- t[i[d]]
	asm("lwz 9,32(30)"); // R9 <- c
	asm("mr 0,20"); // R0 <- t[i[d]]
	asm("add 0,9,0"); // R0 <- R0 + c
	asm("stw 0,32(30)"); // c <- t[i[d]]+c
	asm("lwz 20,36(30)"); // R20 <- d
	asm("addi 0,20,1"); // R0 <- d+1
	asm("stw 0,36(30)"); // d <- d+1
	asm("b L2");
asm("L3: nop");
	asm("lwz 3,32(30)"); // R3 <- c
	asm("blr");



int main(){
	int t[7] = {10, 20, 30, 40, 50, 60, 70};
	int i[3] = {0, 3, 4};
	int resultat, j;
	for (j=0; j<1000000; j++)
		resultat = mystere(i,t,3);
	printf("resultat = %d\n",resultat);
}

