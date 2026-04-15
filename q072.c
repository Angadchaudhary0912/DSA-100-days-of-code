#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int count[26] = {0};
    int i;

    scanf("%s", s);

    for(i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        if(count[s[i] - 'a'] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}