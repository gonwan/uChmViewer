/***************************************************************************
 *   Copyright (C) 2004-2005 by Georgy Yunaev, gyunaev@ulduzsoft.com       *
 *   Please do not use email address above for bug reports; see            *
 *   the README file                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef ICON_STORAGE_H
#define ICON_STORAGE_H

#include <qmap.h>
#include <qpixmap.h>


class KCHMIconStorage
{
	public:
		typedef struct
		{
			unsigned int 	size;
			const char * 	data;
		} png_memory_image_t;

		enum pixmap_index_t
		{
			back = 1000,
			bookmark_add,
			fileopen,
			print,
			findnext,
			findprev,
			forward,
			gohome,
			viewsource,
			view_decrease,
			view_increase,
			next_page,
			prev_page,
			locate_in_content
		};
	
		KCHMIconStorage();
		const QPixmap * getToolbarPixmap (pixmap_index_t pix);
		const QPixmap * getApplicationIcon();
		const QPixmap * getCloseWindowIcon();
	
	private:
		const QPixmap * returnOrLoadImage (unsigned int id, const png_memory_image_t * image);
	
		QMap<unsigned int, QPixmap*>	m_iconMap;
		QPixmap *						m_iconApplication;
		QPixmap *						m_iconCloseWindow;
};

extern KCHMIconStorage	gIconStorage;

#endif /* ICON_STORAGE_H */
