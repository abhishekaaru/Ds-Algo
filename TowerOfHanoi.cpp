#include<iostream>
using namespace std;

void hanoi(int n,char src,char help,char des){
    if(n==0){
        return;
    }

    hanoi(n-1,src,des,help);
    cout<<"Move from "<<src<<" to "<<des<<endl;
    hanoi(n-1,help,src,des);

}

// GFG
long long toh(int n, int from, int to, int aux)
{
    long long move = 0;

    if (n >= 1)
    {
        move += toh(n - 1, from, aux, to);
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        move++;
        move += toh(n - 1, aux, to, from);
    }

    return move;
}

int main(){

    hanoi(3,'A','B','C');

    return 0;
}