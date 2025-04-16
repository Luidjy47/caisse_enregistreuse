#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    double montant = (rand() % 20000 + 100) / 100.0; // entre Rs1.00 et Rs200.00
    double donne;

    printf("Montant à payer : Rs%.2f\n", montant);

    do {
        printf("Entrez le montant donné par le client : Rs");
        scanf("%lf", &donne);

        if (donne < montant) {
            printf("Montant insuffisant. Veuillez réessayer.\n");
        }
    } while (donne < montant);

    double rendu = donne - montant;
    printf("Monnaie à rendre : Rs%.2f\n", rendu);

    return 0;
}

