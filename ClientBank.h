#pragma once
struct bankInfo{
	char type[20];
	char IBAN[23];
	double bal;
	bankInfo();
};


class ClientBank{
	char name[15];
	char fName[15];
	int cNum;
	int bankAccounts;
	bankInfo Table[10];
public:
	ClientBank();
	ClientBank(char *name, char *fName, int cNum);
	bool addAccount(char *type, char *IBAN, double bal);
	bool removeAccount(char *IBAN);
	bankInfo* lookAccIBAN(char *IBAN);
	bool addToAcc(double money, char *IBAN);
	double sumOfAll();
	void printAll();
	int getCNum(){
		return cNum;
	};
	ClientBank& operator=(ClientBank& obj);  // оператор-функция за присвояване
};


