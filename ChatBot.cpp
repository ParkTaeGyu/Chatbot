//============================================================================
// Name        : ChatBot.cpp
// Author      : Cmesias (Carl Mesias)
// Version     :
// Copyright   : MIT License
// Description : Simple Chatbot made in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

	// Loop
	bool quit = false;

	// Welcome screen
	cout << "Welcome to ChatBot V0.01" << "\n\n";

	// Loop until user quits
	while (!quit){

		// Get user response
		bool analyzeReponse = true;
		cout << "YOU: ";
		string response;
		getline(cin, response);

		// Quit if requested, else continue
		if (response == "/quit"){
			quit = true;
			break;
		}

		// Compare response with saved responses
		bool saveResponse = true;
		string line;
		ifstream brain("responses.txt");
		if (brain.is_open()){
			while (getline(brain, line)){
				if (response == line){
					getline(brain, line);
					cout << "COMPUTER: " << line << "\n\n";
					saveResponse = false;
				}
			}
			brain.close();
		}else{
			cout << "No file present.";
		}

		// Response not in database, prompt user for correct response
		if (saveResponse){
			cout << "\nCOMPUTER: " << response << "\n";
			cout << "YOU: ";
			string response2;
			getline(cin, response2);

			ofstream out;
			out.open("responses.txt", std::ios::app);
			stringstream str;
			str << "\n"
				<< response  << "\n"
				<< response2;
			out << str.str().c_str();
			cout << "\n";
			out.close();
		}
	}

	return 0;
}
