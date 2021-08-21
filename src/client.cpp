// FileName: server.cpp
// Description: Qthttpserver demo server
// Author: BigBookPlus

#include <QtCore>

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkrequest.h>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
	QNetworkAccessManager *mgr = new QNetworkAccessManager;
	const QUrl url(QStringLiteral("http://127.0.0.1:8888/post/"));
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json; charset=utf-8");
	QJsonObject obj;
	obj["key1"] = "value1";
    obj["key2"] = "value2";
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
	QNetworkReply *reply = mgr->post(request, data);

	QObject::connect(reply, &QNetworkReply::finished, [=](){
		if(reply->error() == QNetworkReply::NoError){
			QString contents = QString::fromUtf8(reply->readAll());
			qDebug() << contents;
		}
		else{
			QString err = reply->errorString();
			qDebug() << err;
		}
		reply->deleteLater();
	    mgr->deleteLater();
	});

    return app.exec();
}