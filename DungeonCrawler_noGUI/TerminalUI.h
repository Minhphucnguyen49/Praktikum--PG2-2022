#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractUI.h"
#include "Controller.h"
#include "Level.h"
class TerminalUI : virtual public AbstractUI, virtual public Controller
{
public:
    TerminalUI();
    void draw(Level* level) override;
    int move() override;
};

#endif // TERMINALUI_H
