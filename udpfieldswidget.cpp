#include "udpfieldswidget.h"
#include "ui_udpfieldswidget.h"

UDPFieldsWidget::UDPFieldsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UDPFieldsWidget)
{
    ui->setupUi(this);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->spinBoxNrUDP->setMinimum(4);
    ui->spinBoxNrUDP->setValue(4);

    values = {
            "example__bool: true",
            "example__string: Hello world!",
            "example__array_of_double: [1., 2., 3.]",
            "example__array_of_string: [path, file1, file2]"
    };

    for (int i = 0; i < 4; i++)
        addField();

    connect(ui->spinBoxNrUDP,
            QOverload<int>::of(&QSpinBox::valueChanged),
            this,
            &UDPFieldsWidget::onSpinChanged);

    ui->verticalLayoutFields->setSizeConstraint(QLayout::SetMinimumSize);
}

UDPFieldsWidget::~UDPFieldsWidget()
{
    delete ui;
}

void UDPFieldsWidget::addField()
{
    int index = edits.size();

    QLineEdit *e = new QLineEdit(this);

    // LOCK SIZE
    e->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    e->setMinimumHeight(25);
    e->setMaximumHeight(25);

    // set initial value
    e->setText(values[index]);

    edits.push_back(e);
    ui->verticalLayoutFields->addWidget(e);

    connect(e, &QLineEdit::textChanged,
            this, [this, index](const QString &text)
            {
                values[index] = text;
            });
}

void UDPFieldsWidget::removeField()
{
    if (edits.isEmpty())
        return;

    QLineEdit *e = edits.takeLast();
    delete e;

    values.removeLast();
}

void UDPFieldsWidget::onSpinChanged(int count)
{
    if (count < 4)
        count = 4;

    while (edits.size() < count)
    {
        values.append("");
        addField();
    }

    while (edits.size() > count)
    {
        removeField();
    }
}

QStringList UDPFieldsWidget::rvalues() const
{
    return values;
}