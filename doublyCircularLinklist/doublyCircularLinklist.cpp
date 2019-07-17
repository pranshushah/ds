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

class DoublyCircularLinklist
{
private:
  DoublyNode *head = nullptr;

public:
  DoublyCircularLinklist()
  {
    this->head = nullptr;
  }
  void addBack(int data)
  {
    DoublyNode *currentNode = this->head;
    DoublyNode *newNode = new DoublyNode(data);
    if (currentNode == nullptr)
    {
      newNode->next = newNode;
      newNode->prev = newNode;
      this->head = newNode;
    }
    else
    {
      while (currentNode->next != this->head)
        currentNode = currentNode->next;
      currentNode->next = newNode;
      newNode->prev = currentNode;
      newNode->next = this->head;
      this->head->prev = newNode;
    }
  }
  void addFront(int data)
  {
    DoublyNode *currentHead = this->head;
    DoublyNode *newNode = new DoublyNode(data);
    if (currentHead == nullptr)
    {
      newNode->next = newNode;
      newNode->prev = newNode;
    }
    else
    {
      DoublyNode *currentNode = this->head;
      while (currentNode->next != this->head)
        currentNode = currentNode->next;
      currentNode->next = newNode;
      currentHead->prev = newNode;
      newNode->next = currentHead;
      newNode->prev = currentNode;
    }
    this->head = newNode;
  }
  void addAfter(int givenData, int addData)
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
        while (currentNode->next != this->head)
        {
          nextNode = currentNode->next;
          if (currentNode->data == givenData)
          {
            DoublyNode *newNode = new DoublyNode(addData);
            currentNode->next = newNode;
            newNode->next = nextNode;
            newNode->prev = currentNode;
            return;
          }
          currentNode = nextNode;
        }
        if (currentNode->next == this->head && currentNode->data == givenData)
        {
          nextNode = currentNode->next;
          DoublyNode *newNode = new DoublyNode(addData);
          currentNode->next = newNode;
          newNode->next = nextNode;
          newNode->prev = currentNode;
          this->head->prev = newNode;
          return;
        }
        else
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
      DoublyNode *currentNode = this->head;
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
  DoublyNode *getHead()
  {
    return this->head;
  }
  DoublyNode *getTail()
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
        while (currentNode->next != this->head)
          currentNode = currentNode->next;
        return currentNode;
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
    try
    {
      DoublyNode *currentNode = this->head;
      int counter = 1;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
        while (currentNode->next != this->head)
        {
          currentNode = currentNode->next;
          counter++;
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
  DoublyNode *getMiddle()
  {
    try
    {
      DoublyNode *slowPointer = this->head;
      DoublyNode *fastPointer = this->head;
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
  DoublyNode *getNthElementFromHead(int index)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      int counter = 0;
      if (currentNode == nullptr)
      {
        throw "linklist is empty";
      }
      else
      {
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
      DoublyNode *currentHead = this->head;
      if (currentHead == nullptr)
      {
        throw "can not delete head from empty linklist";
      }
      else
      {
        if (currentHead->next == this->head)
        {
          this->head = nullptr;
          delete currentHead;
        }
        else
        {
          while (currentNode->next != this->head)
            currentNode = currentNode->next;
          currentNode->next = currentHead->next;
          currentHead->next->prev = currentNode;
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
  void deleteTail()
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "can not delete tail from empty linklist";
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
          this->head->prev = prevNode;
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
  void deleteElementFromLinklist(int data)
  {
    try
    {
      DoublyNode *currentNode = this->head;
      DoublyNode *prevNode = nullptr;
      if (currentNode == nullptr)
      {
        throw "cannot delete from empty linklist";
      }
      else
      {
        if (currentNode->data == data)
        {
          if (currentNode->next != this->head)
          {
            DoublyNode *tempNode = this->head;
            while (tempNode->next != this->head)
              tempNode = tempNode->next;
            tempNode->next = currentNode->next;
            currentNode->next->prev = tempNode;
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
          if (currentNode->next == this->head && currentNode->data == data)
          {
            prevNode->next = currentNode->next;
            this->head->prev = prevNode;
            std::cout << "\n deleted Node" << currentNode->data << "\n";
            delete currentNode;
          }
          else
          {
            if (currentNode->next != this->head && currentNode->data == data)
            {
              prevNode->next = currentNode->next;
              currentNode->next->prev = prevNode;
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
};

int main()
{
  DoublyCircularLinklist dcl;
  // dcl.addBack(24);
  // dcl.addBack(22);
  // dcl.addBack(21);
  // dcl.deleteElementFromLinklist(22);
  dcl.addFront(221);
  dcl.addFront(23);
  // dcl.addBack(26);
  dcl.addAfter(221, 66);
  // dcl.deleteTail();
  // dcl.deleteHead();
  // DoublyNode *Node = dcl.getNthElementFromHead(2);
  // std::cout << Node->data;

  dcl.printLinklist();
  return 0;
}