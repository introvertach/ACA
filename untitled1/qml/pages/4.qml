import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Label {
            id: label1
            text: "Выбранная дата"
        }

        Button {
            text: "Выбрать дату"
            onClicked: pageStack.push(dialog1)
        }

        DatePickerDialog {
            id: dialog1
            date: new Date()
            onDateChanged: label1.text = date
        }

        /*Dialog {
            id: dialog1
            DatePicker {
                id: calendar
                date: new Date()
                onDateChanged: label1.text = date
            }
        }*/
    }
}
