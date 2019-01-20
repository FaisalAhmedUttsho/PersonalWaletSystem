#include <stdio.h>
#include <stdlib.h>
main()
{
    FILE *income = fopen("D:\\New folder\\next\\p_w_s\\PWS\\income.txt", "r");
    FILE *expense = fopen("D:\\New folder\\next\\p_w_s\\PWS\\expense.txt", "r");
    FILE *password = fopen("D:\\New folder\\next\\p_w_s\\PWS\\password.txt", "r");
    char c, pass[16], store[16], cpass[16], n1[16], n2[16];
    fgets(store, 16, password);
    int bal, bud, choice, inc, exp, switch2;
    printf("-Welcome to Personal Wallet service-\n");
    pass_repeat:
    printf(">Please enter password: ");
    scanf("%s", &pass);
    fgets(store, 16, password);
    again1:
    if(strcmp(store, pass) == 0)
    {
        FILE *balance = fopen("D:\\New folder\\next\\p_w_s\\PWS\\balance.txt", "r");
        FILE *budget = fopen("D:\\New folder\\next\\p_w_s\\PWS\\budget.txt", "r");
        fscanf(balance, "%d", &bal);
        fscanf(budget, "%d", &bud);
        fclose(balance);
        fclose(budget);
        printf("\n\n]Balance: %dTK\n", bal);
        printf("]Available Balance: %dTK\n", bud);
        printf("-1. Transaction\n-2. Budget\n-3. Change Password\n-4. Exit\n");
        printf(">Enter: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\n-1. Cash In\n-2. Cash Out\n>Enter: ");
            scanf("%d", &switch2);
            switch(switch2)
            {
            case 1:
                printf("\n>Enter Cash in amount: ");
                scanf("%d", &inc);
                FILE *income = fopen("D:\\New folder\\next\\p_w_s\\PWS\\income.txt", "a");
                fprintf(income, "Log: %dTK\n", inc);
                fclose(income);
                bal = bal + inc;
                bud = bud +inc;
                FILE *balance = fopen("D:\\New folder\\next\\p_w_s\\PWS\\balance.txt", "w");
                FILE *budget = fopen("D:\\New folder\\next\\p_w_s\\PWS\\budget.txt", "w");
                fprintf(balance, "%d", bal);
                fprintf(budget, "%d", bud);
                fclose(balance);
                fclose(budget);
                goto again1;

            case 2:
                printf("\n>Enter Cash out amount: ");
                scanf("%d", &exp);
                FILE *expense = fopen("D:\\New folder\\next\\p_w_s\\PWS\\expense.txt", "a");
                fprintf(expense, "Log: %dTK\n", exp);
                fclose(expense);
                bal = bal - exp;
                bud = bud - exp;
                FILE *balanc = fopen("D:\\New folder\\next\\p_w_s\\PWS\\balance.txt", "w");
                FILE *budge = fopen("D:\\New folder\\next\\p_w_s\\PWS\\budget.txt", "w");
                fprintf(balanc, "%d", bal);
                fprintf(budget, "%d", bud);
                fclose(balanc);
                fclose(budget);
                goto again1;
            }
            break;

        case 2:
            printf("\n-1. Add budget\n-2. Clear budget\n>Enter: ");
            scanf("%d", &switch2);
            switch(switch2)
            {
            case 1:
                printf("\n>Enter budget: ");
                scanf("%d", &exp);
                bud = bud - exp;
                FILE *budget = fopen("D:\New folder\next\p_w_s\PWS\budget.txt", "w");
                fprintf(budget, "%d", bud);
                fclose(budget);
                goto again1;

            case 2:
                bal = bud;
                FILE *blance = fopen("D:\\New folder\\next\\p_w_s\\PWS\\balance.txt", "w");
                fprintf(blance, "%d", bal);
                fclose(blance);
                printf("\n]Budget cleared[\n");
                goto again1;
            }
            break;

        case 3:

            again3:
            printf("\n>Enter Old password: ");
            scanf("%s", &cpass);
            if(strcmp(cpass, store) == 0)
            {
                again2:
                printf("\n>Enter New password(Must be 1-16 characters): ");
                scanf("%s", &n1);
                printf(">Enter New password again: ");
                scanf("%s", &n2);
                if(strcmp(n1, n2) == 0)
                {
                    fclose(password);
                    FILE *pass = fopen("D:\\New folder\\next\\p_w_s\\PWSs\\password.txt", "w");
                    fputs(n1, password);
                    printf("\n]Password changed successfully[\n");
                    fclose(pass);
                    goto again1;
                }
                else
                {
                    printf("\n]Passwords didn't match[\n]Try again[\n");
                    goto again2;
                }
            }
            else
            {
                printf("]Wrong password[\n]Try again[\n");
                goto again3;
            }
            break;

        case 5:
            printf("\n]]]EXITING APPLICATION[[[\n");
            fclose(password);
            exit(EXIT_SUCCESS);
            return 0;
        }
    }
    else if(strcmp(pass, "EXIT") == 0)
    {
        fclose(password);
        exit(-1);
    }
    else
    {
        printf("\n]!!!WRONG PASSWORD!!![\n>TRY AGAIN<\n\n");
        goto pass_repeat;
    }
    return 0;
}

