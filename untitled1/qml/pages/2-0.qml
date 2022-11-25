import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Button {
            text: "Добавить страницу"
            onClicked: {
                pageStack.pushAttached(Qt.resolvedUrl("2-1.qml"))
            }
        }
        Button {
            text: "Убрать страницу"
            onClicked: {
                pageStack.pop(Qt.resolvedUrl("2-1.qml"))
            }
        }
    }
}
