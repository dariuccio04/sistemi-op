#include <stdio.h>
/*

utilizziamo una struct per definire una unione che definisce altre struct


  */


//vogliamo definire dei veicoli

typedef struct {
  int maxpassengers;
} jet;

typedef struct {
  int liftcapacity;
} helicopter;

typedef struct{
  int maxpayload;
} cargoplane;
//tutte queste struct possono essere contenute da una union
//pov sei james bond e devi scegliere solo un mezzo :(

typedef union{
  jet jet_u;
  helicopter helicopter_u;
  cargoplane cargoplane_u;
} aircraft;

typedef struct {
 int kind;
 aircraft description;
} an_aircraft;


int main(void) {
  an_aircraft bond_aircraft;
  bond_aircraft.kind = 1; // 1 rappresenta un jet

  // Assegna i valori specifici per il jet
  bond_aircraft.description.jet_u.maxpassengers = 4; // Ad esempio, un jet con una capienza massima di 4 passeggeri

 
  printf("James Bond ha scelto un jet con una capienza massima di %d passeggeri.\n", bond_aircraft.description.jet_u.maxpassengers);

  return 0;
}



/*


La union in questo contesto serve a contenere diverse strutture che descrivono tipi di aeromobili. L'uso di una union è appropriato qui perché consente di risparmiare spazio di memoria.

Tuttavia, la union impone una restrizione: puoi accedere a un solo membro della union alla volta. Quando assegni un valore a un membro della union, il valore degli altri membri viene sovrascritto. Questo significa che puoi avere solo un tipo di aeromobile alla volta all'interno di un'istanza di an_aircraft.



*/