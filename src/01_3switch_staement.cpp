#include <iostream>
using namespace std;
//switch statement
int main() {
    int day;
    cin>>day;

    switch(day){ 
        // switch is used to give different output for diff inputs.
        case 1:
            cout<<"monday";
            break;   //using a break statement to break our output and not get the output as montuewedthu...5.
        case 2:
            cout<<"tuesday";
            break;
        case 3:
            cout<<"wednesday";
            break;
        case 4:
            cout<<"thursday";
            break;
        case 5:
            cout<<"friday";
            break;
        case 6:
            cout<<"saturday";
            break;
        case 7:
            cout<<"sunday";
            break;
        default:
            cout<<"invalid";//when none of the condition is satisfied.
            break;
        cout<<"cheak inside switch";//due to break this line never gets printed.
    }

    cout<< "\n" << "check";
    return 0;
}
