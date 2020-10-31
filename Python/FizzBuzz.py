"""
Write a program that prints the numbers from 1 to 100. 
But for multiples of three print "Fizz" instead of the number 
and for the multiples of five print "Buzz". 
For numbers which are multiples of both three and five print "FizzBuzz".
"""
output3 = ["Fizz", "", ""]
output5 = ["Buzz", "", "", "", ""]

for x in range(1, 101):
    print "%s%s" % (output3[x % 3], output5[x % 5]) or x
print my_date.strftime('%d %A %a')
