#include <QApplication>
#include"apprun.h"
int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    AppRun NewTime;
    emit NewTime.Start();
    return app.exec();
}
