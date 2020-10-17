import React from "react";
import Counter from "./counter.jsx";

class Counters extends React.Component {



    render() {

        return (
            <div>

                <button className="btn btn-primary btn-sm m-2" onClick={() => this.props.onReset()}>Reset</button>
                {this.props.counters.map(counter => <Counter key={counter.id} onDelete={this.props.onDelete} counter={counter} increaser={this.props.onIncreaser}>

                </Counter>)}
            </div>
        )
    }



}

export default Counters;
