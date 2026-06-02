#ifndef UDPFIELDSWIDGET_H
#define UDPFIELDSWIDGET_H

#include <QWidget>
#include <QVector>
#include <QLineEdit>

namespace Ui {
class UDPFieldsWidget;
}

class UDPFieldsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UDPFieldsWidget(QWidget *parent = nullptr);
    ~UDPFieldsWidget();

    QStringList rvalues() const;   // renamed getter

private slots:
    void onSpinChanged(int count);

private:
    void addField();
    void removeField();

    Ui::UDPFieldsWidget *ui;

    QStringList values;            // internal model (RENAMED CLARITY FIX)
    QVector<QLineEdit*> edits;
};

#endif