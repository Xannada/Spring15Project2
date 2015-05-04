#include "Project 02.h"

stadium::stadium()
{
	stadiumList = NULL;
}

void stadium::addStadium(string sName,
						 string tName,
						 string a1,
						 string a2,
						 string tele,
						 string date,
						 string seats,
						 bool astroTurf,
						 bool national)
{
	stadiumNode *newVertex;

	newVertex = new stadiumNode;

	newVertex->stadiumName = sName;
	newVertex->teamName = tName;
	newVertex->address1 = a1;
	newVertex->address2 = a2;
	newVertex->phone = tele;
	newVertex->opening = date;
	newVertex->capacity = seats;
	newVertex->fieldType = astroTurf;
	newVertex->league = national;
	newVertex->next = NULL;

	// Checks to see if first in list
	if(stadiumList == NULL)
	{
		stadiumList = newVertex;
		newVertex->prev = NULL;
	}
	else
	{
		stadiumNode *tempVertex;

		tempVertex = stadiumList;

		while(tempVertex->next != NULL)
		{
			tempVertex = tempVertex->next;
		}

		tempVertex->next = newVertex;
		newVertex->prev = tempVertex;
	}
}

void stadium::getList()
{
	stadiumNode *newStadium;
	stadiumNode *tempNode;

	ifstream inFile;

	inFile.open("list.txt");

	newStadium = NULL;
	newStadium = new stadiumNode;

	while(inFile)
	{
		getline(inFile, newStadium->stadiumName);
		getline(inFile, newStadium->teamName);
		getline(inFile, newStadium->address1);
		getline(inFile, newStadium->address2);
		getline(inFile, newStadium->phone);
		getline(inFile, newStadium->opening);
		getline(inFile, newStadium->capacity);
		inFile >> newStadium->fieldType;
		inFile >> newStadium->league;

		inFile.ignore(1000, '\n');

		newStadium->next = NULL;

		if(stadiumList == NULL)
		{
			stadiumList = newStadium;
			newStadium->prev = NULL;
		}
		else
		{
			tempNode = stadiumList;

			while(tempNode->next != NULL)
			{
				tempNode = tempNode->next;
			}

			tempNode->next = newStadium;
			newStadium->prev = tempNode;
		}

		newStadium = new stadiumNode;
	}

	delete newStadium;

	inFile.close();
}

void stadium::alphaLeague()
{
	stadiumNode *tempStadium;

	tempStadium = stadiumList;

	cout << "All stadiums output alphabetically by name:\n\n";
	while(tempStadium->next != NULL)
	{
		cout << "STADIUM NAME: " << "\t\t"
			 << tempStadium->stadiumName << endl;

		cout << "ADDRESS: " << "\t\t"
			 << tempStadium->address1 << ", "
			 << tempStadium->address2 << endl;

		cout << "PHONE: " << "\t\t\t"
			 << tempStadium->phone << endl;

		cout << "DATE CONSTRUCTED: " << "\t"
			 << tempStadium->opening << endl;

		cout << "SEATING CAPACITY: " << "\t"
			 << tempStadium->capacity << endl;

		cout << "FIELD TYPE: " << "\t\t"
			 << (tempStadium->fieldType == false ? "Grass" : "Astroturf" )
			 << endl;

		cout << "TEAM: " << "\t\t\t"
			 << tempStadium->teamName << endl;

		cout << "LEAGUE: " << "\t\t"
			 << (tempStadium == false ? "American" : "National")
			 << endl << endl;

		tempStadium = tempStadium->next;
	}
}

void stadium::alphaStadium()
{
	bTree outputTree;

	stadiumNode *tempList = stadiumList;

	while(tempList->next != NULL)
	{
		outputTree.insertStadium(tempList);
		tempList = tempList->next;
	}

	cout << "All stadiums output alphabetically by name:\n\n";
	outputTree.inorder();
}

void stadium::setStadiumName(string compare,
							 string sName)
{
	comparison(compare)->stadiumName = sName;
}

void stadium::setTeamName(string compare,
						  string tName)
{
	comparison(compare)->teamName = tName;
}

void stadium::setAddress1(string compare,
						  string a1)
{
	comparison(compare)->address1 = a1;
}

void stadium::setAddress2(string compare,
						  string a2)
{
	comparison(compare)->address2 = a2;
}

void stadium::setPhone(string compare,
					   string tele)
{
	comparison(compare)->phone = tele;
}

void stadium::setOpening(string compare,
						 string date)
{
	comparison(compare)->opening = date;
}

void stadium::setCapacity(string compare,
						  string seats)
{
	comparison(compare)->capacity = seats;
}

void stadium::setFieldType(string compare,
						   bool astroTurf)
{
	comparison(compare)->fieldType = astroTurf;
}

void stadium::setLeague(string compare,
						bool national)
{
	comparison(compare)->league = national;
}

string stadium::getStadiumName(string compare)
{
	return comparison(compare)->stadiumName;
}

string stadium::getTeamName(string compare)
{
	return comparison(compare)->teamName;
}

string stadium::getAddress1(string compare)
{
	return comparison(compare)->address1;
}

string stadium::getAddress2(string compare)
{
	return comparison(compare)->address2;
}

string stadium::getPhone(string compare)
{
	return comparison(compare)->phone;
}

string stadium::getOpening(string compare)
{
	return comparison(compare)->opening;
}

string stadium::getCapacity(string compare)
{
	return comparison(compare)->capacity;
}

bool stadium::getFieldType(string compare)
{
	return comparison(compare)->fieldType;
}

bool stadium::getLeague(string compare)
{
	return comparison(compare)->league;
}
