#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_test
{

	char				name;
	char				*obj;
	void				*content;

}						t_test;

t_test	*fonction_test(int i)
{
	t_test	*test;
	char	*str;

	if ((test = (t_test*)malloc(sizeof(t_test))) == NULL )
		exit(-1);
	if ((test->obj = (char*)malloc(sizeof(char) * 42)) == NULL )
		exit(-1);
	if ((str = (char*)malloc(sizeof(char) * 42)) == NULL )
		exit(-1);
	if (i == 0)
		str = "salut\n";
	else if (i == 2)
		str = "saLOT\n";
	else if (i == 3)
		str = "saPUt\n";
	else 
		str = "saBUS\n";
	test->name = 'S' + i;
	test->obj = str;

	printf("name :%c\n", test->name);	
	printf("name42 :%s\n", test->obj);
	return (test);
}

void	show_content(t_list *list)
{
	t_test	*tmp_2;
	t_test	*tmp;

	char	*str;

		while (list)
		{
			if (list->content)
			{
				tmp_2 = list->content;
				printf("iiiii\n");
				printf("name :%c\n", tmp_2->name);
				printf("obj :%s\n", tmp_2->obj);
				if (tmp_2->name == 'T')
					tmp = tmp_2;
			}
			list = list->next;
		//	i++;
		}
	printf("dede\n");
	
	printf("obj---- :%s\n", tmp->obj);


}

t_test	*test_1_parser(void)
{
	t_test	*test;
	char	*str;

	if ((test = (t_test*)malloc(sizeof(t_test))) == NULL )
		exit(-1);
	if ((test->obj = (char*)malloc(sizeof(char) * 42)) == NULL )
		exit(-1);
	if ((str = (char*)malloc(sizeof(char) * 42)) == NULL )
		exit(-1);
	str = "salut\n";

	test->name = 's';
	test->obj = str;

	printf("test1 name :%c\n", test->name);
	printf("test1 name42 :%s\n", test->obj);
	return (test);




}

void	test1_show(t_test *test1)
{
	t_test	*tmp_2;

	tmp_2 = test1;
	printf("test1 iiiii\n");
	printf("test1 name :%c\n", tmp_2->name);
	printf("test1 obj :%s\n", tmp_2->obj);

}

void	test_2_parser_fill(void	**str)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 42);
	tmp = "resalut\n\0";
	*str = tmp;
}

t_test	*test_2_parser(void)
{
	t_test	*test;
	char	*str;
	char	*tmp;

	if ((test = (t_test*)malloc(sizeof(t_test))) == NULL )
		exit(-1);
//	if ((test->obj = (char*)malloc(sizeof(char) * 42)) == NULL )
//		exit(-1);
	if ((str = (char*)malloc(sizeof(char) * 42)) == NULL )
		exit(-1);
	if ((test->content = (void*)malloc(432394342)) == NULL )
		exit(-1);
	test->content = NULL;
	str = "salut\n";

	test_2_parser_fill(&test->content);
	test->name = 's';
	test->obj = str;
	tmp = test->content;

	printf("test2 name :%c\n", test->name);
	printf("test2 name42 :%s\n", test->obj);
	printf("test2 content :%s\n", tmp);
	return (test);




}

void	test2_show(void *test2)
{
	t_test	*tmp_2;

	tmp_2 = test2;
	printf("test2 iiiii\n");
	printf("test2 name :%c\n", tmp_2->name);
	printf("test2 obj :%s\n", tmp_2->obj);

}


int		main(void)
{
	t_list	*list;
	t_test	*tmp_2;
	t_test	*test1;
	int		i;
	int		number;
	int		*tmp;


	void	*test2;


	i = 0;
	number = 42;
	list = ft_lstnew(0, 0);

	test1 = test_1_parser();
	test1_show(test1);

	test2 = test_2_parser();
	test2_show(test2);

	if (0)
	{
		while (i < 3)
		{
			ft_lstadd(&list, ft_lstnew(&number, sizeof(int)));
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			ft_lstadd(&list, ft_lstnew(fonction_test(i), sizeof(t_test)));
			//                  C'EST CA QUI BUGUAIT ->  sizeof(t_test)));
			i++;
		}
	}


	i = 0;
	if (0)
	{
		while (i < 3)
		{
			if (list->content)
			{
				tmp = list->content;
				printf("number:%d\n", *tmp);
			}
			list = list->next;
			i++;
		}
	}
	else if (0)
	{
		
		
		while (i < 3)
		{
			if (list->content)
			{
				tmp_2 = list->content;
				printf("name :%c\n", tmp_2->name);
			}
			list = list->next;
			i++;
		}
	
	show_content(list);
	}
	else
		show_content((t_list*)list);
	return (0);
}
