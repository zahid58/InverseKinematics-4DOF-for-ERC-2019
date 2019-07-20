from PyQt5.QtWidgets import QWidget, QApplication,QPushButton,QSlider,QGridLayout,QLabel 
from PyQt5 import QtGui
from PyQt5.QtCore import QRect,QSize,Qt
import sys
import SerialCom

class Window(QWidget):
    def __init__(self):
        super().__init__()

        self.title = "Arm Control"
        self.top = 100
        self.left = 100
        self.width = 800
        self.height = 400
        self.iconName = "roboticArm.png"
        self.closeIcon = "closeIcon.png"
        self.slider = []
        self.label1 = []
        self.label2 = []
        self.sliderTitles = ['base','shoulder','elbow','wrist','roll','grip']
        self.InitWindow()


    def InitWindow(self):
        self.setWindowIcon(QtGui.QIcon(self.iconName))
        self.setWindowTitle(self.title)
        self.setGeometry(self.left,self.top,self.width,self.height)
        self.UIcomponents()
        self.setLayout(self.grid)
        self.InitSerial()
        self.show()

    def InitSerial(self):
        self.SerialObj = SerialCom.SerialCom()
        self.arduinoOut = self.SerialObj.getConn('COM9',9600)

    def UIcomponents(self):
        
        self.createSlider()
        self.createSendButton()
        self.createCloseButton()

    
    def createSlider(self):
        self.grid = QGridLayout()
        self.grid.setSpacing(5)
        for i in range(4):
            self.label1.append( QLabel(self.sliderTitles[i]) )
            self.label1[i].setFont(QtGui.QFont("Sanserif",16))
            self.slider.append(QSlider())
            self.slider[i].setOrientation(Qt.Horizontal)
            self.slider[i].setTickPosition(QSlider.TicksBelow)
            self.slider[i].setTickInterval(10)
            self.slider[i].setMinimum(0)
            self.slider[i].setMaximum(180)
            self.slider[i].valueChanged.connect(self.changedValue)
            self.label2.append( QLabel("0") )
            self.label2[i].setFont(QtGui.QFont("Sanserif",16))
            
            
            self.grid.addWidget(self.label1[i],i, 0)
            self.grid.addWidget(self.slider[i] , i, 1)
            self.grid.addWidget(self.label2[i] , i, 2)

    def changedValue(self):
        data = []
        for i in range(4):
            size = self.slider[i].value()
            self.label2[i].setText(str(size))
            data.append(str(size))
        dataString = ','.join(data)
        self.SerialObj.sendString(dataString)
        #print(dataString)

    def createSendButton(self):
        button1 = QPushButton("Send",self)
        #button1.setGeometry(QRect(100,200,90,45))
        button1.setIcon(QtGui.QIcon(self.iconName))
        button1.setIconSize(QSize(25,25))
        button1.setToolTip("<h2>click this button to send data to the arm<\h2>")
        button1.clicked.connect(self.ClickMe)
        self.grid.addWidget(button1,4,1)

    def createCloseButton(self):
        button2 = QPushButton("Exit",self)
        #button2.setGeometry(QRect(200,200,90,45))
        button2.setIcon(QtGui.QIcon(self.closeIcon))
        button2.setIconSize(QSize(25,25))
        button2.clicked.connect(self.close)
        self.grid.addWidget(button2,4,2)

    def ClickMe(self):
        data = []
        for i in range(4):
            size = self.slider[i].value()
            data.append(str(size))
        dataString = ','.join(data)
        self.SerialObj.sendString(dataString)
        #print(dataString)
    #this is a slot
    def close(self):
        sys.exit()

App = QApplication(sys.argv)
window = Window()
sys.exit(App.exec())
