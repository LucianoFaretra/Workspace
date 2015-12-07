#include "codavt.cc"
#include "testcoda.hh"
#include <iostream>

using namespace std;

int main(){

  Coda<int> C(MAXLUNG);
  Coda<int> D(MAXLUNG);
  int temp;
  size_t contatore;
/*  C.inCoda(1);
  C.inCoda(2);
  C.inCoda(3);
  C.inCoda(4);
  C.inCoda(5);
  C.inCoda(6);

  cout << " " << C.leggiCoda();
  C.fuoriCoda();
  C.inCoda(4);
  cout << " " << C.leggiCoda();
  C.fuoriCoda();
  cout << " " << C.leggiCoda();
  C.inCoda(5);
  C.fuoriCoda();
  cout << " " << C.leggiCoda();
  C.fuoriCoda();
  cout << " " << C.leggiCoda();
  C.fuoriCoda();

*/
  contatore = 0;
  while(contatore < MAXLUNG){
	  C.inCoda(++contatore);
  }
/*

  while(C.codaVuota() == 0){
	  temp = C.leggiCoda();
	  if(temp % 2 == 0){
		  D.inCoda(temp);
	  }
	  C.fuoriCoda();
  };
*/
  D = C;

  while(D.codaVuota() == 0){
	  cout << " " << D.leggiCoda();
	    D.fuoriCoda();
  };

  return (0);
}
