import React from "react";



export default class Counter extends React.Component {

   // componentDidUpdate(prevProps, prevState){
   //     console.log("prevProps", prevProps);
   //     console.log("prevState", prevState);
   //     console.log(prevProps.counter.value !== this.props.counter.value && "yes");
   // }

  //  componentWillUnmount(){
   //     console.log("coonsole will unmount");
   // }
    // constructor(){
    //    super();
    //    this.increaser = this.increaser.bind(this);
    // }
    styles = {
        fontSize: 10,
        fontWeight: 'bold',
        paddingTop: 5,
        paddingBottom: 5,
        paddingLeft: 7,
        paddingRight: 7,
        textAlign: "center",


    }

    render() {


        return (
            <React.Fragment>
                <h4>Counter {this.props.counter.id}</h4>
                < span style={this.styles} className={this.badgeClasses()} > {this.formatCount()} </span>
                <button className="btn btn-secondary btn-sm" onClick={() => this.props.increaser(this.props.counter.id)} > Increament</button>
                <button onClick={() => this.props.onDelete(this.props.counter.id)} className="btn btn-danger btn-sm  m-2">Delete</button>
                <br></br>
            </React.Fragment>
        );
    }


    badgeClasses() {
        let classes = "badge m-2 badge-";
        classes += (this.props.counter.value === 0) ? "warning" : "primary";
        return classes;
    }

    formatCount() {
        if (this.props.counter.value === 0) {
            return "zero";
        } else {
            return this.props.counter.value;
        }

    }




}