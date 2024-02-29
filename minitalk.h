/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:49:51 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/29 09:08:32 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include "Ft_printf/ft_printf.h"
# include <signal.h>
 
typedef struct s_message 
{
    char                c;
    struct s_message    *next;
}               t_message;
 
#endif