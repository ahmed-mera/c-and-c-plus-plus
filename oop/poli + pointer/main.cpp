#include <iostream>

using namespace std;
class padre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void virtual mess (){
            cout << " sono il padre\n";
        }
};

class f_1 : public padre {
    public:
        /*f_1(): padre(){
            cout << "sono il figlio f_1" << endl;
        }*/
        void  mess (){
            cout << " sono il figlio f_1\n";
        }
};
class f_2 : public padre {
    public:
        /*f_2(): padre(){
            cout << "sono il figlio f_2" << endl;
        }*/
        void mess (){
            cout << " sono il figlio f_2\n";
        }
};

int main()
{
    padre *p;
    f_1 F_1;
    f_2 F_2;
    int scelta;
    while (1){
        cout << "ins scelta :_ ";
        cin >> scelta;
        switch(scelta){
            case 1:
                p = &F_1;
                p->mess();
                break;
            case 2:
                p = &F_2;
                p->mess();
                break;
            case 0:
                exit(0);
                break;
            default:
                break;

        }
    }



    return 0;
}
