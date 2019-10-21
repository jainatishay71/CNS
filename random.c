#include <gmp.h>
#include <time.h>

int main()
{
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	mpz_t max,a,b,bits;
	mpz_inits(max,a,b,bits,NULL);
	mpz_set_ui(max,1024);
	mpz_set_ui(bits,10);
	mpz_urandomm(a,state,max);
	mpz_rrandomb(b,state,10);
	gmp_printf("a is : %Zd\n",a);
	gmp_printf("b is : %Zd\n",b);
}