
#ifndef DATIGLOBALI_H_
#define DATIGLOBALI_H_

#define DIMESIONEFILE 20

typedef struct{
	char codTreno[5];
	char CittaPartenza[20];
	char OraPartenza[5];
	char CittaArrivo[20];
	char OraArrivo[5];
	float prezzo;
}Treni;

#endif /* DATIGLOBALI_H_ */
