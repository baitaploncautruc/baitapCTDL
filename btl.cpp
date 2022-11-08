#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
int dem=0;
using namespace std;

struct SanPham{
	int msp,soluong;
	char tensp[30],ngaysx[20];
	float dongia;
	
	void Nhap(){
		cout<<"Nhap ma san pham :";
		cin>>msp;
		cout<<"Nhap ten san pham:";
		fflush(stdin);
		gets(tensp);
		cout<<"Nhap so luong:";
		cin>>soluong;
		cout<<"Nhap don gia:";
		cin>>dongia;
		cout<<"Nhap ngay san xuat:";
		fflush(stdin);
		gets(ngaysx);
	}
	float gia(){
		return soluong*dongia;
	}
	void Xuat(){
		cout<<setw(2)<<++dem<<setw(6)<<msp<<setw(17)<<tensp<<setw(5)<<soluong<<setw(15)<<dongia;
		cout<<setw(12)<<gia()<<setw(18)<<ngaysx<<endl;
	}
};

typedef SanPham SP;

// nhap so luong san pham 
void nhapSLSP(int &n){
	do{
		cout<<"Nhap so luong san pham : ";
		cin>>n;
		if(n<0)
			cout<<"Moi ban nhap lai";
	}while(n<0);
}

// nhap danh sach san pham
void nhapSP(SP *sp, int n){
	for(int i=0;i<n;i++){
			cout<<"Nhap thong tin san pham thu "<<i+1<<":"<<endl;
			sp[i].Nhap();
	}
}
void tieude(){
	cout<<setw(2)<<"STT"<<setw(5)<<"MSP"<<setw(17)<<"Ten San Pham"<<setw(10)<<"So Luong"<<setw(10)<<"Don Gia";
	cout<<setw(10)<<"Gia"<<setw(20)<<"Ngay san xuat"<<endl;
}

//xuat danh sach san pham 
void xuatSP(SP *sp, int n){
	dem=0;
	tieude();
	for(int i=0;i<n;i++){
		sp[i].Xuat();
	}
}

// them thong tin san pham 
void them(SP *sp,int &n){
	n++;
	cout<<"Nhap thong tin san pham can them:"<<endl;
	sp[n-1].Nhap();
}

// xoa san pham
void xoa(SP *sp,int &n){
	int xmsp;
	cout<<"Nhap ma san pham can xoa: ";
	cin>>xmsp;
	for(int i=0;i<n;i++){
		if(sp[i].msp==xmsp){
			for(int j=i;j<n;j++){
				sp[j]=sp[j+1];
			}
		}
	}
}

//tim kiem san pham
void timkiemSP(SP *sp, int n){
	int tmsp;
	cout<<"Nhap ma san pham can tim: ";
	cin>>tmsp;
	for(int i=0;i<n;i++){
		if(sp[i].msp==tmsp){
			sp[i].Xuat();	
		}
	}
}

//sap xep theo ma san pham tang dan 
void sapxep(SP *sp, int n){
	dem=0;
	cout<<"Danh sach san pham theo thu tu msp tang dan"<<endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sp[i].msp>sp[j].msp){
				swap(sp[i],sp[j]);
			}
		}
	}
	xuatSP(sp,n);
}

//sap xep theo ten 
void sapxepten(SP *sp, int n){
	dem=0;
	cout<<"Danh sach san pham theo ten"<<endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(sp[i].tensp,sp[j].tensp)>0){
				swap(sp[i],sp[j]);
			}
		}
	}
	xuatSP(sp,n);
}

void Press(){
	system("pause");
	system("cls");
}
//tao menu  
void menu(){

	cout<<"\t\tMENU Quan ly san pham"<<"\n";
	cout<<"========================================================"<<"\n";
	cout<<"\n1.Nhap danh sach san pham";
	cout<<"\n2.Hien thi danh sach san pham";
	cout<<"\n3.Them thong tin san pham";
	cout<<"\n4.Xoa thong tin san pham";
	cout<<"\n5.Tim kiem san pham ";
	cout<<"\n6.Sap xep theo ma san pham tang dan";
	cout<<"\n7.Sap xep thep ten san pham";
	cout<<"\n0.Thoat";
}
int main(){
	int n=0, luachon;
	SP *sp;
	sp= new SP[100];

	//menu
	do{
		menu();
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		
		switch(luachon){
			case 1:
				system("cls");
				nhapSLSP(n);
				nhapSP(sp,n);
				Press();
				break;
			case 2:
				system("cls");
				xuatSP(sp,n);
				Press();
				break;
			case 3:
				system("cls");
				them(sp,n);
				Press();
				break;
			case 4:
				system("cls");
				xoa(sp,n);
				Press();
				break;
			case 5:
				system("cls");
				timkiemSP(sp,n);
				Press();
				break;
			case 6:
				system("cls");
				sapxep(sp,n);
				Press();
				break;
			case 7:
				system("cls");
				sapxepten(sp,n);
				Press();
				break;	
			case 0:
				break;			
		default:
			cout<<"Nhap lai"<<endl;
			break;
	    }
	}while(luachon);
	return 0;
}


