#include <stdio.h>
#include <gmp.h>

void extgcd(mpz_t a,mpz_t b,mpz_t x,mpz_t y,mpz_t d)
{
	if(mpz_cmp_ui(b,0)==0)
	{
		mpz_set(d,a);
		mpz_set_ui(x,1);
		mpz_set_ui(y,0);
		return;
	}
	mpz_t q,m,x1,y1,t;
	mpz_inits(q,m,x1,y1,t,NULL);
	mpz_mod(m,a,b);
	mpz_fdiv_q(q,a,b);
	extgcd(b,m,x1,y1,d);
	mpz_set(x,y1);
	mpz_mul(t,q,y1);
	mpz_sub(y,x1,t);
}

int main()
{
	mpz_t a,b,x,y,d;
	mpz_inits(a,b,x,y,d,NULL);
	gmp_printf("Enter first number : ");
	gmp_scanf("%Zd",a);
	gmp_printf("Enter second number : ");
	gmp_scanf("%Zd",b);
	extgcd(a,b,x,y,d);
	gmp_printf("GCD is : %Zd\nx = %Zd\ny = %Zd\n",d,x,y);
	gmp_printf("\nUsing inbuilt function :\n");
	mpz_t s,t,g;
	mpz_inits(s,t,g,NULL);
	mpz_gcdext(g,s,t,a,b);
	gmp_printf("GCD is : %Zd\ns = %Zd\nt = %Zd\n",g,s,t);
}