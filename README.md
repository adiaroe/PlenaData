# PlenaData
## Problem
Create an application that will prompt for a user to input a string. Using the user’s inputted string, find the first letter that is not repeated. 
 
For example: If given the string ‘Bubble’, the letter ‘u’ would be the first character returned from the program.

Once the first character is found and displayed back to the user, rewrite the string in order of number of occurrences and order from the inputted string.

In the above example ‘Bubble’ would then be rewritten as ‘uleBbb’. Display this to the user.

## Solution
The first part of the problem can be solved easily by maintaining an array of size 26 (for 26 characters) and storing their count. Alternatively, a map can also be used with key being the character and value bring the count.

The second part of the problem is a bit trickier given the constraints - maintaining the order from the input string and also maintaining case sensitivity. The code is heavily commented to understand the approach better.

## Test Cases
1. No unique characters present - exception thrown. Eg: "aabbcc" -> "No unique characters!!!" && "aabbcc"
2. "Bubble" -> 'u' && "uleBbb"

## Improvements
Current code assumes that there are no other characters apart from [a-z][A-Z]. Cases with other characters must be handled.
