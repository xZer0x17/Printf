/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alflores <alflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:48:05 by alflores          #+#    #+#             */
/*   Updated: 2023/01/18 00:07:03 by alflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

int	ft_printf(char const *format, ...);

#endif