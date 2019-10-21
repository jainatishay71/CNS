#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main()
{
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	seed = time(NULL);
	gmp_randseed_ui(state,seed);
	mpz_t p,q,n,phi,e,d,t,num;
	mpz_inits(p,q,n,phi,e,d,t,num,NULL);
	mpz_urandomb(p,state,1024);
	mpz_urandomb(q,state,1024);
	mpz_nextprime(p,p);
	mpz_nextprime(q,q);
	gmp_printf("P = %Zd\n\nQ = %Zd\n\n",p,q);
	mpz_mul(n,p,q);
	mpz_sub_ui(p,p,1);
	mpz_sub_ui(q,q,1);
	mpz_mul(phi,p,q);
	do
	{
		mpz_urandomm(e,state,phi);
		mpz_gcd(t,e,phi);
	}while(mpz_cmp_ui(t,1)!=0);
	mpz_gcdext(t,d,t,e,phi);
	gmp_printf("Enter a number : ");
	gmp_scanf("%Zd",num);
	mpz_powm(t,num,e,n);
	gmp_printf("Encrypted : %Zd\n",t);
	mpz_powm(t,t,d,n);
	gmp_printf("Decrypted : %Zd\n",t);
}