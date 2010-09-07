/*****************************************************************************
* NativeCapp
*
* Copyright (c) 2010 Vladimir "Farcaller" Pouzanov <farcaller@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*****************************************************************************/

#ifndef WEBWINDOW_H
#define WEBWINDOW_H

#include <QWidget>
#include <QUrl>
#include <QWebPage>

namespace Ui {
    class WebWindow;
}

class WebWindow : public QWidget
{
    Q_OBJECT
	Q_PROPERTY(bool debug READ debug WRITE setDebug);
	Q_PROPERTY(QUrl baseUrl READ baseUrl WRITE setBaseUrl);

public:
    explicit WebWindow(QWidget *parent = 0);
    ~WebWindow();
	
	void setDebug(bool aDebug);
	bool debug() const;
	
	void setBaseUrl(QUrl url);
	QUrl baseUrl() const;
	
	QWebPage *webPage() const;

//private slots:
//	void onTitleChanged

private:
    Ui::WebWindow *ui;
	bool _debug;
	QUrl _baseUrl;
};

#endif // WEBWINDOW_H
