# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

static int	get_int_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	long	i;

	len = get_int_len(n);
	i = n;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	*(arr + len) = '\0';
	if (i == 0)
		arr[0] = '0';
	else if (i < 0)
	{
		arr[0] = '-';
		i *= -1;
	}
	while (i)
	{
		arr[len - 1] = i % 10 + 48;
		len--;
		i = i / 10;
	}
	return (arr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && (i < num))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

char    *create_hash_id(int width, int height, char* name) {
    unsigned long id;
    int c;

    id = 5381;
    id = ((id << 3) + id) + width;
    id = ((id << 3) + id) + height;
    while (*name)
        id = ((id << 3) + id) + *name++;

    return ft_itoa(id % INT_MAX);
}

int main(int argc, char **argv)
{
    char *first = argv[1];
    char *second = argv[2];
    int  fd;


    char *first_hash = create_hash_id(1600, 1300, first);
    char *second_hash = create_hash_id(1600, 1300, second);

    unsigned char * p = (unsigned char*)&first_hash;

    printf("First hash: %s\n", first_hash);
    printf("Second hash: %s\n", second_hash);
    if (ft_strncmp((const char*)&first_hash, (const char*)&second_hash, 8) == 0)
        printf("Hashes are equal\n");
    else
        printf("Hashes are not equal\n");
    
    fd = open(first_hash, O_RDONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1)
        printf("Error\n");
    else
    {
        printf("File created\n");
        char *line = get_next_line(fd);
    }
    close(fd);
}