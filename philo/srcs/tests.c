/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:30 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 15:34:28 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#define VERBOSE		1
#define ADDRESSES	0
#define	RED			"\033[1;31m"
#define GRE			"\033[1;32m"
#define RES			"\033[0m"
#define YEL			"\033[1;33m"
#define CYA			"\033[1;36m"

char		**ft_split(const char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
static void	**ft_free_all(char **strs);


int	success(int passed)
{
	if (passed)
	{
		printf("%spassed!%s\n", GRE, RES);
		return (EXIT_SUCCESS);
	}
	printf("%sfailed!%s\n", RED, RES);
	return (EXIT_FAILURE);
}

int test_01(void)
{
	int		passed;
	int		ac;
	char	**av;
	t_vars	vars;

	printf("=====Test 01=====\n");
	printf("Testing Init with %s5 800 200 200 7%s entry...", YEL, RES);
	passed = 0;
	ac = 6;
	av = ft_split("philosophers 5 800 200 200 7", ' ');
	passed = init(ac, av, &vars) == 0;
	if (vars.nb_philo != 5)
		passed = 0;
	else if (vars.ttd != 800)
		passed = 0;
	else if (vars.tte != 200)
		passed = 0;
	else if (vars.tts != 200)
		passed = 0;
	else if (vars.ttf != 7)
		passed = 0;
	ft_free_all(av);
	return (success(passed));
}

int test_02(void)
{
	int		passed;
	int		ac;
	char	**av;
	t_vars	vars;

	printf("=====Test 02=====\n");
	printf("Testing Init with %sempty%s entry...", YEL, RES);
	passed = 0;
	ac = 1;
	av = ft_split("philosophers", ' ');
	passed = init(ac, av, &vars) == 1;
	ft_free_all(av);
	return (success(passed));
}

int test_03(void)
{
	int		passed;
	int		ac;
	char	**av;
	t_vars	vars;

	printf("=====Test 03=====\n");
	printf("Testing Init with %s1 2 3 4 5 6 7 8 9%s entry...", YEL, RES);
	passed = 0;
	ac = 10;
	av = ft_split("philosophers 1 2 3 4 5 6 7 8 9", ' ');
	passed = init(ac, av, &vars) == 1;
	ft_free_all(av);
	return (success(passed));
}

int	test_04(void)
{
	int		passed;
	int		ac;
	char	**av;
	t_vars	vars;
	int		i;

	printf("=====Test 04=====\n");
	printf("Testing Creating One Philo with %s5 800 200 200 7%s entry...", YEL, RES);
	passed = 0;
	ac = 6;
	i = 0;
	av = ft_split("philosophers 5 800 200 200 7", ' ');
	passed = init(ac, av, &vars) == 0;
	
	ft_free_all(av);
	return (success(passed));
}

/******************************************************************************/
/************************************UTILS*************************************/
/******************************************************************************/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1);
	dest = malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	size_t	len_str;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start > len_str)
		sub = malloc(sizeof(char));
	else if (len >= len_str)
		sub = malloc(sizeof(char) * (len_str - start + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && len-- > 0 && start < len_str)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}


static void	**ft_free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i++] = NULL;
	}
	free(strs);
	return (NULL);
}

static char	**ft_words_in_tab(const char *s, char c, char **strs)
{
	int	i;
	int	j;
	int	end_last;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		end_last = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > end_last)
		{
			strs[j++] = ft_substr(s, end_last, i - end_last);
			if (!(strs[j - 1]))
				return (*ft_free_all(strs));
		}
	}
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;
	int		end_last;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		end_last = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > end_last)
			j++;
	}
	strs = malloc(sizeof (char *) * (j + 1));
	if (!strs)
		return (NULL);
	strs[j] = NULL;
	strs = ft_words_in_tab(s, c, strs);
	return (strs);
}
