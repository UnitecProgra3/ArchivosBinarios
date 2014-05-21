#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    ofstream out("archivo");

    for(int i=0;i<3;i++)
    {
        char usuario[10] = "";
        cout<<"Usuario: ";
        cin>>usuario;
        out.write(usuario,10);

        int score=0;
        cout<<"Score: ";
        cin>>score;
        out.write((char*)&score,sizeof(int));
    }

    out.close();

    ifstream in("archivo");

    int mayor = 0;

    for(int i=0;i<3;i++)
    {
        char *usuario = new char(0);
        in.read(usuario,10);

        int score;
        in.read((char*)&score,sizeof(int));

        if(mayor<score)
        {
            mayor = score;
        }

//        cout<<usuario<<endl;
//        cout<<score<<endl;
    }

    cout<<"Mayor score: "<<mayor<<endl;

    return 0;
}
