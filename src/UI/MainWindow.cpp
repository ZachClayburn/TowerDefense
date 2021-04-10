#include "MainWindow.h"

#include <stdexcept>

#include "Renderer.h"

MainWindow::MainWindow() {
    renderer = std::make_unique<Renderer>();
    if (!renderer->OnUserCreate()) { throw std::runtime_error("cannot launch main window"); }
}

MainWindow::~MainWindow() = default;

int MainWindow::run() {
    renderer->Construct(256, 256, 4, 4);
    return renderer->Start(); }
