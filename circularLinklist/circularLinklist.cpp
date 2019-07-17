#include <iostream>

class Node
{
public:
  Node *next;
  int data;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  };
};

class CiruclarLinklist
{
private:
  Node *head;

public:
  CiruclarLinklist()
  {
    this->head = nullptr;
  }
  void addBack(int data)
  {
    Node *currentNode = this->head;
    Node *newNode = new Node(data);
    if (currentNode == nullptr)
    {
      newNode->next = newNode;
      this->head = newNode;
    }
    else
    {
      while (currentNode->next != this->head)
        currentNode = currentNode->next;
      currentNode->next = newNode;
      newNode->next = this->head;
    }
  }
  void addFront(int data)
  {
    Node *currentHead = this->head;
    Node *newNode = new Node(data);
    if (currentHead == nullptr)
    {
      newNode->next = newNode;
    }
    else
    {
      Node *currentNode = this->head;
      while (currentNode->next != this->head)
        currentNode = currentNode->next;
      currentNode->next = newNode;
      newNode->next = currentHead;
    }
    this->head = newNode;
  }
  void addAfter(int givenData, int addValue)
  {
    try
    {
      Node *currentNode = this->head;
      Node *nextNode = nullptr;

      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode->next != this->head || currentNode->data == givenData)
        {
          nextNode = currentNode->next;
          if (currentNode->data == givenData)
          {
            Node *newNode = new Node(addValue);
            currentNode->next = newNode;
            newNode->next = nextNode;
            return;
          }
          currentNode = nextNode;
        }
        if (currentNode->next == this->head)
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
  void printLinklist()
  {
    try
    {
      Node *currentNode = this->head;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode->next != this->head)
        {
          std::cout << "\n NodeValue: " << currentNode->data << " \n";
          currentNode = currentNode->next;
        }
        std::cout << "\n NodeValue: " << currentNode->data << " \n";
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
      Node *currentNode = this->head;
      Node *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        if (currentNode->next == this->head)
        {
          this->head = nullptr;
          delete currentNode;
          return;
        }
        else
        {
          while (currentNode->next != this->head)
          {
            prevNode = currentNode;
            currentNode = currentNode->next;
          }
          prevNode->next = this->head;
          delete currentNode;
        }
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
      Node *currentNode = this->head;
      Node *currentHead = this->head;
      if (currentHead == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        if (currentNode->next == this->head)
        {
          this->head = nullptr;
          delete currentNode;
          return;
        }
        else
        {
          while (currentNode->next != this->head)
            currentNode = currentNode->next;
          currentNode->next = currentHead->next;
          this->head = currentHead->next;
          delete currentHead;
        }
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
      Node *currentNode = this->head;
      Node *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        if (currentNode->data == data)
        {
          if (currentNode->next != this->head)
          {
            Node *tempNode = this->head;
            while (tempNode->next != this->head)
              tempNode = tempNode->next;
            tempNode->next = currentNode->next;
            this->head = currentNode->next;
            std::cout << "\n deleted Node" << currentNode->data << "\n";
            delete currentNode;
          }
          else
          {
            this->head = nullptr;
            std::cout << "\n deleted Node" << currentNode->data << "\n";
            delete currentNode;
          }
        }
        else
        {
          while (currentNode->next != this->head && currentNode->data != data)
          {
            prevNode = currentNode;
            currentNode = currentNode->next;
          }
          //check for tail
          if (currentNode->next == this->head && currentNode->data == data)
          {
            prevNode->next = currentNode->next;
            std::cout << "\n deleted Node" << currentNode->data << "\n";
            delete currentNode;
          }
          else
          {
            if (currentNode->next != this->head && currentNode->data == data)
            {
              prevNode->next = currentNode->next;
              std::cout << "\n deleted Node" << currentNode->data << "\n";
              delete currentNode;
            }
            else
            {
              throw "element not found in linklist";
            }
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
  Node *getHead()
  {
    return this->head;
  }
  Node *getTail()
  {
    try
    {
      Node *currentNode = this->head;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      while (currentNode->next != this->head)
        currentNode = currentNode->next;
      return currentNode;
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  int getLength()
  {
    try
    {
      Node *currentNode = this->head;
      int counter = 1;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode->next != this->head)
        {
          counter++;
          currentNode = currentNode->next;
        }
        return counter;
      }
    }
    catch (const char *msg)
    {
      std::cerr << msg << "\n";
      std::terminate();
    }
  }
  Node *getMiddle()
  {
    try
    {
      Node *slowPointer = this->head;
      Node *fastPointer = this->head;
      if (slowPointer == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        if (slowPointer->next == this->head)
        {
          return slowPointer;
        }
        else
        {
          do
          {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
          } while (fastPointer != this->head && fastPointer->next != this->head);
          return slowPointer;
        }
      }
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
      int counter = 0;
      Node *currentNode = this->head;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      while (currentNode->next != this->head && counter != index)
      {
        counter++;
        currentNode = currentNode->next;
      }
      //to get tail node
      if (currentNode->next == this->head && index == counter)
      {
        return currentNode;
      }
      else
      {
        if (currentNode->next == this->head && index != counter)
        {
          throw "index is greater than length of linklist";
        }
        else
        {
          return currentNode;
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

  CiruclarLinklist cl;
  cl.addBack(33);
  cl.addBack(35);
  cl.addBack(36);
  cl.addAfter(35, 34);
  cl.addBack(27);
  cl.deleteElementFromLinklist(36);
  cl.printLinklist();
  return 0;
}