#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcule_monnaie(double monnaie) {
    int valeurs[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1};
    int sous[] = {50, 20, 5};

    int reste = (int)(monnaie * 100 + 0.5);

    printf("\nMonnaie à rendre : Rs%.2f\n", monnaie);

    for (int i = 0; i < sizeof(valeurs)/sizeof(int); i++) {
        int val = valeurs[i] * 100;
        int nb = reste / val;
        if (nb) {
            printf("  Rs%d x %d\n", valeurs[i], nb);
            reste -= nb * val;
        }
    }

    for (int i = 0; i < sizeof(sous)/sizeof(int); i++) {
        int nb = reste / sous[i];
        if (nb) {
            printf("  %d sous x %d\n", sous[i], nb);
            reste -= nb * sous[i];
        }
    }
}

int main() {
    srand(time(NULL));
    double montant = (rand() % 20000 + 100) / 100.0;
    double donne;

    printf("Montant à payer : Rs%.2f\n", montant);

    do {
        printf("Entrez le montant donné : Rs");
        scanf("%lf", &donne);
        if (donne < montant) printf("Montant insuffisant. Réessayez.\n");
    } while (donne < montant);

    calcule_monnaie(donne - montant);
    return 0;
}
