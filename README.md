# Projet get_next_line
## Description
Le but de ce projet est d'implémenter une fonction get_next_line qui permet de lire une ligne d'un fichier ou de l'entrée standard. Cette ligne peut être de n'importe quelle longueur et doit être retournée à chaque appel de la fonction, jusqu'à ce que la fin du fichier soit atteinte. L'idée est de lire le fichier morceau par morceau (par petits blocs de mémoire) et de gérer cette mémoire efficacement.

La fonction get_next_line lira une ligne entière et renverra un pointeur vers cette ligne, sans perdre de données. Si un appel de la fonction atteint la fin du fichier ou de l'entrée, il renverra NULL.

Fonction à Implémenter
La fonction que tu dois implémenter est :

  ```c
  char *get_next_line(int fd);
  ```
Où :

fd : un descripteur de fichier, souvent obtenu par open ou STDIN_FILENO pour l'entrée standard.

La fonction renverra une chaîne de caractères (la ligne lue).

Si elle atteint la fin du fichier, elle retournera NULL.

Comportement de get_next_line
La fonction doit lire une ligne à la fois. Une ligne est définie comme tout texte se trouvant avant un caractère '\n' (nouvelle ligne) ou jusqu'à la fin du fichier. Si la fonction rencontre un '\n', elle doit considérer tout ce qui précède ce caractère comme une ligne et le renvoyer. Si la fin du fichier est atteinte, la fonction retourne NULL.
  ```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("mon_fichier.txt", O_RDONLY);
    char *line;

    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);  // Libérer la mémoire allouée après chaque ligne
    }

    close(fd);
    return 0;
}
```
Ce que tu dois faire :
Lire le fichier : La fonction get_next_line doit lire le fichier ou l'entrée ligne par ligne. Elle lira par petits blocs (par exemple, un tampon de taille fixe) et devra être capable de gérer les lectures partielles (lorsqu'une ligne est trop grande pour être lue en une seule fois).

Gérer la mémoire : À chaque appel de la fonction, tu devras allouer de la mémoire pour stocker la ligne lue. Une fois que la ligne a été utilisée, tu dois libérer cette mémoire pour éviter les fuites de mémoire.

Gérer la fin du fichier : Lorsque la fonction rencontre la fin du fichier, elle devra retourner NULL. Cela se fait souvent en vérifiant si le nombre de caractères lus est égal à 0.

Utiliser les fonctions de la bibliothèque standard : Tu devras probablement utiliser les fonctions read() pour lire à partir d'un fichier, ainsi que malloc() et free() pour gérer la mémoire.

Gestion des tampons : Une partie clé du projet consiste à gérer un tampon pour stocker temporairement les données lues et à gérer ce tampon pour obtenir les lignes complètes à retourner.
