// program to get the file extension

function getFileExtension(filename){

    // get file extension
    const extension = filename.split('.').pop();
    return extension;
}

// passing the filename
let result1 = getFileExtension('module.js');
console.log(result1);

let result2 = getFileExtension('module.txt');
console.log(result2);
