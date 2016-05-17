#ifndef MATRICE_HH_
#define MATRICE_HH_

typedef double tipoelem;

class matrice {
  public:
	matrice(int, int,tipoelem inizializzatore=0); /* costruttore */
    ~matrice();
    tipoelem leggimatrice(int, int);
    void scrivimatrice(int, int, tipoelem);
    void stampa(void);
    void prodottoScalare(tipoelem);
    matrice matriceTrasposta();
    void matriceProdotto(matrice M);
    void generaRandom();
    matrice& operator=(const matrice &m);
  private:
    int rMatrice;
    int cMatrice;
    tipoelem **elementi;
};


// costruttore
	matrice::matrice(int r, int c, tipoelem inizializzatore) {

	cMatrice = c;
	rMatrice = r;
	// allocazione dinamica della matrice
	elementi = new tipoelem**[rMatrice];
	for(auto r_index = 0; r_index != rMatrice; r_index++)
		elementi[r_index] = new tipoelem*[cMatrice];

	// inizializzazione degli elementi
	for(auto r_index = 0; r_index != rMatrice; rMatrice++)
		for(auto c_index = 0; c_index != cMatrice; cMatrice++)
			scrivimatrice(r_index, c_index, inizializzatore);
}

void matrice::scrivimatrice(const int righe, const int colonne, const tipoelem valore) {
	elementi[righe][colonne] = valore;
	return;
}

tipoelem matrice::leggimatrice(const int righe, const int colonne) {
	return (matrice::elementi[righe][colonne]);
}

matrice::~matrice(void) {
	delete elementi;
}

void matrice::stampa() {
	using namespace std;
	for (auto r_index = 0; r_index != rMatrice; r_index++)
		for (auto c_index = 0; c_index != cMatrice; c_index++)
			cout << matrice::leggimatrice(r_index, c_index) << " ";
		cout << endl;
	return;
}

void matrice::prodottoScalare(tipoelem scalare){

	for (auto r_index = 0; r_index != rMatrice; r_index++)
		for (auto c_index = 0; c_index != cMatrice; c_index++)
			matrice::scrivimatrice(r_index, c_index,
								  (matrice::leggimatrice(r_index, c_index)
								  * scalare));
	return;
}

matrice matrice::matriceTrasposta() {
	matrice T(cMatrice, rMatrice);

	for (auto r_index = 0; r_index != rMatrice; r_index++)
		for (auto c_index = 0; c_index != cMatrice; c_index++)
			T.scrivimatrice(r_index, c_index,
					matrice::leggimatrice(c_index, r_index));
	return (T);
}

void matrice::matriceProdotto(matrice M) {
	using namespace std;
	if (rMatrice == cMatrice) {
		for (auto r_index = 0; r_index != rMatrice; r_index++)
			for (auto c_index = 0; c_index != cMatrice; c_index++)
				matrice::scrivimatrice(r_index, c_index,
									  (matrice::leggimatrice(r_index, c_index)
									  * M.leggimatrice(r_index, c_index)));
	}
	else {
		cout
				<< "Attenzione, non è possibile moltiplicare una matrice con numero di righe e colonne diverso"
				<< endl;
	}
	return;
}

void matrice::generaRandom() {
	for (auto r_index = 0; r_index != rMatrice; r_index++)
		for (auto c_index = 0; c_index != cMatrice; c_index++)
			matrice::scrivimatrice(r_index, c_index,(random() % 100));
	return;
}

/* Copiato*/
matrice &matrice::operator=(const matrice &m) {
	// evita gli auto assegnamenti
	if (this != &m) {
		int i, j;
		if (cMatrice != m.cMatrice || rMatrice != m.rMatrice) {
			this->~matrice();
			cMatrice = m.cMatrice;
			rMatrice = m.rMatrice;
			elementi = new tipoelem*[rMatrice];
			for (i = 0; i != rMatrice; i++)
				elementi[i] = new tipoelem[cMatrice];
		}
		for (i = 0; i != rMatrice; i++)
			for (j = 0; j < cMatrice; j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return (*this);
}
/* Copiato*/



#endif /* MATRICE_H_ */
