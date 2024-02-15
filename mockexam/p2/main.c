 #include <stdio.h>

 int main(){
    double d;
    scanf("%lf", &d);

    float f;
    scanf("%f", &f);

    int i;
    scanf("%d", &i);

    double result;
    result = d * f * i;

    printf("result = %lf\n", result);

    double *r_ptr = &result;
    *r_ptr += 5;

    printf("%lf\n%lf\n", result, *r_ptr);

    return 0;
}