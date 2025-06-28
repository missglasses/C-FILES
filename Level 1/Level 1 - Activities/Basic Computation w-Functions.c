#include <stdio.h>

int ask();
int computeSum(int a, int b, int c, int d, int e);
int computeProduct(int a, int b, int c, int d, int e);
int computeDifference(int a, int b);
void display(int sum, int product, int difference);

int main() {
    int a, b, c, d, e;
    
    a = ask();
    b = ask();
    c = ask();
    d = ask();
    e = ask();
    
    
    int sum = computeSum(a, b, c, d, e);
    int product = computeProduct(a, b, c, d, e);
    int difference = computeDifference(product, sum);
    
  
    display(sum, product, difference);
    
    return 0;
}

int ask() {
    int num;
    printf("Enter a value: ");
    scanf("%d", &num);
    return num;
}


int computeSum(int a, int b, int c, int d, int e) {
    return a + b + c + d + e;
}


int computeProduct(int a, int b, int c, int d, int e) {
    return a * b * c * d * e;
}

int computeDifference(int a, int b) {
    return a - b;
}


void display(int sum, int product, int difference) {

    printf("SUM: %d\n", sum);
    printf("PRODUCT: %d\n", product);
    printf("DIFFERENCE: %d\n", difference);
}
