import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    allowedOrientations: Orientation.All
    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingMedium
        SilicaWebView {
            id: webView
            anchors {
                top: parent.top; bottom: urlField.top;
                left: parent.left; right: parent.right;
            }
            url: "https://paimon.moe/characters/keqing"
        }
        TextField {
            id: urlField
            anchors {
                left: parent.left; right: parent.right;
                bottom: parent.bottom
            }
            text: "https://paimon.moe/characters/keqing"
            label: webView.title
            EnterKey.onClicked: webView.url = text

        }
    }
}
