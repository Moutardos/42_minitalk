/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:35:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/07 18:26:02 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

# define STDOUT 1
# define STDIN 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*** PART 1 ***/

/** MEM **/

/* set the nth byte of b to c */
void	*ft_memset(void *b, int c, size_t len);

/* set the nth byte of s to 0 */
void	ft_bzero(void *s, size_t n);

/* return the first occurence of the c in the nth bytes of s*/
void	*ft_memchr(const void *s, int c, size_t n);

/*copy memory of size n from src to dest*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*move memory of length len from src to dst, can overlap*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/* return 0 if they have the same data, positive number if the
	first different byte is bigger or else a negative number */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/** STR **/

/* return a pointer to the first ocurence of c in the string s */
char	*ft_strchr(const char *s, int c);

/* return a pointer to the last occurence of c in the string s */
char	*ft_strrchr(const char *s, int c);

/* copy or concatenate src into dst, garantee to be NUL terminated */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* compare 2 string, return positive if s1 > s2, negative if s2 > s1 
	else 0 if equal */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* locate the string little inside the string big and return where it begins.
	doesn't search after len character */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*return the length of the NUL character terminated string s*/
size_t	ft_strlen(const char *s);

/** VERIF/CONVERT **/

/* return 1 if the character is a letter */
int		ft_isalpha(int c);

/* return 1 if the character is a digit */
int		ft_isdigit(int c);

/* return 1 if the character is a letter or a digit*/
int		ft_isalnum(int c);

/* return 1 if the character is in the ascii table */
int		ft_isascii(int c);

/* return 1 if the character is printable */
int		ft_isprint(int c);

/* return 1 if the character is considerate space (see man) */
int		ft_isspace(int c);

/* return the character to uppercase */
int		ft_toupper(int c);

/* return the character to lowercase */
int		ft_tolower(int c);

/* convert and return the value inside nptr as an integer */
int		ft_atoi(const char *nptr);

/** ALLOC **/

/* allocate an array of nmemb elements, all set to 0 */
void	*ft_calloc(size_t nmemb, size_t size);

/* duplicate a string and return a pointer to it */
char	*ft_strdup(const char *s);

/*Return a duplicate uppercase version of s*/
char	*ft_strup(char *s);

/*Return a duplicate lowercase version of s*/
char	*ft_strlow(char *s);

/*** PART 2 ***/

/** STR **/

/* allocate a concatenation of s1 and s2 */
char	*ft_strjoin(char const *s1, char const *s2);

/* return an allocated string where the characters in set from the beggining
	and end of s1 are removed*/
char	*ft_strtrim(char const *s1, char const *set);

/* allocate and return a string based on s, starting 
	on index start of len size*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* map character of s into a new string and return it */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmap(char const *s, int (*f)(int));

/* iterate the characters of s and apply the function f to each */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_striter(char *s, void (*f)(char *));

/* return an array of the words found in s, delimited by c */
char	**ft_split(char const *s, char c);

/* return 1 if the char c is in s */
int		ft_cinstr(char const *s, char c);
/** DISPLAY **/

/* display the character c in the file descriptor fd */
int		ft_putchar_fd(char c, int fd);

/* display the string s in the file descriptor */
int		ft_putstr_fd(char *s, int fd);

/** display the string s in the file descriptor followed by a newline **/
void	ft_putendl_fd(char *s, int fd);

/* print the integer in the file descriptor */
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbru_fd(unsigned int n, int fd);
/* print the UNSIGNED number hexadecimal form in the file descriptor,
	with the nsize and in uppercase or not*/
int		ft_puthex_fd(size_t n, int fd, unsigned int nsize, int up);

/** CONVERT **/

/* take an int and return an allocated string of the value*/
char	*ft_itoa(int n);

/* take an int and return an allocated string of the value in base */
char	*ft_itob(int n, char *base);

/* return the int n in a hexa */
char	*ft_itohexa(int n);

/* return power of n to the pow*/
long	ft_pow(int n, int pow);
/*** BONUS ***/

/** LINKED LIST **/

/* create a new element */
t_list	*ft_lstnew(void *content);

/* add the new element at the start of the linked list */
void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *s, ...);
#endif
