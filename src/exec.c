#include "ft_script.h"

int run_shell(t_script *env, char **envp)
{
    char *shell;
    char *args[2]; // Un tableau statique pour args: le nom du shell, et NULL

    shell = get_shell(envp);
    args[0] = shell;
    args[1] = NULL;

    // Création du processus enfant
    env->child_pid = fork();
    if (env->child_pid < 0)
    {
        ft_putendl_fd("ft_script: fork failed", 2);
        return (1);
    }
    
    if (env->child_pid == 0)
    {
        /* --- PROCESSUS ENFANT --- */
        // L'enfant n'a pas besoin du fd master ni du fd de log
        close(env->fd_master);
        close(env->fd_out);

        // Rediriger l'entrée (0), la sortie (1) et l'erreur (2) vers le PTY slave
        dup2(env->fd_slave, STDIN_FILENO);
        dup2(env->fd_slave, STDOUT_FILENO);
        dup2(env->fd_slave, STDERR_FILENO);
        close(env->fd_slave);

        // Remplacer le processus actuel par le shell
        execve(shell, args, envp);
        
        // Si execve échoue, le code ci-dessous s'exécute
        ft_putendl_fd("ft_script: execve failed", 2);
        _exit(1); // On quitte brusquement l'enfant pour ne pas polluer le parent
    }
    else
    {
        /* --- PROCESSUS PARENT --- */
        // Le parent n'interagira plus jamais directement avec le slave
        close(env->fd_slave);
    }
    
    return (0);
}