#include <setjmp.h>  // Noncompliant
//#if defined ( X > Y )
//#if defined X && defined Y && X > Y
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