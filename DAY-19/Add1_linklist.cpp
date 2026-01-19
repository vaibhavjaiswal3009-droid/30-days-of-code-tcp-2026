#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverse(Node* head) {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addOne(Node* head) {
        head = reverse(head);

        Node* curr = head;
        int carry = 1;

        while (curr != NULL) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;

            if (carry == 0) break;

            if (curr->next == NULL && carry > 0) {
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }

        return reverse(head);
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    Solution sol;
    head = sol.addOne(head);

    printList(head); 

    return 0;
}