#include <stdio.h>
#include "sinhvien.h"

void nhapHv(Hoc_vien *h)
{
	fflush(stdin);
	printf("Nhap ma hoc vien:");gets(h->mahv);
	printf("Nhap ho ten:");gets(h->hoten);
	nhapNgay(&h->ns);fflush(stdin);
	printf("Nhap gioi tinh (0-nu,1-nam):");scanf("%d",&h->gt);
	fflush(stdin);
	printf("Nhap que quan:");gets(h->quequan);
	printf("Nhap lop:");gets(h->lop);
		printf("Nhap diem toan:");scanf("%2f",&h->diemToan);
	fflush(stdin);
		printf("Nhap gdiem ly:");scanf("%2f",&h->diemLy);
	fflush(stdin);
		printf("Nhap diem hoa:");scanf("%2f",&h->diemHoa);
	fflush(stdin);
}

void inHv(Hoc_vien h)
{
	printf("\nMa hoc vien: %s",h.mahv);
	printf("\nHo ten: %s",h.hoten);
	printf("\nNgay sinh: ");inNgay(h.ns);
	printf("\nGioi tinh: %s",(h.gt!=0?"Nam":"Nu"));
	printf("\nQue quan: %s",h.quequan);
	printf("\nLop: %s",h.lop);
	printf("\ndiem hoa: %2f",h.diemHoa);
	printf("\ndiem ly: %2f",h.diemLy);
	printf("\ndiem toan: %2f",h.diemToan);
}

void nhapdsHv(Hoc_vien *a, int *n)
{
	int i;
	printf("So hoc vien muon nhap:");scanf("%d",n);
	for (i=0;i<*n;i++)
	{
		printf("\nHoc vien thu %d:\n",i+1);
		nhapHv(&a[i]);
	}
	printf("\nNhap du lieu thanh cong...");
}

void indsHv(Hoc_vien *a,int n)
{
	int i;
	printf("\nCac hoc vien da nhap:");
	for (i=0;i<n;i++)
	{
		printf("\nHoc vien thu %d:\n",i+1);
		inHv(a[i]);
	}
}

void timHvTheoMa(Hoc_vien *a,int n)
{
	char findText[15];
	int i;
	fflush(stdin);
	printf("\nNhap ma sinh vien muon tim:");gets(findText);
	for (i=0;i<n;i++)
		if (strcmp(a[i].mahv,findText)==0)
	 		{
	 			inHv(a[i]);
	 		}
}

void ghidsHv(Hoc_vien *a,int n)
{
	char tentep[50]; int i;
	FILE *fp;
	fflush(stdin);
	printf("\nNhap ten tep muon ghi:");gets(tentep);
	if ((fp=fopen(tentep,"w"))==NULL)
	{
		printf("\nLoi mo tep!");
		exit(1);
	}
	for (i=0;i<n;i++)
	{				
		fprintf(fp,"%s\n",a[i].mahv);
		fprintf(fp,"%s\n",a[i].hoten);
		fprintf(fp,"%d %d %d\n",a[i].ns.ngay,a[i].ns.thang,a[i].ns.nam);
		fprintf(fp,"%d\n",a[i].gt);
		fprintf(fp,"%s\n",a[i].quequan);
		fprintf(fp,"%s\n",a[i].lop);
	}
	fclose(fp);
	printf("\nGhi du lieu thanh cong...");
}

void docdsHv(Hoc_vien *a,int *n)
{
	char tentep[50]; 
	Hoc_vien temp;
	FILE *fp;
	fflush(stdin);
	printf("\nNhap ten tep muon doc:");gets(tentep);
	if ((fp=fopen(tentep,"r"))==NULL)
	{
		printf("\nLoi mo tep!");
		exit(1);
	}
	*n=0;
	while (fgets(temp.mahv,10,fp) != NULL)
    {   	
		fgets(temp.hoten,50,fp);
		fscanf(fp,"%d%d%d",&temp.ns.ngay,&temp.ns.thang,&temp.ns.nam);
		fscanf(fp,"%d",&temp.gt);
		fgetc(fp);
		fgets(temp.quequan,30,fp);
		fgets(temp.lop,10,fp);
		a[*n]=temp;
		inHv(a[*n]);
		*n++;
	}
	fclose(fp);
//	*n--;
//	indsHv(a,*n);
	printf("\nDoc du lieu thanh cong...");
}
 void Sapxeptheoten(Hoc_vien *sv, int n){
 	int i,j;
 	for(i=0;i<n-1;i++)
 	{
 		for(j=i+1;j<n;j++)
 		{
 			if(strcmp(sv[i].hoten,sv[j].hoten)>0)
 			{
 				Hoc_vien k=sv[i];
 				sv[i]=sv[j];
 				sv[j]=k;
			 }
		 }
	 }
 }
 void tinhDTB(Hoc_vien *sv) {
 	sv->diemtb=(sv->diemHoa+sv->diemLy+sv->diemToan)/3;	
 }
 void xeploai(Hoc_vien sv){
 	if(sv.diemtb<0||sv.diemtb>10){
 		printf("diem khong hop le");
	 }
	 else if(sv.diemtb>=9){
	 	printf("gioi");
	 }
	 else if(sv.diemtb>=7){
	 	printf("kha");
	 }
	 else if(sv.diemtb>=5){
	 	printf("trung binh");
	 }
	 else{
	 	printf("yeu");
	 }
 }
 void sapxepTheoDTB(Hoc_vien *a, int n) {
    //Sap xep theo DTB tang dan
    Hoc_vien tmp;
    int i,j;
    for( i= 0;i < n;i++){
        for( j = i+1; j < n;j++){
            if(a[i].diemtb > a[j].diemtb){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }printf("%s \n", a[i]);
    }
}
 void xeploaiN(Hoc_vien *a, int n){
 	
 }

