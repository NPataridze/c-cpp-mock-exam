#include <stdio.h>

struct coffee {
    int id;
    char property;
};

const unsigned char regular = 1<<0;
const unsigned char espresso = 1<<1;
const unsigned char double_espresso = 1<<2;
const unsigned char milk = 1<<3;
const unsigned char cream = 1<<4;
const unsigned char soy_milk = 1<<5;
const unsigned char sugar = 1<<6;
const unsigned char sweetener = 1<<7;

void set_coffee_property(struct coffee* c, const unsigned char property){
    c->property |= property;
}

void unset_coffee_property(struct coffee* c, const unsigned property){
    c->property &= ~property;
}

int main(){
    struct coffee my_coffee;
    my_coffee.id = 1;
    my_coffee.property = regular;
    set_coffee_property(&my_coffee, milk);
    set_coffee_property(&my_coffee, sugar);

    printf("Coffee properties:\n");
    printf("Regular: %s\n", (my_coffee.property & regular) ? "Yes" : "No");
    printf("Espresso: %s\n", (my_coffee.property & espresso) ? "Yes" : "No");
    printf("Double Espresso: %s\n", (my_coffee.property & double_espresso) ? "Yes" : "No");
    printf("Milk: %s\n", (my_coffee.property & milk) ? "Yes" : "No");
    printf("Cream: %s\n", (my_coffee.property & cream) ? "Yes" : "No");
    printf("Soy Milk: %s\n", (my_coffee.property & soy_milk) ? "Yes" : "No");
    printf("Sugar: %s\n", (my_coffee.property & sugar) ? "Yes" : "No");
    printf("Sweetener: %s\n", (my_coffee.property & sweetener) ? "Yes" : "No");

    unset_coffee_property(&my_coffee, milk);
    printf("\nAfter unsetting milk:\n");
    printf("Milk: %s", (my_coffee.property & milk) ? "YES" : "NO");

    return 0;

}