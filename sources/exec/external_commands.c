#include "../../includes/minishell.h"

int check_redirections(t_node *node)
{
    t_io_node *tmp_io;
    int status;

    tmp_io = node->io_list;
    while(tmp_io)
    {
        if(node->type == IO_IN && exec_in(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_OUT  && exec_out(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_APPEND  && exec_append(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_HEREDOC)
        {
            dup2(tmp_io->here_doc , 0);
            close(tmp_io->here_doc);
        }
        tmp_io = tmp_io->next;
    }
    return (ENO_SUCCESS);
}