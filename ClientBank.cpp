#include "ClientBank.h"
#include <string>  // нямаше го

bankInfo::bankInfo(){  // преместих го от ClientBank.h
	type[0] = 0;
	IBAN[0] = 0;
	bal = 0;
};

ClientBank::ClientBank(){
	strcpy_s(name, "");
	strcpy_s(fName, "");
	cNum = 0;
	bankAccounts = 0;
}

ClientBank::ClientBank(char* n, char* f, int cN){
	strcpy_s(name, n);
	strcpy_s(fName, f);
	cNum = cN;
	bankAccounts = 0;
}

bool ClientBank::addAccount(char* typ, char* iban, double balance) {
	strcpy_s(this->Table[bankAccounts].type, typ);
	strcpy_s(this->Table[bankAccounts].IBAN, iban);
	this->Table[this->bankAccounts].bal = balance;
	this->bankAccounts++;
	return 1;
}
bool ClientBank::removeAccount(char* iban) {
	for (int i = 0; i < this->bankAccounts; i++) {
		if (strcmp(this->Table[i].IBAN, iban) == 0){
			bankInfo temp;

			strcpy_s(temp.type, this->Table[i].type);
			strcpy_s(temp.IBAN, this->Table[i].IBAN);
			temp.bal = this->Table[i].bal;

			for (int j = i; j < bankAccounts - 1; j++) {
				strcpy_s(this->Table[j].type, this->Table[j + 1].type);
				strcpy_s(this->Table[j].IBAN, this->Table[j + 1].IBAN);
				this->Table[j].bal = this->Table[j + 1].bal;
			}

			strcpy_s(this->Table[bankAccounts - 1].type, temp.type);
			strcpy_s(this->Table[bankAccounts - 1].IBAN, temp.IBAN);
			this->Table[bankAccounts - 1].bal = temp.bal;

			this->bankAccounts--;

			return 1;
		}
	}return 0;
}
bankInfo* ClientBank::lookAccIBAN(char* iban) {
	for (int i = 0; i < this->bankAccounts; i++) {
		if (strcmp(this->Table[i].IBAN, iban) == 0) {
			return &Table[i];
		}
	}

	return NULL;
}

bool ClientBank::addToAcc(double value, char* iban) {
	for (int i = 0; i < this->bankAccounts; i++) {
		if (strcmp(this->Table[i].IBAN, iban) == 0) {
			this->Table[i].bal += value;
			return true;
		}
	}
	return false;
}

double ClientBank::sumOfAll() {
	double sum = 0;
	for (int i = 0; i < this->bankAccounts; i++) {
		sum += this->Table[i].bal;
	}
	return sum;
}

void ClientBank::printAll() {
	printf("Name: %s %s\n", this->name, this->fName);
	printf("Client Number: %d\n", this->cNum);
	printf("Number of accounts: %d\n", this->bankAccounts);

	for (int i = 0; i < this->bankAccounts; i++) {
		printf("\tAccount number: %d\n", i + 1);
		printf("\tIBAN: %s\n", this->Table[i].IBAN);
		printf("\tType: %s\n", this->Table[i].type);
		printf("\tBalance: %.2f\n\n", this->Table[i].bal);
	}
}
ClientBank& ClientBank::operator = (ClientBank& obj){  // оператор-функция, която позвилява да се присвоява стойност на обект
	strcpy_s(name, obj.name);
	strcpy_s(fName, obj.fName);
	cNum = obj.cNum;
	bankAccounts = obj.bankAccounts;
	for (int i = 0; i < bankAccounts; i++)
		Table[i] = obj.Table[i];
	return *this;

}

