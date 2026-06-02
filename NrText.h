#ifndef NRTEXT_H
#define NRTEXT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class NrText : public QWidget
{
    Q_OBJECT

public:
    explicit NrText(QWidget *parent = nullptr);

private slots:
    void onCodeIDChanged(const QString &text);

private:
    QLineEdit *lineEditCodeID;
    QLabel *labelCodeID;
};

#endif // NRTEXT_H