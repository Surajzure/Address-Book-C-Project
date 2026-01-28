#include <stdio.h>
#include "contact.h"
#ifndef COLORS_H
#define COLORS_H
/* Text colors */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#endif

int main()
{
    int option;
    AddressBook addressbook;

    addressbook.contact_count = 0;
    load_contact(&addressbook);

    while (1)
    {
        printf(BLUE"\n╔══════════════════════════════════════╗\n");
        printf("║          ADDRESS BOOK MENU           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Add Contact                      ║\n");
        printf("║  2. Search Contact                   ║\n");
        printf("║  3. Edit Contact                     ║\n");
        printf("║  4. Delete Contact                   ║\n");
        printf("║  5. List / Display Contacts          ║\n");
        printf("║  6. Save Contacts                    ║\n");
        printf("║  7. Save and Exit                    ║\n");
        printf("╚══════════════════════════════════════╝\n"RESET);
        printf("Enter your choice : ");

        scanf("%d", &option);
        getchar();   // clear input buffer

        switch (option)
        {
            case 1:
                create_contact(&addressbook);
                break;

            case 2:
                search_contacts(&addressbook);
                break;

            case 3:
                edit_contact(&addressbook);
                break;

            case 4:
                delete_contact(&addressbook);
                break;

            case 5:
                list_contacts(&addressbook);
                break;

            case 6:
                save_contacts(&addressbook);
                break;

            case 7:
                printf("\n👋 Saving data and exiting...\n");
                save_contacts(&addressbook);
                return 0;

            default:
                printf("\n❌ Invalid option! Please try again.\n");
        }
    }

    return 0;
}
