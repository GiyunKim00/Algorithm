//
// Created by KimGiyun on 25. 11. 17.
//

#include <iostream>

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    char c;

    Node(char c) : c(c), prev(nullptr), next(nullptr) {}
};

int main() {
    int n;

    cin >> n;
    cin.ignore();

    while (n--) {
        string str;
        Node *head = new Node('!');
        Node *cur = head;
        Node *tail = new Node(' ');
        head->next = tail;
        tail->prev = head;

        cin >> str;

        for (auto i: str) {
            if (isalnum(i)) {
                Node *newNode = new Node(i);
                newNode->next = cur->next;
                newNode->prev = cur;
                cur->next = newNode;
                newNode->next->prev = newNode;
                cur = newNode;
            } else {
                if (i == '<' && cur->prev != nullptr) cur = cur->prev;
                if (i == '>' && cur->next != tail) cur = cur->next;
                if (i == '-' && cur != head) {
                    Node *target = cur;
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    cur = cur->prev;
                    delete target;
                }
            }
//            cout << "inst : ";
//            if (i == '<') cout << "left\n";
//            else if (i == '>') cout << "right\n";
//            else if (i == '-') cout << "delete\n";
//            else cout << "insert " << i << "\n";
//            cout << "head : " << head->c << " cursor : ";
//            if (cur->c != ' ') cout << cur->c << "\n";
//            else cout << "end\n";
//            for (Node *k = head; k != nullptr; k = k->next)if (k->c != ' ') cout << k->c;
//            cout << "\n";
        }
        for (Node *k = head->next; k != tail; k = k->next) cout << k->c;
        cout << "\n";
        delete head;
        delete tail;
    }
    return 0;
}

