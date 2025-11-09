#include <iostream>
int gcd(int x, int y)
{
    if(y == 0)
        return x;
    else return gcd(y, x % y);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int g = gcd(a, b);
    
    printf("%d\n%d", g, a * b / g);

    return 0;
}
