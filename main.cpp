#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    ofstream out("archivo");

    for(int i=0;i<3;i++)
    {
        char str[10] = "";
        cout<<"Usuario: ";
        cin>>str;
        out.write(str,10);

        int num=0;
        cout<<"Score: ";
        cin>>num;
        out.write((char*)&num,sizeof(int));
    }

    out.close();

    ifstream in("archivo");

    for(int i=0;i<3;i++)
    {
        char *str = new char(0);
        in.read(str,10);

        int temp;
        in.read((char*)&temp,sizeof(int));

        cout<<temp<<endl;
        cout<<str<<endl;
    }

    cout<<"Mayor score: XXXX"<<endl;

    return 0;
}
