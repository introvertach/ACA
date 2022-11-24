import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Button {
            text: "Назад"
            onClicked: {
                pageStack.push(Qt.resolvedUrl("2-0.qml"))
            }
        }
    }
}
