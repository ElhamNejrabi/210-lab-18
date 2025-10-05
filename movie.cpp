#include <iostream>
#include <string>
using namespace std;

struct Node {
    float rating;
    string comment;
    Node* next;
};

void output(Node* head);

int main() {
    Node* head = nullptr;

   
    Node* n1 = new Node{4.5, "Great movie!", nullptr};
    Node* n2 = new Node{3.7, "Pretty good", nullptr};
    n1->next = n2;
    head = n1;

    output(head);

    return 0;
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
