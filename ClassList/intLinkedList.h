class Element{
  public:
  int _value;
  Element *_next;
};

class IntLinkedList{
  private:
  Element* _head;
  Element* _tail;
  public:
  IntLinkedList();
  ~IntLinkedList();
  int size();
  bool isEmpty();
  void print();
  void removeLast();
  void prepend(int );
  bool contains(int );
  void removeValue(int );
  void addSorted(int );
};