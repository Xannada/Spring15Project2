#include "mst.h"

MST::MST()
{

}

void MST::MSToutput()
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

            for(int i=0; i < temp.size() ; i++)
            {
                out << temp[i].name << endl << temp[i].distance << endl;
            }
            out << 0;
        }
        distances.flush();
    }

    distances.close();
}
