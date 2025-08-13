#ifndef ALLOCATION_H
# define ALLOCATION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"

#define ALLOCATION_CAPACITY 2

typedef enum
{
    TOKENIZATION,
    RESOLVE_PATH,
    EXECUTION,
    PARSING,
    ENVIRON
} t_sid;

typedef struct s_section
{
    t_sid               section_id;
    void                **allocations;
    size_t              capacity;
    size_t              count;
    struct s_section    *next;
} t_section;

t_section               **get_sections(void);
void                    *smalloc(size_t size);
void                    clean_before_prompt(void);
void                    destroy_all_sections(void);
t_section               *create_section(t_sid section_id);
void                    destroy_section(t_sid section_id);
void                    clear_section_data(t_section *section);
t_section               *find_or_create_section(t_sid section_id);
void                    *new_allocation(t_sid section_id, size_t size);
char                    *allocate_retval(t_sid section_id, char *to_copy);
void                    free_one_pointer(t_sid section_id, void *pointer);
t_section               *find_section(t_section *section, t_sid section_id);
void                    add_allocation_to_section(t_sid section_id, void *ptr);
void                    add_allocations_to_section(t_sid section_id, void **ptr);

#endif