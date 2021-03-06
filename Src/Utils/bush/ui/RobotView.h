#pragma once

#include <QGroupBox>
#include <map>
#include "Utils/bush/Session.h"
#include "Utils/bush/models/Power.h"

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

struct Robot;
class TeamSelector;
class QMouseEvent;
class QDropEvent;
class QDragEnterEvent;
class QLabel;
class QProgressBar;
class QWidget;

class RobotView : public QGroupBox
{
  Q_OBJECT

  TeamSelector* teamSelector;
  Robot* robot;
  unsigned short playerNumber;
  unsigned short pos;
  QLabel* cPlayerNumber;
  QWidget* statusWidget;
  QLabel* pingBarWLAN;
  QLabel* pingBarLAN;
  QLabel* currentBar;
  QProgressBar* powerBar;
  void init();
public:
  void update();
  RobotView(TeamSelector* teamSelector,
            Robot* robot,
            unsigned short playerNumber,
            unsigned short position);
  RobotView(TeamSelector* teamSelector,
            Robot* robot);
  void setRobot(Robot* robot);
  unsigned short getPlayerNumber() const { return playerNumber; }
  QString getRobotName() const;
  bool isSelected() const;
protected:
  void mouseMoveEvent(QMouseEvent* me);
  void dragEnterEvent(QDragEnterEvent* e);
  void dropEvent(QDropEvent* e);
public slots:
  void setSelected(bool selected);
  void ShowContextMenu(const QPoint & pos);
  void openTerm(bool wlan);
private slots:
  void setPings(ENetwork network, std::map<std::string, double>* pings);
  void setPower(std::map<std::string, Power>* power);
  void Cable() { openTerm(false); }
  void WIFI() { openTerm(true);  }
signals:
  void robotChanged();
};
