#include <iostream>
#include <string>
using namespace std;

struct Node {
    float rating;
    string comment;
    Node* next;
};

void output(Node* head);
void addHead(Node*& head, float rating, const string& comment);
void addTail(Node*& head, float rating, const string& comment);

int main() {
    Node* head = nullptr;

    // test both ways
    addHead(head, 4.8, "Oscar contender");
    addTail(head, 4.1, "Brilliant lead acting");

    output(head);

    return 0;
}

void addHead(Node*& head, float rating, const string& comment) {
    Node* newNode = new Node{rating, comment, head};
    head = newNode;
}

void addTail(Node*& head, float rating, const string& comment) {
    Node* newNode = new Node{rating, comment, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) current = current->next;
        current->next = newNode;
    }
}

void output(Node* head) {
    Node* current = head;
    int count = 1;
    float sum = 0;
    int total = 0;

    while (current) {
        cout << "> Review #" << count++ << ": "
             << current->rating << ": " << current->comment << endl;
        sum += current->rating;
        total++;
        current = current->next;
    }

    if (total > 0) {
        cout << "> Average: " << (sum / total) << endl;
    } else {
        cout << "No reviews." << endl;
    }
}
