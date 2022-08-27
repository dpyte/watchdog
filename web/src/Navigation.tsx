import './Navigation.css';
import * as React from 'react';
import BottomNavigation from '@mui/material/BottomNavigation';
import BottomNavigationAction from '@mui/material/BottomNavigationAction';

function NavigationBar() {
    const [value, set_value] = React.useState('recents');
    const handle_changes = (
        event: React.SyntheticEvent,
        n_value: string
    ) => {
        set_value(n_value);
    };

    return (
        <div className="NavigationPane">
            <p> Test </p>
            <BottomNavigation sx={{width: 100}} value={value} onChange={handle_changes}>
                <BottomNavigationAction
                    label = "Action"
                    value = "action"
                />
                <BottomNavigationAction
                    label = "Home"
                    value = "action"
                />
            </BottomNavigation>
        </div>
    );
}

export default NavigationBar;