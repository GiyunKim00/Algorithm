#include <iostream>

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    int i;

    Node(int i) : i(i), prev(nullptr), next(nullptr) {}
};

int main() {
    int N, K;
    Node *head = new Node(1);
    Node *cur = head;
    Node *ans = nullptr;
    Node *anscur = nullptr;
    cin >> N >> K;

    for (int i = 2; i <= N; ++i) {
        Node *newNode = new Node(i);
        cur->next = newNode;
        newNode->prev = cur;
        cur = newNode;
    }
    cur->next = head;
    head->prev = cur;
    cur = head;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K - 1; ++j) cur = cur->next;
        Node *target = cur;
        if (ans) {
            anscur->next = new Node(cur->i);
            anscur->next->prev = anscur;
            anscur = anscur->next;
        } else {
            ans = new Node(cur->i);
            anscur = ans;
        }
        cur = cur->next;
        cur->prev = target->prev;
        target->prev->next = cur;
        delete target;
    }
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << ans->i;
        if (i != N - 1) cout << ", ";
        else cout << ">";
        ans = ans->next;
    }

    return 0;
}

