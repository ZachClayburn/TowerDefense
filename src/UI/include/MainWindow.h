
#ifndef MYPROJECT_MAINWINDOW_H
#define MYPROJECT_MAINWINDOW_H

#include <memory>

class Renderer;

class MainWindow
{
    std::unique_ptr<Renderer> renderer;

  public:
    MainWindow();
    ~MainWindow();

    int run();
};


#endif// MYPROJECT_MAINWINDOW_H
