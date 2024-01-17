#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "objects.hpp"
#include "config.hpp"

extern Stack Users ;

void login_session(void);

void AdminMode(Person Admin) ;
void sign_up_session(void) ;
void userMode(Person user) ;

void readSession(Book choosenBook);



#endif // INTERFACE_HPP
