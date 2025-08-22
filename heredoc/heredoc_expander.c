# include "heredoc.h"

static bool	no_dollar_checker(char *str)
{
	if (*str != '\0' && !check_if_dollar(str))
	{
		return (true);
	}
	return (false);
}

t_list_info *heredoc_expander(char *str)
{
	t_list_info	*arg_list;
	t_info		info;

	init_info_struct(&info, str);
	arg_list = init_list_info_struct();
	while (*(info.str))
	{
		info.str += expand_regular_word(&info, no_dollar_checker, false);
		info.str += expand_dollar_word(&info, arg_list, false);
	}
	process_arg(&info, arg_list);
	return (arg_list);
}
