#define MAXSIZE 1000
#include <string>
struct Survivor_Contestants {
	std::string contestant;
	int age;
	int season_number;
	int placement;
	std::string gender;
	int poc;  	
};

class AUList
{
public:
  
  AUList(); // Constructor
  
  void MakeEmpty();  // Returns the list to the empty state.
    
  bool IsFull() const; //Determines whether list is full. (Precondition -- list has been initialized).  Return value of "True" indicates class is full.
  
  int GetLength() const; //Determines the number of elements in list.

  void PutItem(Survivor_Contestants); //Adds the item to the list.
    
  void ResetList();  //Initializes iterator's current position for an iteration through the list.

  Survivor_Contestants GetNextItem(); //Gets the next element in the list.

  bool HasNextItem();
  
  void PrintList(int placement, int decision, int min_age, int max_age, std::string gender);  //Print all elements of the list in a readable format.
  
  AUList PlayersByPlacement(int placement, int decision, int min_age, int max_age, std::string gender);

private:
  int length;
  Survivor_Contestants ListItems[MAXSIZE];
  int currentPos;
};

