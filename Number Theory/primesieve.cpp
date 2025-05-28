const int size = 1e6;
vector<bool> s(size+1, 1);
void sieve(){
	s[0] = s[1] = 0;
	for(int i =2; i*i < size; i++){
		if(s[i]){
			for(int j = i*i; j < size; j+=i){
				s[j] = 0;
			}
		}
	}
}