#include <stdio.h>
#include <string.h>  // for strcpy , strlen functions
#include <ctype.h>   // for isupper, islower, isdigit functions
#include "contact.h" // Including header file
#ifndef COLORS_H
#define COLORS_H
/* Text colors */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#endif

// Function Definitions
// Function to create a contact
int create_contact(AddressBook *addressbook)
{
    char name[32];
    char phone_no[11];
    char Email_ID[35];
    int flag;
    ADD_CONTACT:

    printf(GREEN"\n╔══════════════════════════════════════╗\n");
    printf("║           CREATE NEW CONTACT         ║\n");
    printf("╚══════════════════════════════════════╝\n"RESET);

    /* NAME INPUT */
    do
    {
        flag = 0;
        printf("📛 Enter Name           : ");
        scanf(" %[^\n]", name);
        flag = name_validation(name);
    } while (flag == 0);

    strcpy(addressbook->contact_details[addressbook->contact_count].Name, name);

    /* MOBILE NUMBER INPUT */
    do
    {
        flag = 0;
        printf("📞 Enter Mobile Number  : ");
        scanf("%s", phone_no);
        flag = phone_number_validation(phone_no, addressbook);
    } while (flag == 0);

    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number, phone_no);

    /* EMAIL ID INPUT */
    do
    {
        flag = 0;
        printf("📧 Enter Email ID       : ");
        scanf("%s", Email_ID);
        flag = mail_id_validation(Email_ID, addressbook);
    } while (flag == 0);

    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID, Email_ID);

    addressbook->contact_count++;

    printf(GREEN"\n✅ Contact added successfully!\n"RESET);
    printf("═══════════════════════════════════════\n");

    add_contact_menu:
    int add_contact;

    printf(BLUE"\n╔══════════════════════════════════════╗\n");
    printf("║       ADD NEW CONTACT MENU           ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. Create New Contact               ║\n");
    printf("║  2. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n"RESET);
    printf("Enter your choice: ");

    scanf("%d", &add_contact);

    switch (add_contact)
    {
        case 1:
            goto ADD_CONTACT;
        
        case 2:
            printf("\nExiting Add Contact Menu...\n");
            return 0;

        default:
            printf(RED"\n❌ Invalid choice! Please try again.\n"RESET);
            goto add_contact_menu;
    }
}
// Function to list all contacts
void list_contacts(AddressBook *addressbook)
{
    int i;

    if (addressbook->contact_count == 0)
    {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║          CONTACT LIST EMPTY          ║\n");
        printf("╚══════════════════════════════════════╝\n");
        return;
    }

    printf(YELLOW"╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                      CONTACT DETAILS                                               ║\n");
    printf("╠════╦══════════════════════════════════════╦════════════════════╦═══════════════════════════════════╣\n");
    printf("║ No ║ Name                                 ║ Mobile Number      ║ Email ID                          ║\n");
    printf("╠════╬══════════════════════════════════════╬════════════════════╬═══════════════════════════════════╣\n");

    for (i = 0; i < addressbook->contact_count; i++)
    {
        printf(
            "║ %-2d ║ %-36.36s ║ %-18.18s ║ %-33.33s ║\n",
            i + 1,
            addressbook->contact_details[i].Name,
            addressbook->contact_details[i].Mobile_number,
            addressbook->contact_details[i].Mail_ID
        );
    }

    printf("╚════╩══════════════════════════════════════╩════════════════════╩═══════════════════════════════════╝\n"RESET);
}

// Function to search a contact
int search_contacts(AddressBook *addressbook)
{
    int option;
    RETRY_INDEX:
    while (1)
    {
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          SEARCH CONTACT MENU         ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Search by Name                   ║\n");
        printf("║  2. Search by Mobile Number          ║\n");
        printf("║  3. Search by Email ID               ║\n");
        printf("║  4. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");

        scanf("%d", &option);
        getchar(); // clear newline

        switch (option)
        {
        case 1:
            only_search_by_name(addressbook);
            break;

        case 2:
            only_search_by_phone_number(addressbook);
            break;

        case 3:
            only_search_by_Email_ID(addressbook);
            break;

        case 4:
            printf("\n🔙 Returning to main menu...\n");
            return 0;

        default:
            printf(RED"\n❌ Invalid option! Please try again.\n"RESET);
            goto RETRY_INDEX;
        }
    }
    return 1;
}
// Function to edit a contact
int edit_contact(AddressBook *addressbook)
{
    char name[32];
    char phone_no[11];
    char Email_ID[35];
    int flag = 0;
    int option;
    int index = -1;
    RETRY_INDEX_EDIT:
    while (1)
    {
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          SEARCH CONTACT MENU         ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Search by Name                   ║\n");
        printf("║  2. Search by Mobile Number          ║\n");
        printf("║  3. Search by Email ID               ║\n");
        printf("║  4. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");
        scanf("%d", &option);
        getchar(); // to consume the newline character left by scanf

        switch (option)
        {
        case 1:
        {
            // implementation for Name search
            index = Search_by_name_and_Edit(addressbook);

            break;
        }
        case 2:
        {
            // implementation for Mobile number search
            index = Search_by_phone_number_and_Edit(addressbook);
            break;
        }
        case 3:
        {
            // implementation for Mail ID search
            index = Search_by_Email_ID_and_Edit(addressbook);
            break;
        }
        case 4:
        {
            printf("\n🔙 Returning to main menu...\n");
            return 0;
        }
        default:
        {
            printf(RED"Invalid option.\n"RESET);
            goto RETRY_INDEX_EDIT;
        }
        }
        if (index == -1)
        {
            return 0; // contact not found
        }
        RETRY_INDEX_EDIT_1:
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          EDIT CONTACT MENU           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. EDIT Name                        ║\n");
        printf("║  2. EDIT Mobile Number               ║\n");
        printf("║  3. EDIT Email ID                    ║\n");
        printf("║  4. EDIT All Details                 ║\n");
        printf("║  5. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            do
            {
                flag = 0;
                printf("📛 Enter New Name           : ");
                scanf(" %[^\n]", name);
                flag = name_validation(name);

            } while (flag == 0);
            strcpy(addressbook->contact_details[index].Name, name);
            break;

        case 2:

            do
            {
                flag = 0;
                printf("📞 Enter New Mobile Number  : ");
                scanf("%s", phone_no);
                flag = phone_number_validation(phone_no, addressbook);
            } while (flag == 0);

            strcpy(addressbook->contact_details[index].Mobile_number, phone_no);
            break;

        case 3:
            do
            {
                flag = 0;
                printf("📧 Enter Email ID       : ");
                scanf("%s", Email_ID);
                flag = mail_id_validation(Email_ID, addressbook);
            } while (flag == 0);
            strcpy(addressbook->contact_details[index].Mail_ID, Email_ID);
            break;

        case 4:
            /* NAME INPUT */
            do
            {
                flag = 0;
                printf("📛 Enter Name           : ");
                scanf(" %[^\n]", name);
                flag = name_validation(name);
            } while (flag == 0);

            strcpy(addressbook->contact_details[index].Name, name);

            /* MOBILE NUMBER INPUT */
            do
            {
                flag = 0;
                printf("📞 Enter Mobile Number  : ");
                scanf("%s", phone_no);
                flag = phone_number_validation(phone_no, addressbook);
            } while (flag == 0);

            strcpy(addressbook->contact_details[index].Mobile_number, phone_no);

            /* EMAIL ID INPUT */
            do
            {
                flag = 0;
                printf("📧 Enter Email ID       : ");
                scanf("%s", Email_ID);
                flag = mail_id_validation(Email_ID, addressbook);
            } while (flag == 0);

            strcpy(addressbook->contact_details[index].Mail_ID, Email_ID);

            break;

        case 5:
            printf("\n🔙 Returning to main menu...\n");
            return 0;

        default:
            printf(RED"\n❌ Invalid choice! Please try again.\n"RESET);
            goto RETRY_INDEX_EDIT_1;
        }

        printf(GREEN"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                ✅ CONTACT EDITED SUCCESSFULLY               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);

    }
}
// Function to delete a contact
int delete_contact(AddressBook *addressbook)
{

    int option;
    int index = -1;
    RETRY_INDEX:
    while (1)
    {
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          SEARCH CONTACT MENU         ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Search by Name                   ║\n");
        printf("║  2. Search by Mobile Number          ║\n");
        printf("║  3. Search by Email ID               ║\n");
        printf("║  4. Exit                             ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");

        scanf("%d", &option);
        getchar(); // clear newline

        switch (option)
        {
        case 1:
            index = Search_by_name_and_Delete(addressbook);
            break;

        case 2:
            index = Search_by_phone_number_and_Delete(addressbook);
            break;

        case 3:
            index = Search_by_Email_ID_and_Delete(addressbook);
            break;

        case 4:
            printf("\n🔙 Returning to main menu...\n");
            return 0;

        default:
            printf(RED"\n❌ Invalid option! Please try again.\n"RESET);
            goto RETRY_INDEX;
        }

        if (index == -1)
        {
            printf(RED"\n❌ Contact not found. Deletion failed.\n"RESET);
            goto RETRY_INDEX;
        }

        /* DELETE LOGIC (Shift Records) */
        for (int i = index; i < addressbook->contact_count - 1; i++)
        {
            addressbook->contact_details[i] = addressbook->contact_details[i + 1];
        }

        addressbook->contact_count--;

        printf(GREEN"╔══════════════════════════════════════╗\n");
        printf("║    ✅ CONTACT DELETED SUCCESSFULLY   ║\n");
        printf("╚═══════════════════════════════════════╝\n"RESET);
    }
    int save_contacts(AddressBook *addressbook);
}
// Function to save contacts to a file
int save_contacts(AddressBook *addressbook)
{
    FILE *fptr;
    int i;

    fptr = fopen("contact_data_base.txt", "w");

    if (fptr == NULL)
    {
        printf(RED"\n❌ ERROR: Unable to open contact database file!\n"RESET);
        return 0;
    }

    fprintf(fptr, "#%d\n", addressbook->contact_count);

    for (i = 0; i < addressbook->contact_count; i++)
    {


        fprintf(fptr, "%s,%s,%s\n",
                addressbook->contact_details[i].Name,
                addressbook->contact_details[i].Mobile_number,
                addressbook->contact_details[i].Mail_ID);
    }

    fclose(fptr);

    printf(GREEN"\n╔══════════════════════════════════════╗\n");
    printf("║     💾 CONTACTS SAVED SUCCESSFULLY   ║\n");
    printf("║   File : contact_data_base.txt       ║\n");
    printf("╚══════════════════════════════════════╝\n"RESET);

    return 0;
}
// Load contact
int load_contact(AddressBook *addressbook)
{
    FILE *fptr;
    int i;

    fptr = fopen("contact_data_base.txt", "r");

    if (fptr == NULL)
    {
        printf("\n⚠️  No existing contact database found.\n");
        printf("📂 Starting with an empty address book.\n");
        addressbook->contact_count = 0;
        return 0;
    }

    fscanf(fptr, "#%d\n", &addressbook->contact_count);

    for (i = 0; i < addressbook->contact_count; i++)
    {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
               addressbook->contact_details[i].Name,
               addressbook->contact_details[i].Mobile_number,
               addressbook->contact_details[i].Mail_ID);
    }

    fclose(fptr);

    printf(GREEN"\n╔══════════════════════════════════════╗\n");
    printf("║     📂 CONTACTS LOADED SUCCESSFULLY  ║\n");
    printf("║   Total Contacts : %-3d               ║\n", addressbook->contact_count);
    printf("╚══════════════════════════════════════╝\n"RESET);

    return 0;
}
// Name validation function
int name_validation(char *name)
{
    int i = 0, count = 0;

    if (name[0] == '\0')
    {
        printf(RED"❌ Name cannot be empty. Please enter a valid name.\n"RESET);
        return 0;
    }

    while (name[i] != '\0')
    {
        if (isupper(name[i]) || islower(name[i]) || name[i] == ' ')
        {
            if (isupper(name[i]) || islower(name[i]))
                count++; // count only alphabets
        }
        else if (isdigit(name[i]))
        {
            printf(RED"❌ Invalid Name!\n");
            printf("➡ Name should NOT contain digits. Please try again.\n"RESET);
            return 0;
        }
        else
        {
            printf(RED"❌ Invalid Name!\n");
            printf("➡ Name should NOT contain special characters. Please try again.\n"RESET);
            return 0;
        }
        i++;
    }

    if (count > 0)
    {
        printf(GREEN"✅ Name accepted.\n"RESET);
        return 1;
    }

    printf(RED"❌ Name must contain at least one alphabet character.\n"RESET);
    return 0;
}
// Phone number validation function
int phone_number_validation(char *phone_no, AddressBook *addressbook)
{
    int i = 0;

    /* First digit check */
    if (!(phone_no[0] >= '6' && phone_no[0] <= '9'))
    {
        printf(RED"❌ Invalid Mobile Number!\n");
        printf("➡ First digit must be between 6 and 9.\n"RESET);
        return 0;
    }

    /* Digit check */
    while (phone_no[i] != '\0')
    {
        if (!isdigit(phone_no[i]))
        {
            printf(RED"❌ Invalid Mobile Number!\n");
            printf("➡ Mobile number must contain digits only.\n"RESET);
            return 0;
        }
        i++;
    }

    /* Length check */
    if (i != 10)
    {
        printf(RED"❌ Invalid Mobile Number!\n");
        printf("➡ Mobile number must be exactly 10 digits long.\n"RESET);
        return 0;
    }

    /* Duplicate check */
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strcmp(addressbook->contact_details[i].Mobile_number, phone_no) == 0)
        {
            printf(RED"❌ Mobile number already exists.\n");
            printf("➡ Please enter a unique Mobile Number.\n"RESET);
            return 0;
        }
    }

    printf(GREEN"✅ Mobile number accepted.\n"RESET);
    return 1;
}
// Function to creat Mail ID
int mail_id_validation(char *Email_ID, AddressBook *addressbook)
{
    int i;
    int at_pos = -1;
    int dot_pos = -1;

    /* Scan email characters */
    for (i = 0; Email_ID[i] != '\0'; i++)
    {
        if (Email_ID[i] == '@')
        {
            if (at_pos != -1)
            {
                printf(RED"❌ Invalid Email ID!\n");
                printf("➡ Multiple '@' symbols are not allowed.\n"RESET);
                return 0;
            }
            at_pos = i;
        }
        else if (Email_ID[i] == '.' && at_pos != -1 && dot_pos == -1)
        {
            dot_pos = i;
        }
        else if (!islower(Email_ID[i]) && !isdigit(Email_ID[i]))
        {
            printf(RED"❌ Invalid Email ID!\n");
            printf("➡ Only lowercase letters and digits are allowed.\n"RESET);
            return 0;
        }
    }

    /* '@' position check */
    if (at_pos <= 0)
    {
        printf(RED"❌ Invalid Email ID!\n");
        printf("➡ '@' symbol is missing or placed at an invalid position.\n"RESET);
        return 0;
    }

    /* '.' position check */
    if (dot_pos == -1 || dot_pos == at_pos + 1)
    {
        printf(RED"❌ Invalid Email ID!\n");
        printf("➡ '.' symbol is missing or incorrectly placed after '@'.\n"RESET);
        return 0;
    }

    /* Alphabets only between '@' and '.' */
    for (i = at_pos + 1; i < dot_pos; i++)
    {
        if (!islower(Email_ID[i]))
        {
            printf(RED"❌ Invalid Email ID!\n");
            printf("➡ Domain name must contain lowercase alphabets only.\n"RESET);
            return 0;
        }
    }

    /* Domain extension alphabets only */
    for (i = dot_pos + 1; Email_ID[i] != '\0'; i++)
    {
        if (!islower(Email_ID[i]))
        {
            printf(RED"❌ Invalid Email ID!\n");
            printf("➡ Domain extension must contain lowercase alphabets only.\n"RESET);
            return 0;
        }
    }

    /* Must end with .com only */
    int len = strlen(Email_ID);
    if (len < 5 || strcmp(&Email_ID[len - 4], ".com") != 0)
    {
        printf(RED"❌ Invalid Email ID!\n");
        printf("➡ Email ID must end with .com only.\n"RESET);
        return 0;
    }

    /* Duplicate email check */
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strcmp(addressbook->contact_details[i].Mail_ID, Email_ID) == 0)
        {
            printf(RED"❌ Email ID already exists.\n");
            printf("➡ Please enter a unique Email ID.\n"RESET);
            return 0;
        }
    }

    printf(GREEN"✅ Email ID validated successfully.\n"RESET);
    return 1;
}

// Searching by name
void only_search_by_name(AddressBook *addressbook)
{
    char name[32];
    int i, count = 0;

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           SEARCH BY NAME             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Name to Search : ");
    scanf(" %[^\n]", name); // leading space handles newline

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strcasestr(addressbook->contact_details[i].Name, name) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"\n❌ No contact found matching the given name.\n"RESET);
    }
}
// Searching by Mobile number
void only_search_by_phone_number(AddressBook *addressbook)
{
    char phone_no[11];
    int i, count = 0;

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        SEARCH BY MOBILE NUMBER       ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Mobile Number to Search : ");
    scanf(" %[^\n]", phone_no); // space before %[^\n] handles leftover newline
    getchar();                  // consume newline if needed

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mobile_number, phone_no) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"\n❌ No contact found with the given mobile number.\n"RESET);
    }
}
// Searching by Email ID
void only_search_by_Email_ID(AddressBook *addressbook)
{
    char Email_ID[35];
    int i, count = 0;

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           SEARCH BY EMAIL ID         ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Email ID to Search : ");
    scanf(" %[^\n]", Email_ID); // leading space handles leftover newline
    getchar();                  // consume newline if needed

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");

    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mail_ID, Email_ID) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"\n❌ No contact found with the given Email ID.\n"RESET);
    }
}
// Searching by name and Edit
int Search_by_name_and_Edit(AddressBook *addressbook)
{
    char name[32];
    int edit_index[100];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           SEARCH BY NAME             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Name to Search: ");
    scanf("%[^\n]", name);
    getchar(); // consume leftover newline

    int i, count = 0, j = 0;

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");

    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strcasestr(addressbook->contact_details[i].Name, name) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            edit_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to edit: ");
    scanf("%d", &index);
    getchar(); // consume newline

    if (index < 1 || index > count)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║ INVALID INDEX                                               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }

    index = edit_index[index - 1];

    char confirm;
    printf("║ Are you sure you want to edit this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
    return index; // proceed to edit
    }

    printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                       EDIT CANCELLED                        ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
    return -1; // cancel edit
}
// Searching by Mobile number and Edit
int Search_by_phone_number_and_Edit(AddressBook *addressbook)
{
    char phone_no[11];
    int edit_index[100];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        SEARCH BY PHONE NUMBER        ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Mobile Number to Search: ");
    scanf("%[^\n]", phone_no);
    getchar(); // consume leftover newline

    int i, count = 0, j = 0;

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");

    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mobile_number, phone_no) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            edit_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to edit: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║ INVALID INDEX                                               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }

    index = edit_index[index - 1];

    char confirm;
    printf("║ Are you sure you want to edit this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
        return index; // proceed to edit
    }

    printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                       EDIT CANCELLED                        ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
    return -1; // cancel edit
}
// Searching by Email ID and Edit
int Search_by_Email_ID_and_Edit(AddressBook *addressbook)
{
    char Email_ID[35];
    int edit_index[100];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           SEARCH BY EMAIL ID         ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter Email ID to Search: ");
    scanf("%[^\n]", Email_ID);
    getchar(); // consume leftover newline

    int i, count = 0, j = 0;

    printf("\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");

    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mail_ID, Email_ID) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            edit_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to edit: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count)

    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║ INVALID INDEX                                               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }

    index = edit_index[index - 1];
    char confirm;
    printf("║ Are you sure you want to edit this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
    
        return index; // proceed to edit
    }
    else
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                       EDIT CANCELLED                        ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"YELLOW);
        return -1; // cancel edit
    }
}
// Delete by name
int Search_by_name_and_Delete(AddressBook *addressbook)
{
    char name[32];
    int delete_index[20];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           DELETE BY NAME             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter the name: ");

    scanf("%[^\n]", name);
    getchar();

    int i, count = 0, j = 0;
    printf(YELLOW"\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strcasestr(addressbook->contact_details[i].Name, name) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            delete_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to delete: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║ INVALID INDEX                                               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }

    index = delete_index[index - 1];

    char confirm;
    printf("║ Are you sure you want to delete this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
        return index; // proceed to edit
    }
    else
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                     DELETE CANCELLED                        ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1; // cancel edit
    }
}
// Search and Delete by phone
int Search_by_phone_number_and_Delete(AddressBook *addressbook)
{
    char phone[15];
    int delete_index[20];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        DELETE BY PHONE NUMBER        ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter mobile number: ");

    scanf("%[^\n]", phone);
    getchar();

    int i, count = 0, j = 0;
    printf(YELLOW"\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mobile_number, phone) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            delete_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to delete: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║ INVALID INDEX                                               ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }

    index = delete_index[index - 1];

    char confirm;
    printf("║ Are you sure you want to delete this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
        
        return index; // proceed to edit
    }
    else
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                     DELETE CANCELLED                        ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1; // cancel edit
    }
}
// Search and Delete by email
int Search_by_Email_ID_and_Delete(AddressBook *addressbook)
{
    char email[50];
    int delete_index[20];
    RETRY_INDEX:
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║          DELETE BY EMAIL ID          ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter email ID: ");

    scanf("%[^\n]", email);
    getchar();

    int i, count = 0, j = 0;
    printf(YELLOW"\n╔═════════════════════ MATCHING CONTACTS ═════════════════════╗\n");
    for (i = 0; i < addressbook->contact_count; i++)
    {
        if (strstr(addressbook->contact_details[i].Mail_ID,email) != NULL)
        {
            printf(YELLOW"║ Index      : %d\n", count + 1);
            printf("║ Name       : %s\n", addressbook->contact_details[i].Name);
            printf("║ Mobile     : %s\n", addressbook->contact_details[i].Mobile_number);
            printf("║ Email ID   : %s\n", addressbook->contact_details[i].Mail_ID);
            printf("╠────────────────────────────────────────────────────────────╣\n"RESET);

            delete_index[j++] = i; // store actual index
            count++;
        }
    }

    if (count == 0)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                  CONTACT NOT FOUND                          ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1;
    }

    int index;
    printf("║ Enter index to delete: ");
    scanf("%d", &index);
    getchar();

   if (index < 1 || index > count)
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                   INVALID INDEX                             ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        goto RETRY_INDEX;
    }
    index = delete_index[index - 1];
    char confirm;
    printf("║ Are you sure you want to delete this contact? (Y/N): ");
    scanf("%c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y')
    {
        return index; // proceed to edit
    }
    else
    {
        printf(RED"╔═════════════════════════════════════════════════════════════╗\n");
        printf("║                     DELETE CANCELLED                        ║\n");
        printf("╚═════════════════════════════════════════════════════════════╝\n"RESET);
        return -1; // cancel edit
    }
}
