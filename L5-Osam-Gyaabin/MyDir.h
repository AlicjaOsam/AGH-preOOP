struct MyDir{
  MyDir *up;
  MyDir *child;
  int n;
  char* str;
  int deep;
};

void initDir(MyDir& , char* );

void print(MyDir& );

void printDir(MyDir& );

MyDir* addDir(MyDir& , char* );

MyDir* addDir(MyDir&, MyDir );

void clear(MyDir& );

void clearDir(MyDir* );