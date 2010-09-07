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

#include <QtGui/QApplication>
#include <QUrl>
#include <QSettings>
#include <QDebug>
#include "webwindow.h"
#include "site.h"

enum Options {
	OPT_NOOPTION,
	OPT_APPPATH,
};

bool Debug;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setOrganizationName("Hack&Dev");
	a.setApplicationName("NativeCapp");
	
	Debug = false;
	Options options = OPT_NOOPTION;
	QUrl resolvedSite = QUrl();
	bool dontCareAboutAppName = true;
	
	// I hate parsing arguments in anything other than python >_<
	foreach(QString s, a.arguments()) {
		if(dontCareAboutAppName) {
			dontCareAboutAppName = false;
			continue;
		}
		if(options != OPT_NOOPTION) {
			switch (options) {
				case OPT_APPPATH:
					resolvedSite = QUrl("file://" + s);
					break;
				default:
					break;
			}
			options = OPT_NOOPTION;
		} else if(s == "-d") {
			Debug = true;
		} else if(s == "-a") {
			options = OPT_APPPATH;
		} else
			return 2;
	}
	if(options != OPT_NOOPTION)
		return 2;
	
	if(resolvedSite.isEmpty()) {
		if(Debug)
			resolvedSite = QUrl("qrc:///index-debug.html");
		else
			resolvedSite = QUrl("qrc:///index.html");
	}

	qDebug() << "Site index:" << resolvedSite;
	
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, Debug);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
	
	WebWindow rootWindow;
	rootWindow.resize(800, 600);
	rootWindow.setBaseUrl(resolvedSite);
	rootWindow.show();
	
	return a.exec();
}
