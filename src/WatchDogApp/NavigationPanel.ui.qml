

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15
import QtQuick.Controls 2.15
import WatchDogApp 1.0

Item {
    width: Constants.width
    height: 120
    layer.enabled: false
    activeFocusOnTab: true
    focus: true
    antialiasing: true

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1920
        height: 120
        color: "#fbfcff"

        Button {
            id: button
            x: 8
            width: 114
            height: 76
            anchors.verticalCenter: parent.verticalCenter
            anchors.bottom: parent.bottom
            layer.effect: home_white
            checked: false
            font.styleName: "Regular"
            highlighted: true
            anchors.bottomMargin: 22
            antialiasing: true
            checkable: true
            display: AbstractButton.TextBesideIcon
            flat: true
        }

        Image {
            id: home_white
            x: 24
            y: 29
            width: 81
            height: 61
            source: "content/images/home_white.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}
