/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:36:47 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 02:25:07 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stddef.h>
# include <limits.h>

/*
**----------------------------String manipulation-------------------------------
*/

/*
** FREE and NOFREE are used for "free_flag" parameter in ft_strpad.
*/

# define FREE 1
# define NOFREE 0

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_charstr(int number, unsigned char c);
char				*ft_strpad(char *input, char pad, int num, int free_flag);
char				*ft_strconv(char *str, int (*f)(int));
char				*ft_strins(char *input, char sym, size_t position);

/*
**----------------------------Conversions---------------------------------------
*/

/*
** PREFIX_ON and PREFIX_OFF are used for "flag" parameter in ft_itoa_base.
** SIGN_PLUS and SIGN_MINUS are used for "sign" parameter in ft_itoa_base
** and ft_dtoa.
** F_NOHASH, E_NOHASH, F_HASH and E_HASH are used for "type" parameter in
** ft_dtoa.
*/

# define PREFIX_ON 1
# define PREFIX_OFF 0
# define SIGN_PLUS 1
# define SIGN_MINUS -1
# define F_NOHASH 0
# define E_NOHASH 1
# define F_HASH 2
# define E_HASH 3

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t n, int sign, unsigned int base,
					int flag);
char				*ft_convert_double(double input, int *exponent);
void				ft_round_double(char *input, unsigned int precision,
					int *exponent);
void				ft_stripzeros(char *input);
char				*ft_dtoa(double input, int sign, int type,
					unsigned int precision);

/*
**----------------------------Wide chars and UTF-8------------------------------
*/

char				*ft_wchar_to_utf8(wchar_t c);
char				*ft_wstr_to_utf8(wchar_t *str);
int					ft_isutf8(const char *str);
char				*ft_substr_utf8(char const *s, unsigned int start,
					size_t len);
/*
**----------------------------Simple printing-----------------------------------
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**----------------------------Memory--------------------------------------------
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t new_size, size_t old_size);
void				ft_memprint(size_t const size, void const *const ptr);

/*
**----------------------------Math functions and floats-------------------------
*/
double				ft_math_floor(double value);
double				ft_math_log10(double x);
double				ft_math_pow(double x, int pow);
long long			ft_math_ipow(int x, unsigned int pow);
double				ft_math_frexp(double value, int *exp);
int					ft_isnan(double input);
int					ft_isposinf(double input);
int					ft_isneginf(double input);
int					ft_signbit(double input);

/*
**----------------------------Linked lists--------------------------------------
*/

typedef struct		s_list
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

#endif
