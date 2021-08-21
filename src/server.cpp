// FileName: server.cpp
// Description: Qthttpserver demo server
// Author: BigBookPlus

#include <QtCore>
#include <QtHttpServer>

int main(int argc, char **argv) {
  QCoreApplication app(argc, argv);
  QHttpServer http_server;
  http_server.route("/", []() {
    return "Hello QtHttpServer";
  });
  http_server.route("/post/", QHttpServerRequest::Method::POST,
    [](const QHttpServerRequest &request)
    {
      qDebug() << "received requestBody" << request.body();
      return QJsonObject
      {
        {"message", "finish"}
      };
    });
  http_server.listen(QHostAddress::Any, 8888);
  return app.exec();
}