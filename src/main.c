#include "ft_script.h"

// Initialisation par défaut
void init_env(t_script *env)
{
    env->opt_a = 0;
    env->opt_q = 0;
    env->filename = "typescript"; // Valeur par défaut
    env->fd_out = -1;
}

// Parsing rudimentaire
int parse_args(int ac, char **av, t_script *env)
{
    int i = 1;

    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            if (ft_strncmp(av[i], "-a", 3) == 0)
                env->opt_a = 1;
            else if (ft_strncmp(av[i], "-q", 3) == 0)
                env->opt_q = 1;
            else
            {
                ft_putstr_fd("ft_script: invalid option\n", 2);
                return (1);
            }
        }
        else
        {
            env->filename = av[i];
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_script env;

    init_env(&env);
    
    if (parse_args(ac, av, &env) != 0)
        return (1);
        
    if (open_typescript(&env) != 0)
        return (1);
        
    print_start_message(&env);

    if (init_pty(&env) != 0)
    {
        close(env.fd_out);
        return (1);
    }

    sync_window_size(&env);

    if (save_and_set_raw_mode(&env) != 0)
    {
        close(env.fd_master);
        close(env.fd_slave);
        close(env.fd_out);
        return (1);
    }

    if (run_shell(&env, envp) != 0)
    {
        restore_terminal(&env);
        close(env.fd_master);
        close(env.fd_slave);
        close(env.fd_out);
        return (1);
    }

    // =========================================================
    // Étape 5 - Multiplexage : Le pont est activé !
    // =========================================================
    multiplex_io(&env);

    // Si on sort de multiplex_io, c'est que le shell est terminé.
    // On attend proprement le processus enfant pour éviter les zombies
    waitpid(env.child_pid, NULL, 0);

    // =========================================================
    // Nettoyage final et message de fin
    // =========================================================
    restore_terminal(&env);
    print_end_message(&env);

    close(env.fd_master);
    close(env.fd_out);
    
    return (0);
}