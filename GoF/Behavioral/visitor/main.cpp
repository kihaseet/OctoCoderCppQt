#include <iostream>
#include <string>
using namespace std;

class Face;
class Hat;
class Feather;

class Visitor{
public:
  virtual void visit (Face& face) = 0;
  virtual void visit (Hat& hat) = 0;
  virtual void visit (Feather& feather) = 0;
};

class Object{
public:
  virtual void accept (Visitor& v) = 0;
};

class Face:public Object{
public:
  void accept (Visitor& v)
  {
      v.visit (*this);
  }
};

class Hat:public Object{
public:
  void accept (Visitor& v)
  {
      v.visit(*this);
  }
};

class Feather:public Object{
public:
  void accept (Visitor& v)
  {
      v.visit(*this);
  }
};


class Paint:public Visitor{
public:
  void visit (Face& face)
  {
      cout<<"Face"<<endl;
  }

  void visit (Hat& hat)
  {
      cout<<"::Hat::"<<endl;
  }

  void visit (Feather& feather)
  {
      cout<<":::Feather:::"<<endl;
  }
};

int main()
{
  static const size_t count=3;
  Face face;
  Hat hat;
  Feather feather;


  Object*objects[count]={&face,&hat,&feather};

  for(size_t i=0;i<count;i++)
  {
    Paint painter;
    objects[i]->accept(painter);
  }
  return 0;
}
