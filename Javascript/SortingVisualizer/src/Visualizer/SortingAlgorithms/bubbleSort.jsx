import React from "react";




export function bubbleSortAlgorithm(array)  {
    let temp;

    const track = [];
 
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = 0; j < array.length - 1; j++) {
           
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                track.push([j, j + 1]);
          
            }
       

        }

    }

    return track;

}


    
