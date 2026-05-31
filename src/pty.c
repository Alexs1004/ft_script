#include "ft_script.h"
#include <sys/ioctl.h>
#include <fcntl.h>

// Fonction utilitaire pour ajouter le numéro au chemin sans utiliser malloc
static void build_slave_name(char *buffer, int pty_num)
{
    int     i;
    int     temp;
    int     digits;
    char    num_str[12]; // Assez grand pour un int

    ft_strlcpy(buffer, "/dev/pts/", 256);
    
    // Gérer le 0 explicitement
    if (pty_num == 0)
    {
        ft_strlcat(buffer, "0", 256);
        return;
    }

    // Convertir l'entier en chaîne (à l'envers)
    i = 0;
    temp = pty_num;
    while (temp > 0)
    {
        num_str[i++] = (temp % 10) + '0';
        temp /= 10;
    }
    digits = i;

    // Inverser et concaténer
    while (digits > 0)
    {
        digits--;
        int len = ft_strlen(buffer);
        if (len < 255)
        {
            buffer[len] = num_str[digits];
            buffer[len + 1] = '\0';
        }
    }
}


// Initialise le PTY maître/esclave et ouvre les descripteurs.
int init_pty(t_script *env)
{
    int pty_num;
    int unlock;

    unlock = 0;

    // 1. Ouvrir le master PTY
    // O_RDWR : Lecture et écriture
    // O_NOCTTY : Ne pas faire de ce terminal le terminal de contrôle
    env->fd_master = open("/dev/ptmx", O_RDWR | O_NOCTTY);
    if (env->fd_master < 0)
    {
        ft_putendl_fd("ft_script: failed to open /dev/ptmx", 2);
        return (1);
    }

    // 2. Obtenir le numéro du slave assigné (Remplace ptsname)
    if (ioctl(env->fd_master, TIOCGPTN, &pty_num) < 0)
    {
        ft_putendl_fd("ft_script: ioctl TIOCGPTN failed", 2);
        close(env->fd_master);
        return (1);
    }

    // 3. Déverrouiller le slave (Remplace unlockpt)
    if (ioctl(env->fd_master, TIOCSPTLCK, &unlock) < 0)
    {
        ft_putendl_fd("ft_script: ioctl TIOCSPTLCK failed", 2);
        close(env->fd_master);
        return (1);
    }

    // 4. Construire le chemin complet vers le slave
    build_slave_name(env->slave_name, pty_num);

    // 5. Ouvrir le slave pour s'assurer qu'il est accessible
    env->fd_slave = open(env->slave_name, O_RDWR | O_NOCTTY);
    if (env->fd_slave < 0)
    {
        ft_putstr_fd("ft_script: failed to open slave ", 2);
        ft_putendl_fd(env->slave_name, 2);
        close(env->fd_master);
        return (1);
    }

    return (0);
}

void sync_window_size(t_script *env)
{
    struct winsize ws;

    // 1. Récupérer la taille du vrai terminal
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) < 0)
        return;

    // 2. Appliquer cette taille au PTY
    if (env->fd_master >= 0)
        ioctl(env->fd_master, TIOCSWINSZ, &ws);
}