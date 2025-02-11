#include <iostream>
#include <fstream>
#include "Structure.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>

using namespace std;

bool themSinhVien(ptrsv &First, SV sv){ 
	ptrsv Last, p;
	//p->dt = NULL;
	if(First != NULL)
		for(Last = First; Last->next != NULL; Last = Last->next); // duyet den cuoi danh sach
	if (First == NULL) {
		p = new SV;
		*p = sv;
		p->next = NULL;
		First = p;
	}
	else{
		p = new SV;
		*p = sv;
		p->next = NULL;
		Last->next = p;
	}
//	cout << sv.MSV << "\n";
	return true;
}
void generateArrayRandomNumber(int arrayRandomNumber[]){											
	int randomNumber;
	srand(time(NULL));
	int temp;
	for(int i = 0; i < MAXQUEST; i++){  
		arrayRandomNumber[i] = i;
	}
	arrayRandomNumber[0] = MAXQUEST/2;
	arrayRandomNumber[MAXQUEST/2] = 0;
	for(int i = 1; i < MAXQUEST-1; i++){
		randomNumber = rand() % (MAXQUEST - i)+1;
		//cout << "randomNumber = " << randomNumber << endl;
		temp = arrayRandomNumber[MAXQUEST-i];
		arrayRandomNumber[MAXQUEST-i] = arrayRandomNumber[randomNumber];
		//cout <<"arrayRandomNumber[MAXQUEST-i] = " << arrayRandomNumber[MAXQUEST-i] << endl;	
		arrayRandomNumber[randomNumber] = temp;		
		//cout <<"arrayRandomNumber[randomNumber] = " << arrayRandomNumber[randomNumber] << endl;	
	}
}
int main(){
//	DSLop dsLop;
//	Lop lop1 = {"at01111", "an toan 1", "2020-2029", NULL};
//	Lop lop2 =  {"at02", "an toan 2", "2020-2021", NULL};
//	dsLop.lop[0] = new Lop;
//	dsLop.lop[1] = new Lop;
//	*dsLop.lop[0] = lop1;
//	*dsLop.lop[1] = lop2;
//	dsLop.index = 2;
//	SV tempSV1 = {"SV01", "DO", "ANH QUAN", true, "password", NULL, NULL};
//	SV tempSV2 = {"SV02", "NGUYEN", "VAN A", false, "password",  NULL, NULL};
//	SV tempSV3 = {"SV03", "NGUYEN", "VAN B", true, "password",  NULL, NULL};
//	SV tempSV4 = {"SV04", "NGUYEN", "VAN C", false, "password",  NULL, NULL};
//	themSinhVien(dsLop.lop[0]->sv, tempSV1);
//	themSinhVien(dsLop.lop[0]->sv, tempSV2);
//	themSinhVien(dsLop.lop[1]->sv, tempSV3);
//	themSinhVien(dsLop.lop[1]->sv, tempSV4);
////	ptrsv sv = dsLop.lop[0]->sv;
////	while(sv != NULL){
////		cout << sv->MSV;
////		sv = sv->next;
////	}
//	ofstream outfileLop("DSLop.txt", ios::out | ios::binary);
//	if(outfileLop == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	
//	for(int i=0; i < dsLop.index; i++){
//		// ma lop
//		outfileLop.write( dsLop.lop[i]->MALOP.c_str(), dsLop.lop[i]->MALOP.size());
//		outfileLop.write("\0", sizeof(char));
//		// ten lop
//		outfileLop.write( dsLop.lop[i]->TENLOP.c_str(), dsLop.lop[i]->TENLOP.size());
//		outfileLop.write("\0", sizeof(char));
//		// nien khoa
//		outfileLop.write( dsLop.lop[i]->NK.c_str(), dsLop.lop[i]->NK.size());
//		outfileLop.write("\0", sizeof(char));
//		// luu sinh vien
//		string tenFileLop = dsLop.lop[i]->MALOP + ".txt";
//		ofstream fileLop( tenFileLop, ios::out | ios::binary);
//		if(fileLop == NULL){
//			cout << "Loi file" << endl;
//			return false;
//		}
//		// vong lap while luu sinh vien vao file
//		ptrsv sv = dsLop.lop[i]->sv;
//		while(sv != NULL){
//			// MSV
//			fileLop.write( sv->MSV.c_str(), dsLop.lop[i]->sv->MSV.size());
//			fileLop.write("\0", sizeof(char));
//			// HO
//			fileLop.write( sv->HO.c_str(), dsLop.lop[i]->sv->HO.size());
//			fileLop.write("\0", sizeof(char));
//			// TEN
//			fileLop.write( sv->TEN.c_str(), dsLop.lop[i]->sv->TEN.size());
//			fileLop.write("\0", sizeof(char));
//			// PHAI
//			fileLop.write( (char*)&sv->PHAI, sizeof(bool));
//			// PASSWORD
//			fileLop.write( sv->password.c_str(), dsLop.lop[i]->sv->password.size());
//			fileLop.write("\0", sizeof(char));
//			sv = sv->next;
//		}
//	}
//	outfileLop.close();

	streampos size;
	ifstream infileLop("DSLop.txt", ios::in | ios::binary | ios::ate);
	if(infileLop == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	DSLop dsLop;
	size = infileLop.tellg();
	infileLop.seekg(0, ios::beg);
	while(size != infileLop.tellg()){
		dsLop.lop[dsLop.index] = new Lop;
		// ma lop
		getline(infileLop, dsLop.lop[dsLop.index]->MALOP, '\0');
		// ten lop
		getline(infileLop, dsLop.lop[dsLop.index]->TENLOP, '\0');
		// nien khoa
		getline(infileLop, dsLop.lop[dsLop.index]->NK, '\0');
		
		// doc file lop
		string fileLop = dsLop.lop[dsLop.index]->MALOP + ".txt";
		ifstream infileSV(fileLop, ios::in | ios::binary | ios::ate);
		if(infileSV == NULL){
			cout << "Loi file" << endl;
			return false;
		}
		streampos sizeSV;
		sizeSV = infileSV.tellg();
		infileSV.seekg(0, ios::beg);
		ptrsv sv = dsLop.lop[dsLop.index]->sv;
		int i = 0;
		while(sizeSV != infileSV.tellg()){
			SV tempSV;
			// MSV
			getline(infileSV, tempSV.MSV, '\0');
			// HO
			getline(infileSV, tempSV.HO, '\0');
			// TEN
			getline(infileSV, tempSV.TEN, '\0');
			// PHAI	
//			infileSV.read((char*) &tempSV.PHAI, sizeof(bool));
//			bool PHAI;
			infileSV.read((char*)&tempSV.PHAI, sizeof(bool));
			// PASSWORD
			getline(infileSV, tempSV.password, '\0');
			cout << tempSV.MSV << "  " << tempSV.HO << "  " << tempSV.TEN << " i: " << i << "\n";
			i++;
//			themSinhVien(sv, tempSV);
		}
		infileSV.close();
		dsLop.index++;
	}
	infileLop.close();
	for(int i= 0 ; i < dsLop.index; i++){
		cout << dsLop.lop[i]->MALOP << " " << dsLop.lop[i]->TENLOP << " " << dsLop.lop[i]->NK << "  " << i << "\n";
//		ptrsv sv = dsLop.lop[i]->sv;
//		while(sv != NULL){
//			cout << sv->MSV << "  " << sv->HO << "  " << sv->TEN  << "\n";
//			sv =sv->next;
//		}
	}	

//	streampos size;
//	ifstream infileSV("at02.txt", ios::in | ios::binary | ios::ate);
//	if(infileSV == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	size = infileSV.tellg();
//	infileSV.seekg(0, ios::beg);
//	while(size != infileSV.tellg()){
//		string MSV;
//		// MSV
//		getline(infileSV, MSV, '\0');
//		// HO
//		string HO;
//		getline(infileSV, HO, '\0');
//		// TEN
//		string TEN;
//		getline(infileSV, TEN, '\0');
//		// PHAI
//		bool PHAI;
//		infileSV.read((char*)&PHAI, sizeof(bool));
//		// PASSWORD
//		string password;
//		getline(infileSV, password, '\0');
//		cout << MSV << "-" << HO << "-" << TEN  << "-" << password << "\n";
//	}
	
	return 0;
}
