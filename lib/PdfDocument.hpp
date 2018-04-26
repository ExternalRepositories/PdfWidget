/*
	*
	* PdfDocument - PdfDocument class header
	*
*/

#pragma once

#include <QtCore>
#include <QtGui>

#if QT_VERSION >= 0x050000
	#include <poppler-qt5.h>
	#include <QtWidgets>
#else
	#include <poppler-qt4.h>
#endif

typedef Poppler::Page PdfPage;
typedef QList<Poppler::Page*> PdfPages;

class PdfDocument : public QObject {
	Q_OBJECT

	public:
		PdfDocument( QString pdfPath );

		Poppler::Document* document();
		PdfPages allPages();

		QString name() const;
		QString title() const;

		int pages() const;
		PdfPage *page( int pageNum ) const;

		QString pageText( int pageNo ) const;
		QString text( QRect ) const;

	private:
		Poppler::Document *mPdfDoc;
		bool mDocumentLoaded;

		QString mPdfPath;
		PdfPages mPages;

		void loadPdf();

	Q_SIGNALS:
		void pdfLoaded();
};
