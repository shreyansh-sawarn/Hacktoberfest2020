import React from "react";
import "./Sorting.css";
import "../../node_modules/bootstrap/dist/css/bootstrap.css";
import { bubbleSortAlgorithm } from "./SortingAlgorithms/bubbleSort.jsx";
import { insertionSortAlgorithm } from "./SortingAlgorithms/inertionSort.jsx";
import {selectionSortAlgorithm} from "./SortingAlgorithms/selectionSort.jsx";


export default class Visualizer extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            array: [],

        };
    }

    componentDidMount() {
        this.resetArray();

    }

 

    render() {
        const { array } = this.state;

        return (

            <div>
                <button className="btn btn-small btn-primary m-2" id="reset" onClick={() => this.resetArray()}>ResetArray</button>
                <button className="btn btn-small btn-primary m-2" id="sort" onClick={() => this.bubbleSort()}>BubbleSort</button>
                <button className="btn btn-small btn-primary m-2" id="insertion-sort" onClick={() => this.insertionSort()}>InsertionSort</button>
                <button className="btn btn-small btn-primary m-2" id="selection-sort" onClick={() => this.selectionSort()}>SelectionSort</button>
                <div className="array">

                    {array.map((value, idx) => (
                        <div style={{ height: value, color: "green" }} className="arrayBar" key={idx} id={idx}>
                        </div>
                    ))}
                </div>
            </div>



        );
    }

    resetArray = () => {
        const array = [];
        for (let i = 0; i < 100; i++) {
            array.push(this.randomNumber(5, 500));
        }

        this.setState({ array });
       // const element = document.getElementsByClassName("arrayBar");
       // element.style.color = "green";
    }

    randomNumber(min, max) {

        const random = Math.floor(min + Math.random() * (max - min));

        return random;
    }

    //Bubble Sort
    bubbleSort = () => {

        const track = bubbleSortAlgorithm(this.state.array);
       
        const original = document.getElementsByClassName("arrayBar");
        for (var i = 0; i < track.length; i++) {

          
                const [firstIndex, secondIndex] = track[i];
                const firstIndexStyle = original[firstIndex].style;
                const secondIndexStyle = original[secondIndex].style;



                setTimeout(() => {
                    var temp = firstIndexStyle.height;
                    firstIndexStyle.height = secondIndexStyle.height;
                    secondIndexStyle.height = temp;
                    firstIndexStyle.color = "red";
                    secondIndexStyle.color = "blue";

                }, i);
            
        }
    }

    //insertionSort

    insertionSort(){
        let track = insertionSortAlgorithm(this.state.array);
    
        const original = document.getElementsByClassName("arrayBar");
        
        for(let i = 0;i<track.length;i++){
     
            const [firstIndex, secondIndex] = track[i];

            const firstStyle = original[firstIndex].style;
            const secondStyle = original[secondIndex].style;

            setTimeout(()=>{
                let temp = firstStyle.height;
                firstStyle.height = secondStyle.height;
                secondStyle.height = temp;
                firstStyle.color = "red";
                secondStyle.color = "blue";
            }, i);

   

        }
    }
    //SelectionSort
    selectionSort(){
        let track = selectionSortAlgorithm(this.state.array);
    
        const original = document.getElementsByClassName("arrayBar");
        
        for(let i = 0;i<track.length;i++){
     
            const [firstIndex, secondIndex] = track[i];

            const firstStyle = original[firstIndex].style;
            const secondStyle = original[secondIndex].style;

            setTimeout(()=>{
                let temp = firstStyle.height;
                firstStyle.height = secondStyle.height;
                secondStyle.height = temp;
                firstStyle.color = "red";
                secondStyle.color = "blue";
            }, i*30);

   

        }
    }


}
