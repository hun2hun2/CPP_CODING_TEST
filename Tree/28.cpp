#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

void preorder(const vector<int>& tree, string& answer, int root) {
    if (!tree[root] || root >= tree.size()) return;
    answer += to_string(tree[root]) + ' ';
    preorder(tree, answer, root * 2 + 1);
    preorder(tree, answer, root * 2 + 2);
}

void inorder(const vector<int>& tree, string& answer, int root) {
    if (!tree[root] || root >= tree.size()) return;
    inorder(tree, answer, root * 2 + 1);
    answer += to_string(tree[root]) + ' ';
    inorder(tree, answer, root * 2 + 2);
}

void postorder(const vector<int>& tree, string& answer, int root) {
    if (!tree[root] || root >= tree.size()) return;
    postorder(tree, answer, root * 2 + 1);
    postorder(tree, answer, root * 2 + 2);
    answer += to_string(tree[root]) + ' ';
}

vector<string> solution(vector<int> nodes) {
    vector<string> result;
    string pre = "";
    string in = "";
    string post = "";
    preorder(nodes, pre, 0);
    pre.pop_back();
    result.push_back(pre);
    inorder(nodes, in, 0);
    in.pop_back();
    result.push_back(in);
    postorder(nodes, post, 0);
    post.pop_back();
    result.push_back(post);

    return result;
}

void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, "\n"));
    cout << endl;
}

int main()
{
    print(solution({1, 2, 3, 4, 5, 6, 7})); 
    /** 
     출력값 
     1 2 4 5 3 6 7
     4 2 5 1 6 3 7
     4 5 2 6 7 3 1
    **/
    
    return 0;
}
