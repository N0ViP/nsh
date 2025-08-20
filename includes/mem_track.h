#ifndef MEM_TRACK_H
# define MEM_TRACK_H

# include "nsh.h"

typedef enum
{
    TOKENIZE,
    GLOBALE,
    REMAINS
} t_sid;

typedef struct s_section
{
    t_sid               section_id;
    void                **allocations;
    size_t              capacity;
    size_t              count;
    struct s_section    *next;
} t_section;



void                    init_fds(void);
int                     **shell_fds(void);
t_section               **get_sections(void);
int                     duplicate_fd(int fd);
void                    *smalloc(size_t size);
void                    close_everything(void);
t_sid                   *current_section(void);
void                    destroy_everything(void);
void                    close_and_remove(int fd);
void                    clean_before_prompt(void);
int                     open_readonly(char *path);
bool                    create_pipe(int pipefd[2]);
void                    add_allocation(void *pointer);
void                    *allocate_memory(size_t size);
t_section               *create_section(t_sid section_id);
void                    destroy_section(t_sid section_id);
void                    clear_section_data(t_section *section);
t_section               *find_or_create_section(t_sid section_id);
void                    set_current_section(t_sid updated_section_id);
void                    *new_allocation(t_sid section_id, size_t size);
int                     create_open(char *path, int flags, mode_t mode);
void                    free_one_pointer(t_sid section_id, void *pointer);
t_section               *find_section(t_section *section, t_sid section_id);
void                    add_allocation_to_section(t_sid section_id, void *ptr);
void	                *reallocate_memory(void *pointer, size_t old_size, size_t new_size);

#endif