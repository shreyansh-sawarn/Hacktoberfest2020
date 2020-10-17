import React from "react";

class Navbar extends React.Component {



    render() {
        return (
            <nav className="navbar navbar-default navbar-dark bg-primary">
                <a className="navbar-brand" href="index.js">
                    To-do List
                </a>
                <span className=" badge badge-pill badge-secondary">
                    {this.props.counters}
                </span>

            </nav>
        );
    }
}

export default Navbar;