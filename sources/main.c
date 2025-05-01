/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/30 15:13:06 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

t_data	data;

static  void    init_minishell(char **env)
{
    ft_memset(&data , 0 , sizeof(data));
    data.environ = env;
    init_envlst();
    data.stdin = dup(0);
    data.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &data.original_term);
}

// void    execution(void)
// {
//     signal(SIGQUIT , handler_sigquit);
//     init_tree(data.ast);
// }

// int main(int ac , char **av  , char **env)
// {  
//     (void)ac;
//     (void)av;
//     init_minishell(env);
//     while(1)
//     {
//         init_signal();
//         data.line = readline(PROMPT);
//         if (!data.line)
//             (/*clean_all(), */ft_putstr_fd("exit\n" , 1) , exit(data.exit_s));
//         if(data.line[0])
//             add_history(data.line);
//         printf("Before tokenize\n");
//         data.tokens = tokenize();
//             t_token *curr = data.tokens;
 
//         while (curr)
//         {
//             printf("Token type: %d, Token value: %s\n", curr->type, curr->value);
//             curr = curr->next;
//         }
//         if(!data.tokens)
//             continue;
//         printf("Before start_parsing\n");
//         data.ast = start_parsing();
//         printf("After start_parsing\n");
//         // if(data.parse_error.type)
//         // {
//         //     handle_parse_error();
//         //     continue;
//         // }
//         printf("data_ast : %p\n" , data.ast);
//         //write(STDIN_FILENO, "hey", 4);
//         execution();
//     }
//     garbage_collector(NULL , true);

// }
int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    init_minishell(env);

    // إعداد العقد
    t_node *pipe_node = malloc(sizeof(t_node));
    t_node *left_node = malloc(sizeof(t_node));
    t_node *right_node = malloc(sizeof(t_node));

    // إعداد الأوامر
    char *ls_args[] = {"ls", NULL};
    char *wc_args[] = {"wc", "-l", NULL};

    // ملء العقدة اليسرى
    left_node->type = N_CMD;
    left_node->expanded_args = ls_args;
    left_node->left = NULL;
    left_node->right = NULL;
    left_node->io_list = NULL;

    // ملء العقدة اليمنى
    right_node->type = N_CMD;
    right_node->expanded_args = wc_args;
    right_node->left = NULL;
    right_node->right = NULL;
    right_node->io_list = NULL;

    // عقدة الأنبوب
    pipe_node->type = N_PIPE;
    pipe_node->left = left_node;
    pipe_node->right = right_node;
    pipe_node->expanded_args = NULL;
    pipe_node->io_list = NULL;

    // تنفيذ الأمر عبر الأنبوب
    int status = exec_pipe(pipe_node);
    printf("Exit status: %d\n", status);

    // تنظيف
    free(left_node);
    free(right_node);
    free(pipe_node);

    return 0;
}
