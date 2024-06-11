#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtHead(Node *&head, int d)
{
  Node *newNode = new Node(d);
  newNode->next = head;
  head = newNode;
}

// void insertAtTail(Node **tail, int d)
// {
//   Node *temp = new Node(d);
//   (*tail)->next = temp;
//   *tail = temp;
// }

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}
void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}

void add(int *n)
{
  *n + 2;
}

int main()
{

  Node *node1 = new Node(10);
  Node *head = node1;

  insertAtHead(head, 20);
  insertAtHead(head, 220);
  print(head);

  Node *node2 = new Node(15);
  Node *tail = node2;
  insertAtTail(tail, 225);
  insertAtTail(tail, 20);
  insertAtTail(tail, 25);
  print(node2);

  return 0;
}