#include <iostream>

class Node
{
public:
  Node *next;
  int data;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  };
};

class Linklist
{
private:
  Node *head;

public:
  Linklist()
  {
    this->head = NULL;
  }
  void addBack(int data)
  {
    Node *node = new Node(data);
    if (this->head == NULL)
    {
      this->head = node;
      return;
    }
    else
    {
      Node *currentNode = this->head;
      while (currentNode->next)
        currentNode = currentNode->next;
      currentNode->next = node;
    }
  }
  void addFront(int data)
  {
    Node *node = new Node(data);
    Node *currentHead = this->head;
    if (currentHead == NULL)
    {
      this->head = node;
    }
    else
    {
      this->head = node;
      this->head->next = currentHead;
    }
  }

  void addAfter(int data, int addData)
  {
    try
    {
      Node *currentNode = this->head;
      Node *nextNode = NULL;
      if (currentNode == NULL)
      {
        throw "linklist is empty";
      }
      while (currentNode)
      {
        nextNode = currentNode->next;
        if (currentNode->data == data)
        {
          Node *newNode = new Node(addData);
          newNode->next = nextNode;
          currentNode->next = newNode;
          break;
        }
        currentNode = nextNode;
      }
      if (currentNode == NULL)
      {
        throw "data Not found in linklist";
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }

  void printLinkList()
  {
    Node *currentNode = this->head;
    while (currentNode)
    {
      std::cout << "\n NodeValue: " << currentNode->data << " \n";
      currentNode = currentNode->next;
    }
  }

  void deleteElementFromLinklist(int data)
  {
    try
    {
      Node *currentNode = this->head;
      Node *prevNode = NULL;
      if (currentNode == NULL)
      {
        throw "linklist is empty";
      }
      if (currentNode->data == data)
      {
        if (currentNode->next)
        {
          this->head = currentNode->next;
          std::cout << "\n deleted Node" << currentNode->data << "\n";
          delete currentNode;
        }
        else
        {
          this->head = NULL;
          std::cout << "\n deleted Node" << currentNode->data << "\n";
          delete currentNode;
        }
      }
      else
      {
        while (currentNode && currentNode->data != data)
        {
          prevNode = currentNode;
          currentNode = currentNode->next;
        }
        if (currentNode == NULL)
        {
          throw "delete value not found";
        }
        prevNode->next = currentNode->next;
        std::cout << "\n deleted Node" << currentNode->data << "\n";
        delete currentNode;
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  void deleteHead()
  {
    Node *currentNode = this->head;
    if (currentNode)
    {
      this->head = currentNode->next;
      delete currentNode;
    }
    else
    {
      std::cerr << "Linklist is empty\n";
      std::terminate();
    }
  }
  void deleteTail()
  {
    try
    {
      Node *currentNode = this->head;
      Node *prevNode;
      if (currentNode == NULL)
      {
        throw "Linklist is empty";
      }
      if (currentNode->next == NULL)
      {
        this->head = NULL;
        delete currentNode;
      }
      else
      {
        while (currentNode->next)
        {
          prevNode = currentNode;
          currentNode = currentNode->next;
        };
        delete currentNode;
        prevNode->next = NULL;
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  int getLength()
  {
    Node *currentNode = this->head;
    int counter = 0;
    while (currentNode)
    {
      counter++;
      currentNode = currentNode->next;
    }
    return counter;
  }

  Node *getHead()
  {
    return this->head;
  }

  Node *getMiddle()
  {
    try
    {
      Node *slowPointer = this->head;
      Node *fastPointer = this->head;
      if (slowPointer == NULL)
      {
        throw "Linklist is empty";
      }
      while (fastPointer && fastPointer->next)
      {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
      }
      return slowPointer;
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  Node *getNthElementFromHead(int index)
  {
    try
    {
      Node *currentNode = this->head;
      int counter = 0;
      if (currentNode == NULL)
      {
        throw "Linklist is Empty";
      }
      while (currentNode && counter != index)
      {
        counter++;
        currentNode = currentNode->next;
      }
      if (currentNode == NULL)
      {
        throw "index is greater than length of linklist";
      }
      return currentNode;
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  void reverseLinklist()
  {
    Node *currentNode = this->head;
    Node *prevNode = NULL;
    Node *nextNode = NULL;
    while (currentNode)
    {
      nextNode = currentNode->next;
      currentNode->next = prevNode;
      prevNode = currentNode;
      currentNode = nextNode;
    };
    this->head = prevNode;
  }
};

int main()
{
  Linklist linklist;
  linklist.addBack(33);
  linklist.addBack(34);
  linklist.addBack(35);
  // linklist.addBack(36);
  // linklist.addBack(37);
  // linklist.addBack(38);
  // linklist.addAfter(39, 44);
  // linklist.deleteElementFromLinklist(22);
  linklist.printLinkList();

  return 0;
}