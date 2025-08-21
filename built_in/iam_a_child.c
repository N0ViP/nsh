#include "built-in.h"

bool iam_a_child(int flag)
{
    static bool state = false;

    if (flag == UPDATE)
    {
        state = true;
    }
    return (state);
}
