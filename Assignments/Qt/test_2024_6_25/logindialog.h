#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog {
  Q_OBJECT
 public:
  explicit LoginDialog(QWidget *parent = 0);
  ~LoginDialog();

 private slots:
  void login();

 private:
  QLabel *usrLabel;
  QLabel *pwdLabel;

  QLineEdit *usrEditLine;
  QLineEdit *pwdEditLine;

  QPushButton *loginBtn;
  QPushButton *exitBtn;
};

#endif  // LOGINDIALOG_H
