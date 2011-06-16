/*
Data Quota for Symbian phones.
http://code.google.com/p/dataquota/
Copyright (C) 2008, 2009, 2011  Hugo van Kemenade

This file is part of Data Quota.

Data Quota is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

Data Quota is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Data Quota.  If not, see <http://www.gnu.org/licenses/>.
*/

// INCLUDE FILES
#include "DataQuotaApplication.h"
#include "DataQuotaDocument.h"


// UID for the application should match the UID defined in the mmp file
#ifdef __OVI_SIGNED__
const TUid KUidDataQuotaApp = {0x200427F6};
#else
const TUid KUidDataQuotaApp = {0xA000B6EF};
#endif

CApaDocument* CDataQuotaApplication::CreateDocumentL()
	{
	// Create a Data Quota document, and return a pointer to it
	return (static_cast<CApaDocument*>
					(CDataQuotaDocument::NewL(*this)));
	}


TUid CDataQuotaApplication::AppDllUid() const
	{
	// Return the UID for the Data Quota application
	return KUidDataQuotaApp;
	}

// End of file
