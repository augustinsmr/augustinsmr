/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function that counts and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int compteur = 0;

    while (str[compteur] != '\0'){
        compteur ++;
    }
    return compteur;
}
