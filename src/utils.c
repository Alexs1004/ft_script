#include "ft_script.h"

int open_typescript(t_script *env)
{
    int flags;

    // O_WRONLY : écriture seule
    // O_CREAT : créer le fichier s'il n'existe pas
    flags = O_WRONLY | O_CREAT;

    if (env->opt_a)
        flags |= O_APPEND; // Ne pas écraser, écrire à la fin
    else
        flags |= O_TRUNC;  // Écraser le fichier s'il existe déjà

    // 0664 correspond aux permissions rw-rw-r--
    env->fd_out = open(env->filename, flags, 0664);
    
    if (env->fd_out < 0)
    {
        ft_putstr_fd("ft_script: cannot open ", 2);
        ft_putendl_fd(env->filename, 2);
        return (1);
    }
    return (0);
}

void print_start_message(t_script *env)
{
    time_t      rawtime;
    char        *time_str;

    // Récupérer l'heure actuelle
    time(&rawtime);
    time_str = ctime(&rawtime); // format : "Day Mon DD HH:MM:SS YYYY\n"

    // Écriture sur la sortie standard (si on n'est pas en mode quiet)
    if (!env->opt_q)
    {
        ft_putstr_fd("Script started, file is ", 1);
        ft_putendl_fd(env->filename, 1);
    }

    // Écriture dans le fichier de log (toujours présent)
    ft_putstr_fd("Script started on ", env->fd_out);
    ft_putstr_fd(time_str, env->fd_out);
}