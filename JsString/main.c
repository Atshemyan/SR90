#include "JsString.h"

int main(int argc, char const *argv[])
{
    char* arr = "HaykoMko";
    char* tmp = toUpperCase(arr);

    printf("%s\n", tmp);   
    return 0;
}
