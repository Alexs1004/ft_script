#include "ft_script.h"

int multiplex_io(t_script *env)
{
    fd_set  read_fds;
    int     max_fd;
    char    buffer[4096];
    ssize_t bytes_read;

    // Le select a besoin du FD le plus élevé pour savoir jusqu'où vérifier
    max_fd = env->fd_master > STDIN_FILENO ? env->fd_master : STDIN_FILENO;

    while (1)
    {
        // 1. Initialiser le set de File Descriptors à zéro
        FD_ZERO(&read_fds);
        
        // 2. Ajouter notre clavier (0) et le shell (master) au set
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(env->fd_master, &read_fds);

        // 3. Attendre qu'il se passe quelque chose (bloquant)
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0)
            break; // Si select plante (ex: signal reçu), on quitte

        // ========================================================
        // CAS A : Le shell a envoyé quelque chose (affichage)
        // ========================================================
        if (FD_ISSET(env->fd_master, &read_fds))
        {
            bytes_read = read(env->fd_master, buffer, sizeof(buffer));
            if (bytes_read <= 0)
                break; // Le shell s'est terminé (ex: l'utilisateur a tapé 'exit')
            
            // On l'affiche sur notre vrai terminal
            write(STDOUT_FILENO, buffer, bytes_read);
            // On l'écrit dans le fichier de log typescript
            write(env->fd_out, buffer, bytes_read);
        }

        // ========================================================
        // CAS B : L'utilisateur a tapé sur son clavier
        // ========================================================
        if (FD_ISSET(STDIN_FILENO, &read_fds))
        {
            bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
            if (bytes_read <= 0)
                break; // L'utilisateur a fermé l'entrée (Ctrl+D)
            
            // On envoie la frappe au shell
            write(env->fd_master, buffer, bytes_read);
        }
    }
    return (0);
}