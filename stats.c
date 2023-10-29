#include <stdio.h>
#include <math.h>
#define k 2


typedef struct noeud
{
	double e;
	struct noeud *suiv;
} T_noeud;

typedef struct
{
	T_noeud *tete;
} Col;

typedef struct
{
	Col *col[19];
} Feuille;


// type T_noeud : une liste chainée avec les valeurs numériques d'une même colonne

// type Col : pointeur sur la tête d'une colonne

// Pour représenter 1 fichier de données : tableau de Col (pas besoin du nom des colonnes car tjrs le même ordre)

void affiche_list(Col *col);

int taille(Col *col);

double moyenne(Col *col);

double min(Col *col);

double max(Col *col);

double ecart_type(Col *col);

double mediane(Col *col);

double q1(Col *col);

double q3(Col *col);

void supExtremes(Col *col);

void stats_to_file(Feuille feuille, FILE *fichier);


void affiche_list(Col *col)
{
	T_noeud *courant;
	courant = col->tete;
	while (courant!=NULL)
	{
		printf("%lf\n", courant->e);
		courant = courant -> suiv;
	}
}

int taille(Col *col)
{
	int t = 0;
	T_noeud *courant;
	courant = col->tete;
	while (courant!=NULL)
	{
		courant = courant->suiv;
		t++;
	}
	return t;
}

double moyenne(Col *col)
{
	double s = 0;
	T_noeud *courant;
	courant = col->tete;
	while (courant!=NULL)
	{
		s = s + courant->e;
		courant = courant->suiv;
	}
	return s/taille(col);
}

double min(Col *col)
{
	return col->tete->e;
}

double max(Col *col)
{
	T_noeud *courant;
	courant = col->tete;
	while (courant->suiv!=NULL)
	{
		courant = courant->suiv;
	}
	return courant->e;
}

double ecart_type(Col *col)
{
	double m = moyenne(col);
	T_noeud *courant;
	courant = col->tete;
	double s = 0;
	while (courant!=NULL)
	{
		s = s + pow(m-courant->e, 2);
		courant = courant->suiv;
	}
	return sqrt(s);
}

double mediane(Col *col)
{
	int t = taille(col);
	int m = (t+1)/2;
	T_noeud *courant;
	courant = col->tete;
	for (int i=0; i<m; i++)
		courant = courant->suiv;
	return courant->e;
}

double q1(Col *col)
{
	int t = taille(col);
	int m = (t+1)/4;
	T_noeud *courant;
	courant = col->tete;
	for (int i=0; i<m; i++)
		courant = courant->suiv;
	return courant->e;	
}

double q3(Col *col)
{
	int t = taille(col);
	int m = 3*(t+1)/4;
	T_noeud *courant;
	courant = col->tete;
	for (int i=0; i<m; i++)
		courant = courant->suiv;
	return courant->e;
}

void supExtremes(Col *col)
{
	T_noeud *courant;
	courant = col->tete;
	T_noeud *suivant;
	suivant = courant->suiv;
	double m = moyenne(col);
	double s = ecart_type(col);
	double b_inf = m - k*s;
	double b_sup = m + k*s;
	while (courant->suiv!=NULL) //traite toutes les valeurs sauf la premiere
	{
		if (courant->suiv->e > b_sup || courant->suiv->e < b_inf)
			courant->suiv = courant->suiv->suiv;
		courant = courant->suiv;
	}
	if (col->tete->e > b_sup || col->tete->e < b_inf)
		col->tete = col->tete->suiv;
	
}

void stats_to_file(Feuille feuille, FILE *fichier)
{
	char *nom_col[19] = {
	"USAGE_OF_BACKING_FILM",
	"USAGE_OF_DRESSER",
	"USAGE_OF_POLISHING_TABLE",
	"USAGE_OF_DRESSER_TABLE",
	"PRESSURIZED_CHAMBER_PRESSURE",
	"MAIN_OUTER_AIR_BAG_PRESSURE",
	"CENTER_AIR_BAG_PRESSURE",
	"RETAINER_RING_PRESSURE",
	"RIPPLE_AIR_BAG_PRESSURE",
	"USAGE_OF_MEMBRANE",
	"USAGE_OF_PRESSURIZED_SHEET",
	"SLURRY_FLOW_LINE_A",
	"SLURRY_FLOW_LINE_B",
	"SLURRY_FLOW_LINE_C",
	"WAFER_ROTATION",
	"STAGE_ROTATION",
	"HEAD_ROTATION",
	"DRESSING_WATER_STATUS",
	"EDGE_AIR_BAG_PRESSURE"
	};
	for (int i=0; i<19; i++)
	{
		fprintf(fichier,"%s\t", nom_col[i]);
		fprintf(fichier,"moyenne : %lf\t", moyenne(feuille.col[i]));
		fprintf(fichier,"min : %lf\t", min(feuille.col[i]));
		fprintf(fichier,"max : %lf\t", max(feuille.col[i]));
		fprintf(fichier,"ecart_type : %lf\t", ecart_type(feuille.col[i]));
		fprintf(fichier,"mediane : %lf\t", mediane(feuille.col[i]));
		fprintf(fichier,"q1 : %lf\t", q1(feuille.col[i]));
		fprintf(fichier,"q3 : %lf\t", q3(feuille.col[i]));
	}
	fprintf(fichier,"\n");
}


void main()
{
	
	
}



