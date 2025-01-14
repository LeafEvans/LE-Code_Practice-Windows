#include "logindialog.h"

#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog) {
  ui->setupUi(this);
}

LoginDialog::~LoginDialog() { delete ui; }

void LoginDialog::on_loginBtn_clicked() {
  // 判断用户名和密码是否正确
  if (ui->usrLineEdit->text().trimmed() == tr("tom") &&
      ui->pwdLineEdit->text() == tr("123456")) {
    accept();
  } else {
    QMessageBox::warning(this, tr("警告"), tr("用户名和密码错误"),
                         QMessageBox::Yes);
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
  }
}
