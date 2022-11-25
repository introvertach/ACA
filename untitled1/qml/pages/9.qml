import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        Label {
            id: label3
            text: "Выбранный пункт"
        }
        SilicaListView {
            PullDownMenu {
                MenuItem {
                    text: "A"
                    onClicked: label3.text = text
                }
                MenuItem {
                    text: "B"
                    onClicked: label3.text = text
                }
                MenuLabel { text: qsTr("Menu") }
            }
            /*anchors.fill: parent
            header: PageHeader { title: "Simple List" }
            model: 20
            delegate: ListItem {
                Label {
                    x: Theme.paddingLarge
                    text: "List Item #" + index
                    color: Theme.primaryColor
                }
            }*/
        }

    }
}
