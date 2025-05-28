pair<long long, long long> extendedGCD(long long a, long long b){
	if(b == 0){
		return {1,1};
	}
	auto [x2,y2] = extendedGCD(b, a%b);
	long long x = y2, y = x2-(a/b)*y2;
	return {x,y};
}