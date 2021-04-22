/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

static const int SUCCESS = 0;
static const int ERROR = 84;

typedef struct check_s
{
    int n;
    int c;
}check_t;

int CMD_LEN;
char **TOTAL_CMDS;
char **TOTAL_FILE;

int gestion_arguments(int argc, char **argv);
int label(char *filename);
char **analyse(char **map, char *filename);
void my_puts(int c, char *line);
char *my_itoa(int nbr);
int my_strlen(char const *str);
char **verif_command(char **map, char *filename);
char *my_line(char *line);
char *sp_l(char const *str1);
char *my_cpy(char *str);
int *get_cmds_len(char **cmds, int max);
int my_strcmp(char const *str1, char const *str2);
void error(char *file, int i, int c, int p);
void error_n(char *file, int i);
char **replace_labels(char **cmds, int *cmds_len);
void verify_labels(char **cmds, char *filename);
void write_zork(char **map, char **cmds, char *filename);
void write_cmds(char *line, int out);
int get_c(char const *line, int start, char c);
int cmp_c(char const *line, int d, char c);
void write_nb(int out, int nb, int size, int v);
int cmp_c(char const *line, int d, char c);
int get_c(char const *line, int start, char c);
int convert_op(int p1, int p2);
int new_label(char **cmds, char *label, int *cmds_len, int i);
int label_line(char **cmds, char *label);
void fill_with_zero(int out, int ct_line, int type);
int htoi(const char *s);
void verify_cmds(char **cmds, char *filename);
int cmp_l(char const *str1, char const *str2);
int is_label(char c);

int c_ld(char *line);
int c_st(char *line);
int c_op(char *line);
int c_ldi(char *line);
int c_sti(char *line);
int s_ld(char *line);
int s_st(char *line);
int s_op(char *line);
int s_ldi(char *line);
int s_sti(char *line);

int nxtnbr(char *str, int *u);
int w_first(char *line, int u, int out, int t);
int w_next(char *line, int u, int out, int t);
void w_aff(char *line, int out);
void w_lfork(char *line, int out);
void w_lldi(char *line, int out);
void w_lld(char *line, int out);
void w_fork(char *line, int out);
void w_sti(char *line, int out);
void w_ldi(char *line, int out);
void w_zjmp(char *line, int out);
void w_xor(char *line, int out);
void w_or(char *line, int out);
void w_and(char *line, int out);
void w_sub(char *line, int out);
void w_add(char *line, int out);
void w_st(char *line, int out);
void w_ld(char *line, int out);
void w_live(char *line, int out);

void verif_dnr(char *line, int u, int li, char *filename);
void verif_inr(char *line, int u, int li, char *filename);
void verif_dni(char *line, int u, int li, char *filename);
void verif_all(char *line, int u, int li, char *filename);
void verif_ind(char *line, int u, int li, char *filename);
void verif_reg(char *line, int u, int li, char *filename);
void verif_dir(char *line, int u, int li, char *filename);
void v_aff(char *line, int i, char *filename);
void v_sti(char *line, int i, char *filename);
void v_ldi(char *line, int i, char *filename);
void v_zjmp(char *line, int i, char *filename);
void v_ctrl(char *line, int i, char *filename);
void v_op(char *line, int i, char *filename);
void v_st(char *line, int i, char *filename);
void v_ld(char *line, int i, char *filename);
void v_live(char *line, int i, char *filename);

#endif /* !ASM_H_ */
