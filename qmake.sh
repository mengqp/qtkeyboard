# !/bin/sh
make distclean
echo "./qmake.sh [type] type = cd/dd/cr(cross debug/desk debug/cross releas), other default is cr"


if [ $# -ne 1 ];
then
	echo "param is default"
	exit
# else
	# echo $1
fi

if [ "$1"x = "cd"x ];
then
	echo "cross debug project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=Debug"
elif [ "$1"x = "dd"x ];
then
	echo "desk debug project"
	# QMAKE=/home/mengqp/mengqp/pro/qt/qtsdk-2010.05/qt/bin/qmake
	QMAKE=/usr/bin/qmake-qt4
	CONFIG="CONFIG+=Debug"
elif [ "$1"x = "cr"x ];
then
	echo "cross release project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=release"
else
	echo "cross release project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=release"
fi

$QMAKE -project -Wall  -o  ./qtkeyboard.pro -after "TARGET=./release/" $CONFIG  "OBJECTS_DIR = ./build/obj/" "MOC_DIR = build/moc/" "UI_DIR=build/ui" "QT += gui core sql xml"
$QMAKE -makefile ./qtkeyboard.pro   -o ./Makefile

make
