#include <stdio.h>
#include <gmp.h>

int main()
{
	mpz_t a,b,t;
	mpz_inits(a,b,t,NULL);
	gmp_printf("Enter first number : ");
	gmp_scanf("%Zd",a);
	gmp_printf("Enter second number : ");
	gmp_scanf("%Zd",b);
	if(mpz_cmp(a,b)<0)
		mpz_swap(a,b);
	while(mpz_cmp_ui(b,0)!=0)
	{
		mpz_mod(t,a,b);
		mpz_set(a,b);
		mpz_set(b,t);
	}
	gmp_printf("GCD of the two numbers is %Zd\n",a);
}