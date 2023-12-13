#include "BST.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

AUList csvtoAUList(string csvfile) { //convert a csv file to a list structure
    AUList retCCList;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        Survivor_Contestants newrec;
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.contestant = curvalue; break;
            	case 1: newrec.age = stoi(curvalue); break;
            	case 2: newrec.season_number = stoi(curvalue); break;
            	case 3: newrec.placement = stoi(curvalue); break;
            	case 4: newrec.gender = curvalue; break;
            	case 5: newrec.poc = stoi(curvalue); break;
			}
            fielditer++;
        }
        retCCList.PutItem(newrec);
    }
    return retCCList;
}

int main(int argc, char** argv) {
	AUList Survivors=csvtoAUList("contestant_table.csv");
		
	// Add each AUList at each node in the BST
	BST myBST;
	AUList Placeholder = Survivors.PlayersByPlacement(10, 0, 0, 0, "N");
	myBST.PutItem(10, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(5, 0, 0, 0, "N");	
	myBST.PutItem(5, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(2, 0, 0, 0, "N");
	myBST.PutItem(2, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(1, 0, 0, 0, "N");
	myBST.PutItem(1, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(3, 0, 0, 0, "N");
	myBST.PutItem(3, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(4, 0, 0, 0, "N");
	myBST.PutItem(4, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(7, 0, 0, 0, "N");
	myBST.PutItem(7, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(6, 0, 0, 0, "N");
	myBST.PutItem(6, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(8, 0, 0, 0, "N");
	myBST.PutItem(8, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(9, 0, 0, 0, "N");
	myBST.PutItem(9, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(15, 0, 0, 0, "N");
	myBST.PutItem(15, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(12, 0, 0, 0, "N");
	myBST.PutItem(12, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(11, 0, 0, 0, "N");
	myBST.PutItem(11, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(13, 0, 0, 0, "N");
	myBST.PutItem(13, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(14, 0, 0, 0, "N");
	myBST.PutItem(14, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(18, 0, 0, 0, "N");
	myBST.PutItem(18, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(16, 0, 0, 0, "N");
	myBST.PutItem(16, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(17, 0, 0, 0, "N");
	myBST.PutItem(17, Placeholder);
	Placeholder.MakeEmpty();
	Placeholder = Survivors.PlayersByPlacement(19, 0, 0, 0, "N");
	myBST.PutItem(19, Placeholder);
	Placeholder.MakeEmpty();
	myBST.ResetTree(IN_ORDER);
	myBST.PrintTree();
	// User Input to Search through BST
	myBST.ResetTree(IN_ORDER);
	cout << endl;
	cout << endl;
	cout << "Welcome! This is a dataset about Survivor players that contains information about each player's season(s), placement(s), age, gender, and whether or not they are a person of color. "
	<< "We will use this data to make comparisons between a player's gender/age and the placement that they got.";
	cout << endl;
	cout << endl;
	std::string input_gender;
	int input_placement;
	int input_min_age;
	int input_max_age;
	int decision;
	while(true){
		Placeholder.MakeEmpty();
		cout << "What placement would you like to search through? (This is a number between 1-19 and will contain all of the players that received that placement. Enter 0 to quit): ";
		cin >> input_placement;
		cout << endl;
		if(input_placement == 0){
			break;
		}
		Placeholder = myBST.GetItem(input_placement);
		Placeholder.PrintList(input_placement, 0, 0, 0, "N");
		cout << endl;
		cout << endl;
		cout << "This is the group of contestants that got this placement! Now would you like to filter this group by age (enter 1) or gender (enter 2): ";
		cin >> decision;
		if(decision == 1){
			cout << "Enter minimum age you want to search for: ";
			cin >> input_min_age;
			cout << endl;
			cout << "Enter maximum age you want to search for: ";
			cin >> input_max_age;
			Placeholder.PrintList(input_placement, decision, input_min_age, input_max_age, "N");
			cout << endl << endl;
		} else if(decision == 2){
			cout << "Enter M to filter for males and F to filter for females: ";
			cin >> input_gender;
			Placeholder.PrintList(input_placement, decision, 0, 0, input_gender);
			cout << endl;
			cout << endl;
		
		}
	}
	cout << endl << endl << "I hope you found some interesting insights here! Feel free to try again if you want to look through and make some more observations!" << endl << endl;
}
