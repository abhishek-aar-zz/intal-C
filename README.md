# intal-C
A library for arbitrary length integer<br>
Written in: C<br>
## Intro

A non-negative integer of arbitrary length is called as intal. Intal is actucally a short word for integter of arbitrary length. Several modern programming languages have built-in support for intals. But in the world of C, intal cannot be represented using built-in datatypes. Long integers are supported by C with the built-in data type i.e. long long int, the range of it is limited which is from –(2^(63) –1) to 2^63 –1. So its necessary to build a library on intal for its arithmetic operations which works on C. A common application is in the field of cryptography  where algorithms commonly employ arithmetic with integers having hundreds of digits. Intal arithmetric is also used to compute fundamental mathematical constants such as pi to millions or more digits and to analyze the properties of the digit strings. These can also be used to avoid overflow, which is an inherent limitation of fixed-precision arithmetic.

## What can be performed?
##### Binary Operations
* Addition of two intals -> sum, say a+b
* Subtraction of two intals -> absolute difference, say absolute(a-b)
* Compare two intals -> if both are equal => 0, if first intal is greater => 1 and if second intal is greater => -1
* Multiplication of two intals -> product, say a\*b
* Modulus using two intals -> say a%b
* GCD of two intals -> say gcd(a,b)
* Exponentiation using two intals -> say a^b
##### Mathematical Operations - Xtra
* Finding nth fibonacci number.
* Finding a factorial of an unsigned integer.
* Finding the binary coefficient of (n,k).
##### Operations on array of intals
* Finding max intal in the array of intal.
* Finding min intal in the array of intal.
* Searching for an intal in an array of intal.
* Searching for an intal in an sorted array of intal\[Binary Search\].
* Sorting an intal array.
##### Misc
* Solving _COIN ROW PROBLEM_ of intals.
## Approach
#### Binary Operations
__Addition:__ It is implemented as a binary operation, in which each and every digits with corresponding position of both intals are added using the built-in add operation of C. While single digit addition, a character integer is converted into a real integer. Each addition might generate carry, which is handled in the implementation. If either one of the intal is "0", then the other one is returned.

__Difference:__ Absolute of the difference between both intals are calculated. A copy actual array of characters is reversed for the sake of ease in subtraction. Each digits are subtracted, and then borrow is handled. This funcition follows the basic subtraction algorithm which is done by hand. If both are equal, return "0".

__Compare:__ Comparing each correspoding digit from left to right, when a greater digit is found that intal is marked as greater. When one of the intal array has lesser string length, the other intal is marked as greater.

__Multiplication:__ The length of result array will be the sum of length of intal1 and intal2. Initially carry variable is assigned to 0 and result is an array of intgers, each of them is assigned to 0. Then, for each character in intal1, multiply all the characters in intal2 and add it to the value present in result and add carry and assign it to the corresponding value in result. Then store the result into a character array and remove the leading zero's and return character array.

__Modulus:__ A variable ans is used to the answer and initialize it to 0. Each character from intal1 from left to right is taken. Every time multiply the answer by 10 and add the next character and take the mod of this number with intal2 and assign it to answer. Recursive approach is used.

__GCD:__ A recursive function is implemented which follows Euclids algorithm. Recursively gcd(intal2,intal1%intal2) is called. "0" is returned when both the intals are "0" even though it is mathematically undefined.

__Power:__ A divide and conquer approach is used. Check if intal1 == 0 return 0 or if n == 0 return 1. Keep on dividing y by 2 until y > 0. Initialize result = 1 and store intal1 to a temp variable. If y is odd, multiply res and temp and if y is even, multiply temp and temp. Repeatedly do this operation until y > 0. Do this in a while loop by checking the conditions mentioned above and keep on dividing y by 2.
#### Mathematical Operations - Xtra
__Fibonacci:__ Two variables a to store 0 and b to store 1 are used. Repeatedly add a and b and assign a to b and b to result of a + b. Then repeatedly do this operation untill i value is less than or equal to n where i starts from 2. Then return b.

__Factorial:__ Two variables temp to store 1 and result in initialized to 1. Keep on incrementing untill temp is equal to n and multiply temp and result. Thenreturn result.

__Binary Coefficient:__ If n-k>k, then k is repaced by n-k. Initialize 2-D character array of size k. This done in order to prevent overlapping of calculation. We store all the corresponding values in the array inorder to prevent overlapping problem.
#### Operations on array of intals
__Min:__ Initially use a variable min to store the position of the smallest element. Start comparing the element at position min and compare the elements in the remaining elements. If any element is smaller than the element at position min, change the position of min every time this condition is satisfied.

__Max:__ Initially use a variable max to store the position of the largest element. Start comparing the element at the position max and compare the element at different position. If any element is greater than the element at position max, then change the value of max variable every time this condition is satisfied.

__Search:__ Go through the entire array and compare element at each position with key. If they are the same, return the position of the element else return -1 if element not found.

__Binary Search:__ Begin with the sorted array. Two variables low = start position i.e, 0 and high = end of the list are used. Find mid = (low + high) / 2 and compare if arr\[mid\] == key, return the position mid. If arr\[mid\] > key, change high = mid - 1 else if arr\[mid\] < key, change low = mid + 1. Repeatedly do this operationuntil low < high.

__Sort:__ Heap sort algorithm is used inorder to perform inplace sorting. Initially create a max heap for the existing array, then swap the first and last element to put the element in the array and then create a max heap of the remaining elements and repeat the procedure until only element is left. Worst case time complexity will be O(n.logn) and the worst case space complexity will be O(1).
#### Misc
__Coin Row Problem:__ Sliding window is used to find the solution. Three variables prev which stores 0 and cur to store first element in the array are used. For next to store which is max either prev + arr\[i\] or cur. Repeatedly do this procedure until all the elements in the given array are exhausted. We use sliding window inorder to perform the space O(1).

#### Thankyou!
