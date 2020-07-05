/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:07:03 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:07:05 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>

# define BUFF_SIZE 1000

# define FT_ABS(n) ((n < 0) ? -n : n)

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcut(char *start, char *end);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *src, const char *fnd);
char				*ft_strnstr(const char *src, const char *fnd, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strappendchr(char const *str, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *nptr);
int					ft_atoi_base(char *str, char *base);
int					ft_get_digits(int n, int base);
int					ft_get_digitsl(long int n, int base);
int					ft_get_digitsll(long long int n, int base);
int					ft_get_digits_intmax(intmax_t n, int base);
int					ft_get_digits_uintmax(uintmax_t n, int base);
void				ft_handle_int_min(int *n, char **retval, int *sign, int *i);
void				ft_handle_l_min(long int *n, char **rtv, int *sgn, int *i);
char				*ft_itoa(int n);
char				*ft_uimtoa(uintmax_t n);
char				*ft_dtoa(double num, int precision, int force_dot);
char				*ft_ldtoa(long double num, int precision, int force_dot);
char				*ft_itoa_base(uintmax_t n, int base);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar(char c);
void				ft_putwchar(wint_t c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstcount(t_list *lst);
void				ft_lstreverse(t_list **alst);

void				ft_strrev(char *str);
char				*ft_strchrnul(const char *start, char c);
int					ft_strstartswith(const char *s, const char *f);
void				ft_strpushfront(char *str, char c);

long long int		ft_pow(int i, int pow);
uintmax_t			ft_round(long double num);
uintmax_t			ft_ceil(long double num);
uintmax_t			ft_floor(long double num);

int					get_next_line(int fd, char **line);

#endif
