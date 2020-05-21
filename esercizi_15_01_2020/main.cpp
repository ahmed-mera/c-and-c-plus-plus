#include <iostream>
#include <string>
using namespace std;
int checkString(string word , int count = 0, int call = 0);
int convert(string word , int count = 0);
int check(int arr [] , int dim , int min = 0 , int count = 0 );
int main() {
    string pa = "ahmed" , output = checkString(pa) ? "SI" : "NO" ;
    int arr[5] = {50 , 100 , 2 , 0 , -1};
    cout << "palindroma = " << output << endl;
    cout << "rovescio = ";
    convert(pa);
    cout << endl;
    cout <<  "minimo = " << check(arr, 5 , arr[0] );

    return 0;
}

//----------------------------------------------------------------------------------------

int checkString(string word , int count , int call){
    int length = word.length() - 1;
    (call >= length + 1) ? count = -1 : call += 1;;
    (count == (length / 2)) ? (word[count] == word[length - count]) ? checkString(word,count +=1,call) :  count -= 1 : NULL;
    return (count == (length / 2)) ?  1 : (count < 0) ? 0 : NULL;
}

//----------------------------------------------------------------------------------------

int convert(string word , int count){
    int len = word.length() - count - 1;
    cout << word[len];
    return (len >= 0) ? convert( word , count += 1) : NULL;
}

//----------------------------------------------------------------------------------------

int check(int arr [] , int dim , int min , int count){
    min > arr[count] ? min = arr[count] :  NULL ;
    return count != dim ? check(arr , dim , min , count += 1) : min ;
}
