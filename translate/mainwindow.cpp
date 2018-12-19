#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_key = QString("6F9592B6B09273FABE48F61778D621AB");
    ui->setupUi(this);

    ui->ButtonTranslate->setShortcut(QKeySequence("ctrl+enter"));
    ui->ButtonTranslate->setShortcut(QKeySequence("ctrl+return"));
    ui->buttonEmpty->setShortcut(QKeySequence("ESC"));


    ui->textInput->setPlaceholderText(QString("请输入需要翻译的字、词、句"));
    ui->textOutput->setPlaceholderText(QString("译文"));
    ui->ButtonTranslate->setStyleSheet("background-color: rgb(154,192,205);");
    connect(ui->ButtonTranslate, SIGNAL(clicked(bool)), this, SLOT(slotTranslate()));
    connect(ui->buttonEmpty, SIGNAL(clicked(bool)), this, SLOT(slotEmpty()));

    //daywords();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotEmpty()
{
    ui->textInput->setText("");
    ui->textOutput->setText("");
}

void MainWindow::slotTranslate()
{
    m_word = ui->textInput->toPlainText().trimmed().toLower();
    if(m_word.size() == 0 )
    {
        ui->textOutput->setText(QString("想查些什么呢？"));
        return;
    }
    m_urlspec = "http://dict-co.iciba.com/api/dictionary.php?w="+m_word+"&key="+m_key;
    if (m_urlspec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(m_urlspec);
    if (!newUrl.isValid()) {
        qDebug()<<"new Url is not valid"<<endl;
        return;
    }

    startRequest(newUrl);
}

void MainWindow::slotHttpFinished()
{
    if (m_httpRequestAborted) {
        m_preply->deleteLater();
        m_preply = Q_NULLPTR;
        return;
    }

    if (m_preply->error()) {
        m_preply->deleteLater();
        m_preply = Q_NULLPTR;
        return;
    }

    const QVariant redirectionTarget = m_preply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    m_preply->deleteLater();
    m_preply = Q_NULLPTR;

    if (!redirectionTarget.isNull())
    {
        const QUrl redirectedUrl = m_url.resolved(redirectionTarget.toUrl());
        startRequest(redirectedUrl);
        return;
    }
}

void MainWindow::slotHttpReadyRead()
{
    QString tmp(m_preply->readAll());
    xmlread(tmp);
    if(m_output.size() != 0)
        ui->textOutput->setText(m_output);
    else
        ui->textOutput->setText("好吧，金山翻译API查不到...");
    m_urlspec.clear();
}

void MainWindow::xmlread(QString &tmp)
{
    m_output.clear();
    QXmlStreamReader reader(tmp);
    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType nType = reader.readNext();
        switch(nType)
        {
        case QXmlStreamReader::StartElement:
            parsedict(reader);
            break;
        default:
            break;
        }
    }
}

void MainWindow::parsedict(QXmlStreamReader &reader)
{
    while (!reader.atEnd())
    {
       reader.readNext();
       if (reader.isStartElement())
       {
           QString strElementName = reader.name().toString();
           if (QString::compare(strElementName, QStringLiteral("acceptation")) == 0)
           {
               reader.readNext();
               if (reader.isCharacters())
                   m_output += QStringLiteral("解释:%1").arg(reader.text().toString()) + "\n";
           }
           else if (QString::compare(strElementName, QStringLiteral("pos")) == 0)
               m_output += QStringLiteral("词性:%1").arg(reader.readElementText());
           else if (QString::compare(strElementName, QStringLiteral("sent")) == 0)
               parseorig(reader);
       }
   }
}

void MainWindow::parseorig(QXmlStreamReader &reader)
{
    while (!reader.atEnd())
    {
       reader.readNext();
       if (reader.isStartElement())
       {
           QString strElementName = reader.name().toString();
           if (QString::compare(strElementName, QStringLiteral("orig")) == 0)
           {
               reader.readNext();
               if (reader.isCharacters())
               {
                   m_output += QStringLiteral("例句:%1").arg(reader.text().toString());
               }
           }
           else if (QString::compare(strElementName, QStringLiteral("trans")) == 0)
               m_output += QStringLiteral("%1").arg(reader.readElementText()) + "\n";
       }
   }
}

void MainWindow::startRequest(const QUrl &requestedUrl)
{
    m_url = requestedUrl;
    m_httpRequestAborted = false;

    m_preply = m_qnam.get(QNetworkRequest(m_url));
    connect(m_preply, &QNetworkReply::finished, this, &MainWindow::slotHttpFinished);
    connect(m_preply, &QIODevice::readyRead, this, &MainWindow::slotHttpReadyRead);
}

void MainWindow::daywords()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd");
    m_urlday = "http://open.iciba.com/dsapi/?date="+current_date+"&file=xml";

    const QUrl newUrl = QUrl::fromUserInput(m_urlday);
    startRequest(newUrl);
}
