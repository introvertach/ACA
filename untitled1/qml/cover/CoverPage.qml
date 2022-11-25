import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    property int counter: 0
    Label {
        id: label
        anchors.centerIn: parent
        text: counter
    }

    CoverActionList {
        id: coverAction

        CoverAction {
            iconSource: "image://theme/icon-cover-new"
            onTriggered: counter++
        }

        CoverAction {
            iconSource: "image://theme/icon-cover-delete"
            onTriggered: counter = 0
        }
    }
}
