#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <QWidget>


class GameWindow : public QWidget
{
 Q_OBJECT
 public:
  explicit GameWindow(QWidget *parent = 0);
public:
    int getHeight();
    int getWidth();
    void setHeight(int height);
    void setWidht(int width);

private:
    int m_height;
    int m_width;

 signals:
 public slots:



};

#endif // GAMEWINDOW_H
