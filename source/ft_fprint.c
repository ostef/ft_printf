/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:07:40 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:18:02 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <unistd.h>

t_s64	ft_vfprint(t_file f, t_cstr fmt, va_list va)
{
	va_list	va2;
	t_str	buff;
	t_s64	len;

	va_copy (va2, va);
	len = ft_vsprint (NULL, fmt, va2);
	va_end (va2);
	buff = (t_str)malloc (len + 1);
	if (!buff)
		return (-1);
	ft_vsprint (buff, fmt, va);
	write (f, buff, len);
	free (buff);
	return (len);
}

t_s64	ft_fprint(t_file f, t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vfprint (f, fmt, va);
	va_end (va);
	return (len);
}

t_s64	ft_vfprintln(t_file f, t_cstr fmt, va_list va)
{
	va_list	va2;
	t_str	buff;
	t_s64	len;

	va_copy (va2, va);
	len = ft_vsprintln (NULL, fmt, va2);
	va_end (va2);
	buff = (t_str)malloc (len + 1);
	if (!buff)
		return (-1);
	ft_vsprintln (buff, fmt, va);
	write (f, buff, len);
	free (buff);
	return (len);
}

t_s64	ft_fprintln(t_file f, t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vfprintln (f, fmt, va);
	va_end (va);
	return (len);
}
