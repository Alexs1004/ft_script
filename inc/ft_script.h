#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include "../libft/libft.h"


typedef struct s_script
{
    int     opt_a;      // Flag pour -a (append)
    int     opt_q;      // Flag pour -q (quiet)
    char    *filename;  // Nom du fichier de sortie
    int     fd_out;     // Descripteur de fichier pour la sortie
}   t_script;

/* utils.c */
int    open_typescript(t_script *env);
void   print_start_message(t_script *env);

#endif