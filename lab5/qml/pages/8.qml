import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        ListModel {
                id: model1
                ListElement { name: "Беги на пары"; date: "26.11.2022"; }
                ListElement { name: "Подключайся к парам"; date: "27.11.2022"; }
                ListElement { name: "АДЫХАЙ, МОЙ ХАРОШИЙ"; date: "27.11.2022"; }
        }
        SlideshowView {
                id: view
                anchors.centerIn: parent
                height: width
                itemHeight: width; itemWidth: width;
                model: model1
                delegate: Rectangle {
                    width: view.itemWidth;
                    height: view.itemHeight;
                    Column {
                        anchors.fill: parent
                        anchors.centerIn: parent
                        Text { text: name }
                        Text { text: date }
                    }
                }
        }
    }
}
