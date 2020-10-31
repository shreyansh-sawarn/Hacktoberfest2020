// program to sort words in alphabetical order

// take input
let string = prompt('Enter a sentence: ');

// converting to an array
let words = string.split(' ');

// sort the array elements
words.sort();

// display the sorted words
console.log('The sorted words are:');

for (const element of words) {
  console.log(element);
}
