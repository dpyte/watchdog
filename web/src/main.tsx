import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";
import NavigationBar from "./Navigation";
import "./style.css";

ReactDOM.createRoot(document.getElementById("root") as HTMLElement).render(
  <React.StrictMode>
    <body>
      <App />
    </body>
    <body>
      <NavigationBar />
    </body>
  </React.StrictMode>
);
