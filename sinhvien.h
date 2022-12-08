#include "date.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
typedef struct  
{
	char mahv[10];
	char hoten[50];
	Date ns;
	int gt; //0-nu,1-nam
	char quequan[30];
	char lop[10];
	float diemToan;
    float diemLy;
    float diemHoa;
    float diemtb;
    char hocluc[10];
} Hoc_vien;

void nhapHv(Hoc_vien *h);
void inHv(Hoc_vien h);
void nhapdsHv(Hoc_vien *a, int *n);
void indsHv(Hoc_vien *a,int n);
void timHvTheoMa(Hoc_vien *a,int n);
void ghidsHv(Hoc_vien *a,int n);
void docdsHv(Hoc_vien *a,int *n);
void xeploai(Hoc_vien sv);
void tinhDTB(Hoc_vien *sv) ;
void sapxepTheoDTB(Hoc_vien *a,int n);
 void xeploaiN(Hoc_vien *a, int n);
 void Sapxeptheoten(Hoc_vien *sv, int n);



