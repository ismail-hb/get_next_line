/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:32:02 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/20 21:32:05 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = f(lst->content);
	tmp = new;
	while (lst->next)
	{
		tmp->next = malloc(sizeof(t_list));
		if (!tmp->next)
			return (ft_lstclear(&new, del), NULL);
		tmp = tmp->next;
		lst = lst->next;
		tmp->content = f(lst->content);
	}
	tmp->next = NULL;
	return (new);
}
