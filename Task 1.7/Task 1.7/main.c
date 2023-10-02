#include <string.h>
#include <stdio.h>

int countStrOfS(const char* S,const char* S1){
    int count =0;
    long lenS = strlen(S);
    long lenS1 = strlen(S1);
    
    for (int i =0; i <= lenS - lenS1; i++) {
        int j;
        for (j = 0; j < lenS1; j++){
            if (S[i +j] != S1[j]){
                break;
            }
        }
        
        if (j ==lenS1){
            count++;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    const char* S = "bnbnbnbnnb";
    const char* S1 ="bn";
    int a = countStrOfS(S, S1);
    printf("кол-во вхождений S1 в s: %d\n", a);
    return 0;
}
