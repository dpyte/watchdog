import "./style.css";
import App from "./App";
import React from "react";
import ReactDOM from "react-dom/client";
import NavigationPanel from "./Navigation/NavigationPanel";

ReactDOM.createRoot(document.getElementById("root") as HTMLElement).render(
  /**
   * The object will we running Three seperate entities.
   * 1. Activity Center
   * 2. Event List
   * 3. Navigation Pane
   * 
   * Out of listed above, the following will remain static - navigation pane and the activity center
   */
  <React.StrictMode>
    <body>
      <App />
      <NavigationPanel />
    </body>
  </React.StrictMode>
);
