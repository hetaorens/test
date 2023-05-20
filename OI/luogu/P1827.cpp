#include <bits/stdc++.h>
using namespace std;
string front, middle;
void tree(string front, string middle)
{ // 遍历
    if (front.size() < 1)
        return;                                                                                  // 空子树
    int m = middle.find(front[0]);                                                               // 找到中序遍历中的根节点
    tree(front.substr(1, m), middle.substr(0, m));                                               // 左子树
    tree(front.substr(m + 1, front.size() - m - 1), middle.substr(m + 1, front.size() - m - 1)); // 右子树
    cout << front[0];                                                                            // 输出根节点
}
int main()
{
    cin >> front >> middle; // 前序、中序遍历结果
    tree(front, middle);    // 遍历
    return 0;
}