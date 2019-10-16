#include<bits/stdc++.h>

using namespace std;

struct s{
    int a;
    int b;
};
#include <setjmp.h>  // Noncompliant

jmp_buf buf;

int main(int argc, char* argv[]) {
  int i = setjmp(buf);  // Noncompliant
  if (i == 0) { // value of i was assigned after env was saved & will be indeterminate after longjmp();
    // normal execution
  } else {
    // recover
  }
}

//...

void fun() {
  //...
  longjmp(buf, 1);  // Noncompliant
}

