#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
int get_behind_nl(char (*temp)[BUFFER_SIZE + 1])
{
    int i;
    int j;
    i = 0;
    j = 0;
    while ((*temp)[i] != '\n' && (*temp)[i])
        i++;
    if ((*temp)[i] == '\n')
    {
        while ((*temp)[i + j] && ++j)
            (*temp)[j - 1] = (*temp)[i + j];
        return (1);
    }
    return (0);
}
char    *get_next_line_malloc(char (*temp)[BUFFER_SIZE + 1], char **outp, int *i)
{
    char    *temp1;
    int     j;
    j = 0;
    while ((*temp)[*i] && (((*temp)[*i - 1] != '\n') || *i == 0))
        (*i)++;
    while ((*outp) != NULL && (*outp)[j])
        j++;
    temp1 = malloc(*i + j + 1);
    if (temp1 == NULL)
        return (0);
    if (temp1 == NULL)
        return (NULL);
    temp1[*i + j] = '\0';
    while ((*i) > 0 && (*i)--)
        temp1[j + (*i)] = (*temp)[*i];
    while ((*outp) != NULL && j > 0 && j--)
        temp1[j] = (*outp)[j];
    free ((*outp));
    return (temp1);
}
char    *get_next_line(int fd)
{
    int         i;
    static char temp[BUFFER_SIZE + 1];
    char        *outp;
    i = 1;
    outp = NULL;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while (i)
    {
        i = 0;
        if (temp[i])
        {
            outp = get_next_line_malloc(&temp, &outp, &i);
            if (get_behind_nl(&temp))
                return (outp);
        }
        i = read(fd, temp, BUFFER_SIZE);
        if (i < 0)
            return (NULL);
        temp[i] = '\0';
    }
    return (outp);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = 0;
	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_check(s[i], &args);
		}
		else
		{
			result += ft_putchar_fd(s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (result);
}