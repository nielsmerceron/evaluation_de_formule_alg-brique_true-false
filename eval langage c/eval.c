#include "eval.h"

int main(int argc, char *argv[])
{   
    int i;

    for(i=1;i<argc;i++){
    eval(argv[i]);
    }
    
    return 0;
}
