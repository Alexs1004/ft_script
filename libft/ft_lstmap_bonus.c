/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:49:30 by astutz            #+#    #+#             */
/*   Updated: 2022/11/22 17:47:33 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newobj;
	void	*newcontent;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		newobj = ft_lstnew(newcontent);
		if (!newobj)
		{
			free(newcontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newobj);
		lst = lst->next;
	}
	return (newlst);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*lstnew;
// 	t_list	*lstfinal;
// 	void	*tmp;

// 	if (!f || !del)
// 		return (NULL);
// 	lstfinal = NULL;
// 	while (lst)
// 	{
// 		tmp = f(lst->content);
// 		lstnew = ft_lstnew(tmp);
// 		if (!lstnew)
// 		{
// 			free(tmp);
// 			ft_lstclear(&lst, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&lstfinal, lstnew);
// 		lst = lst->next;
// 	}
// 	return (lstfinal);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*newlst;
// 	t_list	*newelement;

// 	if (lst == NULL || (*f) == NULL || (*del) == NULL)
// 		return (NULL);
// 	newlst = NULL;
// 	while (lst != NULL)
// 	{
// 		newelement = ft_lstnew((*f)(lst->content));
// 		if (newelement == NULL)
// 		{
// 			ft_lstclear(&newelement, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&newlst, newelement);
// 		lst = lst->next;
// 	}
// 	return (newlst);
// }
