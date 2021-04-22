/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

static const int MAX_HISTORY = 10000;
#define SIZE_FUNC 10
#define SIZE_EXEC 3

static const int SUCCESS = 0;
static const int ERROR = 84;
static const int STAY = -1;
static const int TRUE = 1;
static const int FALSE = 0;

typedef struct data_s {
    char **envp;
    char **aliases;
    char **sets;
    int history_index;
    char **history;
    int child_nb;
} data_t;

enum {
    EMPTY = 0,
    COMA,
    ESPER,
    DOUBLE_PIPE,
    PIPE,
    SIMPLE_LEFT,
    SIMPLE_RIGHT,
    DOUBLE_RIGHT,
    DOUBLE_LEFT,
};

typedef struct node_s {
    int symbol;
    char **command;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef struct list_s {
    char *command;
    struct list_s *next;
} list_t;

typedef struct my_func_s {
    int (* func_ptr)(data_t *data, char **arg);
    char name[100];
} my_func_t;

//  History
void fill_history(char *input, data_t *data);
int initialize_history(data_t *data);

//  Chain list
int add_element(list_t **list, char *command);
int add_element_tree(node_t **tree, char *symbol, char **command);
int final_add(node_t **tree, char **command);
int add_left(node_t **left, node_t **tmp_tree, char **command);
int add_right(node_t **right, node_t **tmp_tree, int symbol, char **command);

int minishell(char **envp);
char *get_input(void);
int str_compare(char const *str1, char const *str2);
int compare_var(char *str1, char *str2);
char *get_first_word(char *str);
char **my_str_to_word_array(char const *str);
int my_strlen(char *str);
char **add_to_array(char **array, char *str);
int is_alpha(char const *str);
char *conc_env_name(char *part1, char *part2);
char **copy_table(char **table);
char *generate_row(char *str);
int count_size_array(char **array);
char **remove_from_array(char *str, char **array);
char **remove_at_index(char **array, int index_rm);
int my_getnbr(char *str);
int is_number(char *str);
char *get_env(char *var_name, char **envp);
int replace_env(char *var_name, char *value, char **envp);
char *create_dirpath(char *start, char *end);
int exec_with_arg(char **argv, char **envp);
char *my_strcpy(char *src);
char **get_arg(char *input);
int translate_symbol(char *symbol);
int jump_space(char *str, int start);
char *copy_command(char *str, int start);
int parser(char *input, node_t **tree, data_t *data);
int is_next_symbol(char *input, int start);
int split_parser(char *input, data_t *data);
int input_pipe(node_t *tree);
int wait_child(data_t *data);
int cmd_seperator(node_t *tree, data_t *data, int prev_pipe[2]);
int create_link(node_t *tree, data_t *data, int input[2], int ouput[2]);
int handle_builtin(data_t *data, char **arg);

//Print
void mputerror(char *str);

//Tool
int is_word_in_str_env(char *word, char *str);
int where_word_in_arr_env(char *word, char **arr);
int is_word_in_arr(char *word, char **arr);
int is_word_in_arr_env(char *word, char **arr);
int is_word_in_str(char *word, char *str);
int only_space(char const *str, int index);

//Exec path
char *get_exec_path(char *prog_name, char **envp);
int get_path(char ***arg, char **env);

//Command
int my_exit(data_t *data, char **input);
int my_echo(data_t *data, char **input);
int my_history(data_t *data, char **input);
int my_excla(data_t *data, char **input);
// ---> cd
int my_cd(data_t *data, char **input);
int my_cd_no_arg(data_t *data);
int set_pwd(data_t *data);
int set_old_pwd(data_t *data);
int my_cd_malus(data_t *data);
// cd <---
int my_env(data_t *data, char **input);
int my_setenv(data_t *data, char **imput);
int my_unsetenv(data_t *data, char **imput);
int command_handler(node_t *tree, data_t *data, int prev_pipe[2]);
int split_command(char *input, data_t *data);
int my_exec(data_t *data, char **input);
int exec_pipe(char **argv, data_t *data);
void display_status(int status);

//Aliases
char **reverse_alias(char **lines, char **data);
int alias(data_t *data, char **tab);
int unalias(data_t *data, char **tab);
char **add_alias(char *line, char **alias);
//Aliases(inside)
int strcmpalias(char *line, char *alias);
char *get_dest(char *line);
char *get_alias(char *line);
int find_alias(char *input, char **env, int mv);
char *make_alias_line(char *input);
char **init_aliases(void);
int only_alias(char *line);
int print_alias(char *line, char **aliases);
char **my_arrcpy(char **array, int add);

//Local_var
int my_unset(data_t *data, char **tab);
int my_set(data_t *data, char **tab);
//local_var(inside)
char *get_full_line(char **tab);
int print_set(char *line, char **sets);
char **init_sets(void);
char *make_set_line(char *input);
int find_set(char *input, char **env, int mv);
char *get_set(char *line);
char *get_set_dest(char *line);

void verif_arg(char **arg, data_t *data);
void verif_cat(char **arg);

#endif
