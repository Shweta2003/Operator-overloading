#include <iostream>
using namespace std;

class time
{
private:
    int hour;
    int minute;
public:
    
    void display(){
        cout << "input time -> " << hour << " : " << minute << endl;
        cout << endl;
    }
    friend istream & operator >> (istream & , time &);
    friend ostream & operator << (ostream & , time &);
    time operator +(time t1){
        time temp;
        temp.hour = hour + t1.hour;
        temp.minute = minute + t1.minute;
        temp.minute = (temp.hour*60) + temp.minute;
        return temp;
    }
    friend time & operator - (time & , time &);
};
istream & operator >> (istream & in , time & t){
    cout << "enter time in format hour : minute" << endl;
    cout << "hour : " ;
    in >> t.hour ;
    cout << "minute : " ;
    in >> t.minute;
    return in;
}

ostream & operator << (ostream & out , time & t){
    out << "result time : ";
    out << t.minute <<" minutes" << endl;
    return out;
}

time & operator - (time & t2, time & t3){
    t2.minute = t2.minute + (t2.hour*60);
    t3.minute = t3.minute + (t3.hour*60);
    if (t2.minute > t3.minute){
        cout << "1" << endl;
        t2.minute = t2.minute - t3.minute;
        return t2;
    }
    else{
        t3.minute = t3.minute - t2.minute;
        return t3;
    }
    
}


int main()
{
    char to_con = 'y';
    while (to_con == 'y'){
        cout << "press 1 to enter 2 time values " << endl << "press 2 to add the time " << endl << "press 3 to find difference of time " << endl;
        int ask;
        cin >> ask;
        switch (ask)
        {
        case 1:
            time ta;
            time tb;
            cin >> ta;
            ta.display();
            cout << endl;
            cin >> tb;
            tb.display();
            break;
        case 2:
            time tsum;
            tsum = ta + tb;
            cout << tsum;
            break;
        case 3:
            time tdiff;
            tdiff = ta - tb;
            cout << tdiff;
            break;
        
        default:
            cout << "wrong input..try again" << endl;
            break;
        }
        cout << "do you want to continue(y/n) : ";
        cin >> to_con;
    }
    return 0;
}