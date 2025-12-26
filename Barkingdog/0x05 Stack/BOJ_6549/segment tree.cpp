#include <iostream>

using namespace std;

int init_segment_tree(int *tree, int *arr, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    int left_result = init_segment_tree(tree, arr, node * 2, start, mid);
    int right_result = init_segment_tree(tree, arr, node * 2 + 1, mid + 1, end);
    tree[node] = left_result + right_result;

    return tree[node];
}

int sum(int *tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int left_result = sum(tree, node * 2, start, mid, left, right);
    int right_result = sum(tree, node * 2 + 1, mid + 1, end, left, right);

    return left_result + right_result;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int segment_tree[20] = {0,};
    init_segment_tree(segment_tree, arr, 1, 0, 4);

    for (auto i: segment_tree) cout << i << " ";
    cout << "\n";
    cout << sum(segment_tree, 1, 0, 4, 2, 4);

    return 0;
}