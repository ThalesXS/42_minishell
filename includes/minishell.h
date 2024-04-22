/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:06:26 by pabernar          #+#    #+#             */
/*   Updated: 2024/04/22 12:18:27 by txisto-d         ###   ########.fr       */
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

typedef enum s_special
{
	DEFAULT,
	RD_OVERWRITE,
	RD_APPEND,
	RD_INPUT,
	RD_HEREDOC,
	PIPE,
	STRING,
	EMPTY
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

typedef struct s_processio
{
	char		*line;
	t_parsed	**commands;
	pid_t		parent_pid;
	pid_t		child_pid;
	int			num_com;
	int			total_com;
	int			std_fd[2];
	int			pipe_fd[2];
	int			redirect_fd;
	int			redirect_signal;
}				t_processio;

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
void				ft_parser(t_parsed *tokens, char *line);
int					padding_needed(char *line, int i, int pad);
void				pad(char *src, char *dest, int i, int j);
char				*pad_central(char *line);
int					quotes_open(char *str, int target_index);
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
void				ft_mslvl(t_envs *envs, char *envp);
/* ************************************************************************** */
/*				api.c						   */
/* ************************************************************************** */
t_envs				*return_envs(t_envs *envs);
char				**return_argv(char **argv);
t_processio			*ft_return_processio(t_processio *processio);
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
t_envs				*ft_exec_unset(t_envs *envs, t_parsed *tokens,
						int total_com);
/* ************************************************************************** */
/*				env.c					   */
/* ************************************************************************** */
void				ft_exec_env(t_envs *envs);
void				ft_exec_declare_env(t_envs *envs);
t_envs				*ft_return_new_env(t_envs *new, char **new_envs);
void				ft_expand_question_mark(t_parsed *tokens,
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
void				ft_userhandler(void);
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
pid_t				ft_pipe(t_processio *processio);
int					valid_tokens(t_parsed *tokens);

/* ************************************************************************** */
/*									redirect.c							*/
/* ************************************************************************** */
pid_t				ft_manage_heredoc(int pipe_fd[2], char *heredoc,
						t_processio *processio);
int					ft_redirect(t_processio *processio);
void				ft_in_doc(int pipe_fd[2], char *heredoc);

/* ************************************************************************** */
/*									free.c							*/
/* ************************************************************************** */

void				ft_free_commands(t_parsed **commands, int total_com);
void				ft_free_tokens(t_parsed *tokens);
t_envs				*ft_free_envs(t_envs *envs);
void				ft_free_array(char **arr);
void				ft_err_msg(char *error, int signal);

//	====================		expander_utils.c			====================
void				ft_init_temp(t_parsed *tokens, int *klen, char **point,
						char **tmp);
void				ft_null_text(t_parsed **aux, t_parsed **tokens,
						t_parsed **to_free);
int					ft_prev_is_redirect(t_parsed *aux);
int					ft_before_exp(char *str);

//	====================		redirect_utils.c			====================
void				ft_delete_redirects(t_parsed **aux, t_parsed **tokens,
						int num_com);

//	====================			pipe_utils.c			====================
int					ft_syntax_error(void);

//	====================			envs_utils.c			====================
void				ft_mslvl(t_envs *envs, char *envp);

//	====================			cd_utils.c				====================
void				ft_errno(void);
void				ft_while_else(char	**helper_pwd,
						char **helper2, t_envs **head);
void				ft_get_oldpwd_dir(t_envs *envs);
void				ft_update_curr_dir(t_envs *envs,
						char *curr_dir, char *old_pwd);
void				ft_retrieve_io(t_processio *processio);
void				ft_finish_redirect(t_processio *processio);
char				*ft_expand_heredoc(char *line, t_envs *envs);
char				*ft_getenv(char *key, t_envs *envs);
size_t				ft_envlen(char *str);
void				ft_free_expander(char *value, char *beginner, char *mid,
						char *line);
#endif