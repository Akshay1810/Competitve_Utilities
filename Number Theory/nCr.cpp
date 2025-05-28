// Instructions of using it
// remember calling factorials() for precomputations of factorials ans also adjusting size of facts array
// and also check the value of m (mod) once

// for precomputation of factorials
vector<long long> fact(100);
const int m = 1e9+7;

long long mmul(long long a, long long b, long long m){
	return (a%m * b%m)%m;
}

//precomputing factorials function
void factorials(){
	fact[0] = 1;
	for(int i = 1; i < 100; i++){
		fact[i] = mmul(fact[i-1],i,m);
	}
}

long long mod_exponentiation(long long a, long long b, long long m){
	if(b == 0) return 1;
	long long res = mod_exponentiation(a,b/2,m);
	res = mmul(res,res,m);
	if(b&1 == 1){
	   res = mmul(res,a,m);
	}
	return res;
}

//implementing fermat little theorem
long long modInverse(long long a, long long m)
{
    if (__gcd(a, m) != 1)
        return -1;
 
    else {
 
        // If a and m are relatively prime, then
        // modulo inverse is a^(m-2) mode m
        return mod_exponentiation(a,m-2,m);
    }
}

long long mdiv(long long a, long long b, long long m){
	return mmul(a, modInverse(b, m), m);
}

long long nCr(long long n, long long r, long long m){
	if(r < 0 || r > n) return 0;
	return mdiv(fact[n], mmul(fact[r], fact[n-r], m), m);
}