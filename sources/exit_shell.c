#include "nsh.h"

void exit_shell(int exit_status)
{
    // close_everything();
    destroy_everything();
    exit(exit_status);
}
