/*!
 * @file: main.c
 * @date: 2023-12-23
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of application skeleton to test one module of lib.
 */

#include <stdio.h>

/*!
 * @brief Application entry point
 * @param argc  Argument counter.
 * @param argv  Argument values.
 * @return 0 on success otherwise -1.
*/
int main (int argc, char** argv)
{
    int i = 0;

    for(i=0; i<argc; i++)
    {
        printf("Argv[%d] = %s.\r\n", i, argv[i]);
    }

    return 0;
}