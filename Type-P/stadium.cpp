//#include "MainHeader.h"

//// Sets stuct to null
//stadium::stadium()
//{
//	stadiumList = NULL;
//}

//void stadium::test()
//{
//	cout << stadiumList->next->next->next->next->next->next->next
//			->next->next->next->next->next->next->next->next->next
//			->next->next->next->next->next->next->next->next->next
//			->next->next->next->next->next->stadiumName << endl;
//}
//// Manually adds a stadium in
//void stadium::addStadium(string sName,
//						 string tName,
//						 string a1,
//						 string a2,
//						 string tele,
//						 string date,
//						 string seats,
//						 bool   astroTurf,
//						 bool   national)
//{
//	stadiumNode *newVertex;
//	stadiumNode *tempVertex;

//	// Gets memory
//	newVertex = new stadiumNode;
//	tempVertex = stadiumList;

//	// Populates values
//	newVertex->stadiumName = sName;
//	newVertex->teamName = tName;
//	newVertex->address1 = a1;
//	newVertex->address2 = a2;
//	newVertex->phone = tele;
//	newVertex->opening = date;
//	newVertex->capacity = seats;
//	newVertex->fieldType = astroTurf;
//	newVertex->league = national;
//	newVertex->next = NULL;

//	if(stadiumList == NULL)
//	{
//		stadiumList = newVertex;
//	}
//	else
//	{
//		while(tempVertex->next->next != NULL)
//		{
//			tempVertex = tempVertex->next;
//		}

//		delete tempVertex->next->next;
//		delete tempVertex->next;

//		tempVertex->next = NULL;

//		cout << "FINALTEST: " << tempVertex->teamName << endl;
//		tempVertex->next = newVertex;
//	}
//}

//// Reads the list of stadiums from the input file
//void stadium::readList()
//{
//	stadiumNode *newStadium;
//	stadiumNode *tempNode;

//	ifstream inFile;

//	// The actual file we're reading from
//    inFile.open("list.txt");

//	newStadium = new stadiumNode;

//	// Goes until the end of the file
//	while(inFile)
//	{
//		getline(inFile, newStadium->stadiumName);
//		getline(inFile, newStadium->teamName);
//		getline(inFile, newStadium->address1);
//		getline(inFile, newStadium->address2);
//		getline(inFile, newStadium->phone);
//		getline(inFile, newStadium->opening);
//		getline(inFile, newStadium->capacity);
//		inFile >> newStadium->league;
//		inFile >> newStadium->fieldType;

//		inFile.ignore(1000, '\n');

//		newStadium->next = NULL;

//		// If the first node
//		if(stadiumList == NULL)
//		{
//			stadiumList = newStadium;
//		}
//		// Every other node
//		else
//		{
//			tempNode = stadiumList;

//			while(tempNode->next != NULL)
//			{
//				tempNode = tempNode->next;
//			}

//			tempNode->next = newStadium;
//		}

//		newStadium = new stadiumNode;
//	}

//	delete newStadium;

//	inFile.close();
//}

//// Writes the list of stadiums to file
//void stadium::writeList()
//{
//	stadiumNode *tempNode;

//	ofstream outFile;

//	tempNode = stadiumList;
//    outFile.open("list.txt");

//	while(tempNode->next != NULL)
//	{
//		outFile << tempNode->stadiumName << endl;
//		outFile << tempNode->teamName << endl;
//		outFile << tempNode->address1 << endl;
//		outFile << tempNode->address2 << endl;
//		outFile << tempNode->phone << endl;
//		outFile << tempNode->opening << endl;
//		outFile << tempNode->capacity << endl;
//		outFile << tempNode->league << endl;
//		outFile << tempNode->fieldType << endl;

//		tempNode = tempNode->next;
//	}

//	outFile.close();
//}

//void stadium::alphaLeague()
//{
//	priority_queue<teamCompare> sortingQueue;
//	deque<teamCompare> national;
//	deque<teamCompare> american;
//	teamCompare tempNode;

//	stadiumNode *temp;

//	temp = stadiumList;

//	// Inserts stadiums from list into a priority queue for sorting
//	while(temp->next != NULL)
//	{
//		tempNode.address1 = temp->address1;
//		tempNode.address2 = temp->address2;
//		tempNode.capacity = temp->capacity;
//		tempNode.fieldType = temp->fieldType;
//		tempNode.league = temp->league;
//		tempNode.opening = temp->opening;
//		tempNode.phone = temp->phone;
//		tempNode.stadiumName = temp->stadiumName;
//		tempNode.teamName = temp->teamName;
//		sortingQueue.push(tempNode);

//		temp = temp->next;
//	}

//	// Puts the priority queue into a deque so I can pop the front
//	// during output
//	while(!sortingQueue.empty())
//	{
//		if(sortingQueue.top().league == 0)
//		{
//			american.push_back(sortingQueue.top());
//		}
//		else
//		{
//			national.push_back(sortingQueue.top());
//		}
//		sortingQueue.pop();
//	}


//	// Outputs elements FIFO
//	cout << "All teams output alphabetically by league:\n";
//	cout << "American League\n\n";
//	while(!american.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << american.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << american.front().address1 << ", "
//			 << american.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << american.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << american.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << american.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (american.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << american.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (american.front().league == false ? "American" : "National")
//			 << endl << endl;

//		american.pop_front();
//	}

//	cout << "\nNational League\n\n";
//	while(!national.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << national.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << national.front().address1 << ", "
//			 << national.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << national.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << national.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << national.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (national.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << national.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (national.front().league == false ? "American" : "National")
//			 << endl << endl;

//		national.pop_front();
//	}
//}

//void stadium::alphaStadium()
//{
//	priority_queue<stadiumCompare> sortingQueue;
//	deque<stadiumCompare> output;
//	stadiumCompare tempNode;

//	stadiumNode *temp;

//	temp = stadiumList;

//	// Inserts stadiums from list into a priority queue for sorting
//	while(temp->next != NULL)
//	{
//		tempNode.address1 = temp->address1;
//		tempNode.address2 = temp->address2;
//		tempNode.capacity = temp->capacity;
//		tempNode.fieldType = temp->fieldType;
//		tempNode.league = temp->league;
//		tempNode.opening = temp->opening;
//		tempNode.phone = temp->phone;
//		tempNode.stadiumName = temp->stadiumName;
//		tempNode.teamName = temp->teamName;
//		sortingQueue.push(tempNode);

//		temp = temp->next;
//	}

//	// For some bulshit reason the queue doesn't sort properly.
//	// Angel stadium always goes to the end of the list even though
//	// it should be first, so I put everything into a deque and push
//	// Angel stadium to the front
//	while(sortingQueue.size() != 1)
//	{
//		output.push_back(sortingQueue.top());
//		sortingQueue.pop();
//	}

//	output.push_front(sortingQueue.top());

//	// Outputs elements FIFO
//	cout << "All stadiums output alphabetically by name:\n\n";
//	while(!output.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << output.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << output.front().address1 << ", "
//			 << output.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << output.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << output.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << output.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (output.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << output.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (output.front().league == false ? "American" : "National")
//			 << endl << endl;

//		output.pop_front();
//	}
//}

//void stadium::alphaTeam()
//{
//	priority_queue<teamCompare> sortingQueue;
//	deque<teamCompare> output;
//	teamCompare tempNode;

//	stadiumNode *temp;

//	temp = stadiumList;

//	// Inserts stadiums from list into a priority queue for sorting
//	while(temp->next != NULL)
//	{
//		tempNode.address1 = temp->address1;
//		tempNode.address2 = temp->address2;
//		tempNode.capacity = temp->capacity;
//		tempNode.fieldType = temp->fieldType;
//		tempNode.league = temp->league;
//		tempNode.opening = temp->opening;
//		tempNode.phone = temp->phone;
//		tempNode.stadiumName = temp->stadiumName;
//		tempNode.teamName = temp->teamName;
//		sortingQueue.push(tempNode);

//		temp = temp->next;
//	}

//	// Puts the priority queue into a deque so I can pop the front
//	// during output
//	while(!sortingQueue.empty())
//	{
//		output.push_back(sortingQueue.top());
//		sortingQueue.pop();
//	}


//	// Outputs elements FIFO
//	cout << "All stadiums output alphabetically by team:\n\n";
//	while(!output.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << output.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << output.front().address1 << ", "
//			 << output.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << output.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << output.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << output.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (output.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << output.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (output.front().league == false ? "American" : "National")
//			 << endl << endl;

//		output.pop_front();
//	}
//}

//void stadium::opening()
//{
//	priority_queue<openingCompare> sortingQueue;
//	deque<openingCompare> output;
//	openingCompare tempNode;

//	stadiumNode *temp;

//	temp = stadiumList;

//	// Inserts stadiums from list into a priority queue for sorting
//	while(temp->next != NULL)
//	{
//		tempNode.address1 = temp->address1;
//		tempNode.address2 = temp->address2;
//		tempNode.capacity = temp->capacity;
//		tempNode.fieldType = temp->fieldType;
//		tempNode.league = temp->league;
//		tempNode.opening = temp->opening;
//		tempNode.phone = temp->phone;
//		tempNode.stadiumName = temp->stadiumName;
//		tempNode.teamName = temp->teamName;
//		sortingQueue.push(tempNode);

//		temp = temp->next;
//	}

//	// Puts the priority queue into a deque so I can pop the front
//	// during output
//	while(!sortingQueue.empty())
//	{
//		output.push_back(sortingQueue.top());
//		sortingQueue.pop();
//	}

//	// Outputs elements FIFO
//	cout << "All stadiums output by opening date:\n\n";
//	while(!output.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << output.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << output.front().address1 << ", "
//			 << output.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << output.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << output.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << output.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (output.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << output.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (output.front().league == false ? "American" : "National")
//			 << endl << endl;

//		output.pop_front();
//	}
//}

//void stadium::seating()
//{
//	priority_queue<seatingCompare> sortingQueue;
//	deque<seatingCompare> output;
//	seatingCompare tempNode;

//	stadiumNode *temp;

//	temp = stadiumList;

//	// Inserts stadiums from list into a priority queue for sorting
//	while(temp->next != NULL)
//	{
//		tempNode.address1 = temp->address1;
//		tempNode.address2 = temp->address2;
//		tempNode.capacity = temp->capacity;
//		tempNode.fieldType = temp->fieldType;
//		tempNode.league = temp->league;
//		tempNode.opening = temp->opening;
//		tempNode.phone = temp->phone;
//		tempNode.stadiumName = temp->stadiumName;
//		tempNode.teamName = temp->teamName;
//		sortingQueue.push(tempNode);

//		temp = temp->next;
//	}

//	// Puts the priority queue into a deque so I can pop the front
//	// during output
//	while(!sortingQueue.empty())
//	{
//		output.push_back(sortingQueue.top());
//		sortingQueue.pop();
//	}


//	// Outputs elements FIFO
//	cout << "All stadiums output by seating capacity:\n\n";
//	while(!output.empty())
//	{
//		cout << "STADIUM NAME: " << "\t\t"
//			 << output.front().stadiumName << endl;

//		cout << "ADDRESS: " << "\t\t"
//			 << output.front().address1 << ", "
//			 << output.front().address2 << endl;

//		cout << "PHONE: " << "\t\t\t"
//			 << output.front().phone << endl;

//		cout << "DATE CONSTRUCTED: " << "\t"
//			 << output.front().opening << endl;

//		cout << "SEATING CAPACITY: " << "\t"
//			 << output.front().capacity << endl;

//		cout << "FIELD TYPE: " << "\t\t"
//			 << (output.front().fieldType == false ? "Grass" : "Astroturf" )
//			 << endl;

//		cout << "TEAM: " << "\t\t\t"
//			 << output.front().teamName << endl;

//		cout << "LEAGUE: " << "\t\t"
//			 << (output.front().league == false ? "American" : "National")
//			 << endl << endl;

//		output.pop_front();
//	}
//}

//void stadium::setStadiumName(string compare,
//							 string sName)
//{
//	comparison(compare)->stadiumName = sName;
//}

//void stadium::setTeamName(string compare,
//						  string tName)
//{
//	comparison(compare)->teamName = tName;
//}

//void stadium::setAddress1(string compare,
//						  string a1)
//{
//	comparison(compare)->address1 = a1;
//}

//void stadium::setAddress2(string compare,
//						  string a2)
//{
//	comparison(compare)->address2 = a2;
//}

//void stadium::setPhone(string compare,
//					   string tele)
//{
//	comparison(compare)->phone = tele;
//}

//void stadium::setOpening(string compare,
//						 string date)
//{
//	comparison(compare)->opening = date;
//}

//void stadium::setCapacity(string compare,
//						  string seats)
//{
//	comparison(compare)->capacity = seats;
//}

//void stadium::setFieldType(string compare,
//						   bool astroTurf)
//{
//	comparison(compare)->fieldType = astroTurf;
//}

//void stadium::setLeague(string compare,
//						bool national)
//{
//	comparison(compare)->league = national;
//}

//string stadium::getStadiumName(string compare)
//{
//	return comparison(compare)->stadiumName;
//}

//string stadium::getTeamName(string compare)
//{
//	return comparison(compare)->teamName;
//}

//string stadium::getAddress1(string compare)
//{
//	return comparison(compare)->address1;
//}

//string stadium::getAddress2(string compare)
//{
//	return comparison(compare)->address2;
//}

//string stadium::getPhone(string compare)
//{
//	return comparison(compare)->phone;
//}

//string stadium::getOpening(string compare)
//{
//	return comparison(compare)->opening;
//}

//string stadium::getCapacity(string compare)
//{
//	return comparison(compare)->capacity;
//}

//bool stadium::getFieldType(string compare)
//{
//	return comparison(compare)->fieldType;
//}

//bool stadium::getLeague(string compare)
//{
//	return comparison(compare)->league;
//}

//void stadium::Dijkstra()
//{
//	vector<Vertex*> vertices;

//	Vertex* Safeco = new Vertex("Safeco Field");
//	Vertex* ATT = new Vertex("AT&T Park/O.co Coliseum");
//	Vertex* Dodger = new Vertex("Dodger Stadium/Angel Stadium");
//	Vertex* Petco = new Vertex("PETCO Park");
//	Vertex* Chase = new Vertex("Chase Field");
//	Vertex* Coors = new Vertex("Coors Field");
//	Vertex* Rangers = new Vertex("Rangers Ballpark");
//	Vertex* Minutemaid = new Vertex("Minute Maid Park");
//	Vertex* Kauffman = new Vertex("Kauffman Stadium");
//	Vertex* Target = new Vertex("Target Field");
//	Vertex* Busch = new Vertex("Busch Stadium");
//	Vertex* Miller = new Vertex("Miller Park");
//	Vertex* Wrigley = new Vertex("Wrigley Field/US Cellular Field");
//	Vertex* Greatamerican = new Vertex("Great American Ballpark");
//	Vertex* Comerica = new Vertex("Comerica Park");
//	Vertex* Turner = new Vertex("Turner Field");
//	Vertex* Progressive = new Vertex("Progressive Field");
//	Vertex* Rogers = new Vertex("Rogers Center");
//	Vertex* PNC = new Vertex("PNC Center");
//	Vertex* Tropicana = new Vertex("Tropicana Field");
//	Vertex* Marlin = new Vertex("Marlin Field");
//	Vertex* National = new Vertex("Nationals Park/Camden Yards");
//	Vertex* Citizen = new Vertex("Citizens Bank Park");
//	Vertex* Citi = new Vertex("Citi Field/Yankee Stadium");
//	Vertex* Fenway = new Vertex("Fenway Park");

//	// Edges from Safeco
//	Edge Safeco_ATT(680, Safeco, ATT);
//	Safeco->add(Safeco_ATT);
//	Edge Safeco_Rogers(2070, Safeco, Rogers);
//	Safeco->add(Safeco_Rogers);
//	Edge Safeco_Target(1390, Safeco, Target);
//	vertices.push_back(Safeco);

//	// Edges from AT&T
//	Edge ATT_Safeco(680, ATT, Safeco);
//	ATT->add(ATT_Safeco);
//	Edge ATT_Dodger(340, ATT, Dodger);
//	ATT->add(ATT_Dodger);
//	Edge ATT_Chase(650, ATT, Chase);
//	ATT->add(ATT_Chase);
//	vertices.push_back(ATT);

//	// Edges from Dodger
//	Edge Dodger_ATT(340, Dodger, ATT);
//	Dodger->add(Dodger_ATT);
//	Edge Dodger_Petco(110, Dodger, Petco);
//	Dodger->add(Dodger_Petco);
//	Edge Dodger_Target(1500, Dodger, Target);
//	vertices.push_back(Dodger);

//	// Edges from Petco
//	Edge Petco_Dodger(110, Petco, Dodger);
//	Petco->add(Petco_Dodger);
//	Edge Petco_Chase(300, Petco, Chase);
//	Petco->add(Petco_Chase);
//	Edge Petco_Coors(830, Petco, Coors);
//	Petco->add(Petco_Chase);
//	vertices.push_back(Petco);

//	// Edges from Chase
//	Edge Chase_Petco(300, Chase, Petco);
//	Chase->add(Chase_Petco);
//	Edge Chase_ATT(650, Chase, ATT);
//	Chase->add(Chase_ATT);
//	Edge Chase_Coors(580, Chase, Coors);
//	Chase->add(Chase_Coors);
//	Edge Chase_Rangers(870, Chase, Rangers);
//	Chase->add(Chase_Rangers);
//	Edge Chase_Minutemaid(1115, Chase, Minutemaid);
//	Chase->add(Chase_Minutemaid);
//	vertices.push_back(Chase);

//	// Edges from Coors
//	Edge Coors_Petco(830, Coors, Petco);
//	Coors->add(Coors_Petco);
//	Edge Coors_Chase(580, Coors, Chase);
//	Coors->add(Coors_Chase);
//	Edge Coors_Rangers(650, Coors, Rangers);
//	Coors->add(Coors_Rangers);
//	Edge Coors_Kauffman(560, Coors, Kauffman);
//	Coors->add(Coors_Kauffman);
//	vertices.push_back(Coors);

//	// Edges from Rangers
//	Edge Rangers_Chase(870, Rangers, Chase);
//	Rangers->add(Rangers_Chase);
//	Edge Rangers_Coors(650, Rangers, Coors);
//	Rangers->add(Rangers_Coors);
//	Edge Rangers_Kauffman(460, Rangers, Kauffman);
//	Rangers->add(Rangers_Kauffman);
//	Edge Rangers_Turner(740, Rangers, Turner);
//	Rangers->add(Rangers_Turner);
//	Edge Rangers_Minutemaid(230, Rangers, Minutemaid);
//	Rangers->add(Rangers_Minutemaid);
//	vertices.push_back(Rangers);

//	// Edges from Minutemaid
//	Edge Minutemaid_Rangers(230, Minutemaid, Rangers);
//	Minutemaid->add(Minutemaid_Rangers);
//	Edge Minutemaid_Chase(1115, Minutemaid, Chase);
//	Minutemaid->add(Minutemaid_Chase);
//	Edge Minutemaid_Busch(680, Minutemaid, Busch);
//	Minutemaid->add(Minutemaid_Busch);
//	Edge Minutemaid_Tropicana(790, Minutemaid, Tropicana);
//	Minutemaid->add(Minutemaid_Tropicana);
//	Edge Minutemaid_Marlins(965, Minutemaid, Marlin);
//	Minutemaid->add(Minutemaid_Marlins);
//	vertices.push_back(Minutemaid);

//	// Edges from Kauffman
//	Edge Kauffman_Coors(560, Kauffman, Coors);
//	Kauffman->add(Kauffman_Coors);
//	Edge Kauffman_Rangers(460, Kauffman, Rangers);
//	Kauffman->add(Kauffman_Rangers);
//	Edge Kauffman_Busch(235, Kauffman, Busch);
//	Kauffman->add(Kauffman_Busch);
//	Edge Kauffman_Wrigley(415, Kauffman, Wrigley);
//	Kauffman->add(Kauffman_Wrigley);
//	vertices.push_back(Kauffman);

//	// Edges from Target
//	Edge Target_Safeco(1390, Target, Safeco);
//	Target->add(Target_Safeco);
//	Edge Target_Miller(300, Target, Miller);
//	Target->add(Target_Miller);
//	Edge Target_Dodger(1500, Target, Dodger);
//	Target->add(Target_Dodger);
//	Edge Target_Busch(465, Target, Busch);
//	Target->add(Target_Busch);
//	vertices.push_back(Target);

//	// Edges from Busch
//	Edge Busch_Kauffman(235, Busch, Kauffman);
//	Busch->add(Busch_Kauffman);
//	Edge Busch_Minutemaid(680, Busch, Minutemaid);
//	Busch->add(Busch_Minutemaid);
//	Edge Busch_Target(465, Busch, Target);
//	Busch->add(Busch_Target);
//	Edge Busch_Greatamerican(310, Busch, Greatamerican);
//	Busch->add(Busch_Greatamerican);
//	vertices.push_back(Busch);

//	// Edges from Miller
//	Edge Miller_Target(300, Miller, Target);
//	Miller->add(Miller_Target);
//	Edge Miller_Wrigley(80, Miller, Wrigley);
//	Miller->add(Miller_Wrigley);
//	Edge Miller_Rogers(430, Miller, Wrigley);
//	Miller->add(Miller_Wrigley);
//	vertices.push_back(Miller);

//	// Edges from Wrigley
//	Edge Wrigley_Kauffman(415, Wrigley, Kauffman);
//	Wrigley->add(Wrigley_Kauffman);
//	Edge Wrigley_Miller(80, Wrigley, Miller);
//	Wrigley->add(Wrigley_Miller);
//	Edge Wrigley_Comerica(240, Wrigley, Comerica);
//	Wrigley->add(Wrigley_Comerica);
//	Edge Wrigley_Greatamerican(250, Wrigley, Greatamerican);
//	Wrigley->add(Wrigley_Greatamerican);
//	vertices.push_back(Wrigley);

//	// Edges from Greatamerican
//	Edge Greatamerican_Busch(310, Greatamerican, Busch);
//	Greatamerican->add(Greatamerican_Busch);
//	Edge Greatamerican_Wrigley(250, Greatamerican, Wrigley);
//	Greatamerican->add(Greatamerican_Wrigley);
//	Edge Greatamerican_Progressive(225, Greatamerican, Progressive);
//	Greatamerican->add(Greatamerican_Progressive);
//	Edge Greatamerican_PNC(260, Greatamerican, PNC);
//	Greatamerican->add(Greatamerican_PNC);
//	Edge Greatamerican_Turner(375, Greatamerican, Turner);
//	Greatamerican->add(Greatamerican_Turner);
//	Edge Greatamerican_Tropicana(790, Greatamerican, Tropicana);
//	Greatamerican->add(Greatamerican_Tropicana);
//	vertices.push_back(Greatamerican);

//	// Edges from Comerica
//	Edge Comerica_Wrigley(240, Comerica, Wrigley);
//	Comerica->add(Comerica_Wrigley);
//	Edge Comerica_Rogers(210, Comerica, Rogers);
//	Comerica->add(Comerica_Rogers);
//	Edge Comerica_Progressive(90, Comerica, Progressive);
//	Comerica->add(Comerica_Progressive);
//	vertices.push_back(Comerica);

//	// Edges from Turner
//	Edge Turner_Rangers(740, Turner, Rangers);
//	Turner->add(Turner_Rangers);
//	Edge Turner_Greatamerican(310, Turner, Greatamerican);
//	Turner->add(Turner_Greatamerican);
//	Edge Turner_National(560, Turner, National);
//	Turner->add(Turner_National);
//	Edge Turner_Tropicana(600, Turner, Tropicana);
//	Turner->add(Turner_Tropicana);
//	vertices.push_back(Turner);

//	// Edges from Progressive
//	Edge Progressive_Greatamerican(225, Progressive, Greatamerican);
//	Progressive->add(Progressive_Greatamerican);
//	Edge Progressive_Comerica(90, Progressive, Comerica);
//	Progressive->add(Progressive_Comerica);
//	Edge Progressive_PNC(115, Progressive, PNC);
//	Progressive->add(Progressive_PNC);
//	vertices.push_back(Progressive);

//	// Edges from Rogers
//	Edge Rogers_Safeco(2070, Rogers, Safeco);
//	Rogers->add(Rogers_Safeco);
//	Edge Rogers_Miller(430, Rogers, Miller);
//	Rogers->add(Rogers_Miller);
//	Edge Rogers_Comerica(210, Rogers, Comerica);
//	Rogers->add(Rogers_Comerica);
//	Edge Rogers_PNC(225, Rogers, PNC);
//	Rogers->add(Rogers_PNC);
//	Edge Rogers_Fenway(430, Rogers, Fenway);
//	Rogers->add(Rogers_Fenway);
//	vertices.push_back(Rogers);

//	// Edges from PNC
//	Edge PNC_Greatamerican(260, PNC, Greatamerican);
//	PNC->add(PNC_Greatamerican);
//	Edge PNC_Progressive(115, PNC, Progressive);
//	PNC->add(PNC_Progressive);
//	Edge PNC_Rogers(225, PNC, Rogers);
//	PNC->add(PNC_Rogers);
//	Edge PNC_Citi(315, PNC, Citi);
//	PNC->add(PNC_Citi);
//	Edge PNC_National(195, PNC, National);
//	PNC->add(PNC_National);
//	vertices.push_back(PNC);

//	// Edges from Tropicana
//	Edge Tropicana_Minutemaid(790, Tropicana, Minutemaid);
//	Tropicana->add(Tropicana_Minutemaid);
//	Edge Tropicana_Greatamerican(790, Tropicana, Greatamerican);
//	Tropicana->add(Tropicana_Greatamerican);
//	Edge Tropicana_Marlin(210, Tropicana, Marlin);
//	Tropicana->add(Tropicana_Marlin);
//	vertices.push_back(Tropicana);

//	// Edges from Marlin
//	Edge Marlin_Minutemaid(965, Marlin, Minutemaid);
//	Marlin->add(Marlin_Minutemaid);
//	Edge Marlin_Tropicana(210, Marlin, Tropicana);
//	Marlin->add(Marlin_Tropicana);
//	Edge Marlin_Turner(600, Marlin, Turner);
//	Marlin->add(Marlin_Turner);
//	Edge Marlin_National(930, Marlin, National);
//	Marlin->add(Marlin_National);
//	Edge Marlin_Fenway(1255, Marlin, Fenway);
//	Marlin->add(Marlin_Fenway);
//	vertices.push_back(Marlin);

//	// Edges from National
//	Edge National_Marlin(930, National, Marlin);
//	National->add(National_Marlin);
//	Edge National_Turner(560, National, Turner);
//	National->add(National_Turner);
//	Edge National_PNC(195, National, PNC);
//	National->add(National_PNC);
//	Edge National_Citizen(90, National, Citizen);
//	National->add(National_Citizen);
//	vertices.push_back(National);

//	// Edges from Citizen
//	Edge Citizen_National(90, Citizen, National);
//	Citizen->add(Citizen_National);
//	Edge Citizen_Citi(90, Citizen, Citi);
//	Citizen->add(Citizen_Citi);
//	vertices.push_back(Citizen);

//	// Edges from Citi
//	Edge Citi_Citizen(90, Citi, Citizen);
//	Citi->add(Citi_Citizen);
//	Edge Citi_PNC(315, Citi, PNC);
//	Citi->add(Citi_PNC);
//	Edge Citi_Fenway(195, Citi, Fenway);
//	Citi->add(Citi_Fenway);
//	vertices.push_back(Citi);

//	// Edges from Fenway
//	Edge Fenway_Rogers(430, Fenway, Rogers);
//	Fenway->add(Fenway_Rogers);
//	Edge Fenway_Citi(195, Fenway, Citi);
//	Fenway->add(Fenway_Citi);
//	Edge Fenway_Marlin(1255, Fenway, Marlin);
//	Fenway->add(Fenway_Marlin);
//	vertices.push_back(Fenway);

//	iDijkstra(Dodger);

//	// This part will need to be changed for QT
//	for(unsigned j = 0; j < vertices.size(); j++)
//	{
//		Vertex* current = vertices[j];
//		cout << "\nTo " << current->name << ":\n";
//		for(unsigned i = 0; i < current->verticesTo.size(); i++){
//			cout << setw(14) << current->verticesTo[i]->name
//				 << setw(5)  << current->verticesTo[i]->weightTo
//				 << "mi"  << endl;
//		}
//	}
//}

//void stadium::iDijkstra(Vertex* start)
//{
//	unsigned index;
//	vector<Vertex*> visited;
//	Vertex* current;
//	int toVertex;
//	int atVertex;
//	Vertex* end;

//	index = 0;
//	start->weightTo = 0;
//	start->verticesTo.push_back(start);
//	visited.push_back(start);
//	while(index < visited.size()){
//		current = visited[index];
//		for(unsigned i = 0; i < current->edges.size(); i++){
//			end = current->edges[i].end;
//			if(end->state != VISITED){
//				end->state = VISITED;
//				visited.push_back(end);
//			}
//			toVertex = current->weightTo + current->edges[i].weight;
//			atVertex = end->weightTo;
//			if(atVertex > toVertex){
//				end->weightTo   = toVertex;
//				end->verticesTo = current->verticesTo;
//				end->verticesTo.push_back(end);
//			}
//		}
//		index++;
//	}
//}

//void stadium::MST()
//{
//    int parent[25]; // Array to store constructed MST
//    int key[25];   // Key values used to pick minimum weight edge in cut
//    bool mstSet[25];  // To represent set of vertices not yet included in MST
//	int adjMatrix[25][25] = {
//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Comerica

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Fenway

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Rangers

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Kauffman

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Minutemaid

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Progressive

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Rogers

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Safeco

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Target

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Tropicana

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // ATT

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Busch

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Chase

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Citi

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Citizen

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Coors

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Dodger

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Great America

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Marlin

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Miller

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // National

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Petco

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // PNC

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Turner

//							 {
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0,
//							  0, 0, 0, 0, 0
//							 }, // Wrigley
//							};

//    // Initialize all keys as INFINITE
//    for (int i = 0; i < 25; i++)
//       key[i] = 1000, mstSet[i] = false;

//    // Always include first 1st vertex in MST.
//    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
//    parent[0] = -1; // First node is always root of MST

//    // The MST will have V vertices
//    for (int count = 0; count < 24; count++)
//    {
//       // Pick the minimum key vertex from the set of vertices
//       // not yet included in MST
//       int u = minKey(key, mstSet);

//       // Add the picked vertex to the MST Set
//       mstSet[u] = true;

//       // Update key value and parent index of the adjacent vertices of
//       // the picked vertex. Consider only those vertices which are not yet
//       // included in MST
//       for (int v = 0; v < 25; v++)
//       {
//           // graph[u][v] is non zero only for adjacent vertices of m
//           // mstSet[v] is false for vertices not yet included in MST
//           // Update the key only if graph[u][v] is smaller than key[v]
//          if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] <  key[v])
//          {
//             parent[v]  = u;
//        	 key[v] = adjMatrix[u][v];
//          }
//       }
//    }

//    printMST(parent, 25, adjMatrix);
//}

