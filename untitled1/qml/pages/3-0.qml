import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium

            Label {
                id: label4
                text: " "
            }


        Button {
            text: "Диалог"
            onClicked: {
                pageStack.push(dialog3);

            }
        }
        Dialog {
            id: dialog3
           //property alias firstTextFieldValue: firstTextField.text
            Column {
               width: parent.width
               //spacing: Theme.paddingMedium
               DialogHeader { }
               TextField {
                   id: firstTextField
                   width: parent.width
               }
            }
           onAccepted: label4.text = dialog3.firstTextField.text
        }
    }
}
