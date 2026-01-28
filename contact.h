#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;                         // Structure to hold contact details, nickname Contacts

typedef struct AddressBook_Data
{
    Contacts contact_details[100]; //array of contacts
    int contact_count;             //number of contacts stored
} AddressBook;              // Structure to hold address book details  , nickname AddressBook

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int load_contact(AddressBook *);

//FUNCTION 
// Validation functions
int name_validation(char *name);
int phone_number_validation(char *phone_no,AddressBook *);
int mail_id_validation(char * Email_ID,AddressBook *);
// Search functions
void only_search_by_name(AddressBook *name);
void only_search_by_phone_number(AddressBook *phone_no);
void only_search_by_Email_ID(AddressBook *Email_ID);
//Search and edit
int Search_by_name_and_Edit(AddressBook *name);
int Search_by_phone_number_and_Edit(AddressBook *phone_no);
int Search_by_Email_ID_and_Edit(AddressBook *Email_ID);
//Delete functions
int Search_by_name_and_Delete(AddressBook *addressbook);
int Search_by_phone_number_and_Delete(AddressBook *addressbook);
int Search_by_Email_ID_and_Delete(AddressBook *addressbook);

#endif // CONTACT_H
       // CONTACT_H