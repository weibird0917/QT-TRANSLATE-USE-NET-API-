#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QtNetwork>
#include <QProgressDialog>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startRequest(const QUrl &requestedUrl);
    void xmlread(QString &tmp);
    void parsedict(QXmlStreamReader &reader);//解析解释
    void parseorig(QXmlStreamReader &reader);//解析例子

    void daywords();

    QNetworkAccessManager m_qnam;
    QNetworkReply *m_preply;
    QUrl m_url;
    bool m_httpRequestAborted;

    QString m_word;
    QString m_key;
    QString m_urlspec;
    QString m_output;

    QString m_urlday;
    QString m_daywords;

public slots:
    void slotEmpty();
    void slotTranslate();
    void slotHttpFinished();
    void slotHttpReadyRead();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
