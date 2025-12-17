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
    string init_str;
    int n;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *cur = new Node(' ');

    cin >> init_str >> n;
    cin.ignore();

    for (auto i: init_str) {
        Node *node = new Node(i);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    cur->prev = tail;
    tail->next = cur;

    while (n--) {
        string str;
        getline(cin, str);
        if (str.length() > 1) {
            Node *newNode = new Node(str[2]);

            if (cur->prev) {
                cur->prev->next = newNode;
                newNode->prev = cur->prev;
            } else head = newNode;

            newNode->next = cur;
            cur->prev = newNode;

        } else {
            if (str[0] == 'L' && cur->prev != nullptr) cur = cur->prev;
            if (str[0] == 'D' && cur->next != nullptr) cur = cur->next;
            if (str[0] == 'B') {
                if (cur->prev != nullptr) {
                    Node *target = cur->prev;
                    cur->prev = target->prev;

                    if (target->prev) target->prev->next = cur;
                    else head = cur;

                    delete target;
                }
            }
        }
//        cout << "inst : ";
//        if (str[0] == 'L') cout << "left\n";
//        else if (str[0] == 'D') cout << "right\n";
//        else if (str[0] == 'B') cout << "delete\n";
//        else cout << "insert " << str[2] << "\n";
//        cout << "head : " << head->c << " tail : " << tail->c << " cursor : ";
//        if (cur->c != ' ') cout << cur->c << "\n";
//        else cout << "end\n";
//        for (Node *k = head; k != nullptr; k = k->next) {
//            if(k->c != ' ') cout << k->c;
//        }
//        cout << "\n";
    }

    for (Node *k = head; k != nullptr; k = k->next) if (k->c != ' ') cout << k->c;

    return 0;
}

