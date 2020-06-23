#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>

class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = nullptr);

public slots:
    void newGame();

};

#endif // MENUWINDOW_H
