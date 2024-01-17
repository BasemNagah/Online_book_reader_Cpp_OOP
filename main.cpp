#include <iostream>
#include "objects.hpp"
#include "config.hpp"
#include "interface.hpp"

using namespace std;

Stack Users ;
void config(void)
{
    Person Admin ;
    Admin.setUserName(adminUserName) ;
    Admin.setName(adminName) ;
    Admin.setEmail(adminEmail);
    Admin.setPassword(adminPassword);
    Admin.setadmin(Admin_role);

    Users.push(Admin) ;
}

void start()
{
    int choice ;
    cout<<"Welcome to Online Book Reader \n";
    cout<<"Menu: \n";
    cout<<"1: Login\n" ;
    cout<<"2: Sign up\n" ;

    cout<<"Enter number in range 1-2 : " ;
    cin>>choice ;
    switch(choice)
    {
    case 1 :
        login_session();
        break;
    case 2 :
        sign_up_session() ;
        break;
    default :
        cout<<"\ninvalied input please try again !\n";
        start();
        break;
    }



}



int main()
{
    config();

    while(1)
    {
        start() ;
    }

    return 0;
}
