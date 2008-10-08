/*
 *      keymgmt.h
 *
 *      Copyright 2008 gpg4usb-team <gpg4usb@cpunk.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#ifndef __KEYMGMT_H__
#define __KEYMGMT_H__


class QMainWindow;
class QWidget;
class iostream;
class QtGui;
class QString;
class QFileDialog;
class QStringList;
class QIcon;
class QMessageBox;
class QAction;
class QMenu;
class QApplication;

#include "context.h"
#include "keylist.h"

class KeyMgmt : public QMainWindow
{
    Q_OBJECT

public:
    KeyMgmt(GpgME::Context* ctx, QString iconpath);

public slots:
    void importKeyFromFile();
    void importKeyFromClipboard();
    void exportKeyToFile();
    void exportKeyToClipboard();
    void deleteCheckedKeys();
    void deleteSelectedKeys();


private:
    void createMenus();
    void createActions();
    void createToolBars();

    KeyList *mKeyList;
    QString mIconPath;
    GpgME::Context *mCtx;
    QMenu *fileMenu;
    QMenu *keyMenu;
    QAction *importKeyFromFileAct;
    QAction *importKeyFromEditAct;
    QAction *importKeyFromClipboardAct;
    QAction *exportKeyToFileAct;
    QAction *exportKeyToClipboardAct;
    QAction *deleteCheckedKeysAct;
    QAction *deleteSelectedKeysAct;
    QAction *closeAct;
};

#endif // __KEYMGMT_H__