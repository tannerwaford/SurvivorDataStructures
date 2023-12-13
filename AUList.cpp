// Implementation file for AUList
#include <iostream>
#include <stdexcept>
#include "AUList.h"
#include <string>

//Many AUList Operations are unaffected!
AUList::AUList() {
  length = 0; 
}
bool AUList::IsFull() const {
  return (length == MAXSIZE); 
}
int AUList::GetLength() const {
  return length;
}

void AUList::MakeEmpty() {
  length = 0; //as with the constructor, we need do nothing to the actual array, as it now "junk" data
}
void AUList::PutItem(Survivor_Contestants item) { //This function assumes the "IsFull" condition hasn't been met.
  ListItems[length] = item; //Remember that C++ uses 0-indexing.
  length++;
}

void AUList::ResetList() {
  currentPos = -1; //We want the position BEFORE the first element, since incrementation in GetNextItems happens first
}

bool AUList::HasNextItem() {
  return currentPos<(length-1);
}

Survivor_Contestants AUList::GetNextItem() {
  currentPos++; //Remember that currentPos is a class member variable
  return ListItems[currentPos];
}

void AUList::PrintList(int placement, int decision, int min_age, int max_age, std::string gender) { //simple function to print a list's items in stored order
  if(decision==0){
  	for (int loc=0; loc<length; loc++) {
  	Survivor_Contestants curitem=ListItems[loc];
	std::cout<< "Rec " << loc << ": " <<curitem.contestant<<", "<<curitem.age<<", "
	<<curitem.season_number<<", "<<curitem.placement<<", "<<curitem.gender<<", "<<curitem.poc<<std::endl;
  }	
  }
  if (decision==1){
  	for (int loc=0; loc<length; loc++) {
  	Survivor_Contestants curitem=ListItems[loc];
	if(curitem.age >= min_age && curitem.age <= max_age)
	std::cout<< "Rec " << loc << ": " <<curitem.contestant<<", "<<curitem.age<<", "
	<<curitem.season_number<<", "<<curitem.placement<<", "<<curitem.gender<<", "<<curitem.poc<<std::endl;
  }	
  }
  if(decision == 2){
  	for (int loc=0; loc<length; loc++) {
  	Survivor_Contestants curitem=ListItems[loc];
  	if(curitem.gender == gender){
  		std::cout<< "Rec " << loc << ": " <<curitem.contestant<<", "<<curitem.age<<", "
	<<curitem.season_number<<", "<<curitem.placement<<", "<<curitem.gender<<", "<<curitem.poc<<std::endl;
	  }
	
  }	
  }
  
}

AUList AUList::PlayersByPlacement(int placement, int decision, int min_age, int max_age, std::string gender){
	AUList Players;
	if(decision == 0){
		for (int loc=0; loc<length; loc++){
		Survivor_Contestants curitem = ListItems[loc];
		if(curitem.placement==placement){
			Players.PutItem(curitem);
		}
	}
}
	return Players;
}
