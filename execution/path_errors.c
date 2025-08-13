# include "execution.h"

t_state path_validity(const char *path)
{
    struct stat st;

    if (stat(path, &st) < 0) 
        return NO_FILE_ERROR;
    if (S_ISDIR(st.st_mode))
        return IS_DIR_ERROR;
    // if (!S_ISREG(st.st_mode))
    //     return PERMISSION_ERROR;
    if (access(path, X_OK) < 0) 
        return PERMISSION_ERROR;
    return (VALID_PATH);
}

t_state stat_error(void)
{
    if (errno == ENOENT)
        return (NO_FILE_ERROR);
    else if (errno == EACCES)//should it return err
        return (PERMISSION_ERROR);
    else
        return (STAT_ERROR);
}

void report_error(const char *cmd, t_state error)
{
    int code;

    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, ft_strlen(cmd));
    if (error == NOT_FOUND_ERROR)
        write(STDERR_FILENO, ": Command not found\n", 20);
    else if (error == NO_FILE_ERROR)
        write(STDERR_FILENO, ": No such file or directory\n", 28);
    else if (error == IS_DIR_ERROR)
        write(STDERR_FILENO, ": Is a directory\n", 17);
    else if (error == PERMISSION_ERROR)
        write(STDERR_FILENO, ": Permission denied\n", 20);//, free((void *)cmd)
    else if (error == STAT_ERROR)
        perror(cmd);
    code = 126;
    if(error == NOT_FOUND_ERROR || error == NO_FILE_ERROR)
        code = 127;
    destroy_all_sections();
    exit(code);
}
