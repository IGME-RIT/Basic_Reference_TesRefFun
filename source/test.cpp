/*
TestRefFun
(c) 2016
original authors : David I.Schwartz
Written under the supervision of David I.Schwartz, Ph.D., and
supported by a professional development seed grant from the B.Thomas
Golisano College of Computing & Information Sciences
(https ://www.rit.edu/gccis) at the Rochester Institute of Technology.
	This program is free software : you can redistribute it and / or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or (at
	your option) any later version.
	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU
	General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.If not, see <http://www.gnu.org/licenses/>.

*	This tutorial illustrates the reference as function type and function's parameters.
*	It also involves the concept of structure and pointer.
*/

#include <iostream>
using namespace std;

#pragma region return values
/*
int& test2(int x, int& y) {	// declare function test2, its int type parameter x and reference parameter y
	 int z;        // declare int type variable z
	// return z;   // z is local, which means? 
	 return x;	   // works?
	// return 10;  // works? no. test2 should return to a reference type value
	// return y+1; // works? no. 
	// return y;   // works? ( motivation: what if y were an OOP-object?) 
				   // using an object as function parameter:  the object will be copied into the parameter. Modification only 
				   //										  affects the parameter but not the object.
				   // using reference of an object as function parameter:  Modification can affect the object and be visible once 
				   //													   the function once the function has completed.
}
*/

/*
const int& test3(int& x) {
	 return x+2; // a const ref can store a temporary (local) value
	//return x;
}
*/
#pragma endregion


#pragma region const functions params
/*
void test1(const int& x, int& y) {	// declare function test1, its const reference parameter x and reference type y
	// x = 2;      // change x?		// illegal. x is const
	// y = x + 3;  // change y?		// legal
}
*/
#pragma endregion



#pragma region efficiency
/*
struct Thing {			// declare a struct type variable Thing
	char big[1000000];	// declare member type
};
void slow(Thing t) { }	// pass Thing structure type t to function slow()
void fast(Thing& t) { }	// pass reference t refers to a Thing structure type to function fast()
*/
#pragma endregion



#pragma region swap values
/*
void swapInts(int& x, int& y) {	// declare function swapInts, its reference type parameter x and y
	int tmp = x;				// initialize int type variable tmp. tmp gets x's value
	x = y;						// x gets y's value
	y = tmp;					// y gets tmp's value
}
*/
#pragma endregion



#pragma region mixing refs/pointers
int& test4(int& x, int* y) {  
	//return x; // dummy return: try the next 3 returns
	//return y;   // error: y is a pointer, function test4 should return reference of int type 
	//return &y;  // error: &y is the address of the pointer
	//return *y;  // return the dereference of pointer y
}
#pragma endregion


int main() {

	// calling function with ref params:
	// http://msdn.microsoft.com/en-us/library/f0a5bh3e.aspx 
	// pass the address of the object while maintaining the syntax that would have been used to access the object
	//cout << "\nTesting swap:" << endl;			// output: Testing swap:
	//int m = 1;									// m gets 1
	//int n = 2;									// n gets 2
	//swapInts(m,n);								// call function swapInts(), pass m and n as its arguments
	//cout << "M: " << m << ", N: " << n << endl;	// output: M: 2, N: 1	the values of m and n are swapped

	// using ref instead of value for param:
	//cout << "\nTesting efficiency:" << endl;		// output: Testing efficiency:
	//Thing t;    // contains a whopping-big array	// c++ type structure declaration
	//slow(t);  // runs? no							// call function slow(), pass t as its argument
	//fast(t);  // runs? yes						// call function fast(), pass t as its argument
	//cout << "it worked." << endl;					// output: it worked. (only when uncomment fast function)

	// testing const function params:
	//cout << "\nTesting const function params:" << endl;
	//int a = 0; // a is var, but the ref is const	// a gets 0
	//int b = 0;									// b gets 0
	//test1(a,b);									// call function test1, pass a and b as its arguments
	//cout << "A: " << a << ", B: " << b << endl;	// output: A: 0, B: 3 (uncomment line "y = x + 3;" )

	// ref return types:
	// http://msdn.microsoft.com/en-us/library/z0c3dx2s.aspx
	// cout << "\nTesting return values:" << endl;		// output: Testing return values:
	// int v = 123, w=456;								// initialize int type variable v,w; v gets 123, w gets 456
	// int ret1 = test2(v,w);							// call funtion test2, pass v and w as its arguments; put the returning value of test2 to ret1
	//													// 				test2 returns:	x		z		10			y+1			y
	// cout << "return from test2: " << ret1 << endl;	// output: return from test2:  123	-858993460	not work	not work	456
	// w = 789;											// w gets 789
	// cout << ret1 << endl;							// output:					   123	-858993460	not work	not work	456

	// cout << "\nTesting const return value:" << endl;	// output: Testing const return value:
	// int k = 100;										// k gets 100.
	// int& ret2 = test3(k);         // error: cannot convert from 'const int' to 'int&'
	// const int& ret2 = test3(k);	 // initialize a constant reference of int type 'ret2'. pass k to function test3 as argument. put the result to 'ret2'
	// cout << ret2 << endl;							// output: 100 (when test3 returns to 'x') / 102 (when test3 returns to 'x+2')

	// mixing reference and pointers:
	// cout << "\nTesting mixing pointers/refs:" << endl;	// output: Testing mixing pointers/refs:
	// int v1 = 0;											// v1 gets 0.
	// int& v2 = v1;										// initialize a reference of int type variable, put v1 to it
	// int* p1 = &v1;										// initialize a pointer that points to a int type variable, put the address of v1 to it
	// int v3 = test4(v1,p1);								// initialize an int type v3; pass v1 and p1 to test4 as arguments, put the return value of test4 to v3
	//														// test3 returns to:	x		y		&y		*y
	// cout << v3 << endl;									// output:				0	(error)   (error)	 0
	// int v4 = test4(p1, NULL);							// error: cannot convert argument 1 from 'int *' to 'int &'
	// int v4 = test4(*p1, NULL);							// undefined behavior! when test4 returns to '*y'
	// cout << v4 << endl;									// output: 0 (only when test4 returns to 'x')

}
