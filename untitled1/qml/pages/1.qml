import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Button {
            text: "Назад"
            onClicked: {
                pageStack.pop(currentPage)
                label1.text = "Глубина стека: " + PageStack.depth
            }
        }
        Button {
            text: "Вперёд"
            onClicked: {
                pageStack.push()
                label1.text = "Глубина стека: " + PageStack.depth
            }
        }
        Label {
            id: label1
            text: "Глубина стека: " + PageStack.depth
        }
    }
}

