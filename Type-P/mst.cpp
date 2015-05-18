#include "mst.h"

MST::MST()
{
    mstSize = 0;
    totaldistance = 0;
}

MST::~MST()
{

}

//6810
int MST::totaldist()
{
    return totaldistance;
}

//calculates the MST and returns it in order, and the total distance
vector<QString> MST::MSToutput()
{
    parentVector.clear();
    mstSize = stadiumDistances.size();

    int u;
    treenode temp;
    temp.mstSet = false;
    itt = stadiumDistances.begin();
    for(;itt != stadiumDistances.end(); itt++)
    {
        temp.name = itt->first;
        Key.push_back(temp);
    }

    // Always include first 1st vertex in MST.
    parentVector.push_back(Key[0].name);
    Key[0].mstSet = true;

    // The MST will have V vertices
    for (int count = 0; count < mstSize - 1; count++)
    {
       // Pick the minimum key vertex from the set of vertices
       // not yet included in MST
       u = minKey();

       // Add the picked vertex to the MST Set
       Key[u].mstSet = true;
       parentVector.push_back(Key[u].name);
    }
    return parentVector;
}

// THESE NEED TO BE PRIVATE METHODS
int MST::minKey()
{
   // Initialize min value
   int min = 100000;
   int dist;
   int min_index;

   for(int j = 0; j < parentVector.size(); j++)
   {
       for(int v = 0; v < Key.size();v++)
       {
           dist = distanceOfTwo(parentVector[j], Key[v].name);
//           qDebug() << dist << endl;
         if (Key[v].mstSet == false && dist < min && dist > -1)
         {
             min = dist;
             min_index = v;
         }
       }
   }
    totaldistance += min;
   return min_index;
}

void MST::readFile()
{
    QString key;
    QString reader;
    node temp;
    QFile distances("Distances.txt");

    map<QString,node> thisisdumb;

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

            if(reader != "-5" && reader != "")
            {
                key = reader;
                reader = in.readLine();
            }

            while(reader != "-5" && reader != "")
            {
                temp.name = reader;
                reader = in.readLine();
                temp.distance = reader.toInt();
                thisisdumb[temp.name] = temp;
//                qDebug() <<"read in ~ " << temp.name <<endl;
                reader = in.readLine();
            }
            map<QString,node>::iterator stilldumb = thisisdumb.begin();
            for(; stilldumb != thisisdumb.end();stilldumb++)
            {
//                qDebug() <<"push in ~ " << (stilldumb->second).name <<endl;
                stadiumDistances[key].push_back(stilldumb->second);
            }
        }
    }
    distances.close();
}

void MST::writeFile()
{
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

            for(unsigned int i=0; i < itt->second.size() ; i++)
            {
                out << itt->second[i].name << endl << itt->second[i].distance << endl;
            }
            out << -5;
        }
        distances.flush();
    }

    distances.close();
}

void MST::addNewStadium(QString n)
{
    node temp;
    temp.distance = -1;
    temp.name = n;
    //set as not connected from all the pre-existing stadiums
    itt = stadiumDistances.begin();
    for(;itt != stadiumDistances.end();itt++)
    {
        itt->second.push_back(temp);
    }
    //add the new stadium
    stadiumDistances[n];
    //set it as not connected to any of the other stadiums
    itt = stadiumDistances.begin();
    for(;itt != stadiumDistances.end();itt++)
    {
        temp.name = itt->first;
        stadiumDistances[n].push_back(temp);
    }
    writeFile();
    stadiumDistances.clear();
    readFile();
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

int MST::getSize()
{
    return mstSize;
}

//6810
void MST::tree()
{

}


vector<dijknode> MST::singledijk(QString start)
{
    TravelList.clear();
    dijknode temp;
    bool pushOn = true;
    int index = 0;
    vector<node> stadiumAtNameVec;
    vector<node>::iterator distcheck;

    temp.name = start;
    temp.distanceFromStart = 0;

    TravelList.push_back(temp);

    while(index < TravelList.size())
    {
        stadiumAtNameVec = stadiumDistances[TravelList[index].name];
        distcheck = stadiumAtNameVec.begin();
        while(distcheck != stadiumAtNameVec.end())
        {
            if(distcheck->distance >= 0)
            {
                temp.name = distcheck->name;
                temp.distanceFromStart = TravelList[index].distanceFromStart + distcheck->distance;

                //check if node is already pushed and make sure the shortest distances is saved
                for(int i = 0; i < TravelList.size(); i++)
                {
                    if(TravelList[i].name == temp.name)
                    {
                        pushOn = false;
                        if(temp.distanceFromStart < TravelList[i].distanceFromStart)
                        {
                            TravelList[i].distanceFromStart = temp.distanceFromStart;
                        }
                    }
                }

                if(pushOn)
                {
                    TravelList.push_back(temp);
                }

                pushOn = true;
            }
            distcheck++;
        } // finished checking all connections at current node, loop and check next node
        index++;
    } // end big loop -> all nodes connected in the graph have been visited and added

    //sorting TravelList
    for(int i = 0; i < TravelList.size(); i++)
    {
        for(int j = TravelList.size() - 1; j > i; j--)
        {
            if(TravelList[i].distanceFromStart > TravelList[j].distanceFromStart)
            {
                temp = TravelList[i];
                TravelList[i] = TravelList[j];
                TravelList[j] = temp;
            }
        }
    }
    return TravelList;
}

vector<dijknode> MST::doubleDijking(vector<QString> toVisit)
{
    QString current;
    vector<QString>::iterator toErase;
    vector<dijknode> toReturn;
    int index = 0;
    int check;
    bool found = false;

    //start node
    current = toVisit[index];
    toVisit.erase(toVisit.begin());
    dijknode temp;
    temp.distanceFromStart = 0;
    temp.name = current;
    toReturn.push_back(temp);

    //calculate the closest stadium, and then the closest from that and so on
    while(!toVisit.empty())
    {

        singledijk(current);

        check = 0;
        while(!found && check < TravelList.size())
        {
            toErase = toVisit.begin();
            while(!found && toErase != toVisit.end())
            {
                if(*toErase == TravelList[check].name)
                {
                    found = true;
                    toReturn.push_back(TravelList[check]);
                    current = TravelList[check].name;
                    toVisit.erase(toErase);
                }
                else
                {
                    toErase++;
                }
            }
            check++;
        }
        found = false;
    }
    return toReturn;
}

//vector<QString> MST::dijk(QString start)
//{
//    vector <QString> visited;
//    QString current = start;
//    int index;
//     int smallest = 10000;
//    const int SIZE = stadiumDistances.size ();
//    //stands for isVisited
//    bool isV[SIZE];
//    for (int j = 0; j < SIZE; j ++)
//    {
//        isV[j] = false;
//    }

//    int startIndex;
//    for(int k = 0; k < SIZE; k++)
//    {
//        if(stadiumDistances[current].at(k).name == current)
//        {
//            startIndex = k;
//        }
//    }

//    //startIndex--right
//    int vertex = startIndex;
//    qDebug() << QString::number(vertex);
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(0).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(1).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(2).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(3).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(4).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(5).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(6).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(7).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(8).name << endl;
//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(9).name << endl;

//    qDebug() << "map.vec" << stadiumDistances["Angel Stadium"].at(9).distance << endl;
//    qDebug() << "overall size" << SIZE;

//    index = 0;
//    visited.push_back(start);
//    isV[vertex] = true;

//    qDebug() << "first of vec" <<visited.at(0);

//    while( visited.size() <= SIZE)
//    {
//        current = visited[index];
//        qDebug() << "current at top of loop" << current;
//        for (int i = 0; i < SIZE; i++)
//        {
//            if(stadiumDistances[current].at(i).distance < smallest
//               && stadiumDistances[current].at(i).distance > -1
//               && !(isV[i]) )
//            {
//                vertex = i;
//                smallest = stadiumDistances[current].at(i).distance;
//                current = stadiumDistances[current].at(i).name;
//                //visited.push_back(stadiumDistances[current].at(i).name);
//            }
//        }
//        isV[vertex] = true;
//        qDebug() << "current " << current << endl;
//        qDebug() << "vertex" << QString::number(vertex);
//        visited.push_back(current);
//        smallest = 10000;
//        index ++;

//    }


//    return visited;
//}
