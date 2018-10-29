#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Student *t = new Student(s.getName(), s.getPerm());
  Node* c = new Node;
  c->s = t;
  c->next = nullptr;
  if (head == NULL)
    {
      head = c;
      tail = c;
    }
  else
    {
      tail->next = c;
      tail = c;
    }
}

std::string StudentRoll::toString() const {
  Node* c = head;
  std::string ans = "[";
  while (c != nullptr)
    {
      ans += c->s->toString();
      c = c->next;
      if ( c)
	{
	  ans += ",";
	}

    }
  ans += "]";
  return ans;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  StudentRoll *copy = new StudentRoll;
  Node* h = orig.head;
  while(h != nullptr)
    {
      Student *temp = h->s;
      copy->insertAtTail(*temp);
      h = h->next;
    }
  head = copy->head;
  tail = copy->tail;
}

StudentRoll::~StudentRoll() {
  Node* curr = head;
  while(curr != nullptr)
    {
      curr = curr->next;
      delete curr;
    }
  delete head;
  head = nullptr;
  tail = nullptr;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node *temp = nullptr;

  while (temp != nullptr)
    {
      temp = head->next;
      delete temp;
      head = temp;
    }
  head = nullptr;
  Node* curr = right.head;
  if (curr == nullptr)
    {
      return *this;
    }
  while (curr != nullptr)
    {
      Student *t = curr->s;
      this->insertAtTail(*t);
      curr = curr->next;
    }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





