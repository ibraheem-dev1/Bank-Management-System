#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
    char username[50];
    char password[50];
} Admin;

typedef struct {
    char first_name[50];
    char last_name[50];
    char father_name[50];
    char mother_name[50];
    char cnic[13];
    char address[100];
    int account_type;
    char username[50];
    char password[50];
    double balance;
    double mini_statements[10];
    int statement_count;
} User;

void admin_panel();
void user_panel();
void signup(User *new_user);
void add_predefined_users();
void signin();
void atm();
void currency_exchange();
void loan();
void password(char password[50]);
void withdraw_money(User *user);
void deposit_money(User *user);
void transfer_money(User *user);
void check_balance(User *user);
void mini_statement(User *user);
void update_account_info(User *user);
void delete_account(User *user, int index);
int find_user(const char* username, const char* password_1);
double total_bank_balance();
void access_user_account();
void save_users_to_file();
void load_users_from_file();

Admin admins[10] = {{"manager", "manager123"}};
User users[100];
int user_count = 0;

int main() {
    load_users_from_file();
    add_predefined_users();

    int choice;
    do {
        printf("-----------------Welcome to our Bank-----------------\n");
        printf("1. Admin panel\n");
        printf("2. User panel\n");
        printf("3. ATM Machine\n");
        printf("4. Currency Exchange Calculator\n");
        printf("5. Apply For Loan\n");
        printf("-----------------Enter '0' for exit-----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            int back;
            case 0:
                printf("Thanks for using our Bank\n");
                break;
            case 1:
                admin_panel();
                do {
                    printf("Enter 0 to return!!!!");
                    scanf("%d", &back);
                } while (back != 0);
                if (back == 0) {
                    break;
                }
            case 2:
                user_panel();
                do {
                    printf("Enter 0 to return!!!!");
                    scanf("%d", &back);
                } while (back != 0);
                if (back == 0) {
                    break;
                }
            case 3:
                atm();
                do {
                    printf("Enter 0 to return!!!!");
                    scanf("%d", &back);
                } while (back != 0);
                if (back == 0) {
                    break;
                }
            case 4:
                currency_exchange();
                do {
                    printf("Enter 0 to return!!!!");
                    scanf("%d", &back);
                } while (back != 0);
                if (back == 0) {
                    break;
                }
            case 5:
                loan();
                do {
                    printf("Enter 0 to return!!!!");
                    scanf("%d", &back);
                } while (back != 0);
                if (back == 0) {
                    break;
                }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void add_predefined_users() {
    
    if (user_count == 0) {
        strcpy(users[user_count].first_name, "Muhammad");
        strcpy(users[user_count].last_name, "Ibraheem");
        strcpy(users[user_count].father_name, "Sarfraz Ahmad");
        strcpy(users[user_count].mother_name, "Sarfraz Ahmad");
        strcpy(users[user_count].cnic, "34104-0464840-9");
        strcpy(users[user_count].address, "Gujranwala");
        users[user_count].account_type = 1;
        strcpy(users[user_count].username, "ibraheem");
        strcpy(users[user_count].password, "123");
        users[user_count].balance = 1000.0;
        users[user_count].statement_count = 0;
        user_count++;

        strcpy(users[user_count].first_name, "Muneeb");
        strcpy(users[user_count].last_name, "Tahir");
        strcpy(users[user_count].father_name, "Tahir Ali");
        strcpy(users[user_count].mother_name, "Aisha Ali");
        strcpy(users[user_count].cnic, "2345678901234");
        strcpy(users[user_count].address, "Lda Lahore");
        users[user_count].account_type = 2;
        strcpy(users[user_count].username, "muneeb");
        strcpy(users[user_count].password, "abc");
        users[user_count].balance = 2000.0;
        users[user_count].statement_count = 0;
        user_count++;

        strcpy(users[user_count].first_name, "Maryam");
        strcpy(users[user_count].last_name, "Kamal");
        strcpy(users[user_count].father_name, "Kamal Haider");
        strcpy(users[user_count].mother_name, "Zainab Fatima");
        strcpy(users[user_count].cnic, "3456789012345");
        strcpy(users[user_count].address, "comsat");
        users[user_count].account_type = 3;
        strcpy(users[user_count].username, "maryam");
        strcpy(users[user_count].password, "123abc");
        users[user_count].balance = 3000.0;
        users[user_count].statement_count = 0;
        user_count++;
    }
}

void admin_panel() {
    int a;
    do {
        printf("Select one of the following options\n1.Manager\n0.Exit\n");
        scanf("%d", &a);
        switch (a) {
            case 0:
                printf("Exiting admin panel...\n");
                break;

            case 1: {
                char username[50];
                char password_1[50];
                printf("Enter Username: ");
                fflush(stdin);
                gets(username);
                printf("Enter Password: ");
                password(password_1);
                int back;
                int found = 0;

                if (strcmp(admins[0].username, username) == 0 && strcmp(admins[0].password, password_1) == 0) {
                    found = 1;
                }

                if (found) {
                    int c;
                    do {
                        printf("Select one of the following options\n1.Delete account\n2.Total Cash in Bank\n3.Access account\n0.Exit\n");
                        scanf("%d", &c);
                        double bank_balance;
                        switch (c) {
                            case 1: {
                                // Account delete
                                for (int i = 0; i < user_count; i++) {
                                    printf("%d. %s\n", i + 1, users[i].username);
                                }
                                int account_to_delete;
                                printf("Enter the number of the account to delete: ");
                                scanf("%d", &account_to_delete);
                                if (account_to_delete > 0 && account_to_delete <= user_count) {
                                    delete_account(&users[account_to_delete - 1], account_to_delete - 1);
                                } else {
                                    printf("Invalid account number.\n");
                                }
                                do {
                                    printf("Enter 0 to return!!!!");
                                    scanf("%d", &back);
                                } while (back != 0);
                                if (back == 0) {
                                    break;
                                }
                            }
                            case 2:
                                bank_balance = total_bank_balance();
                                printf("Total bank balance: %.2lf\n", bank_balance);
                                do {
                                    printf("Enter 0 to return!!!!");
                                    scanf("%d", &back);
                                } while (back != 0);
                                if (back == 0) {
                                    break;
                                }
                            case 3:
                                access_user_account();
                                do {
                                    printf("Enter 0 to return!!!!");
                                    scanf("%d", &back);
                                } while (back != 0);
                                if (back == 0) {
                                    break;
                                }

                            case 0:
                                printf("Exiting...\n");
                                break;
                            default:
                                printf("Invalid choice. Please try again.\n");
                                break;
                        }
                    } while (c != 0);
                } else {
                    printf("Invalid credentials. Please try again.\n");
                }
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (a != 0);
}

void user_panel() {
    int selection;
    do {
        printf("------------------Welcome to User Interface----------------\n");
        printf("Select one of the following options:\n 1.New User (wants to sign up)\n2.Already user (sign in)\n0.Exit\n");
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                signup(&users[user_count++]);
                save_users_to_file(); 
                break;
            case 2:
                signin();
                break;
            case 0:
                printf("Exiting user interface...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (selection != 0);
}

void signup(User *new_user) {
    printf("Enter your first name: ");
    fflush(stdin);
    gets(new_user->first_name);
    printf("Enter your last name: ");
    fflush(stdin);
    gets(new_user->last_name);
    printf("Enter your father name: ");
    fflush(stdin);
    gets(new_user->father_name);
    printf("Enter your mother name: ");
    fflush(stdin);
    gets(new_user->mother_name);
    printf("Enter your CNIC: ");
    fflush(stdin);
    gets(new_user->cnic);
    printf("Enter your address: ");
    fflush(stdin);
    gets(new_user->address);
    printf("Enter your account type (1-Current, 2-Saving, 3-Fixed): ");
    scanf("%d", &new_user->account_type);
    printf("Create your username: ");
    fflush(stdin);
    gets(new_user->username);
    printf("Create your password: ");
    password(new_user->password);
    new_user->balance = 0.0;
    new_user->statement_count = 0;
    printf("Signup successful! You can now sign in.\n");
}

void password(char password[50]) {
    int p = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == 13) { 
            password[p] = '\0';
            break;
        } else if (ch == 8) { 
            if (p > 0) {
                p--;
                printf("\b \b");
            }
        } else {
            password[p++] = ch;
            printf("*");
        }
    }
    printf("\n");
}

void signin() {
    char username[50];
    char password_1[50];
    printf("Enter your username: ");
    fflush(stdin);
    gets(username);
    printf("Enter your password: ");
    password(password_1);

    int user_index = find_user(username, password_1);
    if (user_index != -1) {
        int choice;
        do {
            printf("Welcome, %s!\n", users[user_index].first_name);
            printf("1. Withdraw Money\n");
            printf("2. Deposit Money\n");
            printf("3. Transfer Money\n");
            printf("4. Check Balance\n");
            printf("5. Mini Statement\n");
            printf("6. Update Account Info\n");
            printf("0. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    withdraw_money(&users[user_index]);
                    break;
                case 2:
                    deposit_money(&users[user_index]);
                    break;
                case 3:
                    transfer_money(&users[user_index]);
                    break;
                case 4:
                    check_balance(&users[user_index]);
                    break;
                case 5:
                    mini_statement(&users[user_index]);
                    break;
                case 6:
                    update_account_info(&users[user_index]);
                    break;
                case 0:
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 0);
    } else {
        printf("Invalid username or password. Please try again.\n");
    }
}

void withdraw_money(User *user) {
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        printf("Withdrawal successful. New balance: %.2lf\n", user->balance);
        user->mini_statements[user->statement_count++ % 10] = -amount;
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

void deposit_money(User *user) {
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);
    if (amount > 0) {
        user->balance += amount;
        printf("Deposit successful. New balance: %.2lf\n", user->balance);
        user->mini_statements[user->statement_count++ % 10] = amount; 
    } else {
        printf("Invalid amount.\n");
    }
}

void transfer_money(User *user) {
    char target_username[50];
    double amount;
    printf("Enter the username of the recipient: ");
    fflush(stdin);
    gets(target_username);
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);
    if (amount > 0 && amount <= user->balance) {
        int target_index = find_user(target_username, ""); 
        if (target_index != -1) {
            user->balance -= amount;
            users[target_index].balance += amount;
            printf("Transfer successful. Your new balance: %.2lf\n", user->balance);
            user->mini_statements[user->statement_count++ % 10] = -amount; 
            users[target_index].mini_statements[users[target_index].statement_count++ % 10] = amount; 
        } else {
            printf("Recipient not found.\n");
        }
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

void check_balance(User *user) {
    printf("Your balance is: %.2lf\n", user->balance);
}

void mini_statement(User *user) {
    printf("Mini Statement:\n");
    for (int i = 0; i < user->statement_count && i < 10; i++) {
        printf("%d. %.2lf\n", i + 1, user->mini_statements[i]);
    }
}

void update_account_info(User *user) {
    printf("Update your information:\n");
    printf("1. First Name\n");
    printf("2. Last Name\n");
    printf("3. Father Name\n");
    printf("4. Mother Name\n");
    printf("5. CNIC\n");
    printf("6. Address\n");
    printf("7. Password\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter new first name: ");
            fflush(stdin);
            gets(user->first_name);
            break;
        case 2:
            printf("Enter new last name: ");
            fflush(stdin);
            gets(user->last_name);
            break;
        case 3:
            printf("Enter new father name: ");
            fflush(stdin);
            gets(user->father_name);
            break;
        case 4:
            printf("Enter new mother name: ");
            fflush(stdin);
            gets(user->mother_name);
            break;
        case 5:
            printf("Enter new CNIC: ");
            fflush(stdin);
            gets(user->cnic);
            break;
        case 6:
            printf("Enter new address: ");
            fflush(stdin);
            gets(user->address);
            break;
        case 7:
            printf("Enter new password: ");
            password(user->password);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    printf("Information updated successfully.\n");
}

void delete_account(User *user, int index) {
    for (int i = index; i < user_count - 1; i++) {
        users[i] = users[i + 1];
    }
    user_count--;
    printf("Account deleted successfully.\n");
    save_users_to_file(); 
}

int find_user(const char* username, const char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && (password[0] == '\0' || strcmp(users[i].password, password) == 0)) {
            return i;
        }
    }
    return -1;
}

double total_bank_balance() {
    double total = 0.0;
    for (int i = 0; i < user_count; i++) {
        total += users[i].balance;
    }
    return total;
}

void access_user_account() {
    char username[50];
    printf("Enter the username of the account to access: ");
    fflush(stdin);
    gets(username);
    int user_index = find_user(username, "");
    if (user_index != -1) {
        int choice;
        do {
            printf("Accessing account of %s %s:\n", users[user_index].first_name, users[user_index].last_name);
            printf("1. Check Balance\n");
            printf("2. Mini Statement\n");
            printf("3. Update Account Info\n");
            printf("4. Delete Account\n");
            printf("0. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    check_balance(&users[user_index]);
                    break;
                case 2:
                    mini_statement(&users[user_index]);
                    break;
                case 3:
                    update_account_info(&users[user_index]);
                    save_users_to_file(); 
                    break;
                case 4:
                    delete_account(&users[user_index], user_index);
                    choice = 0;
                    break;
                case 0:
                    printf("Going back...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 0);
    } else {
        printf("Account not found.\n");
    }
}

void save_users_to_file() {
    FILE *file = fopen("users.dat", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(&user_count, sizeof(int), 1, file);
    fwrite(users, sizeof(User), user_count, file);
    fclose(file);
    printf("User data saved successfully.\n");
}

void load_users_from_file() {
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fread(&user_count, sizeof(int), 1, file);
    fread(users, sizeof(User), user_count, file);
    fclose(file);
    printf("User data loaded successfully.\n");
}
void atm() {
    char username[50];
    char password_1[50];
    printf("Enter your ATM PIN (same as account password): ");
    password(password_1);

    int found = 0;
    int user_index;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].password, password_1) == 0) {
            found = 1;
            user_index = i;
            break;
        }
    }

    if (found) {
        printf("Welcome, %s %s\n", users[user_index].first_name, users[user_index].last_name);
        printf("Your current balance is: %.2lf\n", users[user_index].balance);
        withdraw_money(&users[user_index]);
    } else {
        printf("Invalid username or ATM PIN. Please try again.\n");
    }
}
void loan() {
    int selection;
    printf("1. New User\n");
    printf("2. Existing User\n");
    printf("Enter your choice: ");
    scanf("%d", &selection);

    if (selection == 1) {
        User new_user;
        signup(&new_user);
        users[user_count++] = new_user;
        printf("Account created. Now you can apply for a loan.\n");
    } 

    if (selection == 1 || selection == 2) {
        char username[50];
        char password_1[50];
        printf("Enter username: ");
    fflush(stdin);
        gets( username);
        printf("Enter password: ");
        password(password_1);

        int user_index = find_user(username, password_1);
        if (user_index == -1) {
            printf("Invalid username or password.\n");
            return;
        }

        double loan_amount;
        char loan_purpose[100];
        char agreement;

        printf("Enter the amount of loan: ");
        scanf("%lf", &loan_amount);
        printf("Enter the purpose of the loan: ");
        fflush(stdin);
        gets( loan_purpose);

        printf("Do you accept the loan agreement? (Y/N): ");
        scanf(" %c", &agreement);

        if (agreement == 'Y' || agreement == 'y') {
            printf("Loan request accepted for %.2lf for the purpose of: %s\n", loan_amount, loan_purpose);
            users[user_index].balance += loan_amount;
            printf("New balance: %.2lf\n", users[user_index].balance);
        } else {
            printf("Loan request rejected. You must accept the agreement.\n");
        }
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}
void currency_exchange() {
    
    double amount;
    int choice;
    double converted_amount;

    printf("Enter the amount in PKR: ");
    scanf("%lf", &amount);

    printf("Select the currency you want to convert to:\n");
    printf("1. USD (1 USD = 160 PKR)\n");
    printf("2. EUR (1 EUR = 190 PKR)\n");
    printf("3. GBP (1 GBP = 220 PKR)\n");
    printf("4. AED (1 AED = 45 PKR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            converted_amount = amount / 160.0;
            printf("%.2lf PKR is equal to %.2lf USD\n", amount, converted_amount);
            break;
        case 2:
            converted_amount = amount / 190.0;
            printf("%.2lf PKR is equal to %.2lf EUR\n", amount, converted_amount);
            break;
        case 3:
            converted_amount = amount / 220.0;
            printf("%.2lf PKR is equal to %.2lf GBP\n", amount, converted_amount);
            break;
        case 4:
            converted_amount = amount / 45.0;
            printf("%.2lf PKR is equal to %.2lf AED\n", amount, converted_amount);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
