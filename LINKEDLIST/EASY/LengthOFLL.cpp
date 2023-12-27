#include<iostream>

using namespace std;

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

int length(Node *head)
{
	if(!head) return 0;

    int cnt=1;

    while(head->next!=nullptr){
        cnt++;
        head=head->next;
    }

    return cnt;
}

int main(){

    return 0;
}

