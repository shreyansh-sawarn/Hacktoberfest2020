import React from "react";


export function insertionSortAlgorithm(array) {

    let track = [];

    for (let i = 1; i < array.length; i++) {
        let temp = array[i];
        
        let j = i-1;

        while(j>=0 && array[j]>temp){
            array[j+1] = array[j];
            track.push([j, j+1]);
        
            j--;
        }

        array[j+1] = temp;
    }


    return track;
   
}