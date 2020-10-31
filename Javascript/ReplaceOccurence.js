// program to replace all occurrence of a string

let string = 'Mr Red has a red house and a red car';

// regex expression
let regex = /red/gi;

// replace the characters
let newText = string.replace(regex, 'blue');

// display the result
console.log(newText);
