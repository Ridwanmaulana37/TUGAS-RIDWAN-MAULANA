#include <stdio.h>
#include <stdlib.h>

int main() {
    // Inisialisasi PIN
    int pin = 171945;
    // First Balance
    float balance = 300000;
    // Inisialisasi variabel-variabel
    int choice, login_attempt = 0;
    int transfer_account_number;
    float saldo_awal, saldo_akhir, jumlah_transfer;
    char nama_bank[50], nomor_rekening[50], kode_bank_tujuan[10];
    float transfer_amount, top_up_dana, top_up_gopay,top_up_shoppe_pay,top_up_ovo,withdrawal_amount;

    // Loop PIN If Wrong Put PIN
    while (login_attempt < 3) {
        // User To Put PIN
        int input_pin;
        printf("Enter Your PIN: ");
        scanf("%d", &input_pin);
        
        // If PIN is Right , Return to Main Menu
        if (input_pin == pin) {
            printf("\nLogin Succesfully!\n");

            while (1) {
                printf("\nATM Menu\n");
                printf("1. Check Balance\n");
                printf("2. Add Balance\n");
                printf("3. Withdraw\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Log Out\n");
                printf("Enter Your Choice:");
                scanf("%d", &choice);
                
                // Switch case For Every Menu
                switch (choice) {
                    case 1:
                        printf("Your Balance Now: %.2f\n", balance);
                        break;
                    case 2:
                        printf("enter the amount of money: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Fill in your balance has been successful, the current balance: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Enter the amount you want to withdraw: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Not Enough Balance.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Withdraw your balance has been successful, the current balance: %.2f\n", balance);
                        }
                        break;
                    case 4:
                         printf("enter the name of the bank you want to go to: ");
                         scanf("%s", &nama_bank);
                         printf("Enter the destination account number: ");
                         scanf("%s", &nomor_rekening);
    
                         printf("Enter the code of bank: ");
                         scanf("%s", &kode_bank_tujuan);
    
                         printf("Enter the amount you want to transfer: ");
                         scanf("%f", &jumlah_transfer);
                         printf("Enter PIN: ");
                         scanf("%d", &pin);
                         printf("top up successful , your current balance: %.2f\n", balance -=top_up_dana);
    
    if (jumlah_transfer > balance) {
        printf("Sorry, your balance is insufficient to make a transfer of %f", jumlah_transfer);
    } else {
        saldo_akhir = balance - jumlah_transfer;
        printf("The transfer of %f was successfully made to the %s account at the %s bank with the destination bank code %s.\n", jumlah_transfer, nomor_rekening, nama_bank, kode_bank_tujuan);
        printf("Your Balance Now %f", saldo_akhir);
    }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Dana\n");
                        printf("2. Gopay\n");
                        printf("3. ShoppePay\n");
                        printf("4. Ovo\n");
                        printf("What you choose: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("Enter the amount you want to top up: ");
                                scanf("%f", &top_up_dana);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Your refill has been successful, please check the balance for more details, the current balance: %.2f\n", balance -=top_up_dana);
                                break;
                            case 2:
                                printf("Enter the amount you want to top up: ");
                                scanf("%f", &top_up_gopay);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Your refill has been successful, please check the balance for more details, the current balance: %.2f", balance -= top_up_gopay);
                                break;
                            case 3:
                                printf("Enter the amount you want to top up: ");
                                scanf("%f", &top_up_shoppe_pay);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Your refill has been successful, please check the balance for more details, the current balance: %.2f", balance -= top_up_shoppe_pay);
                                printf("Your refill has been successful, please check the balance for more details, the current balance: %.2f\n", balance);
                                 break;
                            case 4:
                                printf("Enter the amount you want to top up: ");
                                scanf("%f", &top_up_ovo);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Your refill has been successful, please check the balance for more details, the current balance: %.2f", balance -= top_up_ovo);
                              
                            break;
                            default:
                                printf("\nNot Valid Option.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Back to Main Menu
                        printf("Logout Succesfully, thank you for using our service.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Not Valid Option.\n");
                        break;
                }
            }
        } else {
            // If PIN Wrong , Put the error code and add some attempt for input PIN Again and Again
            printf("PIN Not Valid, Please Try Again...\n");
            login_attempt++;
        }
    }
    // If 3 Attempts still wrong , Put Error Code and Back To PIN Again
    if (login_attempt == 3) {
        printf("you have done it 3 times and keep getting it wrong, then your card is blocked.\n");
    }
    return 0;
}