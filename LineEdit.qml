import Qt 4.7

Item {
    id:lineedit

    width: 200
    height: 32

    property Component background : defaultbackground
    property Component content : defaultContents
    property alias text: input.text
    property string icon

    property color backgroundColor: "#fff";
    property color foregroundColor: "#222";
    property alias hover : mousearea.containsMouse

    // background
    Loader {
        id:backgroundComponent
        anchors.fill:parent
        sourceComponent:background
    }

    // Contents
    Loader {
        id:contentsComponent
        anchors.fill:parent
        sourceComponent:content
        onLoaded: {
            item.parent = lineedit
        }
    }

    MouseArea {
        id:mousearea
        anchors.fill:parent
        hoverEnabled:true
    }

    TextInput {
        id:input
        font.pixelSize:14
        anchors.margins:4
        anchors.fill:contentsComponent.item
        selectByMouse:true
    }

    Component {
        id:defaultbackground
        Item {

            Rectangle{
                color:backgroundColor
                radius: 5
                x:1
                y:1
                width:parent.width-2
                height:parent.height-2
            }

            BorderImage {
                anchors.fill:parent
                id: backgroundimage
                smooth:true
                source: "images/lineedit_normal.png"
                width: 80 ; height: 24
                border.left: 6; border.top: 3
                border.right: 6; border.bottom: 3
            }
        }
    }

    Component {
        id:defaultContents
        Item{anchors.fill:parent; anchors.margins: 4}
    }
}