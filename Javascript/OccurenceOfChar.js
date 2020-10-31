// program to check the occurrence of a character

function countString(str, letter) {

    // creating regex 
    let re = new RegExp(letter, 'g');

    // matching the pattern
    let count = str.match(re).length;

    return count;
}

// take input from the user
let string = prompt('Enter a string: ');
let letterToCheck = prompt('Enter a letter to check: ');

//passing parameters and calling the function
let result = countString(string, letterToCheck);

// displaying the result
console.log(result);
