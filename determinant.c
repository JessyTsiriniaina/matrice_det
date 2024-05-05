#include <stdio.h>

/* En faisant cet exercice je me suis rendu compte qu'il ne faut pas
  juste imaginer quand on fait une analyse, il faut ecrire 
  quelque part pour que les yeux voient. J'ai compris aussi 
  l'importance de decouper son probleme en plusieurs petits problemes
  plus simple*/

void remplir_matrice(double (*tab)[10], int ordre);
void cofacteur(double (*tab)[10], double (*cofact)[10], int col, int ordre);
double determinant(double (*tab)[10], int ordre);

int main(void)
{
        int n;
        printf("Entrer l'ordre du matrice: ");
        scanf("%d", &n);

        double matrice[10][10];
        remplir_matrice(matrice, n);

        printf("Le determinant du matrice est: %lf \n", determinant(matrice, n));

        return 0;
}

void remplir_matrice(double (*tab)[10], int ordre)
{
        for (int i = 0; i < ordre; i++)
                for (int j = 0; j < ordre; j++)
                {
                        printf("[%d][%d]: ", i, j);
                        scanf("%lf", &tab[i][j]);
                };
}

void cofacteur(double (*tab)[10], double (*cofact)[10], int col, int ordre)
{
        int i = 0, j = 0;

        for (int ligne = 0; ligne < ordre; ligne++)
        {
                for (int colonne = 0; colonne < ordre; colonne++)
                {
                        if ((colonne != col) && (ligne != 0))
                        {
                                cofact[i][j] = tab[ligne][colonne];
                                j++;
                        }

                        if (j == ordre - 1)
                        {
                                j = 0;
                                i++;
                        }
                }
        }
}

double determinant(double (*tab)[10], int ordre)
{
        if (ordre == 1)
        {
                return tab[0][0];
        }

        double det = 0;
        double cofact[10][10];
        int signe = 1;

        for (int i = 0; i < ordre; i++)
        {
                cofacteur(tab, cofact, i, ordre);
                det += signe * tab[0][i] * determinant(cofact, ordre - 1);
                signe = -signe;
        }
        return det;
}
