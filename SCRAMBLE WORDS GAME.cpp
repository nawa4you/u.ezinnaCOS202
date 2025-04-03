#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <sstream>
#include <vector>
using namespace std;
//i used online resources to find out bool can be used to validate login, others are straight from prev work.
bool login() {
	

string usernames[5] = {"daniel", "ezinna", "desmond", "david", ""/* this empty gap was used as a back door for quick test*/};

string password[5] = {"1234", "abcd", "qwerty", "uiop", ""};



		while (true) {
		cout << "Input username:";
		string name_input;
		getline(cin, name_input);
		for (int i = 0; i < 5 ; i++)
		{
			if (name_input == usernames[i])	
			{
				
				
				cout << "Input password:";
				string user_pas;
				getline(cin, user_pas);
				

				if (user_pas == password[i])
				{
					
					cout << "Welcome " << usernames[i] << "!!!!\n";
					return true;
					
				
				}

				else {
				}

			}
			}
			cout << "Wrong login details.\n";
		}
			return false;
		}


string scramble(const string& text) {
	string chars = text;
	for (int i = 0; i < chars.length(); i++)
	{
		int y = rand();
//		cout << y << endl;
		int j = y % chars.length();
		char temp = chars[i];
		chars [i] = chars[j];
		chars[j] = temp;
	} return chars;
}


	string ask_questions(const string *questions, const int* score, const int* hint, const int *i) {
	
			if (*i == 9) {
			cout << "\n\n\t\tTHIS IS THE LAST WORD\n\n\n";
		}
	string ans;
	cout<< "\t\t\t\t\t\t\tSCORE: "<< *score <<"/10\n\t\t\t\tHOTKEYS\n\t\t\t\tH for Get correct letter (YOU HAVE "<< *hint 
		<<" HINTS REMAINING)\n\t\t\t\tN for next question(SCORE FOR THIS QUESTION WILL BE 0)\n\n\n"<<*i +1<<")\nWord:\n\n"<<*questions<< endl;
	getline(cin, ans);
	return ans; 

}

int main() {
		
	string *user_ans;
	user_ans = new string [10];
	//ask user to enter
	string start;
	cout << "\t\t\t\t--------------------------------------------------------------"<< endl;
	cout << "\t\t\t\t--------COMMUNITY SERVICE ENGLISH DEVELOPMENT PROGRAM---------"<< endl;
	cout << "\t\t\t\t------------------CREATED BY DANIEL EZINNA--------------------"<< endl;
	cout << "\t\t\t\t--------------------------------------------------------------"<< endl;

		//enter the game
	while( true ) {
	cout << "\n\nStart Application? (y/n)";
	getline(cin,start);
	if (start == "n" or start == "N")	
	{
		cout << "Alright. Thanks for using our app!";
		return 0;
	} else if (start == "y" or start == "Y")
	{
		system("cls");
		cout << "Lets proceed!\n\n\n";
		break;
	}	else {
	}
		cout << "Please enter a valid input y or n" << endl;
}
	//continued for login, not necessarry cuz to continue to main, the infinite loop HAS to be right.... but still had to add for fun hehe
	if (!login()) {
		
	}
	
	
	string word[10] = {"apple", "pineapple", "marble", "keyboard", "android", "trashbin", "duvet", "dubai", "hotel", "lightbulb" };
	

									//ai
	random_device rd;
    mt19937 g(rd());
    vector<string> arrangement(word, word + 10); // Initialize with the contents of word
    shuffle(arrangement.begin(), arrangement.end(), g);
    //ai end (could have used the swap with a random modulus but this is more efficient and easy to understand)
    
    vector<string> scrambled_words(10); // Store scrambled words separately
    for (int i = 0; i < 10; ++i) {
        scrambled_words[i] = scramble(arrangement[i]); // Scramble once and store
    }

	
	string hint_phrase;
	//hint phrase
	
	
	int hint = 5;
	int score = 0;
	int index = 0;
	
for (int i = 0; i < 10; i++)
{
	//hint phrase define
{
	if (arrangement[i] == "apple")
	{
		hint_phrase = "red fruit";
	}
	else if (arrangement[i] == "pineapple") {
		hint_phrase = "fruit with yellow inside";
	}
	else if (arrangement[i] == "marble") {
		hint_phrase = "(i honestly dont know what to hint this)";
	}
	else if (arrangement[i] == "keyboard") {
		hint_phrase = "look down";
	}
	else if (arrangement[i] == "android") {
		hint_phrase = "iphones opp";
	}
	else if (arrangement[i] == "trashbin") {
		hint_phrase = "do not litter";
	}
	else if (arrangement[i] == "duvet") {
		hint_phrase = "cover yourself on bed";
	}
	else if (arrangement[i] == "dubai") {
		hint_phrase = "arab nation";
	}
	else if (arrangement[i] == "hotel") {
		hint_phrase = "sheraton four point";
	}
	else if (arrangement[i] == "lightbulb") {
		hint_phrase = "a bright idea!!";
	}
}
//scramble the word


//    string scrambled = scramble(arrangement[i]); //when this is used, it gets re shuffled after use of h but creating a vector for shuffled better.
    user_ans[i] = ask_questions(&scrambled_words[i], &score, &hint, &i);




    	if (user_ans[i] == "h" or user_ans[i] == "H") {
			if (hint != 0) {
//	
		

				hint--;
				cout << "letters from 1 to " << index + 1  << " Has been corrected\n";
				cout << arrangement[i].substr(0,index + 1) << endl; //substring to slice the string( online resource)
				cout << "Hint: " << hint_phrase << endl;
				i--;
				index++;
			 
				
			} else {
				cout << "You have used up all your hint";
				index = 0;
				i--;
			}
		}
		else if (user_ans[i] == arrangement[i]) { 
			score = score +1 ;
			hint = hint+1;
			index = 0;
            system("cls");
            cout << "Correct!\nYou spelt the word correctly" << endl;

			}
		else if (user_ans[i] == "n" or user_ans[i] == "N" ){
			while (true){
				string proceed;
				cout << "Proceeding to next question marks this question as wrong (Score will be 0)\nAre you sure you want to proceed?(y/n)";
				getline(cin, proceed);
				if(proceed == "y" or proceed == "Y") {
					system("cls"); 
					cout << "The correct word was " << arrangement[i] <<"\nScore for question no" << i + 1 <<" is zero"<<endl;
					cout << "\nYour next Question\n";
					index = 0;
					break;
				}
				else if (proceed == "n" or proceed == "N") {
					i--;
					break;
				}
				else {
					cout << "Invalid Input\n";
				}
			}
		}
		
		
		else {
			cout << "Incorrect spelling\n";
			i-2;
		}
		}
		cout << "You Have finished.\nScore: "<< score << endl;
		 std::string message = "MADE BY UDOCHUKWU EZINNA 200LVL";
    	string title = "Udochukwu's code..."; // Ai to learn more on system programming
    	string command = "powershell -Command \"Add-Type -AssemblyName System.Windows.Forms; [System.Windows.Forms.MessageBox]::Show('" + message + "','" + title + "')\"";
    	system(command.c_str());
delete[] user_ans; 
	return 0;
}
































	         
