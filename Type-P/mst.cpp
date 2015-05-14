#include "mst.h"

MST::MST()
{

}

//calculates the MST and returns it in order, and the total distance
vector<QString> MST::MSToutput(int &totalDist)
{

}

void MST::readFile()
{
    QString key;
    QString reader;
    node temp;
    QFile distances("Distances.txt");

    if(!distances.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(0,"Cannot Open to Read", distances.errorString());
    }
    else
    {
        QTextStream in(&distances);

        while(!in.atEnd())
        {
            reader = in.readLine();

            if(reader != "-1" && reader != "")
            {
                key = reader;
                reader = in.readLine();
            }

            while(reader != "0" && reader != "")
            {
                temp.name = reader;
                reader = in.readLine();
                temp.distance = reader.toInt();
                stadiumDistances[key].push_back(temp);
                reader = in.readLine();
            }
        }
    }
    distances.close();
}

void MST::writeFile()
{
    vector<node> temp;
    QFile distances("Distances.txt");

    if(!distances.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(0,"Cannot Open to Write", distances.errorString());
    }
    else
    {
        QTextStream out(&distances);

        itt = stadiumDistances.begin();
        for(;itt != stadiumDistances.end(); itt++)
        {
            if(itt != stadiumDistances.begin())
                out << endl;
            out << itt->first << endl;  //output key
            temp = itt->second;

            for(unsigned int i=0; i < temp.size() ; i++)
            {
                out << temp[i].name << endl << temp[i].distance << endl;
            }
            out << 0;
        }
        distances.flush();
    }

    distances.close();
}

void MST::addNewStadium(QString n)
{
    stadiumDistances[n];
    node temp;
    temp.distance = 0;
    stadiumDistances[n];
    itt = stadiumDistances.begin();
    for(;itt != stadiumDistances.end();itt++)
    {
        temp.name = itt->first;
        stadiumDistances[n].push_back(temp);
    }
}

void MST::changeDistance(QString current, QString n, int d)
{
    vector<node>::iterator it2 = stadiumDistances[current].begin();

    while(it2 != stadiumDistances[current].end() && it2->name != n)
    {
        it2++;
    }
    if(it2->name == n)
    {
        it2->distance = d;
    }
}

int MST::distanceOfTwo(QString current, QString dest)
{
    int i = 0;
    vector<node>::iterator it2 = stadiumDistances[current].begin();

    while(it2 != stadiumDistances[current].end() && it2->name != dest)
    {
        it2++;
    }
    if(it2->name == dest)
    {
        i = it2->distance;
    }
    return i;
}

vector<node> MST::distToOthers(QString n)
{
    return stadiumDistances[n];
}

void MST::tree()
{
//    int parent[25]; // Array to store constructed MST
//    int key[25];   // Key values used to pick minimum weight edge in cut
//    bool mstSet[25];  // To represent set of vertices not yet included in MST

//    // Initialize all keys as INFINITE
//    for (int i = 0; i < 25; i++)
//    {
//        key[i] = 100000;
//        mstSet[i] = false;
//    }

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
//       for (int v = 0; v < 24; v++)
//       {
//           // graph[u][v] is non zero only for adjacent vertices of m
//           // mstSet[v] is false for vertices not yet included in MST
//           // Update the key only if graph[u][v] is smaller than key[v]
//          if (stadiumDistances[u].at(v) && mstSet[v] == false && stadiumDistances[u].at(v) <  key[v])
//          {
//             parent[v]  = u;
//             key[v] = stadiumDistances[u].at(v);
//          }
//       }
//    }

//    printMST(parent, 25, stadiumDistances);
}

// THESE NEED TO BE PRIVATE METHODS
//int minKey(int key[], bool mstSet[])
//{
//   // Initialize min value
//   int min = 10000, min_index;
//
//   for (int v = 0; v < 30; v++){
//     if (mstSet[v] == false && key[v] < min){
//         min = key[v];
//         min_index = v;
//     }
//   }
//
//   return min_index;
//}
//
//void printMST(int parent[25], int n, map<QString,vector<node> >)
//{
//    cout << "Edge         Weight\n";
//   for (int i = 1; i < 12; i++){
//
//       cout << setw(15) << stadiumDistances.at(i).data(); ;
//
//       cout << graph[i][parent[i]] << endl;
//   }
//}
