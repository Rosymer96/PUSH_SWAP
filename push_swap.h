#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
typedef struct s_data {
    int *stack_a;
    int size;
    int strategy;
    int bench_mode;
    double disorder;
} t_data;

// Gestion de memoria y salida en caso de error
void free_and_exit(t_data *data, char **nums_split, int status);
void free_split(char **words);
//Parseo y flags
int is_flag(char *arg);
void update_flag(t_data *data, char *arg);
int process_num(char **nums_split, t_data *data);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
//Validacion y conversion de numeros
int is_numeric(char *str);
long long ft_atoll(char *str);
int check_duplicates(int *stack, int size);
int add_to_stack(t_data *data, int val);

//Funciones de algoritmos ALBA











#endif