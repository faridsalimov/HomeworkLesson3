#include <iostream>
#include <Windows.h>

using namespace std;

// ===================================================================
// class: Debtor (debtor-borclu)
// fields: objectId, name, surname, workAddress, debt, phoneNumber
// fields: hasLatePayment(bool), liveAddress, debt, Id(static)
// methods: showDebtor
//
// class: Bank 
// fields: name, debtors(array)
// method: showAllDebtors,
// method: borcu 1000 den yuxari olanlari gostermek
// method: gecikmesi olanlari gostermek
//
// QEYD: Kechdiymiz her shey istifade olunsun.
// static field, copy constructor ve s
// ===================================================================

class Debtor {
	static int objectId;
	int id;
	string name;
	string surname;
	string workAddress;
	string liveAddress;
	int debt;
	int phoneNumber;
	bool hasLatePayment;

public:
	Debtor() {
		id = objectId++;
		name = "";
		surname = "";
		workAddress = "";
		liveAddress = "";
		debt = 0;
		phoneNumber = 0;
		hasLatePayment = false;
	}

	Debtor(string name, string surname, string workAddress, string liveAddress, int debt, int phoneNumber, bool hasLatePayment) {
		id = objectId++;
		this->name = name;
		this->surname = surname;
		this->workAddress = workAddress;
		this->liveAddress = liveAddress;
		this->debt = debt;
		this->phoneNumber = phoneNumber;
		this->hasLatePayment = hasLatePayment;
	}

	int GetId() {
		return id;
	}

	string GetName() {
		return name;
	}

	string GetSurname() {
		return surname;
	}

	string GetWorkAddress() {
		return workAddress;
	}

	string GetLiveAddress() {
		return liveAddress;
	}

	int GetDebt() {
		return debt;
	}

	int GetPhoneNumber() {
		return phoneNumber;
	}

	bool GetLatePayment() {
		return hasLatePayment;
	}
};

int Debtor::objectId = 1;

class Bank {
	string bankName;
	Debtor** debtors;
	int size;

public:
	Bank() {
		bankName = "";
		debtors = nullptr;
		size = 0;
	}

	Bank(string bankName) {
		this->bankName = bankName;
	}

	void ShowAllDebtors() {
		cout << "[!] Welcome to " << bankName << "!\n" << endl;

		for (int i = 0; i < size; i++)
		{
			cout << "[!] Details of the Debtor [" << debtors[i]->GetId() << "]: \n";
			cout << ">> Name: " << debtors[i]->GetName() << "\n>> Surname: " << debtors[i]->GetSurname() << "\n>> Work Address: " << debtors[i]->GetWorkAddress() << "\n>> Live Address: " << debtors[i]->GetLiveAddress() << "\n>> Debt: " << debtors[i]->GetDebt() << "$\n>> Phone Number: +994" << debtors[i]->GetPhoneNumber() << "\n>> Has Late Payment: " << (debtors[i]->GetLatePayment() ? "Yes" : "No") << "\n\n";
		}
	}

	void ShowOnlyDebtors() {
		cout << "[!] Welcome to " << bankName << "!\n" << endl;

		for (int i = 0; i < size; i++)
		{
			if ((debtors[i]->GetLatePayment() == true) && (debtors[i]->GetDebt() > 1000)) {
				cout << "[!] Details of the Debtor [" << debtors[i]->GetId() << "]: \n";
				cout << ">> Name: " << debtors[i]->GetName() << "\n>> Surname: " << debtors[i]->GetSurname() << "\n>> Work Address: " << debtors[i]->GetWorkAddress() << "\n>> Live Address: " << debtors[i]->GetLiveAddress() << "\n>> Debt: " << debtors[i]->GetDebt() << "$\n>> Phone Number: +994" << debtors[i]->GetPhoneNumber() << "\n>> Has Late Payment: " << (debtors[i]->GetLatePayment() ? "Yes" : "No") << "\n\n";
			}
		}
	}

	void AddPerson(const Debtor* debt) {
		Debtor** temp = new Debtor * [size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = debtors[i];
		}

		delete[] debtors;
		temp[size] = new Debtor(*debt);
		debtors = temp;
		temp = nullptr;
		size++;
	}
	
	~Bank() {
		for (int i = 0; i < size; i++) delete debtors[i];
		delete[] debtors;
	}
};

void main() {
	Bank bk("Bank of Santos");
	Debtor d1("Ferid", "Selimov", "Baku", "Xirdalan", 750, 507388281, false);
	Debtor d2("Rinat", "Qedimov", "Sumqayit", "Xirdalan", 1295, 774332926, true);

	bk.AddPerson(&d1);
	bk.AddPerson(&d2);

	//bk.ShowAllDebtors();
	bk.ShowOnlyDebtors();
}