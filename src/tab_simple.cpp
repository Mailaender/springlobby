/**
    This file is part of Settings++,
    Copyright (C) 2007
    Original work by Kloot
    cross-plattform/UI adaptation and currently maintained by koshi (Ren� Milk)
    visit http://spring.clan-sy.com/phpbb/viewtopic.php?t=12104
    for more info/help

    Settings++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Settings++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Settings++.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "tabs.h"
#include "presets.h"

void tab_simple::initOptSizer(wxFlexGridSizer* sizer ) {
	sizer->Add(new wxStaticText(this, -1,  wxT("RENDER_QUALITY")), 0,wxALL);
	//sizer->Add(new wxStaticText(this, -1, wxT("Water Quality")), 0, wxTOP , 10);
	renderQuality_CBX = new wxComboBox(this, ID_SIMPLE_QUAL_CBX, vlow_To_vHigh[0], wxDefaultPosition, wxSize(220,21), 
					5,vlow_To_vHigh,wxCB_DROPDOWN|wxCB_READONLY);
	sizer->Add(renderQuality_CBX, 0, wxBOTTOM, 15);	
	
	sizer->Add(new wxStaticText(this, -1,  wxT("RENDER_DETAIL")), 0,wxALL);
	renderDetail_CBX = new wxComboBox(this, ID_SIMPLE_DETAIL_CBX, low_To_High[0], wxDefaultPosition, wxSize(220,21), 
					3,low_To_High,wxCB_DROPDOWN|wxCB_READONLY);
	sizer->Add(renderDetail_CBX, 0, wxBOTTOM, 15);	

	sizer->Add(new wxStaticText(this, -1,  wxT("VIDEO_MODE")), 0,wxALL);
	videoMode_CBX = new wxComboBox(this, ID_SIMPLE_MODE_CBX, vl_Resolution_Str[0], wxDefaultPosition, wxSize(220,21), 
					3,vl_Resolution_Str,wxCB_DROPDOWN|wxCB_READONLY);
	sizer->Add(videoMode_CBX, 0, wxBOTTOM, 15);	
		
	
}

tab_simple::tab_simple(wxWindow *parent, wxWindowID id , const wxString &title , const wxPoint& pos , const wxSize& size, long style)
                : abstract_panel(parent, id , title , pos , size, style) {

	wxSizer* parentSizer = new wxFlexGridSizer(2,0,0);	
		wxSizer* leftSizer = new wxFlexGridSizer(1,15,0);
		wxSizer* middleSizer = new wxFlexGridSizer(1,15,0);
		wxSizer* rightSizer = new wxFlexGridSizer(1,15,0);//for info
		wxFlexGridSizer* Sizer_CBX = new wxFlexGridSizer(2,10,10);
		wxFlexGridSizer* SizerB = new wxFlexGridSizer(1,15,10);
		wxFlexGridSizer* SizerC = new wxFlexGridSizer(1,15,10);
		wxFlexGridSizer* SizerD = new wxFlexGridSizer(1,5,10);
		wxStaticBoxSizer* boxA = new wxStaticBoxSizer(wxVERTICAL ,this,wxT("SIMPLE_OPTIONS"));
//		wxStaticBoxSizer* boxB = new wxStaticBoxSizer(wxVERTICAL ,this,wxT("Video Mode Options"));
//		wxStaticBoxSizer* boxC = new wxStaticBoxSizer(wxVERTICAL ,this,wxT("Anti-Aliasing Options"));
//		wxStaticBoxSizer* boxD = new wxStaticBoxSizer(wxVERTICAL ,this,wxT("Z-/Depth-Buffer"));
//		Sizer_CBX->AddGrowableCol(0);
//		Sizer_CBX->AddGrowableCol(1);
//	    SizerB->AddGrowableCol(0);
//	    SizerC->AddGrowableCol(0);
//	    SizerD->AddGrowableCol(0);

		
		initOptSizer(Sizer_CBX);
//		initVideoSizer(SizerB);
//		initAASizer(SizerC);
//		initZBufferSizer(SizerD);
		
		Sizer_CBX->Fit(this);
	    Sizer_CBX->SetSizeHints(this);
//	    SizerB->Fit(this);
//	    SizerB->SetSizeHints(this);
//	    SizerC->Fit(this);
//	    SizerC->SetSizeHints(this);
//	    SizerD->Fit(this);
//	    SizerD->SetSizeHints(this);
	    
	    boxA->Add(Sizer_CBX);
//	    boxB->Add(SizerB);
//	    boxC->Add(SizerC);
//	    boxD->Add(SizerD);
//	    leftSizer->Add(boxB,0,wxEXPAND);
//	    leftSizer->Add(boxC);
	    middleSizer->Add(boxA,0,wxEXPAND);
	    //middleSizer->Add(boxD,0,wxEXPAND);
	  //  parentSizer->Add(leftSizer,0,wxALIGN_LEFT|wxALIGN_TOP |wxALL,10);
	    parentSizer->Add(middleSizer,0,wxALIGN_CENTER_HORIZONTAL|wxALL,10);
	   
	    SetSizer(parentSizer, true); // true --> delete old sizer if present
}

tab_simple::~tab_simple(void) {
	
}


//disbaled for the moment
BEGIN_EVENT_TABLE(tab_simple, abstract_panel)
	EVT_SLIDER(1,            tab_simple::OnSliderMove)
	EVT_TEXT(1,              tab_simple::OnTextUpdate)
	EVT_CHECKBOX(1,          tab_simple::OnCheckBoxTick)
	EVT_RADIOBUTTON(1,       tab_simple::OnRadioButtonToggle)
	EVT_IDLE(                       tab_simple::update)
END_EVENT_TABLE()


