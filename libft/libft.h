/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:16:25 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/09 22:06:32 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				**split_quotes(char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_itoalen(int n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *nptr);

int					ft_printf(const char *str, ...);
int					ft_typefinder(char c, va_list args);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putnbr_unsigned(unsigned int n);
int					ft_puthex(unsigned int n, int upper);
int					ft_putpointer(unsigned long n);
int					ft_putstr(char *str);
int					free_splits(char **line);

char				*get_next_line(int fd);
char				*ft_check_str(char *str, int charead);
char				*ft_buffer_to_str(char *src, int charead);
int					quotes_open(char *str, int target_index);

int					find_char(char c, char *find);
int					ft_str_has_newline(char *str);
int					ft_buffer_is_empty(char *buffer);

#endif
