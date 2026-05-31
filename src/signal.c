#include "ft_script.h"

// On a besoin d'accéder à env depuis le signal handler
static t_script *g_env = NULL;

void sigwinch_handler(int sig)
{
    (void)sig;
    if (g_env)
        sync_window_size(g_env);
}

void setup_signals(t_script *env)
{
    g_env = env; // On lie notre globale à l'environnement

    // Quand la fenêtre change de taille, on déclenche le handler
    signal(SIGWINCH, sigwinch_handler);
}