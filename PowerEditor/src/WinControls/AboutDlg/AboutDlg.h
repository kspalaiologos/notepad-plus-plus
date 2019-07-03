// This file is part of Notepad++ project
// Copyright (C)2003 Don HO <don.h@free.fr>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// Note that the GPL places important restrictions on "derived works", yet
// it does not provide a detailed definition of that term.  To avoid      
// misunderstandings, we consider an application to constitute a          
// "derivative work" for the purpose of this license if it does any of the
// following:                                                             
// 1. Integrates source code from Notepad++.
// 2. Integrates/includes/aggregates Notepad++ into a proprietary executable
//    installer, such as those produced by InstallShield.
// 3. Links to a library or executes a program that does any of the above.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#pragma once

#include "URLCtrl.h"
#include "resource.h"
#include "StaticDialog.h"

#define LICENCE_TXT \
TEXT("This program is free software; you can redistribute it and/or \
modify it under the terms of the GNU General Public License \
as published by the Free Software Foundation; either \
version 2 of the License, or (at your option) any later version.\r\n\
\r\n\
This program is distributed in the hope that it will be useful, \
but WITHOUT ANY WARRANTY; without even the implied warranty of \
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the \
GNU General Public License for more details. \r\n\
\r\n\
You should have received a copy of the GNU General Public License \
along with this program; if not, write to the Free Software \
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.")


class AboutDlg : public StaticDialog
{
public :
	AboutDlg() : StaticDialog() {};

	void doDialog();

    virtual void destroy() {
        _emailLink.destroy();
        _pageLink.destroy();
    };

protected :
	virtual INT_PTR CALLBACK run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam);

private :
    URLCtrl _emailLink;
    URLCtrl _pageLink;
};


class DebugInfoDlg : public StaticDialog
{
public:
	DebugInfoDlg() : StaticDialog() {};

	void init(HINSTANCE hInst, HWND parent, bool isAdmin, const generic_string& loadedPlugins) {
		_isAdmin = isAdmin;
		_loadedPlugins = loadedPlugins;
		Window::init(hInst, parent);
	};

	void doDialog();

	virtual void destroy() {
		_copyToClipboardLink.destroy();
	};

protected:
	virtual INT_PTR CALLBACK run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam);

private:
	generic_string _debugInfoStr;
	bool _isAdmin = false;
	generic_string _loadedPlugins;
	URLCtrl _copyToClipboardLink;
};

class DoSaveOrNotBox : public StaticDialog
{
public:
	DoSaveOrNotBox() : StaticDialog() {};

	void init(HINSTANCE hInst, HWND parent, const TCHAR* fn, bool isMulti) {
		Window::init(hInst, parent);
		if (fn)
			_fn = fn;

		_isMulti = isMulti;
	};

	void doDialog(bool isRTL = false);

	virtual void destroy() {
	};

	int getClickedButtonId() const {
		return clickedButtonId;
	};

	void changeLang();

protected:
	virtual INT_PTR CALLBACK run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam);

private:
	int clickedButtonId = -1;
	generic_string _fn;
	bool _isMulti = false;
};
