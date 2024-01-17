#include "interface.hpp"

vector<Book> book ;

//login session
void login_session(void)
{
    Person* user_ptr = Users.returnPointerUsers() ;
    string copyUserName ;
    string copyPassword ;
    cout<<"Enter user name (no spaces): " ;
    cin>>copyUserName ;
    if(copyUserName == user_ptr[0].getUserName())
    {
        int localCounter  = 3 ;
        while(localCounter)
        {
            cout<<"Enter Password (no spaces): " ;
            cin>>copyPassword;
            if(copyPassword == user_ptr[0].getPassword())
            {
                localCounter = 0 ;
                AdminMode(user_ptr[0]) ;
            }
            else
            {
                localCounter-- ;
                cout<<"Wrong password ( still "<<localCounter<<" tries ) !\n" ;
            }
        }
    }
    else
    {
        for(int i=1 ;i<Users.getTopStack() ; i++)
        {
            //cout<<user_ptr[i].getName()<<"\n" ;
            if(copyUserName == user_ptr[i].getUserName())
            {
                int localCounter  = 3 ;
                while(localCounter)
                {
                    cout<<"Enter Password (no spaces): " ;
                    cin>>copyPassword;
                    if(copyPassword == user_ptr[i].getPassword())
                    {
                        localCounter = 0 ;
                        userMode(user_ptr[i]) ;
                    }
                    else
                    {
                        localCounter-- ;
                        cout<<"Wrong password ( still "<<localCounter<<" tries ) !\n" ;
                    }
                }
                break ;
            }
        }
    }
}// end of login session function


// Admin session fun
void AdminMode(Person Admin)
{
    cout<<"Hello Basem Nagah | Admin View\n" ;
    while(true)
    {
        int AdminChoice ,logout_flag = 0 ;
        cout<<"menu: \n" ;
        cout<<"        1: View Profile\n" ;
        cout<<"        2: Add Book\n" ;
        cout<<"        3: Logout\n" ;
        cout<<"Enter number in range 1-3 : " ;
        cin>>AdminChoice ;
        switch(AdminChoice)
        {
            case 1:
                cout<<"\nName: "<<Admin.getName()<<"\n" ;
                cout<<"Email: "<<Admin.getEmail()<<"\n" ;
                cout<<"User Name: "<<Admin.getUserName()<<"\n\n" ;
                break;

            case 2:
                {
                    Book temp ;
                    temp.setNewBook();
                    book.push_back(temp) ;
                }
                break;
            case 3:
                cout<<"Logout Successfully !\n" ;
                logout_flag = 1 ;
                break;

            default :
                cout<<"Please enter valid number !\n" ;
                break;
        }

        if(logout_flag == 1)break;
    }
}
// end Admin session fun

//sign up
void sign_up_session(void)
{
    Person new_user ;
    string copy_str ;
    cout<<"Enter user name (no spaces): " ;
    cin>>copy_str;
    new_user.setUserName(copy_str);
    cout<<"Enter Password (no spaces): " ;
    cin>>copy_str;
    new_user.setPassword(copy_str);
    cout<<"Enter Name (no spaces): " ;
    cin>>copy_str;
    new_user.setName(copy_str);
    cout<<"Enter Email (no spaces): " ;
    cin>>copy_str;
    new_user.setEmail(copy_str);
    Users.push(new_user) ;
    userMode(new_user);
}//end sign up

//user mode
void userMode(Person user)
{
    cout<<"Hello "<< user.getName()<<" | User View\n" ;
    while(true)
    {
        int userChoice ,logout_flag = 0 ;
        cout<<"menu: \n" ;
        cout<<"        1: View Profile\n" ;
        //cout<<"        2: List & Select from My Reading History\n" ;
        cout<<"        2: List & Select from Available Books\n" ;
        cout<<"        3: Logout\n" ;
        cout<<"Enter number in range 1-3 : " ;
        cin>>userChoice ;
        switch(userChoice)
        {
            case 1:
                cout<<"\nName: "<<user.getName()<<"\n" ;
                cout<<"Email: "<<user.getEmail()<<"\n" ;
                cout<<"User Name: "<<user.getUserName()<<"\n\n" ;
                break;
            case 2:
                {
              //  cout<<"counter = "<<book[0].getBookCounter()<<"\n" ;
                int bookChoice = -1;
                if(book[0].getBookCounter() != 0)
                {
                    cout<<"Our current book collection:\n";
                    for(int i=0 ; i<book[0].getBookCounter() ; i++ )
                    {
                        cout<<"        "<<i+1 <<"- "<<book[i].getBook_name()<<"\n";
                    }
                    while(!(bookChoice>=1 && bookChoice<=book[0].getBookCounter()))
                    {
                        //if(book[0].getBookCounter() == 0)break ;

                        cout<<"Enter Book Number 1 - "<<book[0].getBookCounter()<<" : " ;
                        cin>>bookChoice ;

                    }
                    readSession(book[bookChoice-1]);
                }
                else
                {
                    cout<<"Sorry there is no books now \n";
                }
                }
                break;

            case 3:
                cout<<"Logout Successfully !\n" ;
                logout_flag = 1 ;
                break;

            default :
                cout<<"Please enter valid number !\n" ;
                break;
        }

        if(logout_flag == 1)break;
    }
}//end user mode

//readsession
void readSession(Book choosenBook  )
{
    int readChoice=0 ;
    cout<<"choosen book is : "<<choosenBook.getBook_name();
    int page_index = 0 ;
    while(readChoice != 3)
    {
        if(readChoice == 1)
        {
            if(page_index < choosenBook.getPage_num()-1)
            page_index++;
        }
        else if(readChoice ==2 )
        {
            if(page_index > 0)
            page_index--;
        }
        else
        {   if(readChoice!=0)
            cout<<"Enter valid number !\n";
        }
        cout<<"Current page: "<<page_index+1<<"/"<<choosenBook.getPage_num()<<"\n";
        cout<<char('A'+page_index)<<" "<<choosenBook.getPage(page_index)<<"\n\n" ;
        cout<<"menu:\n";
        if(page_index < choosenBook.getPage_num()-1)
        cout<<"        1: Next Page\n";
        if(page_index > 0)
        cout<<"        2: Previous page\n";
        cout<<"        3: Stop Reading\n\n";
        cout<<"Enter number in range :";
        cin>>readChoice ;

    }

}
