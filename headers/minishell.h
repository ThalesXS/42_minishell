/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:06:26 by pabernar          #+#    #+#             */
/*   Updated: 2024/04/12 21:11:45 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*				Libraries					   */
/* ************************************************************************** */
# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <errno.h>
/* ************************************************************************** */
/*				Macros						   */
/* ************************************************************************** */
# define PROMPT "[Minishell]>"
/* ************************************************************************** */
/*				Structs						   */
/* ************************************************************************** */
/* *next -> if pipe. */

typedef struct s_minish
{
	char			*command;
	char			**args;
	struct s_envs	*envs;
	char			**redir_in;
	char			**redir_out;
	struct s_minish	*next;
}					t_minish;

typedef enum s_special
{
	DEFAULT,
	RD_OVERWRITE,
	RD_APPEND,
	RD_INPUT,
	RD_HEREDOC,
	PIPE,
	STRING
}					t_special;

typedef struct s_envs
{
	char			*key;
	char			*value;
	struct s_envs	*next;
}					t_envs;

typedef struct s_parsed
{
	char				*text;
	t_special			type;
	struct s_parsed		*next;
	struct s_parsed		*prev;
	int					unite_with_next;
}					t_parsed;

/* ************************************************************************** */
/*				Global Var					   */
/* ************************************************************************** */
extern int			g_signal;
/* ************************************************************************** */
/*				minishell.c					   */
/* ************************************************************************** */
void				ft_minishell(void);
/* ************************************************************************** */
/*				parser.c					   */
/* ************************************************************************** */
void				ft_parser(t_parsed *tokens);
int					redirect_check(char *line);
int					padding_needed(char *line, int i, int pad);
void				pad(char *src, char *dest, int i, int j);
int					pipe_checks(char *line);
char				*pad_central(char *line);
int					quotes_open(char *str, int target_index);
t_parsed			*make_list(char **args);
void				ft_farfaraway(t_parsed *tokens, int klen, char **new,
						char **tmp);
int					ft_check_open_quotes(char *line);
int					redirect_basic_check(char *line);
int					pipe_check(char *line);
int					redirect_basic_check(char *line);

/* ************************************************************************** */
/*				executer.c					   */
/* ************************************************************************** */
void				ft_executer(char *command, char **new_array,
						char **array_env, t_parsed *tokens);
void				ft_save_exit_status(int status, t_envs *envs);
/* ************************************************************************** */
/*				excve.c					       */
/* ************************************************************************** */
void				*ft_check_command(t_envs *envs, t_parsed *tokens);
void				ft_find_path(t_parsed *token, t_envs *envs);
/* ************************************************************************* */
/*				envs.c						   */
/* ************************************************************************** */
t_envs				*ft_create_envs(char **envp);
t_envs				*ft_new_env(char *str);
t_envs				*ft_add_env(t_envs *envs, t_envs *new);
char				**ft_array_envs(t_envs *envs);
t_envs				*ft_create_envs_for_export(t_envs *new, char **new_envs);
/* ************************************************************************** */
/*				api.c						   */
/* ************************************************************************** */
t_envs				*return_envs(t_envs *envs);
char				**return_argv(char **argv);
/* ************************************************************************** */
/*				signal.c					   */
/* ************************************************************************** */
void				ft_init_signals(void);
void				ft_ignore_signals(void);
void				ft_restore_signals(void);
void				ft_doc_signals(void);
t_parsed			**ft_save_commands(t_parsed **commands);

/* ************************************************************************** */
/*				builtins.c					   */
/* ************************************************************************** */
void				ft_exec_builtins(t_parsed *tokens,
						t_parsed **commands, int total_com);
/* ************************************************************************** */
/*				echo.c					   */
/* ************************************************************************** */
void				ft_exec_echo(t_parsed *tokens);
/* ************************************************************************** */
/*				cd.c					   */
/* ************************************************************************** */
void				ft_exec_cd(t_parsed *tokens, t_envs *envs);
/* ************************************************************************** */
/*				pwd.c					   */
/* ************************************************************************** */
void				ft_exec_pwd(void);
/* ************************************************************************** */
/*				export.c					   */
/* ************************************************************************** */
t_envs				*ft_exec_export(t_envs *envs,
						t_parsed *tokens, int total_com);
/* ************************************************************************** */
/*				unset.c					   */
/* ************************************************************************** */
t_envs				*ft_exec_unset(t_envs *envs, t_parsed *tokens);
/* ************************************************************************** */
/*				env.c					   */
/* ************************************************************************** */
void				ft_exec_env(t_envs *envs);
void				ft_exec_declare_env(t_envs *envs);
t_envs				*ft_return_new_env(t_envs *new, char **new_envs);
int					ft_expand_question_mark(t_parsed *tokens,
						char *new, char *tmp);
/* ************************************************************************** */
/*				exit.c					   	      */
/* ************************************************************************** */

/**
 * @brief Free the memory and exit the program.
 */
void				ft_exit(t_parsed *tokens, t_parsed *force_signal,
						t_parsed **commands, int total_com);

/* ************************************************************************** */
/*				signal_handlers.c				   */
/* ************************************************************************** */
void				ft_handle_eof(void);
void				ft_handle_sigint(int sig);
void				ft_handle_sigint_ign(int sig);
void				ft_handle_sigquit(int sig);
void				ft_handle_doc(int sig);
/* ************************************************************************** */
/*									directory.c								*/
/* ************************************************************************** */

/**
 * @brief Get the current directory.
 * @return char * with the current directory memory allocated.
 */
char				*ft_get_dir(void);
char				**ft_get_path(t_envs *envs);
char				*ft_get_pwd_env(void);

/* ************************************************************************** */
/*									split_token.c							*/
/* ************************************************************************** */

t_parsed			*ft_split_token(char *line);

/* ************************************************************************** */
/*									expander.c							*/
/* ************************************************************************** */
t_parsed			*ft_expand_variables(t_parsed *tokens);
int					ft_before_exp(char *str);
int					ft_key_len(char *str);

/* ************************************************************************** */
/*									treat_token.c							*/
/* ************************************************************************** */
void				ft_treat_token(t_parsed **token, char *line);

/* ************************************************************************** */
/*									pipe.c							*/
/* ************************************************************************** */
void				ft_pipe(int *num_com, int total_com, pid_t parent);
int					valid_tokens(t_parsed *tokens);

/* ************************************************************************** */
/*									redirect.c							*/
/* ************************************************************************** */
pid_t				ft_manage_heredoc(int pipe_fd[2], char *heredoc,
						int std_0, t_parsed **tokens);
int					ft_redirect(t_parsed **tokens, int num_com, int std_0);
void				ft_in_doc(int pipe_fd[2], char *heredoc);
int					ft_write_append(t_parsed **aux, t_parsed **tokens,
						int num_com, int flag);
int					ft_input(t_parsed **aux, t_parsed **tokens, int num_com);
int					ft_doc(t_parsed **aux, t_parsed **tokens,
						int num_com, int std_0);
/* ************************************************************************** */
/*									free.c							*/
/* ************************************************************************** */

void				ft_free_commands(t_parsed **commands, int total_com);
void				ft_free_tokens(t_parsed *tokens);
t_envs				*ft_free_envs(t_envs *envs);
void				ft_free_array(char **arr);

// FIX FILE ORDER
void				ft_io_reset(int *std_fd);
int					ft_get_fd(t_parsed *aux, t_parsed **tokens,
						int num_com, int std_0);
int					ft_invalid_pipe(t_parsed *tokens);
void				ft_void_text(t_parsed **aux, t_parsed **to_free,
						t_parsed **tokens);
void				ft_define_error(char *command, struct stat path_stat);
void				ft_head_cd(t_envs *head, t_envs *envs);
void				ft_test_dir(char *args, t_envs *envs, char *curr_dir,
						char *old_pwd);
void				ft_found(t_envs *envs, char *key,
						t_envs **start, t_envs *last);
int					ft_check_quotes_and_exp(char *str);
#endif
