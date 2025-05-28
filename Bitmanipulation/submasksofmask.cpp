    int mask;
    cin>>mask;
	for (int subset = mask; subset; subset = (mask & (subset-1)))
		cout << subset << "\n";