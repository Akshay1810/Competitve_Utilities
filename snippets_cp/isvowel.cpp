int isvowel(char ch) { // make sure ch is in lowercase
  char vowel[6] = "aeiouAEIOU";
  for (int j = 0; vowel[j]; j++)
    if (vowel[j] == ch)
      return 1;
  return 0;
}