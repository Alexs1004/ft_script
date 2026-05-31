#include "ft_script.h"

// Restaurer la configuration d'origine
void restore_terminal(t_script *env)
{
    // TCSETS applique la configuration
    // STDIN_FILENO (0) est l'entrée standard
    ioctl(STDIN_FILENO, TCSETS, &env->orig_termios);
}

// Sauvegarder et passer en mode RAW
int save_and_set_raw_mode(t_script *env)
{
    struct termios raw;

    // 1. Sauvegarder la configuration actuelle via TCGETS (remplace tcgetattr)
    if (ioctl(STDIN_FILENO, TCGETS, &env->orig_termios) < 0)
    {
        ft_putendl_fd("ft_script: failed to get terminal attributes", 2);
        return (1);
    }

    // 2. Copier la configuration pour la modifier
    raw = env->orig_termios;

    // 3. Modifier les flags pour le mode RAW
    // c_lflag (Local flags) : 
    // - ISIG   : Désactive la gestion de l'interruption (Ctrl+C, Ctrl+Z)
    // - ICANON : Désactive le mode ligne par ligne
    // - ECHO   : Désactive l'affichage automatique des touches pressées
    // - IEXTEN : Désactive les fonctions d'extension d'entrée
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // c_iflag (Input flags) :
    // - BRKINT, ICRNL, INPCK, ISTRIP, IXON : Désactive la traduction des retours charriot et le contrôle de flux
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    // c_cflag (Control flags) : Définit la taille des caractères à 8 bits
    raw.c_cflag &= ~(CSIZE | PARENB);
    raw.c_cflag |= CS8;

    // c_oflag (Output flags) : Désactive le post-processing de sortie
    raw.c_oflag &= ~(OPOST);

    // 4. Appliquer la nouvelle configuration via TCSETS (remplace tcsetattr)
    if (ioctl(STDIN_FILENO, TCSETS, &raw) < 0)
    {
        ft_putendl_fd("ft_script: failed to set raw mode", 2);
        return (1);
    }

    return (0);
}