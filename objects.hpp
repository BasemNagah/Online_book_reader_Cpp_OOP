#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <vector>
using namespace std ;
//class person
class Person
{
    string user_name ;
    string name ;
    string email ;
    string password ;
    static int counter ;


protected :
    bool isAdmin = false ;

public:
    Person()
    {
        counter++ ;
    }
    void setUserName(string) ;
    void setName(string) ;
    void setEmail(string) ;
    void setPassword(string) ;
    void setadmin(bool) ;

    string getUserName() ;
    string getName() ;
    string getEmail() ;
    string getPassword() ;
    bool getrole () ;

    static int getCounter()
    {
        return counter;
    }

};



// stack
class Stack
{
    int top_stack ;
    Person* s_ptr  ;

public:

    Stack()
    {
        top_stack = 0;
        s_ptr = new Person[100] ;
    }
    ~Stack()
    {
        delete []s_ptr ;
    }

    void push(Person) ;
    Person pop();
    Person* returnPointerUsers() ;
int getTopStack()
     {
        return top_stack;
     }


};

class Book
{
    string ISBN ;
    string book_name  ;
    string author_name ;
    int num_pages ;
    vector <string> pages ;
    static int book_counter ;

public:
    Book()
    {
        book_counter++ ;
    }

    void setISBN(string);
    void setBook_name(string);
    void setAuthor_name(string);
    void setNewBook();

    string getISBN();
    string getBook_name();
    string getAuthor_name();
    string getPage(int page_num);
    static int getBookCounter() ;
    int getPage_num()
    {
        return num_pages ;
    }

};

#endif // OBJECTS_HPP
