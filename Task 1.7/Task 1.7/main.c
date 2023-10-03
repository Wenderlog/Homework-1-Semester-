#include <string.h>
#include <stdio.h>

int countStrOfS(const char* String, const char* String2){
int count = 0;
long lenS = strlen(String);
long lenS1 = strlen(String2);

for (int i = 0; i <= lenS - lenS1; i++) {
int j;
for (j = 0; j < lenS1; j++){
if (String[i +j] != String2[j]) {
break;
}
}

if (j == lenS1) {
count++;
}
}
return count;
}

int main(int argc, const char * argv[]) {
const char* String = "bnbnbnbnnb";
const char* String2 = "bn";
int a = countStrOfS(String, String2);
printf("кол-во вхождений S1 в s: %d\n", a);
return 0;
}
