vector<string> tokens;
char *p;

for (p = strtok(str, " ."); p; p = strtok(NULL, " .")) {
    tokens.push_back(p); // casting from C string to C++ string is automatic
}