#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
#include <ctype.h>
void sortbyname(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)//loop runs up to no.of contacts-1 times
    {
        for(int j=0;j<addressBook->contactCount-1-i;i++)//first contact to contact count-1-i times
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)//compares the adjacent of two contacts 
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];//if j is greater than j+1 swap two contacts
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}
void sortbyphone(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)//loop runs up to no.of contacts-1 times
    {
        for(int j=0;j<addressBook->contactCount-1-i;j++)//first contact to contact count-1-i times
        {
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)//compares the adjacent of two contacts
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];//if j is greater than j+1 swap two contacts
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}
void sortbyemail(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)//loop runs up to no.of contacts-1 times
    {
        for(int j=0;j<addressBook->contactCount-1-i;i++)//first contact to contact count-1-i times
        {
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)//compares the adjacent of two contacts
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];//if j is greater than j+1 swap two contacts
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    char name[50],phone[20],email[50];
    
    switch(sortCriteria)

    {
        case 1:
        
            sortbyname(addressBook);//sort contacts by name
            printf("1.name\t2.phone\t3.email\n");
            for(int i=0;i<addressBook->contactCount;i++)
            {
                printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            break;
        case 2:
        
            sortbyphone(addressBook);//sort contacts by phone
            printf("1.name\t2.phone\t3.email\n");
            for(int i=0;i<addressBook->contactCount;i++)
            {
                printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            break;
        case 3:
        
            sortbyemail(addressBook);//sort contacts by email
            printf("1.name\t2.phone\t3.email\n");
            for(int i=0;i<addressBook->contactCount;i++)
            {
                printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            break;
    }

}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
     void sortbyname(AddressBook *addressBook);
     void sortbyphone(AddressBook *addressBook);
     void sortbyemail(AddressBook *addressBook);

}

void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
Contact addcontact;
int isvalidname(char *name)
{
    for(int i=0;i<strlen(name);i++)
    {
        if(!isalpha(name[i])&& name[i]!=' '&&name[i]!='.') //name should contain alphabets or space or'.'
        {
             return 0;
        } 
    }
    return 1;
}
int isvaliddigit(char *digitphone)
{
    if(!isdigit)
    {
        return 0;
    }
   return 1;
}
int isvalidphone(char *phone)
{
    if(strlen(phone)!=10)//phone number should have 10 characters.
    {
       return 0;
    }
    for(int i=0;i<strlen(phone);i++)
     {
         if(!isdigit(phone[i]))//it should be only digits.
         {
             return 0;
         }
     }
     return 1;
}
//phone number is unique
int isuniquephone(AddressBook *addressBook,char *phone)
{ 
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)//number should unique in the addressbook
        {
            return 0;//duplicate found
        }
    }
    return 1;
}
int isvalidemail(char *email)
{
    char *at = strchr(email, '@');
    char *dot = strrchr(email, '.');
    if (at && dot && at < dot && dot > at + 1 && dot[1] != '\0' && strlen(dot) <= 4)//the email address contains both @ and .
    {
        return 1;
    }
    return 0;
}
int isuniqueemail(AddressBook *addressBook,char *email)
{
    for(int i=0;i<addressBook->contactCount;i++)
     {
        if(strcmp(addressBook->contacts[i].email,email)==0)//email should be unique in the addressbook
        {
            return 0;//email already exists
        }
    }
    return 1;//unique email
}
void createContact(AddressBook *addressBook)                                                                                                                                                                                                                                                                                                                                                                                                                                                            
{
    int count=0;
    if(addressBook->contactCount<MAX_CONTACTS)
    {
        Contact addcontact;
        while(1)//loop runs until valid name entered
        {
            printf("Enter the user name:");
            scanf(" %[^\n]",addcontact.name);
            if(isvalidname(addcontact.name))
            {
                break;
            }
            else
            {
                printf("Invalid name.Please enter valid name ❌❌.\n");
            }
        }
        while(1)//loop runs until valid name entered
        {
            printf("Enter user phone number:");
            scanf(" %[^\n]",addcontact.phone);
            if(isvalidphone(addcontact.phone) && isuniquephone(addressBook,addcontact.phone))
            {
                break;
            }
            else if(!isvalidphone(addcontact.phone))
            {
                printf("Invalid phone number.Please enter valid phone number❌\n");
            }
            else
            {
                printf("This number is already exists please enter unique phone number!!...\n");
            }
        }
        while(1)
        {
            printf("Enter user email:");
            scanf(" %[^\n]",addcontact.email);//read mail from the user 
            if(isuniqueemail(addressBook,addcontact.email) && isvalidemail(addcontact.email))
            {
               break;
            }
            else if(!isvalidemail(addcontact.email))
            {
                printf("invalid email ❌");
            }
            else if(!isuniqueemail(addressBook,addcontact.email))
            {
                printf("This email is already exists.please enter a unique email id\n");
            }
            
        }
        printf("Contact added successfully‼️ ...\n");
        addressBook->contacts[addressBook->contactCount++]=addcontact;
    }
    else
    {
        printf("address book is full:\n");
        return;
    }
    
}
void searchContact(AddressBook *addressBook) 
{
    Contact addcontact;
    if(addressBook->contactCount==0)//check if addressbook is empty
    {
       printf("Contact was not found!!!");
       return;
    }
   int option;
   printf("Enter the option 1.name 2.phone 3.gmail:\n");
   scanf("%d",&option);
   int found=0,count=0;
   int i;
   int index[100];//declare index array
   switch(option)
   {
        case 1:
            //char searchname[100]
            printf("Enter the name:");
            scanf(" %[^\n]",addcontact.name);//read the search name from the user
            if(isvalidname(addcontact.name))//check if name is valid or not
            {
                printf("Index\t Name\t phone\t email\n");
                 for(i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the addressbook
                {
                    if (strstr(addressBook->contacts[i].name, addcontact.name)!=NULL)//checks if name matches
                    {
                        index[count] = i;//stores the index of matching contact
                        printf("%d\t %s\t %s\t %s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        count++;
                        found=1;
                    }
                }
                if(!found)//check if no match found
                {
                     printf("contact not found");
                     return;
                }
            }
            else
            {
               printf("Invalid name.please enter valid name\n");
               //return;//exit from the function
            }
        
            break;
        case 2:
            char searchphone[60];
            printf("Enter phone number: ");
            scanf(" %[^\n]",searchphone);//prompt the user to enter phone number
            if(isvaliddigit(searchphone))//check if number is valid or not
            {
                printf("Index\t Name\t phone\t email\n");
                for(i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the addressbook
                {
                     if(strcasestr(addressBook->contacts[i].phone,searchphone)!=NULL)//check if phone number matches
                    {
                          index[count] = i;//store the index of matching contact
                          printf("contact found\n");
                          printf("%d\t  %s\t   %s\t   %s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                          count++;
                          found=1; 
                          break;
                    }
                }
            
            }
            else
            {
                printf("Invalid phone number.please enter valid phone number");
            }
            if(!found)//check if no match found
            {
                printf("contact not found\n");
            }
            break;
        case 3:
       
            char searchemail[80];
            printf("Enter email: ");
            scanf(" %[^\n]",searchemail);//prompt the user to enter email
            if(isvalidemail(searchemail))//check if email is valid or not
            {
                printf("Index\t Name\t phone\t email\n");
                for(i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the addressbook
                {
                    if(strcasestr(addressBook->contacts[i].email,searchemail)!=NULL)//check if search email matches with the email present in the addressbook
                    {
                        index[count++] = i;//store the index of matching contacts
                        printf("%d\t %s\t %s\t  %s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        found=1;
                        break;
                    }
                }
            }
            else
            {
                printf("Invalid email!!!..please enter valid email\n");
            }
            if(!found)//if not found
            {
                printf("contact not found");
            }
           break;
        default:
            printf("Invalid option\n");
            return;
    }
}
void editContact(AddressBook *addressBook)
{
    int option,i,j,index[100],count=0,found=0,searchindex;
   printf("1.name 2.phone 3.email\n ");
    printf("Enter the option:");
    scanf("%d",&option);
    switch(option)
    {
        case 1://edit by name
            char searchname[50];
            printf("Enter name you want to edit:");
            scanf(" %[^\n]",searchname);//prompt the user to read the name
            //printf("same contact details");
            printf("index\t name\t phone\t email\n");
            if(isvalidname(searchname))//check if name is valid or not
            {
                 for(i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the addressbook
                {
                    if (strcasestr(addressBook->contacts[i].name, searchname) != NULL)//check if name matches or not
                    {
                        index[count] = i;//store the index of matching contacts
                        printf("%d\t%s\t%s\t%s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        count++;
                        found=1;
                    }

                }
                if(!found)
                {
                    printf("no name found❌❌\n");
                    return;
                }
            
                printf("select which index you want to edit:");
                scanf("%d",&searchindex);//prompt the user to select the search index
                printf("enter what you want to edit\n");
                printf("1.name\t 2.phone\t 3.email\n");
                scanf("%d",&option);
                j=index[searchindex-1];//get index of contact to edit
            if(option==1)//edit name
            {
                char newname[50];
                printf("Enter new name");
                scanf(" %[^\n]",newname);
                if(isvalidname(newname))
                {
                    strcpy(addressBook->contacts[j].name,newname);//update newname
                    printf("name updated succesfully👍\n");
                }
                else
                {
                    printf("invalid name.please enter valid name");
                }
            }
            else if(option==2)//edit phone number
            {
                char newphone[20];
                printf("Enter new phone number:");
                scanf(" %[^\n]",newphone);//prompt the user to enter new name
                if(isvalidphone(newphone)&&isuniquephone(addressBook,newphone))//check if new phone number is valid and unique
                {
                    strcpy(addressBook->contacts[j].phone,newphone);
                    printf("phone number updated successfully 📞\n");
                }
                else
                {
                    printf("invalid phone number please enter valid phone number\n");
                }
            }
            else if(option==3)
            {
                char newemail[60];
                printf("Enter new email:");
                scanf(" %[^\n]",newemail);//prompt the user to enter new email
                if(isvalidemail(newemail)&&isuniqueemail(addressBook,newemail))//new wmail is valid and unique
                {
                    strcpy(addressBook->contacts[j].email,newemail);//update new email
                    printf("email updated successfully💌'\n");
                }
                else
                {
                    printf("invalid email!! please enter valid email⛔\n");
                }
            }
            }
            break;
        case 2:
            char searchphone[30];
            printf("Enter phone number you want to edit:");
            scanf(" %[^\n]",searchphone);//prompt the user to enter search phone number
            printf("1.name\t 2.phone\t 3.email\n");
           if(isvalidphone(searchphone))//search phone number is valid or not
           {
               for(i=0;i<addressBook->contactCount;i++)//loop runrs up to no.of contacts present in the addressbook
               {
                   if(strstr(addressBook->contacts[i].phone,searchphone)!=NULL)//check if number matches or not
                   {
                       index[count]=i;//store the index of matching contact
                        printf("%d\t%s\t%s\t%s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        count++;
                        found=1;
                    }
                }
                if(count==0)
                {
                    printf("no name found!!!\n");
                    return;
                }
            printf("enter what you want to edit\n");
            printf("1.name\t 2.phone\t 3.email\n");
            scanf("%d",&option);
            if(option==1)//edit name
            {
                char newname[50];
                printf("Enter new name");
                scanf(" %[^\n]",newname);//prompt the user to enter new name
                if(isvalidname(newname))//check if name is valid or not
                {
                    strcpy(addressBook->contacts[j].name,newname);//update new name
                    printf("name updated succesfully\n");
                }
                else
                {
                    printf("invalid name.please enter valid name");
                }
            }
            else if(option==2)//edit  phone number
            {
                char newphone[20];
                printf("Enter new phone number:");
                scanf(" %[^\n]",newphone);//prompt the user to read the phone number
                if(isvalidphone(newphone)&&isuniquephone(addressBook,newphone))//chaeck if number is valid or not
                {
                    strcpy(addressBook->contacts[j].phone,newphone);//update new phone number
                    printf("phone number updated successfully✅\n");
                }
                else
                {
                    printf("invalid phone number please enter valid phone number\n");
                }
            }
            else if(option==3)//edit email
            {
                char newemail[60];
                printf("Enter new email:");
                scanf(" %[^\n]",newemail);//prompt the user to read email
                if(isvalidemail(newemail)&&isuniqueemail(addressBook,newemail))//check if email is valid or not
                {
                    strcpy(addressBook->contacts[j].email,newemail);//update new email
                    printf("email updated successfully✅\n");
                }
                else
                {
                    printf("invalid email please enter valid email!!❌\n");
                }
            }
            }
            else
            {
                printf("invalid name");
            }
            break;
        case 3:
            char searchemail[40];
            printf("Enter email you want to edit:");
            scanf(" %[^\n]",searchemail);//prompt the user to read searchemail
            printf("index\t name\t phone\t email\n");
            if(isvalidemail(searchemail))//chaeck if search email is valid or not
            {
                 for(i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the addressbook
                {
                    if (strstr(addressBook->contacts[i].email, searchemail) != NULL)//check if email matche or not
                    {
                        index[count] = i;//store the index of matching contact
                        printf("%d\t%s\t%s\t%s\t",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        count++;
                        found=1;
                    }
                }
                if(!found)
                {
                     printf("email not found");
                }
            }
            char newname[50];
            //printf("select which index you want to edit:");
            //scanf("%d",&searchindex);
            printf("enter what you want to edit:");
            scanf("%d",&option);
            printf("1.name\t 2.phone\t 3.email\n");
            //j=index[searchindex-1];//get index of edit contact
            if(option==1)
            {
                printf("Enter new name");
                scanf(" %[^\n]",newname);//prompt the user to read new name
                if(isvalidname(newname))//check if newname is valid or not
                {
                    strcpy(addressBook->contacts[j].name,newname);//update new name
                    printf("name updated succesfully\n");
                }
                else
                {
                    printf("invalid name.please enter valid name\n");
                }
            }
            else if(option==2)
            {
                char newphone[20];
                printf("Enter new phone number\n");
                scanf(" %[^\n]",newphone);//prompt the user to read new phone number
                if(isvalidphone(newphone)&&isuniquephone(addressBook,newphone))//check if number is valid or not
                {
                    strcpy(addressBook->contacts[j].phone,newphone);//update new phone number
                    printf("phone number updated successfully\n");
                }
                else
                {
                    printf("invalid phone number please enter valid phone number\n");
                }
            }
            else if(option==3)
            {
                char newemail[60];
                printf("Enter new email\n");
                scanf(" %[^\n]",newemail);//prompt the user to read newemail
                if(isvalidemail(newemail)&&isuniqueemail(addressBook,newemail))//check if email is valid or not
                {
                    strcpy(addressBook->contacts[j].email,newemail);//update new email
                    printf("email updated successfully\n");
                }
                else
                {
                    printf("invalid email  please enter valid email\n");
                }
            }  
             break;
        default:
        {
            printf("Invalid option:");
            return;
        }
    }
}
void deleteContact(AddressBook *addressBook)
{
    char name[50],phone[30],email[60];
    int choice,found=0,i,j,index[100],searchindex,count=0;
    char del;
    printf("Enter your option what you want to delete: 1.name 2.phone 3.email: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter name to delete:");
       getchar();
        scanf("%[^\n]",name);//prompt the user to read the name
        if(isvalidname(name))//check if name is valid or not
        {
            printf("Index\t    Name\t     Phone\t     email\n");
            
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strstr(addressBook->contacts[i].name,name)!=NULL)//check if the name is present in the addressbook or not
                {
                    index[count]=i;//store the index of matcing contacts
                    printf("%d\t %s\t %s\t %s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    count++;
                    found=1;
                }
            }
            if(found)
            {
                 printf("select which index you want to delete:");
                 scanf(" %d",&searchindex);//prompt the user which index you want to delete
                printf("Do you want to delete the contact(y/n):");
                getchar();
                scanf("%c",&del);
                if(del=='y' || del=='Y')
                {
                    int i = index[searchindex-1];
                  for(int j=i;j<addressBook->contactCount-1;j++)
                  {
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                  }
                  printf("contact deleted successfully\n");
                  addressBook->contactCount--;
                  return;
                 }
                else
               {
                printf("Contact not deleted");
               }
               
            }
            else
           {
               printf("contact not found\n");   
           }
           
        }
        else
        {
            printf("invalid name please enter valid name\n");
            return;
        }
        break;
        case 2:
        printf("Enter the phone number to delete:");
        getchar();
        scanf("%[^\n]",phone);//prompt the user to read the number
        if(isvalidphone(phone))//check if number is valid or not
        {
            printf("Index\tName\tPhone\temail\n");
            for(int i=0;i<addressBook->contactCount;i++)//loop runs up to number of contacts present in the addressbook
            {
                if(strstr(addressBook->contacts[i].phone,phone)!=NULL)//check if phone number is matching with the addressbook contacts
               {
                    index[count]=i;//store the index of matching contacts
                    printf("%d\t%s\t%s\t%s\n",count+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    count++;
                    found=1;
               }
            }
            if(found)
            {
                    printf("select which index you want to delete:");
                     scanf("%d",&searchindex);
                    printf("Do yo want to delete the contact(y/n):");
                    getchar();
                    scanf("%c",&del);
                   if(del=='y' || del=='Y')
                    {
                      for(int j=i;j<addressBook->contactCount-1;j++)//loop runs up to no.of contacts present the addressbook
                      {
                           addressBook->contacts[j]=addressBook->contacts[j+1];//
                       }
                       addressBook->contactCount--;//decrement the contact count
                       printf("Contact deleted successfully: ");
                       break;
                    }
                     else
                    {
                       printf("contact not deleted\n");
                    }
            }
            else
            {
               printf("contact not found\n");
            }
        }
        else
        {
            printf("Invalid phone number please enter valid phone number\n");
            return;
            
        }
        break;
        case 3:
        printf("Enter the email to detete:");
        getchar();
        scanf("%[^\n]",email);//prompt the user to read the email
        if(isvalidemail(email))//check if email is valid or not
        {
            printf(" Index\t    name\t    phone\t     email\t");
            for(int i=0;i<addressBook->contactCount;i++)//loop runs up to no.of contacts present in the b
            {
               if(strstr(addressBook->contacts[i].email,email))//check if entered email is present in the address book or not
               {
                    index[count]=i;//store the index of matching contact
                    printf("%d\t    %s\t    %s\t   %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    count++;
                    found=1;
               }
            }
            if(found)
            {
                    printf("select which index you want to delete:");
                    scanf(" %d",&searchindex);
                    printf("Do you want to delete the contact(y/n):");
                    getchar();
                    scanf("%c",&del);
                   if(del=='y'|| del=='Y')
                    {
                       for(int j=0;j<addressBook->contactCount-1;j++)//loop runs up to no.of contacts present in the addressbook
                       {
                           addressBook->contacts[j]=addressBook->contacts[j+1];
                        }
                         addressBook->contactCount--;//decrement the contact count
                        printf("Contact deleted successfully\n");
                        break;
                    }
                    else
                   {
                       printf("contacts not deleted:");
                    }
            }
            else
            {
                printf("email not found\n");
            }
        }
        else
        {
            printf("Invalid email please enter valid email\n");
            return;
        }
    }
}   //default
       
    


   

