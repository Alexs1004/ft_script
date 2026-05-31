#include "ft_script.h"

// Initialisation par défaut
void init_env(t_script *env)
{
    env->opt_a = 0;
    env->opt_q = 0;
    env->filename = "typescript"; // Valeur par défaut
    env->fd_out = -1;
}

// Parsing rudimentaire (à adapter selon tes besoins exacts)
int parse_args(int ac, char **av, t_script *env)
{
    int i = 1;

    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            // Vérification des flags
            if (ft_strncmp(av[i], "-a", 3) == 0)
                env->opt_a = 1;
            else if (ft_strncmp(av[i], "-q", 3) == 0)
                env->opt_q = 1;
            else
            {
                ft_putstr_fd("ft_script: invalid option\n", 2);
                return (1); // Retour d'erreur propre
            }
        }
        else
        {
            // Si ce n'est pas une option, c'est le fichier cible
            env->filename = av[i];
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_script env;

    init_env(&env);
    
    if (parse_args(ac, av, &env) != 0)
        return (1);
        
    if (open_typescript(&env) != 0)
        return (1);
        
    print_start_message(&env);

    // TODO: Étape 2 - Ouverture du PTY master / slave
    // TODO: Étape 3 - Sauvegarde et mode RAW du terminal
    // TODO: Étape 4 - Fork et exécution du shell
    // ...

    // Fin temporaire pour tester ton étape 1
    close(env.fd_out);
    return (0);
}