#ifndef ALLOCATION_H
# define ALLOCATION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"

#define ALLOCATION_CAPACITY 2

typedef struct s_section
{
    char                *section_name;
    void                **allocations;
    size_t              capacity;
    size_t              count;
    struct s_section    *next;
} t_section;

void                    *smalloc(size_t size);
t_section               **get_sections(void);
void                    destroy_all_sections(void);
t_section               *create_section(const char *name);
void                    destroy_section(const char *name);
void                    clear_section_data(t_section *section);
t_section               *find_section(t_section *section, const char *name);
void                    *new_allocation(const char *section_name, size_t size);
void                    free_one_pointer(const char *section_name, void *pointer);

#endif