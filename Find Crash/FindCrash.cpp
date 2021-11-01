#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

class love {
private:
    string boy;
    string girl;
public:
    bool input();
    double sum();
    void output();
};
bool  love::input() {
    cout<<" Enter Your Name = ";
    getline(cin,boy) ;
    cout<<"Enter Your Crush name = ";
    getline(cin,girl);
    return true;
}

double love::sum() {
    int l = boy.size();
    int m = girl.size();
    int boysum = 0;
    int girlsum = 0;
    for (int i = 0; i < l; ++i) {
        if (boy[i] >= 'A' && boy[i] <= 'Z') {
            boysum += boy[i] - 64;
        }
        if (boy[i] >= 'a' && boy[i] <= 'z') {
            boysum += boy[i] - 96;
        }
    }
    while (boysum){
        if(boysum/10==0)
            break;

        int temp=boysum;
        boysum=0;
        while (temp){
            boysum+=temp%10;
            temp/=10;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (girl[i] >= 'A' && girl[i] <= 'Z') {
            girlsum += girl[i] - 64;
        }
        if (girl[i] >= 'a' && girl[i] <= 'z') {
            girlsum += girl[i] - 96;
        }
    }
    while (girlsum){
        if(girlsum/10==0)
            break;

        int temp=girlsum;
        girlsum=0;
        while (temp){
            girlsum+=temp%10;
            temp/=10;
        }
    }
    return girlsum > boysum ? (double) boysum / girlsum : (double) girlsum / boysum;
}
void love::output() {
    double z=sum()*100;
    cout<<"Relation ship "<<fixed<<setprecision(2)<<z<<" % true"<<endl;
}
int main() {
    love *me;
    me=new love;
    while (me->input()){
        me->output();
    }
    return 0;
}
