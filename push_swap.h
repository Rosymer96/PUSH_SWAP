#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data {
    int *stack_a;
    int size;
    int strategy;
    int bench_mode;
    double disorder;
} t_data;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void update_flag(t_data *data, char *arg);
void free_and_exit(t_*data, char **nums_split, int status);
char	**ft_split(char const *s, char c);
void free_split(char **words);











#endif