#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char** argv) {
	
	cout << "[1] : save new account" << endl;
	cout << "[2] : show account details" << endl;
	cout << "[3] : save new transaction" << endl;
	cout << "[4] : list transaction" << endl;
	string action;
	cin >> action;
	
	if(action == "1"){
	
		cout << "== save new account ==" << endl;
		cout << "enter your account number : ";
		string accountNumber;
		cin >> accountNumber;
			
		cout << "enter your money (Toman) : ";
		string money;
		cin >> money;
		
		cout << "enter bank name : ";
		string bankName;
		cin >> bankName;
		
		cout << "enter card number : ";
		string cardNumber;
		cin >> cardNumber;
		
		string prevData;
		string row;
		ifstream reader("data.txt");
		while( getline(reader , row) ){
			prevData += row + "\n";
		}
		
		
		ofstream w("data.txt");
		string data;
		data = accountNumber  + "\n" + bankName + "\n" + money + "\n" +
		 cardNumber + "\n" + "\n";
		
		prevData += data;
		
		w<<prevData;
		w.close();
		
		
		ofstream w2("tr_" + accountNumber + ".txt");
		w2.close();
		
		cout << endl << "your data saved!";
		
	}
	
	if (action == "2"){
		cout << "== show account details ==" << endl;
		cout << "enter your account number : ";
		string accountNumber;
		cin >> accountNumber;
		
		
		cout << ">> your account info : " << endl;
		
		string row;
		ifstream reader("data.txt");
		string detail[] = { " account number : " , " bank name : ", " money : ", " card number : "};
		int i=-1;
		while( getline(reader , row) ){
			
			if (row == accountNumber) {
				i= 0;
			}
			
			
			if( i > -1 ){
				cout << detail[i] << row <<endl;
				i++;
			}
			
			
			if(row == ""){
				cout << endl;
				i=-1;
			}
			
		}
		
		reader.close();
		cout << endl << "DONE";
	}
	
	if (action == "3"){
		cout << "== add new transaction ==" << endl;
		
		cout << "give me your account number : ";
		string account;
		cin >> account;
		
		
		
		cout << "give me number of new transaction : " ;
		int num;
		cin >> num;
		
		int newMoney=0;
		string tran[num];
		for(int i=0; i<num; i++){
			
			int amount;
			cout << "amount : ";
			cin >> amount;
			
			string reamount;
			cout << "re enter amount : ";
			cin >> reamount;
			
			
			if (amount > 0){

				newMoney = newMoney + amount;
				tran[i] = "+" + reamount;
			}
			else {

				newMoney =  newMoney + amount;
				tran[i] = reamount;
			}
			

		}
		
		
		ifstream reader("tr_" + account + ".txt");
		string befor;
		string row;
		while( getline(reader , row) ){
			befor += row + "\n";
		}
		reader.close();
		
		for(int i=0; i< num; i++){
			befor += tran[i] + "\n";
		}
		
		ofstream w("tr_" + account + ".txt");		
		w<<befor;
		w.close();
		
		
		
		ifstream reader3("data.txt");
		string befor3;
		int finalMoney;
		string row3;
		int k=-1;
		while( getline(reader3 , row3) ){
			
			if(row3 == account){
				k++;
			}
			
			if(k > -1){
				k++;
			}
			
			if(k == 3){

				finalMoney = stoi(row3);
				finalMoney += newMoney;
				string money_s = to_string(finalMoney);
				row3 = money_s;
			}
			
			
			if (row3 == "") {
				k=-1;
			}
			
			befor3 += row3 + "\n";
		}
		reader.close();
		
		
		ofstream w3("data.txt");		
		w3<<befor3;
		w3.close();
		
		
		
		cout<< endl << endl << "now you have  " << finalMoney << "  Toman in your account!";
	}
	
	if (action == "4"){
		cout << "== list transactions of your account ==" << endl;
		cout << "give me your account number : ";
		string account;
		cin >> account;
		
		ifstream reader("tr_" + account + ".txt");
		string row;
		while( getline(reader , row) ){
			cout << row << endl ;
		}
		reader.close();
		
		
		cout << endl << endl << "END list of your transactions";
	}

	
	return 0;
}
