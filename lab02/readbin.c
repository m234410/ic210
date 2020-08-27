/* Daniel Murray*/

#include"ic210.h"

int main() {
fputs("Enter a 4-bit binary number: ", stdout);
char columnfour = readchar(stdin);
char columnthree = readchar(stdin);
char columntwo = readchar(stdin);
char columnone = readchar(stdin);

fputs("In decimal ", stdout);
fputc(columnfour, stdout);
fputc(columnthree, stdout);
fputc(columntwo, stdout);
fputc(columnone, stdout);

int four = (int)columnfour;
four = four - 48;
int three = (int)columnthree;
three = three - 48;
int two = (int)columntwo;
two = two - 48;
int one = (int)columnone;
one = one - 48;

int total = one + (two*2) + (three*4) + (four*8);

fputs(" = ", stdout);
writenum(total, stdout);
fputs("\n", stdout);

return 0;
}

