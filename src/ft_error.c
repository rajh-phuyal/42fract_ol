/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:16:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/22 22:03:42 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define BOLD "\033[1m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define UNDERLINE    "\x1b[4m"

/*
result:
	[0]-> number of lines the text will be printed (only for the message)
	[1]-> if heading exceeding 50, then 1 else 0
	[2]-> number of space padding for the heading
	[3]-> number of space padding for the message
*/
int	*calculate_stuff(char *heading, char *message)
{
	int	*result;
	int	message_len;
	int	heading_len;

	result = malloc(sizeof(int) * 5);
	message_len = ft_strlen(message);
	heading_len = ft_strlen(heading);
	result[0] = 2 + (message_len > 50);
	result[1] = 0 + (heading_len < 50);
	if (result[1])
	{
		result[2] = (2 + (50 - heading_len - ((50 - heading_len) % 2 != 0)));
		result[3] = (2 + (50 - message_len - ((50 - message_len) % 2 != 0)));
	}
	return (result);
}

void	print_line(int iter, char char_ter)
{
	while (iter--)
		printf("%c", char_ter);
}

void	print_message(char *message, int *calculated)
{
	int	iter;

	iter = ft_strlen(message);
	printf(CYAN "║" YELLOW " ");
	if (calculated[0] == 2)
		print_line(calculated[3] / 2, ' ');
	else
		print_line(2, ' ');
	while (*message && iter--)
		printf("%c", *message++);
	printf("\n");
	if (calculated[0] == 2)
		print_line(calculated[3] / 2, ' ');
	else
		print_line(2, ' ');
	iter = ft_strlen(message);
	while (*message && iter--)
		printf("%c", *message++);
	printf(CYAN "║" RESET "\n");
}

int	ft_error(char *heading, char *message)
{
	int	*calculated;
	int	iter;

	calculated = calculate_stuff(heading, message);
	if (!calculated[1])
		return (printf("Really? Heading that big?!\n"));
	iter = 52;
	printf(CYAN "╔");
	while (iter--)
		printf("═");
	iter = 51;
	printf("╗" RESET "\n");
	printf(CYAN "║");
	print_line(calculated[2] / 2, ' ');
	printf(RED "%s" RESET, heading);
	print_line(calculated[2] / 2, ' ');
	printf(CYAN "║" RESET "\n");
	printf(CYAN "╟");
	print_line(52, '-');
	printf("╢" RESET "\n");
	print_message(message, calculated);
	free(calculated);
	return (1);
}
