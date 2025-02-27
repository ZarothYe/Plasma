/*==LICENSE==*

CyanWorlds.com Engine - MMOG client, server and tools
Copyright (C) 2011  Cyan Worlds, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Additional permissions under GNU GPL version 3 section 7

If you modify this Program, or any covered work, by linking or
combining it with any of RAD Game Tools Bink SDK, Autodesk 3ds Max SDK,
NVIDIA PhysX SDK, Microsoft DirectX SDK, OpenSSL library, Independent
JPEG Group JPEG library, Microsoft Windows Media SDK, or Apple QuickTime SDK
(or a modified version of those libraries),
containing parts covered by the terms of the Bink SDK EULA, 3ds Max EULA,
PhysX SDK EULA, DirectX SDK EULA, OpenSSL and SSLeay licenses, IJG
JPEG Library README, Windows Media SDK EULA, or QuickTime SDK EULA, the
licensors of this Program grant you additional
permission to convey the resulting work. Corresponding Source for a
non-source form of such a combination shall include the source code for
the parts of OpenSSL and IJG JPEG Library used as well as that of the covered
work.

You can contact Cyan Worlds, Inc. by email legal@cyan.com
 or by snail mail at:
      Cyan Worlds, Inc.
      14617 N Newport Hwy
      Mead, WA   99021

*==LICENSE==*/
#ifndef _pyGUIControlMultiLineEdit_h_
#define _pyGUIControlMultiLineEdit_h_

//////////////////////////////////////////////////////////////////////
//
// pyGUIControlMultiLineEdit   - a wrapper class to provide interface to modifier
//                   attached to a GUIControlMultiLineEdit
//
//////////////////////////////////////////////////////////////////////

#include "pyGUIControl.h"
#include "pyGlueHelpers.h"

#include <tuple>

class plKey;
class pyColor;
class pyKey;
namespace ST { class string; }

class pyGUIControlMultiLineEdit : public pyGUIControl
{
protected:
    pyGUIControlMultiLineEdit(): pyGUIControl() {} // used by python glue, do NOT call
    pyGUIControlMultiLineEdit(pyKey& gckey);
    pyGUIControlMultiLineEdit(plKey objkey);

public:
    // required functions for PyObject interoperability
    PYTHON_CLASS_NEW_FRIEND(ptGUIControlMultiLineEdit);
    static PyObject *New(pyKey& gckey);
    static PyObject *New(plKey objkey);
    PYTHON_CLASS_CHECK_DEFINITION; // returns true if the PyObject is a pyGUIControlMultiLineEdit object
    PYTHON_CLASS_CONVERT_FROM_DEFINITION(pyGUIControlMultiLineEdit); // converts a PyObject to a pyGUIControlMultiLineEdit (throws error if not correct type)

    static void AddPlasmaClasses(PyObject *m);
    static void AddPlasmaConstantsClasses(PyObject *m);

    static bool IsGUIControlMultiLineEdit(const plKey& key);

    void Clickable();
    void Unclickable();
    void SetScrollPosition(int32_t topLine);
    int32_t GetScrollPosition();
    bool IsAtEnd();
    void MoveCursor(int32_t dir);
    int32_t GetCursor() const;
    void ClearBuffer();
    void SetText(const ST::string& text);
    ST::string GetText();
    void SetEncodedBuffer(PyObject* buffer_object);
    ST::string GetEncodedBuffer();
    size_t GetBufferSize() const;

    void SetBufferLimit(int32_t limit);
    int32_t GetBufferLimit();
    int16_t GetCurrentLink() const;

    void InsertChar(wchar_t c);
    void InsertString(const ST::string& string);
    void InsertColor(pyColor& color);
    void InsertStyle(uint8_t fontStyle);
    void InsertLink(int16_t linkId);
    void ClearLink();
    void DeleteChar();

    void Lock();
    void Unlock();
    bool IsLocked();

    void EnableScrollControl();
    void DisableScrollControl();

    void DeleteLinesFromTop(int lines);

    uint32_t  GetFontSize() const override;
    void    SetFontSize(uint32_t fontsize) override;

    void BeginUpdate();
    void EndUpdate(bool redraw);
    bool IsUpdating() const;

    std::tuple<int, int, int, int> GetMargins() const;
    void SetMargins(int top, int left, int bottom, int right);
};

#endif // _pyGUIControlMultiLineEdit_h_
