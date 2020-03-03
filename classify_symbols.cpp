#include<iostream>
#include<unicode/uchar.h>
#include<unicode/ustdio.h>

int main(int argc, char** argv){
    UChar32 c;
    UFILE *in = u_finit(stdin, NULL, NULL);
    UFILE *out = u_get_stdout();
    const char *name;
    int val;
    while((c = u_fgetcx(in))!=U_EOF){
        val = u_charType(c);
        name = u_getPropertyValueName(UCHAR_GENERAL_CATEGORY, val, U_SHORT_PROPERTY_NAME);
        u_fputc(c, out);
        std::cout << " " << name <<"\n";
    }
}
