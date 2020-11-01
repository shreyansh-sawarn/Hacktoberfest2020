// Ask for temperature in fahenheit
let fahenheit = prompt("Enter a \xB0F to convert to \xB0C")
let celsius = convertToCelsius(fahenheit)
alert(fahenheit + "\xB0F" + " is " + celsius + "\xB0C")

// Function to convert fahenheit to celsius.
function convertToCelsius(num){
    return (num - 32) * 5 / 9;
}
