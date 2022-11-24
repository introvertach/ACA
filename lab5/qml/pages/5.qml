import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Label {
            id: label2
            text: "Выбранное время"
        }

        Button {
            text: "Выбрать время"
            onClicked: pageStack.push(dialog2)
        }
        /*Dialog {
            id: dialog2
            TimePicker {
                id: timepicker
                hour:  ;
                minute: ;
                onTimeChanged: label2.text = time
            }
        }*/
        TimePickerDialog {
            id: dialog2
            hour:  ;
            minute: ;
            onTimeChanged: label2.text = time
        }
    }
}
