#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include "../libft/libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/select.h>
# include <signal.h>


typedef struct s_script
{
    int     opt_a;      // Flag pour -a (append)
    int     opt_q;      // Flag pour -q (quiet)
    char    *filename;  // Nom du fichier de sortie
    int     fd_out;     // Descripteur de fichier pour la sortie

    int     fd_master;
    int     fd_slave;
    char    slave_name[256]; // Buffer statique pour éviter malloc !

    struct termios  orig_termios;

    pid_t           child_pid;
}   t_script;

/* utils.c */
int     open_typescript(t_script *env);
void    print_start_message(t_script *env);
void    print_end_message(t_script *env);
char    *get_shell(char **envp);

/* pty.c */
int     init_pty(t_script *env);
void    sync_window_size(t_script *env);

/* terminal.c */
int     save_and_set_raw_mode(t_script *env);
void    restore_terminal(t_script *env);

/* exec.c */
int     run_shell(t_script *env, char **envp);

/* multiplex.c */
int     multiplex_io(t_script *env);

#endif