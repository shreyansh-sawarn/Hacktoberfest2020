import React from "react";
import Navbar from "./Components/navbar.jsx";
import Counters from "./Components/counters.jsx";

class App extends React.Component {
    state = {
        counters: [
            {
                id: 1,
                value: 0
            },
            {
                id: 2,
                value: 0
            },
            {
                id: 3,
                value: 0
            },
            {
                id: 4,
                value: 0
            }
        ],

    };


    handleDelete = (counterId) => {
        const counters = this.state.counters.filter(c => c.id !== counterId);

        this.setState({ counters: counters });


    };

    increaser = (counterId) => {
        const counter = this.state.counters.map(c => {
            if (c.id === counterId) {
                c.value = c.value + 1;
            }
            return c;
        });

        this.setState({ counter });
    }
    reset = () => {
        const counters = this.state.counters.map(c => {
            c.value = 0;
            return c;
        });

        this.setState({ counters })
    };

    render() {

        return (
            
            <React.Fragment>
                <Navbar counters={this.state.counters.filter(c => c.value > 0).length} />
                <main className="container">
                    <Counters counters={this.state.counters} onReset={this.reset} onIncreaser={this.increaser} onDelete={this.handleDelete} />
                </main>
            </React.Fragment>

        );
    }
}

export default App;