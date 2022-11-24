import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Rectangle {
            height: 100
            width: parent.width
            Label {
                id: label2
                text: ""
            }
        }

        Button {
            text: "Диалог"
            onClicked: {
                var dialog = pageStack.push(Qt.resolvedUrl("3-1.qml"));
                label2.text = dialog.firstTextField.text
            }
        }
    }
}
