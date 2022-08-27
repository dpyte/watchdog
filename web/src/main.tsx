import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";
import NavigationBar from "./Navigation";
import EventListings from "./EventListings";
import "./style.css";

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
      <EventListings />
      <NavigationBar />
    </body>
  </React.StrictMode>
);
