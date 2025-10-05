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
void clearList(Node*& head);

int main() {
    Node* head = nullptr;
    int mode;

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes at the head\n";
    cout << "    [2] New nodes at the tail\n";
    cout << "Choice: ";
    cin >> mode;
    cin.ignore();

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        float rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, comment);

        if (mode == 1) addHead(head, rating, comment);
        else addTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore();
    }

    output(head);
    clearList(head);
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
    cout << "Outputting all reviews:\n";
    Node* current = head;
    int count = 1;
    float sum = 0;
    int total = 0;

    while (current) {
        cout << "    > Review #" << count++ << ": "
             << current->rating << ": " << current->comment << endl;
        sum += current->rating;
        total++;
        current = current->next;
    }

    if (total > 0) cout << "    > Average: " << (sum / total) << endl;
    else cout << "No reviews.\n";
}

void clearList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
}
