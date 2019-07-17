#include <iostream>

class DoublyNode
{
public:
  int data;
  DoublyNode *next;
  DoublyNode *prev;
  DoublyNode(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinklist
{
private:
  DoublyNode *head;

public:
  DoublyLinklist()
  {
    this->head = nullptr;
  }
  void printLinklist()
  {
    DoublyNode *currentNode = this->head;
    while (currentNode)
    {
      std::cout << "\n node-value: " << currentNode->data << "\n";
      currentNode = currentNode->next;
    }
  }
  void addBack(int data)
  {
    DoublyNode *currentNode = this->head;
    DoublyNode *dNode = new DoublyNode(data);
    if (currentNode == nullptr)
    {
      this->head = dNode;
    }
    else
    {
      while (currentNode->next)
        currentNode = currentNode->next;
      currentNode->next = dNode;
      dNode->prev = currentNode;
    }
  }
  void addFront(int data)
  {
    DoublyNode *currentHead = this->head;
    DoublyNode *newHead = new DoublyNode(data);
    if (currentHead == nullptr)
    {
      this->head = newHead;
      return;
    }
    else
    {
      currentHead->prev = newHead;
      newHead->next = currentHead;
      this->head = newHead;
    }
  }
  void addAfter(int givenValue, int newValue)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *nextNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode)
        {
          nextNode = currentNode->next;
          if (currentNode->data == givenValue)
          {
            DoublyNode *dNode = new DoublyNode(newValue);
            currentNode->next = dNode;
            dNode->prev = currentNode;
            dNode->next = nextNode;
            if (nextNode)
            {
              nextNode->prev = dNode;
            }
            break;
          }
          currentNode = nextNode;
        }
        if (currentNode == nullptr)
        {
          throw "given value is not found in linklist";
        }
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  void reverseDoublyLinklist()
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *prevNode = nullptr;
      DoublyNode *nextNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "Linklist is empty";
      }
      else
      {
        while (currentNode)
        {
          nextNode = currentNode->next;
          currentNode->next = prevNode;
          currentNode->prev = nextNode;
          prevNode = currentNode;
          currentNode = nextNode;
        }
        this->head = prevNode;
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
    try
    {
      DoublyNode *currentNode = this->head;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        DoublyNode *nextNode = currentNode->next;
        if (nextNode)
        {
          nextNode->prev = nullptr;
        }
        this->head = nextNode;
        delete currentNode;
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  void deleteTail()
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode->next)
        {
          prevNode = currentNode;
          currentNode = currentNode->next;
        }
        delete currentNode;
        prevNode->next = nullptr;
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  void deleteElementFromLinklist(int data)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "Linklist is empty";
      }
      else
      {
        if (currentNode->data == data)
        {
          this->deleteHead();
          std::cout << "\n deleted Node" << currentNode->data << "\n";
        }
        else
        {
          while (currentNode && currentNode->data != data)
          {
            prevNode = currentNode;
            currentNode = currentNode->next;
          }
          if (currentNode == nullptr)
          {
            throw "element not found in linklist";
          }
          else
          {
            prevNode->next = currentNode->next;
            currentNode->next->prev = prevNode;
            std::cout << "\n deleted Node" << currentNode->data << "\n";
            delete currentNode;
          }
        }
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
    DoublyNode *currentNode = this->head;
    int counter = 0;
    while (currentNode)
    {
      counter++;
      currentNode = currentNode->next;
    }
    return counter;
  }
  DoublyNode *getHead()
  {
    return this->head;
  }
  DoublyNode *getMiddle()
  {
    try
    {
      DoublyNode *slowPointer = this->head;
      DoublyNode *fastPointer = this->head;
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
  DoublyNode *getNthElementFromLinklist(int index)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      int counter = 0;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
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
  DoublyNode *getElementFromLinklist(int data)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode)
        {
          if (currentNode->data == data)
          {
            return currentNode;
          }
          currentNode = currentNode->next;
        }
        if (currentNode == nullptr)
        {
          throw "element not found in linklist";
        }
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
};

int main()
{
  DoublyLinklist dl;
  dl.addBack(33);
  dl.addBack(35);
  dl.addBack(36);
  dl.addBack(37);
  dl.addFront(23);
  dl.addFront(24);
  dl.deleteElementFromLinklist(33);
  dl.deleteHead();
  dl.deleteTail();
  dl.printLinklist();
  return 0;
}