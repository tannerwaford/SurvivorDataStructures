### Surviving Survivor
Hello! This is a project that allows the user to view how age and gender can affect a Survivor player's placement. This is done through the use of data structures, csv file access, and user input.
Data Structures used:
- BST
- Array Unsorted List
- Circular Linked Queue

The 'main' code creates a BST where each of the nodes contains an Array Unsorted List and an integer value named "placement". This "placement" variable determines the position of the nodes in the BST.
The nodes are added to the BST in a way that makes the tree balanced so that searching through the BST for different Unsorted Array Lists has a time complexity of binary search time.
Each Array Unsorted List contains information from the csv file (the dataset) which has information about the players including their season(s), placement(s), age, and gender.
The user decides which placement group they want to search through. For example, they can look through all of the players that got 3rd place or maybe even 11th place.
Then, they pick which factor they want to consider which are "gender" or age". They can choose to either filter the data by male or female or they can filter it by providing an age range.
You can go ahead and play around with the code to see what insights you can draw!
