#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("whats your name? ");
    printf("hello, %s\n", name);
}
