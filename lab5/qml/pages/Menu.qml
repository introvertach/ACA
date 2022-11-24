import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Button {
            text: "1"
            onClicked: pageStack.push(Qt.resolvedUrl("1.qml"))
        }
        Button {
            text: "2"
            onClicked: pageStack.push(Qt.resolvedUrl("2.qml"))
        }
        Button {
            text: "3"
            onClicked: pageStack.push(Qt.resolvedUrl("3.qml"))
        }
        Button {
            text: "4"
            onClicked: pageStack.push(Qt.resolvedUrl("4.qml"))
        }
        Button {
            text: "5"
            onClicked: pageStack.push(Qt.resolvedUrl("5.qml"))
        }
        Button {
            text: "6"
            onClicked: pageStack.push(Qt.resolvedUrl("6.qml"))
        }
        Button {
            text: "7"
            onClicked: pageStack.push(Qt.resolvedUrl("7.qml"))
        }
        Button {
            text: "8"
            onClicked: pageStack.push(Qt.resolvedUrl("8.qml"))
        }
        Button {
            text: "9"
            onClicked: pageStack.push(Qt.resolvedUrl("9.qml"))
        }
        Button {
            text: "10"
            onClicked: pageStack.push(Qt.resolvedUrl("10.qml"))
        }
    }
}
