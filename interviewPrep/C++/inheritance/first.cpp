class car{
    
};

class sportsCar: public car{

};

/* Types of inheritance
    1. Single inheritance
    2. Multilevel inheritance;
    3. Multiple inheritance
    4. Heirarchical inheritance
    5. Hybrid inheritance
 */

//Single inheritance
class A{};
class B: public A{};

//Multilevel inheritance
class C: public B{}; //C has got all the properties of A and B (Transitive)

//Multiple inheritance i.e multiple classes are inherited
class A1{};
class A2{};
class A3:public A1, public A2{};

//Heirarchical inheritance i.e same class is being inherited by multiple classes (most popular)
class A4{};
class A5 : public A4 {};
class A6:  public  A4  {};


/* 
* Protected and Private members of a class can't be directly accessed by the object of the class.

* By default the inheritance access specifier is private.

* Visibility modes or access specifiers: 
    1. private
    2. protected
    3. public

* Types of users of class 
    1. User1 will create object of your class.

    2. User2 will derive class from your class.

* Availability Vs Accessbility
    * Private: 
    *    1. User1 and User2 both will have availability of private members of the class created by me but they won't have access to them. 
    *       Access to those variables is only available to the creater of the class through the class member functions.
    
    * Protected:
    *   1. User1 can't access protected members but User2 can access the protected members of the base class directly. Remember that private
    *      is still available to both the users but only accessible by user2.
    *
    * Public: 
    *   1. Can be accessed by both User1 and User2.
    *   2. 
    * 
 */
