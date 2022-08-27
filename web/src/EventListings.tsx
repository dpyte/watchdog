import React, { useState } from "react";
import { ProSidebar, SidebarHeader } from "react-pro-sidebar";

import "./EventListings.css";

const EventListings = () => {
    const [menu_collapse, set_menu_collapse] = useState(false)

    const menu_icon_click = () => {
        menu_collapse ? set_menu_collapse(false) : set_menu_collapse(true);
    };
    
    return (
        <>
            <div id = "Header">
                <ProSidebar collapsed = {menu_collapse}>
                    <SidebarHeader>
                    <div className="logotext">
                        <p> { menu_collapse ? "Logo" : "Events" } </p>
                    </div>    
                    </SidebarHeader>
                </ProSidebar>
            </div>
        </>
    );
};

export default EventListings;