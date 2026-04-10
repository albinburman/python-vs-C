#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG 100

// ---------------- IP-VALIDERING ----------------
int validate_ip(const char *ip) {
    int num, dots = 0;
    char *ptr;
    char ip_copy[50];

    strncpy(ip_copy, ip, sizeof(ip_copy));
    ip_copy[sizeof(ip_copy)-1] = '\0';

    ptr = strtok(ip_copy, ".");
    while (ptr != NULL) {

        for (int i = 0; ptr[i] != '\0'; i++) {
            if (!isdigit(ptr[i])) {
                return 0;
            }
        }

        num = atoi(ptr);
        if (num < 0 || num > 255) {
            return 0;
        }

        ptr = strtok(NULL, ".");
        dots++;
    }

    return dots == 4;
}

// ---------------- PORT-VALIDERING ----------------
int validate_port(int port) {
    return port >= 1 && port <= 65535;
}

// ---------------- MAIN ----------------
int main() {
    int choice;
    char ip[50];
    int port;

    char logg[MAX_LOG][100];
    int log_count = 0;

    while (1) {
        printf("\n═══ NÄTVERKSVERKTYG ═══\n");
        printf("1. Validera IP-adress\n");
        printf("2. Validera port\n");
        printf("3. Visa logg\n");
        printf("4. Avsluta\n");
        printf("Välj ett alternativ: ");
        scanf("%d", &choice);
        getchar(); // rensa newline

        switch (choice) {

            case 1:
                printf("Ange IP-adress: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0;

                if (validate_ip(ip)) {
                    printf("%s är en giltig IP-adress.\n", ip);
                    snprintf(logg[log_count++], 100, "IP %s - giltig", ip);
                } else {
                    printf("%s är inte en giltig IP-adress.\n", ip);
                    snprintf(logg[log_count++], 100, "IP %s - ogiltig", ip);
                }
                break;

            case 2:
                printf("Ange port: ");
                scanf("%d", &port);
                getchar();

                if (validate_port(port)) {
                    printf("%d är en giltig port.\n", port);
                    snprintf(logg[log_count++], 100, "Port %d - giltig", port);
                } else {
                    printf("%d är inte en giltig port.\n", port);
                    snprintf(logg[log_count++], 100, "Port %d - ogiltig", port);
                }
                break;

            case 3:
                printf("\n═══ LOGG ═══\n");
                for (int i = 0; i < log_count; i++) {
                    printf("%d. %s\n", i + 1, logg[i]);
                }
                break;

            case 4:
                printf("Avslutar programmet...\n");
                return 0;

            default:
                printf("Ogiltigt val.\n");
        }
    }
}