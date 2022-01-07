import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import "fonction.js" as FonctionsCalcul

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Calculatrice")

    GridLayout {
        id: gridLayout
        x: 30
        y: 15
        width: 590
        height: 440
        visible: true
        opacity: 1

        TextArea {
            id: textAreaAffichage
            Layout.row: 1
            Layout.column: 0
            Layout.columnSpan: 5
            Layout.rowSpan: 1
            width: 514
            height: 51
            placeholderText: qsTr("Text Area")
        }

        Button {
            id: button
            Layout.row: 5
            Layout.column: 1
            text: qsTr("0")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonReset
            Layout.row: 5
            Layout.column: 0
            text: qsTr("C")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonEgale
            Layout.row: 5
            Layout.column: 2
            text: qsTr("=")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonDiv
            Layout.row: 5
            Layout.column: 3
            text: qsTr("/")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button1
            Layout.row: 4
            Layout.column: 0
            text: qsTr("1")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button2
            Layout.row: 4
            Layout.column: 1
            text: qsTr("2")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button3
            Layout.row: 4
            Layout.column: 2
            text: qsTr("3")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonMulti
            Layout.row: 4
            Layout.column: 3
            text: qsTr("*")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button4
            Layout.row: 3
            Layout.column: 0
            text: qsTr("4")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button5
            Layout.row: 3
            Layout.column: 1
            text: qsTr("5")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button6
            Layout.row: 3
            Layout.column: 2
            text: qsTr("6")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonSous
            Layout.row: 3
            Layout.column: 3
            text: qsTr("-")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button7
            Layout.row: 2
            Layout.column: 0
            text: qsTr("7")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button8
            Layout.row: 2
            Layout.column: 1
            text: qsTr("8")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: button9
            Layout.row: 2
            Layout.column: 2
            text: qsTr("9")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

        Button {
            id: buttonAdd
            Layout.row: 2
            Layout.column: 3
            text: qsTr("+")
            onClicked: {
                FonctionsCalcul.operation(this.text);
            }
        }

    }

}
