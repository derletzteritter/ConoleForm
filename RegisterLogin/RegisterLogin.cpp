#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {

	string username, password, un, pw;

	cout << "Enter your username: "; cin >> username;
	cout << "Enter your password: "; cin >> password;

	// reads the file and checks if stored username 
	// and checks if values match
	ifstream read("c:\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int choice;
	
	cout << "1: Register new user\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1) {
		string username, password;

		cout << "Select a username: "; cin >> username;
		cout << "Select a password: "; cin >> password;

		// opens the file, write to it and close it.
		ofstream file;
		file.open("c:\\" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2) {
		// if returns 0, we close the program
		bool status = IsLoggedIn();

		if (!status) {
			cout << "False Login!" << endl;
			system("PAUSE");
			
			return 0;
		}
		else {
			cout << "Successfully logged in!" << endl;
			system("PAUSE");

			return 1;
		}

	}
}
