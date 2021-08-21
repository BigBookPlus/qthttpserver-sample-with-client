# qthttpserver-sample-with-client

This is a DIY sample code of the [qt-labs/qthttpserver](https://github.com/qt-labs/qthttpserver) lib. In this demo, we start a simple server which response to a GET / POST request,  and do a simple http post with json-format body.

## Build QtHttpServer

please refer to [qt-labs/qthttpserver](https://github.com/qt-labs/qthttpserver), we check out branch 5.15 for we using Qt5.

Built as instructions, and copy files into our your Qt dirs. QtCreator is always recommended.

## Build this repo

Please modify the following line in `CMakeLists.txt` file, replace `Qt5_DIR` with your own Qt installation dir.

```cmake
set(Qt5_DIR D:/Qt/Qt5.12.6/5.12.6/msvc2017_64/lib/cmake/Qt5)
```

simply as usual,

```bash
mkdir build && cd build
cmake ..
make
```

## TEST

to start the server,

```bash
./server 
```

open internet browser and try http://127.0.0.1:8888, we can see a message `Hello QtHttpServer`.

to do a http post, run client

```bash
./client
```

If everything goes well, server will print the posted json body from client and client will print the response message from server.

## References

[How to send a POST request in Qt with the JSON body](https://stackoverflow.com/questions/60107604/how-to-send-a-post-request-in-qt-with-the-json-body)

[qt-labs/qthttpserver](https://github.com/qt-labs/qthttpserver)