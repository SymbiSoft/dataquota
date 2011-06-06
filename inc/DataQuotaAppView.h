/*
Data Quota for Symbian phones.
http://code.google.com/p/dataquota/
Copyright (C) 2008, 2009, 2010, 2011  Hugo van Kemenade

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

#ifndef __DATAQUOTAAPPVIEW_H__
#define __DATAQUOTAAPPVIEW_H__

// CONSTANTS
_LIT(KVersion, "1.36");

// FORWARD DECLARATIONS
class CAknNavigationControlContainer;
class CAknNavigationDecorator;
class CDataQuotaTouchFeedbackInterface;
class CRepository;

// CLASS DECLARATION
class CDataQuotaAppView : public CCoeControl
	{
	public:
		enum TQuotaType
			{
			EDaily,
			EMonthly
			};

	public: // New methods
		static CDataQuotaAppView* NewL(const TRect& aRect);
		static CDataQuotaAppView* NewLC(const TRect& aRect);
		virtual ~CDataQuotaAppView();

	public:  // Functions from base classes
		void Draw(const TRect& aRect) const;

	public: // New methods
		void UpdateValuesL();
		TInt DataQuota();
		void SetDataQuotaL(TInt aDataQuota);
		TInt BillingDay();
		void SetBillingDayL(TInt aBillingDay);
		void SetQuotaTypeL(TQuotaType aQuotaType);

	private: // from CCoeControl
		virtual void SizeChanged();
		TTypeUid::Ptr MopSupplyObject(TTypeUid aId);
		TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, 
									TEventCode aType);
		void HandlePointerEventL(const TPointerEvent& aPointerEvent);

	// private: // from CAknView
		// void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);
	
	private: // Constructors
		void ConstructL(const TRect& aRect);
		CDataQuotaAppView();

		// Drawing helper methods
		void DrawText(const TDesC& aText, 
					  const TInt& aY, 
					  const TRgb& aPenColor) const;

		void DrawRect(const TRect& aRect, 
					  const TRgb& aPenColor, 
					  const TRgb& aBrushColor) const;

		void LoadResourceFileTextL();
		void LoadSettingsL();
		void SaveSettingsL();

		void DoChangePaneTextL() const;

	private:
		// text from resource files
		HBufC* iSentText;
		HBufC* iRcvdText;
		HBufC* iUsedText;
		HBufC* iHourText;
		HBufC* iDayText;
		HBufC* iSeperatorText;
		HBufC* iMegabyteText;
		HBufC* iGigabyteText;

		CRepository*  iRepository;
		const CFont* iFont;

		MAknsControlContext* iBackground; // for skins support 

		TInt iDataQuota;

		TInt iSentData;
		TInt iRcvdData;

		TDateTime iDateTime;
		TInt iDaysThisPeriod;
		TInt iBillingDay;
		TInt iDaysSinceBillingDay;
		TQuotaType iQuotaType;

		TRect iDataRect;
		TRect iSentRect;
		TRect iRcvdRect;

		TRect iDateRect;
		TRect iNowRect;
		TInt iRectWidth;

		CAknNavigationControlContainer *iNaviContainer;
		CAknNavigationDecorator* iNaviLabelDecorator;
		TPoint iLastTouchPosition;
		CDataQuotaTouchFeedbackInterface* iFeedback;
		TUid iDtorIdKey;
	};

#endif // __DATAQUOTAAPPVIEW_H__

// End of file