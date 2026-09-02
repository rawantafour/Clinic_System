#include <iostream>
#include <string>
using namespace std ;

string names[200] ;
string phones[200] ;
string bookingtimes[200] ;
bool confirms[200] ;
int last=0 ;

int search (string searchname ,string searchphone)
{
    for(int i=0;i<last;i++)
    {
        if(names[i]==searchname&&phones[i]==searchphone)
        {
            return i ;
        }
    }
    return -1 ;
}
bool add (string name ,string phone , string bookingtime)
{
    int r=search(name ,phone) ;
     if(r>-1)
     {
         return false ;
     }
     else
     {
         names[last]=name ;
         phones[last]=phone ;
         bookingtimes[last]=bookingtime ;
         confirms[last]=false ;
         last++ ;
         return true ;
     }
}
bool deletebooking (string name)
{
    for(int i=0;i<last;i++)
    {
        if (names[i]==name)
        {
          names[i]=names[i+1] ;
          phones[i]=phones[i+1] ;
          bookingtimes[i]=bookingtimes[i+1] ;
          return true ;
        }
    }
    return false ;
}
bool update (string name ,string phone ,string bookingtime)
{
    for(int i=0;i<last;i++)
    {
        if(names[i]==name)
        {
          int x=0 ;
          cout<<"please enter one number "<<endl;
          cout<<"1- name only"<<endl;
          cout<<"2- phone only"<<endl;
          cout<<"3- bookingtime only"<<endl;
          cout<<"4- all information"<<endl;
          cin>> x;
          if(x==1)
          {
              cout<<"please enter name"<<endl;
              cin>> name ;
              names[i]=name ;
          }
          else if(x==2)
          {
             cout<<"please enter phone"<<endl;
             cin>> phone ;
             phones[i]=phone ;
          }
          else if(x==3)
          {
              cout<<"please enter bookingtime "<<endl;
              cin>> bookingtime;
              bookingtimes[i]=bookingtime ;
          }
          else
          {
              cout<<"please enter your information(name ,phone ,bookingtime)"<<endl;
              cin>>name>>phone>>bookingtime ;
              names[i]=name ;
              phones[i]=phone ;
              bookingtimes[i]=bookingtime ;
          }
        }
    }
    return false ;
}
void viewallbooking ()
{
    for(int i=0;i<last;i++)
    {
        cout<<names[i]<<","<<phones[i]<<","<<bookingtimes[i] <<endl;
    }
}
bool confirm (string name ,string phone)
{
    int r=search(name , phone) ;
    if(r>-1)
    {
        if(confirms[r]==true)
        {
         return true ;
        }
        else
        {
            return false ;
        }
    }
    else
    {
        return false ;
    }
}
int main()
{
   int x=0 ;
     while(true)
     {
         cout<<"please enter number from 1 to 7 "<<endl;
         cout<<"1-search"<<endl;
         cout<<"2-add"<<endl;
         cout<<"3-update"<<endl;
         cout<<"4-viewallbooking"<<endl;
         cout<<"5-confirm"<<endl ;
         cout<<"6-deletebooking"<<endl;
         cout<<"7-exist"<<endl;
         cin>> x;
         if(x==1)
         {
             string name;
             string phone ;
             cout<<"please enter name,phone"<<endl;
             cin>>name>>phone;
             int r=search(name ,phone) ;
             if(r>-1)
             {
                 cout<<"booking is found"<<endl;
             }
             else
             {
                 cout<<"booking is not found "<<endl;
             }
         }
         else if(x==2)
         {
             string name ;
             string phone ;
             string bookingtime ;
             cout<<"please enter name,phone,bookingtime"<<endl;
             cin>>name>>phone>>bookingtime;
             bool r=add(name ,phone ,bookingtime) ;
               if(r==1)
               {
                   cout<<"added successflly"<<endl ;
               }
               else
               {
                   cout<<"daplicated"<<endl ;
               }
         }
         else if(x==3)
         {
             string name ;
             string phone ;
             string bookingtime ;
             cout<<"please enter name,phone,bookingtime"<<endl;
             cin>>name>>phone>>bookingtime ;
             bool r=update(name,phone,bookingtime) ;
             if(r==1)
             {
                 cout<<"updated successflly"<<endl;
             }
             else
             {
                 cout<<"name is not found"<<endl;
             }

         }
         else if(x==4)
         {
             viewallbooking() ;
         }
         else if(x==5)
         {
             string name ;
             string phone ;
             cout<<"please enter name,phone"<<endl;
             cin>>name>>phone;
             bool r=confirm(name,phone) ;
             if(r==1)
             {
                 cout<<"booking is confirm"<<endl;
             }
             else
             {
                cout<<"booking is not confirm"<<"or"<<"name is not found"<<endl;
             }
         }
         else if(x==6)
         {
                 string name ;
                 cout<<"please enter name"<<endl;
                 cin>>name;
                 bool r=deletebooking(name) ;
                   if(r==1)
                   {
                       cout<<"daleded successfully "<<endl;
                   }
                   else
                   {
                       cout<<" deleted unsuccessfully"<<endl;
                   }

         }
         else
         {
            cout<<"goodbay"<<endl;
         }
         }
}
