    #include"objects.hpp"

    //set parameters
    int Person::counter = 0;

    void Person::setUserName(string user_name)
    {
        this->user_name = user_name ;
    }

    void Person::setName(string name)
    {
        this->name = name ;
    }

    void Person::setEmail(string email)
    {
        this->email = email ;
    }

    void Person::setPassword(string password)
    {
        this->password = password ;
    }

    void Person::setadmin(bool isAdmin)
    {
        this->isAdmin = isAdmin ;
    }


    //get parameters
    string Person::getUserName()
    {
        return user_name;
    }

    string Person::getName()
    {
        return name ;
    }
    string Person::getEmail()
    {
        return email ;
    }
    string Person::getPassword()
    {
        return password ;
    }

    bool Person::getrole ()
    {
        return isAdmin ;
    }



    void Stack::push(Person newUser)
    {
        s_ptr[top_stack] = newUser ;
        top_stack++ ;
    }

    Person Stack::pop()
    {
        return (s_ptr[--top_stack]) ;
    }

    Person* Stack::returnPointerUsers()
    {
        return s_ptr ;
    }


    int Book::book_counter = 0 ;
    void Book::setISBN(string ISBN)
    {
        this->ISBN = ISBN ;
    }
    void Book::setBook_name(string book_name)
    {
        this->book_name = book_name ;
    }
    void Book::setAuthor_name(string author_name)
    {
        this->author_name = author_name ;
    }
    void Book::setNewBook()
    {
        string str ;
        cout<<"Enter ISBN: " ;
        cin>>str ;
        setISBN(str) ;
        cout<<"Enter Title: " ;
        cin>>str ;
        setBook_name(str) ;
        cout<<"Enter Author Name: " ;
        cin>>str ;
        setAuthor_name(str) ;
        cout<<"Enter How many pages: " ;
        cin>>num_pages ;
        for(int i=0 ;i<num_pages ;i++)
        {
            cout<<"Enter page # "<<i+1<<": " ;
            cin>>str ;
            pages.push_back(str) ;
        }

    }

    string Book::getISBN()
    {
        return ISBN;
    }
    string Book::getBook_name()
    {
        return book_name;
    }
    string Book::getAuthor_name()
    {
        return author_name;
    }
    string Book::getPage(int page_num)
    {
        return (this->pages[page_num]) ;
    }

    int Book::getBookCounter()
    {
        return book_counter ;
    }

