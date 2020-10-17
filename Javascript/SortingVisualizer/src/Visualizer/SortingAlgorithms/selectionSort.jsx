import React from "react";

export function selectionSortAlgorithm(array) {

   let track = [];
    for (var i = 0; i < array.length - 1; i++) {
        var pos = i;
        for (var j = i; j < array.length; j++) {
            if (array[j] < array[pos]) {
                pos = j
            }
        }
        var temp = array[pos];
        array[pos] = array[i];
        array[i] = temp;
        track.push([i, pos]);
    }
    console.log(array);
    return track;
}