#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
} Node;

class queue {
private:
    Node *front;
    Node *back;
    int size;

public:
    queue();

    void push(int data);

    void pop();

    void is_empty();

    void front_num();

    void last_num();

    void return_size();
};

queue::queue() {
    front = nullptr;
    back = nullptr;
    size = 0;
}

void queue::push(int data) {
    Node *new_node = new Node;
    new_node->num = data;
    new_node->next = nullptr;

    if (front == nullptr)
        front = new_node;
    else
        back->next = new_node;
    back = new_node;
    size++;
}

void queue::pop() {
    if (front == nullptr)
        cout << "-1\n";
    else {
        cout << front->num << "\n";
        Node *del = front;
        front = front->next;
        delete del;
        size--;
    }
}

void queue::is_empty() {
    if (size == 0)
        cout << "1\n";
    else
        cout << "0\n";
}

void queue::front_num() {
    if (front != nullptr)
        cout << front->num << "\n";
    else
        cout << "-1\n";
}

void queue::return_size() {
    cout << size << "\n";
}

void queue::last_num() {
    if (front != nullptr)
        cout << back->num << "\n";
    else
        cout << "-1\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string inst;
    queue que;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> inst;
        if (inst.compare("push") == 0) {
            cin >> num;
            que.push(num);
        } else if (inst.compare("front") == 0) {
            que.front_num();
        } else if (inst.compare("back") == 0) {
            que.last_num();
        } else if (inst.compare("pop") == 0) {
            que.pop();
        } else if (inst.compare("size") == 0) {
            que.return_size();
        } else {
            que.is_empty();
        }
    }
}