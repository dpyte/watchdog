import React from "react";
import { useState } from "react";
import { invoke } from "@tauri-apps/api/tauri";
import "./App.css";

class ActivityCenter extends React.Component {
  render() {
    return (
    <div className="ActivityListener">
      
    </div>
    );
  }
}

function App() {
/* CMT1 
      <div className="row">
        <a href="https://vitejs.dev" target="_blank">
          <img src="/vite.svg" className="logo vite" alt="Vite logo" />
        </a>
        <a href="https://tauri.app" target="_blank">
          <img src="/tauri.svg" className="logo tauri" alt="Tauri logo" />
        </a>
        <a href="https://reactjs.org" target="_blank">
          <img src={reactLogo} className="logo react" alt="React logo" />
        </a>
      </div>
*/

  return (
    <div className="ActivityCenter">
      <ActivityCenter />
    </div>
  );
}

export default App;
