bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first)
        return a.first < b.first; // Descending order for the first element
    return a.second > b.second;  // Ascending order for the second element
}