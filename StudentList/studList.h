struct Element{
  char* name;
  Element *next;
};

struct StudList{
  Element *head;
  Element *tail;
  char* name;
};

void initList(StudList* , char* );
void prepend(StudList* , char* );
bool isEmpty(const StudList* );
void print(const StudList* );
void removeLast(StudList* );
void clearList(StudList* );
void removeList(StudList* );