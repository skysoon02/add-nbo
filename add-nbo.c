#include<stdio.h>
#include<stdint.h>
#include<netinet/in.h>

int main(int argc, char **argv){
    FILE *f1 = fopen(argv[1], "rb"); 
    FILE *f2 = fopen(argv[2], "rb");

    uint32_t int1, int2;
    fread(&int1, sizeof(uint32_t), 1, f1);
    fread(&int2, sizeof(uint32_t), 1, f2);

    int1 = ntohl(int1);
    int2 = ntohl(int2);

    printf("%d(%#x) + %d(%#x) = %d(%#x)", int1, int1, int2, int2, int1+int2, int1+int2);

    fclose(f2); 
    fclose(f1);
}
