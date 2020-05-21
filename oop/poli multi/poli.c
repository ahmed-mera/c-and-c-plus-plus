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
class madre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void virtual mess (){
            cout << " sono la madre \n";
        }
};
class figlio : public padre , public madre {
    public:
       /* padre (){
            cout << " sono il custruttore del padre" << endl ;

        }*/
        void  mess (){
            cout << " sono il figlio\n";
        }
};

int main()
{
    padre *p;
    figlio f;

    f.mess();

    return 0;
}

