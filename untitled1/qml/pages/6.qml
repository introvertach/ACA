import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        ListModel {
                id:model
                ListElement { name: "Беги на пары"; date: "26.11.2022"; }
                ListElement { name: "Подключайся к парам"; date: "27.11.2022"; }
                ListElement { name: "АДЫХАЙ, МОЙ ХАРОШИЙ"; date: "27.11.2022"; }
            }
        SilicaListView {
            anchors.fill: parent
            model: model
            header: PageHeader { title: "Задачи" }
            section {
                property: 'date'
                delegate: SectionHeader { text: section }
            }
            delegate: Text { text: name }
        }
    }
}
