
#include <LiquidCrystal.h>

const int piezoPin = 13;

const int rPin = 5;
const int bPin = 4;
const int jPin = 3;
const int vPin = 2;

int lrPin = A2;
int lbPin = A3;
int ljPin = A4;
int lvPin = A5;

int lumieres[] = {rPin, bPin, jPin, vPin};
int notes[] = {262,294,330,349};
int commutateurs[] = {lrPin, lbPin, ljPin, lvPin};
int nb_commutateurs = 4;

int niv1_loop = 0;  // Nombre de tours dans le loop (a partir de 1) 
int niv2_loop = 0;
int niv3_loop = 0;
int niv4_loop = 0;

int is_array_egaux(int a[], int b[], int len){            // Comparaison des notes
  for(int i = 0; i < len; i++){
    if(a[i] != b[i]) return 0;
  }
  return 1;
}
int melodie_0[] = {1, 1, 3, 3, 2, 0, 0};
int melodie_1[] = {0, 2, 1, 3};
int melodie_2[] = {3, 1, 2, 2, 3};
int melodie_3[] = {2, 3, 2, 3, 1, 0};
int melodie_4[] = {1, 0, 3, 1, 0, 2, 3};
int melodie_5[] = {0, 0, 1, 2, 3, 1, 2, 3, 1, 0, 2, 1};


void jouer_melodie(int melodie[], int nb_notes){         //Jouer la melodie
  for(int i = 0; i < nb_notes; i++){
    digitalWrite(lumieres[melodie[i]], HIGH);
    tone(piezoPin, notes[melodie[i]]);
    delay (100);
    noTone(piezoPin);
    delay (500);
    digitalWrite(lumieres[melodie[i]], LOW);
    delay (500);  
  }
}


void jouer_melodie_finale(int melodie[], int nb_notes){         //Jouer la melodie FINALE
  for(int i = 0; i < nb_notes; i++){
    digitalWrite(lumieres[melodie[i]], HIGH);
    tone(piezoPin, notes[melodie[i]]);
    delay (100);
    noTone(piezoPin);
    delay (500);
    digitalWrite(lumieres[melodie[i]], LOW);
    delay (500);  

    if(i == nb_notes){
        for(int j = 0; j < nb_notes; i++){
         digitalWrite(lumieres[melodie[i]], HIGH);
         tone(piezoPin, notes[melodie[i]]);
         delay (50);
         noTone(piezoPin);
         delay (250);
         digitalWrite(lumieres[melodie[i]], LOW);
         delay (250);  

         if(j == nb_notes) {
          for(int k = 0; k < nb_notes; i++){
           digitalWrite(lumieres[melodie[i]], HIGH);
           tone(piezoPin, notes[melodie[i]]);
           delay (10);
           noTone(piezoPin);
           delay (50);
           digitalWrite(lumieres[melodie[i]], LOW);
           delay (250);  
          }
      }
  }
}
}
}


int * lire_notes(int nb_notes){        // nb_notes est le nombre de notes à lire  (Lire les notes)
  int reponse[nb_notes];
  int nb_notes_lues = 0;

  while(nb_notes_lues < nb_notes){
    for(int i = 0; i < nb_commutateurs; i++){
      if(analogRead(commutateurs[i]) > 950){  // Est-ce que le commutateur 0 est allumé?
        tone(piezoPin, notes[i]);
        delay (100);
        noTone(piezoPin);
        reponse[nb_notes_lues++] = i;
        delay (500);
      }
    }
  }

  return reponse;
}

void setup() {
  
Serial.begin(9600);

pinMode (piezoPin,OUTPUT);
digitalWrite (piezoPin, LOW);
 
pinMode (rPin,OUTPUT);
pinMode (bPin,OUTPUT);
pinMode (jPin,OUTPUT);
pinMode (vPin,OUTPUT);

digitalWrite (rPin, LOW);
digitalWrite (bPin, LOW);
digitalWrite (jPin, LOW);
digitalWrite (vPin, LOW);

pinMode (lrPin,INPUT);
pinMode (lbPin,INPUT);
pinMode (ljPin,INPUT);
pinMode (lvPin,INPUT);
}

void loop() {
  niv1_loop++;
//////////////////////////////////////////////////////////////////////////////niveau1///////////////////////////////////////////
  if(niv1_loop == 1){  // Si premier tour
    // Jouer la séquence:
    jouer_melodie(melodie_0, 7); //intro
    delay(1000);
    jouer_melodie(melodie_1, 4);
  }
  
  if(is_array_egaux(lire_notes(4), melodie_1, 4)){
    // Gagné
////////////////////////////////////////////////////////////////////////////niveau2////////////////////////////////////////////
 niv2_loop++;
  if(niv2_loop == 1){  // Si premier tour
    // Jouer la séquence:
    jouer_melodie(melodie_2, 5);
  }
  
  if(is_array_egaux(lire_notes(5), melodie_2, 5)){
    // Gagné
////////////////////////////////////////////////////////////////////////////niveau3/////////////////////////////////////////////
  niv3_loop++;
  if(niv3_loop == 1){  // Si premier tour
    // Jouer la séquence:
    jouer_melodie(melodie_3, 6);
  }
  
  if(is_array_egaux(lire_notes(6), melodie_3, 6)){
    // Gagné
 //////////////////////////////////////////////////////////////////////////niveau4//////////////////////////////////////////////
  niv4_loop++;
   if(niv4_loop == 1){  // Si premier tour
    // Jouer la séquence:
    jouer_melodie(melodie_4, 7);
  }
  
  if(is_array_egaux(lire_notes(7), melodie_4, 7)){
    // Gagné
 /////////////////////////////////////////////////////////////////////////niveau5/////////////////////////////////////////////////
 jouer_melodie_finale(melodie_5, 12);
 delay(2000);
 //////FINAL/////
 
  }
  else{
    // Perdu
  }
 
  }
  else{
    // Perdu
  }
  }
  else{
    // Perdu
  }
  }
  else{
    // Perdu
  }
}








