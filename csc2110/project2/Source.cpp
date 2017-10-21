//Programmed by: Adrian Ionascu
//CSC 21110 Part 2 Project 2

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

class ExceptionRange{
public:
	ExceptionRange(std::string str){ message = str; };
	std::string outputError(){return message;};
private:
	std::string message;
}; 
class ExceptionInput{
public:
	ExceptionInput(std::string str){ message = str; };
	std::string outputError(){ return message; };
private:
	std::string message;
};
class ExceptionSell{
public:
	ExceptionSell(std::string str){ message = str; };
	std::string outputError() { return message; };
private:
	std::string message;
};
ExceptionRange range("Input is out of range.");
ExceptionRange neg("Number can't be negatives.");
ExceptionInput input("Input is not valid.");
ExceptionSell sell("You cannot sell more than what is in the store.");

struct store{
	std::vector<int> itemID;
	std::vector<std::string> itemName;
	std::vector<int> pOrdered;
	std::vector<int> pInStore;
	std::vector<int> pSold;
	std::vector<double> menufPrice;
	std::vector<double> sellingPrice;
}; 
store store1;

template <typename T> void swap(std::vector<T> &list, int place){
	T temp = list[place];
	list[place] = list[place - 1];
	list[place - 1] = temp;
}
//function is used when sorting to swap the needed elements of any vector
template <typename T> int search(std::vector<T> &list, T find){	

	for (int i = 0; i < list.size(); i++){
		if (find == store1.itemID[i]){
			return i;
			break;
		}
		if (i == (store1.itemID.size() - 1)){
			return -1;
		}
	}
}		
//function to search for a specific item by itemID or itemName
template <typename T> T editItem_check(std::string message){
	T var;
	if (typeid(T) == typeid(std::string)){
		while (true){
			try{
				std::cout << message;
				if (!(std::cin >> var))
					throw input;
				else
					break;
			}
			catch (ExceptionInput input){
				std::cout << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << input.outputError() << std::endl;
			}
		}
	}
	else{
		while (true){
			try{
				std::cout << message;
				if (!(std::cin >> var))
					throw input;
				else if (var < 0)
					throw neg;
				else
					break;
			}
			catch (ExceptionRange neg){
				std::cout << std::endl;
				std::cout << neg.outputError() << std::endl;
			}
			catch (ExceptionInput input){
				std::cout << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << input.outputError() << std::endl;
			}
		}
	}

	return var;
}
//function to ask for proper input based in needed return


double newInputCheck(std::string message){
	double var;
	
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (true){
		try{
			std::cout << message;
			if (!(std::cin >> var))
				throw input;
			else if (var < 0)
				throw neg;
			else
				break;
		}
		catch (ExceptionRange neg){
			std::cout << std::endl;
			std::cout << neg.outputError() << std::endl;
		}
		catch (ExceptionInput input){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << input.outputError() << std::endl;
		}
	}

	return var;
}

void menu();	//displays menu and calls appropriate functions according to user input
void checkItem();	//checks how many of an item are still in a store
void inputData();	//used to read data from text file and implements them into the appropriate vectors
void sort();	//function that sorts all arrays by itemName
void sellItem();	//function used when selling an item
int maxLength(std::vector<std::string> list);	//find the string with largest length in the itemName vector for output purposes
void printReport();	//prints report of all items in store and needed information to an output text file
void addNewItem();	//adds new item for inventory
double newInputCheck(std::string message); // checks input for bad inputs

void main(){
	inputData();
	sort();
	menu();

}

void sort(){	//sorts by product name
	int j;

	for (int i = 0; i < store1.itemName.size(); i++){
		j = i;
		while (j > 0 && store1.itemName[j] < store1.itemName[j - 1]){
			swap(store1.itemID, j);
			swap(store1.itemName, j);
			swap(store1.pOrdered, j);
			swap(store1.pInStore, j);
			swap(store1.pSold, j);
			swap(store1.menufPrice, j);
			swap(store1.sellingPrice, j);
			j--;
		}
	}
}

void inputData(){
	std::ifstream doc;
	doc.open("task2StoreData.txt");

	int itemID_file, pOrdered_file, pInStore_file, pSold_file;
	double menufPrice_file, sellingPrice_file;
	std::string itemName_file;

	while(!(doc.eof())){
		doc >> itemID_file;
		doc.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//grab itemID and skip to next line

		getline(doc, itemName_file);	//grab item name and skip to next line

		doc >> pOrdered_file;
		doc >> menufPrice_file;
		doc >> sellingPrice_file;	//grab the rest of info for products

		store1.itemID.push_back(itemID_file);	//appropriately push vectors back to make space for new information about product
		store1.itemName.push_back(itemName_file);
		store1.pOrdered.push_back(pOrdered_file);
		store1.menufPrice.push_back(menufPrice_file);
		store1.sellingPrice.push_back(sellingPrice_file);
		store1.pSold.push_back(0);
		store1.pInStore.push_back(pOrdered_file);
	}
}

void menu(){
	int choice;
	std::cout << "Hardware store INC." << std::endl;
	std::cout << "1. Check if an item is in store." << std::endl;
	std::cout << "2. Sell an item." << std::endl;
	std::cout << "3. Print report." << std::endl;
	std::cout << "4. Input new item." << std::endl;
	std::cout << "5. Edit item info." << std::endl;
	std::cout << "0. Exit" << std::endl;

	while (true){
		try{
			std::cout << "Please choose function: ";
			if (!(std::cin >> choice))
				throw input;
			else if ((choice < 0) || (choice > 5))
				throw range;
			else break;
		}
		catch (ExceptionRange range){
			std::cout << std::endl;
			std::cout << range.outputError() << std::endl;
		}
		catch (ExceptionInput input){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << input.outputError() << std::endl;
		}
	}

	switch (choice){
	case 1: checkItem();
		menu();
		break;
	case 2: sellItem();
		menu();
		break;
	case 3:	sort();
		printReport();
		menu();
		break;
	case 4:addNewItem();
		menu();
		break;
	case 5: // edit item info
		menu();
		break;
	case 0:
		break;
	}
}

void checkItem(){
	int itemfind;
	std::cout << std::endl;

	while (true){
		try{
			std::cout << "Please enter itemID: ";
			if (!(std::cin >> itemfind))
				throw input;
			else
				break;
		}
		catch (ExceptionInput input){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << input.outputError() << std::endl;
		}
	}

	int found = search(store1.itemID, itemfind);
	if ( found == -1){
		std::cout << "ItemID not found." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Amount in store: " << store1.pInStore[found] << std::endl;
		std::cout << std::endl;
	}

}

void sellItem(){
	int item, selling, found;
	while (true){
		try{
			std::cout << "Please enter itemID: ";
			if (!(std::cin >> item))
				throw input;
			else{
				found = search(store1.itemID, item);
				if (found == -1){
					std::cout << "Item not found." << std::endl;
					std::cout << std::endl;
					exit(NULL);
				}
				else
					break;
			}

		}
		catch (ExceptionInput input){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << input.outputError() << std::endl;
		}
	}



	while (true){
		try{
			std::cout << "Please enter amount you want to sell: ";
			if (!(std::cin >> selling))
				throw input;
			else if (selling < 0)
				throw range;
			else if (selling > store1.pInStore[found])
				throw sell;
			else
				break;
		}
		catch (ExceptionInput input){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << input.outputError() << std::endl;
		}
		catch (ExceptionRange range){
			std::cout << std::endl;
			std::cout << range.outputError() << std::endl;
		}
		catch (ExceptionSell sell){
			std::cout << std::endl;
			std::cout << sell.outputError() << std::endl;
		}
	}
	store1.pInStore[found] -= selling;
	store1.pSold[found] += selling;

	std::cout << "Info has been updated. " << store1.itemName[found] << " has sold " << store1.pSold[found] << " units." << std::endl;
	std::cout << "There are currently " << store1.pInStore[found] << " units in the store." << std::endl;
	std::cout << std::endl;

}

void printReport(){
	std::ofstream output;
	output.open("hardwareStoreOutput.txt");
	output << "itemID" << " ";
	output << std::setw(maxLength(store1.itemName))<< std::left << "itemName"; output << " " << "pOrdered" << " " << "pInStore" << " " << "pSold" << " " << "menufPrice" << " " << "sellingPrice" << std::endl;

	for (int i = 0; i < store1.itemID.size(); i++){
		output << store1.itemID[i] << "   ";
		output << std::setw(maxLength(store1.itemName)) << std::left << store1.itemName[i];
		output << " " << std::setw(8) << std::right << store1.pOrdered[i];
		output << " " << std::setw(8) << std::right << store1.pInStore[i];
		output << " " << std::setw(5) << std::right << store1.pSold[i];
		output << " " << std::setw(10) << std::fixed << std::setprecision(2)<< std::right << store1.menufPrice[i];
		output << " " << std::setw(12) << std::fixed<< std::setprecision(2)<< std::right << store1.sellingPrice[i] << std::endl;
	}

	output << std::endl;
	double invCost = 0; int numOfItems = 0;
	for (int i = 0; i < store1.itemID.size(); i++){
		invCost += (store1.sellingPrice[i] * store1.pInStore[i]);
		numOfItems += store1.pInStore[i];
	}

	output << "Total Inventory: $" << std::fixed << std::setprecision(2) << invCost << std::endl;
	output << "Total number of items in the store: " << numOfItems << std::endl;
	output.close();
	std::cout << "Report Printed to \"hardwareStoreOutput.txt\"" << std::endl;
}

int maxLength(std::vector<std::string> list){
	int max = 0;
	for (int i = 0; i < list.size(); i++){
		if (list[i].length() > max)
			max = list[i].length();
	}
	return max;
}

void addNewItem(){	
	std::string itemName_new;
	int itemID_new, pOrdered_new, pInStore_new, pSold_new;
	double menufPrice_new, sellingPrice_new;

	std::cout << "Please enter the item name: ";	//doesnt save name of new item for some reason
	getline(std::cin, itemName_new);

	store1.itemName.push_back(itemName_new);

	itemID_new = newInputCheck("Please input itemID(must be all numeric digits): ");
	pOrdered_new = newInputCheck("Please input amount of item ordered: ");
	pInStore_new = newInputCheck("Please input amount of item in store: ");
	pSold_new = newInputCheck("Please input amount sold of new item: ");
	menufPrice_new = newInputCheck("Please input price of manufacturing the item: ");
	sellingPrice_new = newInputCheck("Please input selling price of the item: ");

	store1.itemID.push_back(itemID_new);
	store1.pOrdered.push_back(pOrdered_new);
	store1.pInStore.push_back(pInStore_new);
	store1.pSold.push_back(pSold_new);
	store1.menufPrice.push_back(menufPrice_new);
	store1.sellingPrice.push_back(sellingPrice_new);
	
	std::cout << "New Item has been added" << std::endl;
	std::cout << std::endl;
}

void editItem(){
	std::cout << std::endl;
	int edit_itemID;
	int choice;

	edit_itemID = newInputCheck("Please input itemID: ");

	int found = search(store1.itemID, edit_itemID);
	if (found == -1){
		std::cout << "ItemID not found." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "1. itemID" << std::endl;
		std::cout << "2. itemName" << std::endl;
		std::cout << "3. pOrdered" << std::endl;
		std::cout << "4. pInStore" << std::endl;
		std::cout << "5. pSold" << std::endl;
		std::cout << "6. menufPrice" << std::endl;
		std::cout << "7. sellingPrice" << std::endl;
		std::cout << std::endl;
		std::cout << "Choose the value you want to edit: ";
		std::cin >> choice;

		switch (choice){
		case 1:int new_itemID;
			std::string ask;
			new_itemID = editItem_check(ask);
		}
	}
}

