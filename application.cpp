#include "application.h"

#include <iostream>
#include "polinom.h"

using namespace std;

TApplication::TApplication(int argc, char **argv) :
    QCoreApplication(argc, argv)
{

}

int TApplication::run()
{
    int ch;
    number a,b,c;
    number point;
    number masiv[2]={0,0};
    
    while (true)
    {
        cout<<"1 - input data"<<endl;
        cout<<"2 - roots"<<endl;
        cout<<"3 - value"<<endl;
        cout<<"4 - output"<<endl;
        cout<<"0 - exit"<<endl;
        cout<<"> ";
        cin>>ch;
        switch (ch)
        {
            case 1:
            {
                cout << "a=";
                cin >> a;
                cout << "b=";
                cin >> b ;
                cout << "c=";
                cin >> c ;
                cout << endl;


                // записать значения
            }
                break;
            case 2:
            {
                TPolinom polinom(a, b, c);
                cout << " Kolichestvo kornei =" << polinom.roots(masiv) << endl;
                if (polinom.roots(masiv) == 0)
                {
                    cout << "Net kornei" <<endl;
                    break;
                }
                cout << " Koren1 " << masiv[0];
                cout << " Koren2 " << masiv[1];
                cout << endl;
            }
                break;
            case 3:
            {
                TPolinom polinom(a, b, c);
                cout << " Enter a point: ";
                cin >> point;
                cout << " Result in the point " << point << " is " <<  polinom.value(point) << endl;
            }
                break;
            case 4:
                {
                    TPolinom polinom(a, b, c);
                    //TPolinom p(a,b,c);
                    cout<<polinom<<endl;
                }
                break;
            default: break;
        }
        if (ch == 0) break;
    }
    return 0;
}
