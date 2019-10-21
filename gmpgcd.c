#include <stdio.h>
#include <gmp.h>

int main()
{
	mpz_t a,b,d;
	mpz_inits(a,b,d,NULL);
	gmp_printf("Enter first number : ");
	gmp_scanf("%Zd",a);
	gmp_printf("Enter second number : ");
	gmp_scanf("%Zd",b);
	mpz_gcd(d,a,b);
	gmp_printf("GCD of %Zd and %Zd is %Zd\n",a,b,d);
}