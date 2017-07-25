#include "simpleQueue.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <string>

using std::endl;
using std::cin; using std::cout;
using std::setw;
using std::cerr;
using std::stack;
using std::string;

int main() 
{
    Queue q;
    string op;
    int val = 0;

   cout << "operation -- size front end" << endl;
   while ( !cin.eof() ) 
   {
        cin >> op;
        if ( op == "push" ) 
	{
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" )
	{
            q.pop();
            cout << op << "       -- ";
        }
        else
	{
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
    }

    while ( !q.empty() )
      q.pop();

    cout << "End -- size of Queue is: " << q.size() << endl;

    return 0;
}


/*                                                                     empty()
  Parameters:
       n/a

  Objective:
       checks to see if both stack s1 and stack s2 are empty

  Returns:
       Will return true if s1 and s2 are both empty, else it will return false

******************************************************************************/
bool Queue::empty() const
{
  if (s1.empty() && s2.empty())
     return true;
  else
     return false;
}


/*								         size()
  Parameters:
        n/a

  Objective:
        calls the size for s1 and s2 then adds them to a total value.

  Returns:
	returns the total of s1 and s2.

******************************************************************************/
int Queue::size() const
{
   int totalSize = s1.size() + s2.size();
   return totalSize;
}


/*								        front()
  Parameters:
	n/a

  Objective:
	This method will return the oldest element in the stack. If s2 is empty
	 it will move elements from s1 to s2. 

  Returns:
	Returns the top value of s2's stack.

******************************************************************************/
int Queue::front()
{
      if(s2.empty())
      {
         while(!s1.empty())
         {
            s2.push(s1.top());
            s1.pop();
         }
      }
    return s2.top();
}

/*									back()
   Parameters:
	n/a

   Objective:
	will return the newest element of the stack.

   Returns:
	Returns the newest element, or "s1.top()".

******************************************************************************/
int Queue::back()
{
    return s1.top();
}



/*							                 push()
   Parameters:
	const int& val - this is the value being pushed onto the stack

   Objective:
        pushes the value paramter onto s1's stack.

   Return:
	void - no return value.

******************************************************************************/
void Queue::push(const int& val)
{
    s1.push(val);
}


/*								         pop()
   Parameters:
	n/a

   Objective:
	This function will remove the oldest element.

   Returns:
	void - no return value.

******************************************************************************/
void Queue::pop()
{
  if(!empty())
  {
     front();
  }
  s2.pop();
}


