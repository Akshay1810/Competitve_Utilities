// leetcode 572. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    // string serialization algorithm makes our works a little bit easy reduced complexity from
    // O(m*n) to O(m+n)
    void serialize(TreeNode *root, string &ref)
    {
        if (root == NULL)
        {
            ref += 'N';
            return;
        }
        ref += (char)('0' + root->val);
        serialize(root->left, ref);
        serialize(root->right, ref);
    }
    // Compute LPS (longest proper prefix-suffix) array for pattern
    vector<int> computeLPS(string &pattern)
    {
        int m = pattern.size();
        std::vector<int> lps(m);
        int len = 0; // length of the previous longest prefix suffix
        lps[0] = 0;  // lps[0] is always 0

        for (int i = 1; i < m;)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    // fall back in the pattern
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool isSubstringKMP(string &text, string &pattern)
    {
        int n = text.size();
        int m = pattern.size();
        if (m == 0)
            return true; // empty pattern matches
        if (n < m)
            return false; // pattern longer than text

        vector<int> lps = computeLPS(pattern);
        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == m)
                {
                    return true; // match found
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1]; // fall back in pattern
                }
                else
                {
                    i++; // move text pointer
                }
            }
        }
        return false; // no match found
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string rootstr = "";
        string subrootstr = "";
        serialize(root, rootstr);
        serialize(subRoot, subrootstr);
        // cout<<rootstr<<" "<<subrootstr<<endl;
        return isSubstringKMP(rootstr, subrootstr);
    }
};