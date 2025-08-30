#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QMainWindow>

#include "main_menu.hpp"
#include "quiz.hpp"

QT_BEGIN_NAMESPACE
namespace Ui{
    class StratadexMainWindow;
}
QT_END_NAMESPACE

namespace stratadex{
    class StratadexMainWindow : public QMainWindow{
        Q_OBJECT
        public:
            StratadexMainWindow(QWidget *parent);
            ~StratadexMainWindow();
        private:
            Ui::StratadexMainWindow *ui;

            QWidget *current_widget = nullptr;

            Quiz *quiz_widget;
            MainMenu *main_menu_widget;

            void UpdateCurrentWidget(QWidget *widget);
    };
}
#endif