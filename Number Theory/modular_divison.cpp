long long mmul(long long a, long long b, long long m){
	return (a%m * b%m)%m;
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