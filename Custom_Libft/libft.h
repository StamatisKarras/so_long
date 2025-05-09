/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:23:07 by skarras           #+#    #+#             */
/*   Updated: 2025/03/05 13:54:21 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_buffer {
	int		fd;
	int		eof;
	size_t	flushed_bytes;
	size_t	unflushed_bytes;
	char	memory[BUFFER_SIZE];
}	t_buffer;

typedef struct s_line {
	char			*line;
	ssize_t			new_line_index;
}	t_line;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *strn);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_itoa(int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
void		ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest_str, const void *src_str, size_t n);
void		*ft_memmove(void *dest_str, const void *src_str, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
char		*get_next_line(int fd);
void		*ft_memmove(void *dest_str, const void *src_str, size_t n);
char		*ft_strjoin_and_free(char *s1, char *s2);
size_t		ft_strlen(const char *s);
int			ft_printf_normal(const char *s);
int			ft_printf(const char *s, ...);
int			sorting_hat(const char *s, va_list args);
int			print_char(int c);
int			putnbr_count(int n);
int			put_str_count(const char *s);
int			strlen_count(const char *s);
int			print_usnigned(unsigned int n, int count);
int			print_hex(unsigned long long nb, char type);
int			print_pointer(unsigned long nb, int count);
int			outoflines(const char *s, va_list args);
size_t		ft_len(const char *strn);
char		*ft_allocation(int len);
int			ft_count_n(int c);
char		*my_itoa(int n);
void		putstr_fd(char *s, int fd);

#endif
