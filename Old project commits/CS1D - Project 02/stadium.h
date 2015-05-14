#include "Project 02.h"

class stadium
{
	public:
	stadium();

	// Manually adds a stadium to the list
	void addStadium(string sName,
					string tName,
					string a1,
					string a2,
					string tele,
					string date,
					string seats,
					bool   astroTurf,
					bool   national);

	void test();

	// Reads list from file
	void readList();
	// Outputs stadiums to list
	void writeList();

	// Various outputs of entire list
	void alphaLeague();
	void alphaStadium();
	void alphaTeam();
	void opening();
	void seating();

	// Setters
	void setStadiumName(string compare, string sName);
	void setTeamName(string compare, string tName);
	void setAddress1(string compare, string a1);
	void setAddress2(string compare, string a2);
	void setPhone(string compare, string tele);
	void setOpening(string compare, string date);
	void setCapacity(string compare, string seats);
	void setFieldType(string compare, bool astroTurf);
	void setLeague(string compare, bool national);

	// Getters
	string getStadiumName(string compare);
	string getTeamName(string compare);
	string getAddress1(string compare);
	string getAddress2(string compare);
	string getPhone(string compare);
	string getOpening(string compare);
	string getCapacity(string compare);
	bool getFieldType(string compare);
	bool getLeague(string compare);

	// The Dijkstra method to call
	void Dijkstra();
	void MST();

	private:

		// The actual Dijkstra algorithm, used internally
		void iDijkstra(Vertex* start);

		struct stadiumNode
		{
			string stadiumName;
			string teamName;
			string address1;
			string address2;
			string phone;
			string opening;
			string capacity;

			bool league;    // 0 for American
			bool fieldType; // 0 for grass

			stadiumNode *next;
		};

		stadiumNode *comparison(string compare)
		{
			stadiumNode *tempNode;

			tempNode = stadiumList;

			while(tempNode->stadiumName != compare)
			{
				tempNode = tempNode->next;
			}

			return tempNode;
		}

		int minKey(int key[], bool mstSet[])
		{
		   // Initialize min value
		   int min = 10000, min_index;

		   for (int v = 0; v < 30; v++){
		     if (mstSet[v] == false && key[v] < min){
		         min = key[v];
		   	   	 min_index = v;
		     }
		   }

		   return min_index;
		}

		string DetermineLocation(int index)
		{
			string location;
			switch(index)
			{
			case(0):
					location ="Safeco Field";
					break;
			case(1):
					location ="AT&T Park/O.co Coliseum";
					break;
			case(2):
					location ="Dodger Stadium/Angel Stadium";
					break;
			case(3):
					location ="PETCO Park";
					break;
			case(4):
					location ="Chase Field";
					break;
			case(5):
					location ="Coors Field";
					break;
			case(6):
					location ="Rangers Ballpark";
					break;
			case(7):
					location ="Minute Maid Park";
					break;
			case(8):
					location ="Kauffman Stadium";
					break;
			case(9):
					location ="Target Field";
					break;
			case(10):
					location ="Busch Stadium";
					break;
			case(11):
					location ="Miller Park";
					break;
			case(12):
					location ="Wrigley Field/US Cellular Field";
					break;
			case(13):
					location ="Great American Ballpark";
					break;
			case(14):
					location ="Comerica Park";
					break;
			case(15):
					location ="Turner Field";
					break;
			case(16):
					location ="Progressive Field";
					break;
			case(17):
					location ="Rogers Center";
					break;
			case(18):
					location ="PNC Center";
					break;
			case(19):
					location ="Tropicana Field";
					break;
			case(20):
					location ="Marlin Field";
					break;
			case(21):
					location ="Nationals Park/Camden Yards";
					break;
			case(22):
					location ="Citizens Bank Park";
					break;
			case(23):
					location ="Citi Field/Yankee Stadium";
					break;
			case(24):
					location ="Fenway Park";
					break;
			}

			return location;
		}

		void printMST(int parent[25], int n, int graph[25][25])
		{
		    cout << "Edge         Weight\n";
		   for (int i = 1; i < 12; i++){

			   cout << setw(15) << DetermineLocation(parent[i]) ;

			   cout << graph[i][parent[i]] << endl;
		   }
		}

		stadiumNode *stadiumList;
};
