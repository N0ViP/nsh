# include "getenv.h"

void set_var_value(char *key, char *value)
{
    size_t k_len;
    size_t v_len;
    char   *key_value;

    k_len = ft_strlen(key);
    v_len = ft_strlen(value);
    key_value = new_allocation(REMAINS, k_len + v_len + 2);
    ft_memcpy(key_value, key, k_len);
    key_value[k_len] = '=';
    ft_memcpy(key_value + k_len + 1, value, v_len + 1);
    add_in_env(*env_list(), key_value);
}
