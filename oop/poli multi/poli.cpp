#include <iostream>

using namespace std;
class padre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void virtual messp (){
            cout << " sono il padre\n";
        }
};
class madre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void virtual messm (){
            cout << " sono la madre \n";
        }
};
class figlio : public padre , public madre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void  messf (){
            cout << " sono il figlio\n";
        }
};

int main()
{
    figlio f;
    f.messp(); //padre
    f.messm(); //madre
    f.messf(); //figlio


    return 0;
}

