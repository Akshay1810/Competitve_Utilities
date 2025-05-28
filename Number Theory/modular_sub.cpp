long long msub(long long a, long long b, long long m){
	return (a%m - b%m + m)%m;
}