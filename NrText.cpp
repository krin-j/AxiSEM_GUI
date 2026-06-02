#include "NrText.h"
#include <QVBoxLayout>

NrText::NrText(QWidget *parent)
    : QWidget(parent)
{
    lineEditCodeID = new QLineEdit(this);
    labelCodeID = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEditCodeID);
    layout->addWidget(labelCodeID);

    setLayout(layout);

    connect(lineEditCodeID, &QLineEdit::textChanged,
            this, &NrText::onCodeIDChanged);
}

void NrText::onCodeIDChanged(const QString &text)
{
    QString result = text;

    result.replace(" ", "_");
    result.replace("-", "_");
    result.remove("(");
    result.remove(")");

    if (!result.isEmpty() && !result.endsWith(":"))
    {
        result.append(":");
    }

    labelCodeID->setText(result);
}