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
    QFile distances(":/files/Distances.txt");

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
    QFile distances(":/files/Distances.txt");

    if(!mercfile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(0,"Cannot Open to Write", distances.errorString());
    }
    else
    {
        QTextStream out(&distances);

        itt = theList.begin();
        for(;itt != theList.end(); itt++)
        {
            if(itt != theList.begin())
                out << endl;
            out << itt->first << endl;  //output key
            temp = itt->second;

            for(int i=0; i < temp.size() ; i++)
            {
                out << temp[i].name << endl << temp[i].price << endl;
            }
            out << 0;
        }
        distances.flush();
    }

    distances.close();
}
