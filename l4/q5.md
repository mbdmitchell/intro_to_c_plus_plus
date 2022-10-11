# QUESTION: What screen output does the [following](https://www.doc.ic.ac.uk/~wjk/C++Intro/RobMillerEx4-5.cpp) program produce, and why?

NB: "Integers" file: "123 456"  

## SCREEN OUTPUT
character: '1'  
integer: 23  
character: '4'  
integer: 56  

## THE 'WHY'
`in_stream >> character >> integer;` the first char in the stream is assigned to 'character' and all following chars in the stream until the next space are assigned to 'integer'  

This results in:   
`character: '1'  
integer: 23`  

When this line repeats it reads from '4'.   
This results in,    
`character: '4'  
integer: 56`  
