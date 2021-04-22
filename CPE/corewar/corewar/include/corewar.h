/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"

typedef struct verif_s {
    int alive;
    int is_number;
    int is_memory;
} verif_t;

typedef struct champion_s {
    int nb_player;
    verif_t verif;
    char *filename;
    char *name;
    char *comment;
    char *code;
    int code_size;
    int mem_index;
    int pc;
    int wait_time;
    int reg[REG_NUMBER];
    int carry;
    int is_dead;
} champion_t;

typedef struct instruction_s {
    char mnemonic;
    int (*func)(champion_t *champion, char *map);
} instruction_t;

typedef struct mem_value_s {
    int value;
    int type;
} mem_value_t;

enum {
    MAX_CHAMPION = 4,
    SUCCESS = 0,
    ERROR = 84,
};

enum {
    B_REG = 1,
    B_DIR = 2,
    B_IND = 3,
};

typedef struct data_s {
    champion_t champion[MAX_CHAMPION + 1];
    int dump;
    int time_cycle_die;
    int last_live;
    char *last_name;
} data_t;

//  Gestion input
int gestion_argument(int argc, char **argv);

//  Take a certain number of bytes after a position
int take_nb_bytes(int nb_bytes, char *map, int pos);

//  Tools
int my_strcmp(char const *str, char const *comp);
int my_strlen(char const *str);
int mgetnbr(char *str);
char *my_strcat(char *str1, char *str2, int str1_size, int str2_size);
void my_put(char const *str, int std);
char *my_strcpy(char *str);
int bytes_to_int(char *map, int start, int size);
int mputnbr(int nb);
void print_in_mem(char *map, int index, int size, int nbr);

//  Display help
void display_help(void);

//  init data
void init_data(data_t *data);

//  Create
char *create_map(void);

//Load champion
int fill_data(char **argv, int i, data_t *data);
void memory_champ(char **argv, int i, champion_t *champion);
int load_champion(champion_t *champion);
char *get_champ_name(char *content, int *index, int size);
char *get_champ_comment(char *content, int *index, int size);
char *get_champ_code(char *content, int *index, int size);
int place_champion(char *map, champion_t *champion);

//  Verif
int multiple_definition(champion_t *champion, char **argv);
int multiple_memory(champion_t *champion, char **argv);
int check_nb(int *tab, int nb, char *commit);

//vm
int vm(data_t *data);
void dump_memory(char *map);

//Champion instruction
int exec_champion(champion_t *champion, char *map);
int champ_live(champion_t *champion, char *map);
int champ_ld(champion_t *champion, char *map);
int champ_st(champion_t *champion, char *map);
int champ_add(champion_t *champion, char *map);
int champ_sub(champion_t *champion, char *map);
int champ_and(champion_t *champion, char *map);
int champ_or(champion_t *champion, char *map);
int champ_xor(champion_t *champion, char *map);
int champ_zjmp(champion_t *champion, char *map);
int champ_ldi(champion_t *champion, char *map);
int champ_sti(champion_t *champion, char *map);
int champ_fork(champion_t *champion, char *map);
int champ_lld(champion_t *champion, char *map);
int champ_lldi(champion_t *champion, char *map);
int champ_lfork(champion_t *champion, char *map);
int champ_aff(champion_t *champion, char *map);
void end_instruction(char *map, champion_t *champion, mem_value_t *value);

int load_value(char *map, int index, mem_value_t **value, int *type);

#endif /* !COREWAR_H_ */
