import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        //anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        SilicaListView {
            anchors.fill: parent
            model: 5
            delegate: ListItem {
                id: delegate
                Label {
                    x: Theme.paddingLarge
                    text: "List Item #" + index
                    color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
                }
                ContextMenu {
                    MenuLabel { text: "Context Menu" }
                    MenuItem {
                        text: "Menu Item 1"
                        onClicked: console.log("Menu Item 1 is clicked")
                    }
                    MenuItem {
                        text: "Menu Item 2"
                        onClicked: console.log("Menu Item 2 is clicked")
                    }
                }
        }
      }

    }
}
