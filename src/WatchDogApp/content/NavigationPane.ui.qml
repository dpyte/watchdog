import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import WatchDogApp 1.0

Item {
    width: Constants.width
    height: 50

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1920
        height: 50
        color: "#ffffff"

        HomeButton {
            id: homeButton
            x: 16
            y: 0
        }
    }
}
