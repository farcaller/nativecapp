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

#include "webwindow.h"
#include "ui_webwindow.h"
#include <QWebSettings>

WebWindow::WebWindow(QWidget *parent)
	: QWidget(parent), ui(new Ui::WebWindow)
{
	ui->setupUi(this);
	connect(ui->webView, SIGNAL(titleChanged(QString)), this, SLOT(setWindowTitle(QString)));
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
}

WebWindow::~WebWindow()
{
	delete ui;
}

void WebWindow::setDebug(bool aDebug)
{
	_debug = aDebug;
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, _debug);
}

bool WebWindow::debug() const
{
	return _debug;
}

void WebWindow::setBaseUrl(QUrl url)
{
	_baseUrl = url;
	ui->webView->load(_baseUrl);
}

QUrl WebWindow::baseUrl() const
{
	return _baseUrl;
}

QWebPage *WebWindow::webPage() const
{
	return ui->webView->page();
}