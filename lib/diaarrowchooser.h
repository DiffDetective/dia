/* Dia -- an diagram creation/manipulation program
 * Copyright (C) 1998 Alexander Larsson
 *
 * diarrowchooser.h -- Copyright (C) 1999 James Henstridge.
 *                     Copyright (C) 2004 Hubert Figuiere
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#pragma once

#include <gtk/gtk.h>

#include "arrows.h"
#include "diatypes.h"
#include "dia-autoptr.h"

G_BEGIN_DECLS

/* --------------- DiaArrowPreview -------------------------------- */

#define DIA_TYPE_ARROW_PREVIEW dia_arrow_preview_get_type ()
G_DECLARE_FINAL_TYPE (DiaArrowPreview, dia_arrow_preview, DIA, ARROW_PREVIEW, GtkMisc)


struct _DiaArrowPreview {
  GtkMisc misc;
  ArrowType atype;
  gboolean left;
};


GtkWidget *dia_arrow_preview_new            (ArrowType               atype,
                                             gboolean                left);


/* ------- Code for DiaArrowChooser ----------------------- */

#define DIA_TYPE_ARROW_CHOOSER dia_arrow_chooser_get_type ()
G_DECLARE_FINAL_TYPE (DiaArrowChooser, dia_arrow_chooser, DIA, ARROW_CHOOSER, GtkButton)


typedef void (*DiaChangeArrowCallback) (Arrow atype, gpointer user_data);

struct _DiaArrowChooser {
  GtkButton button;
  DiaArrowPreview *preview;
  Arrow arrow;
  gboolean left;

  DiaChangeArrowCallback callback;
  gpointer user_data;

  GtkWidget *menu;
  GtkWidget *dialog;
  DiaArrowSelector *selector;
};


GtkWidget *dia_arrow_chooser_new            (gboolean                left,
                                             DiaChangeArrowCallback  callback,
                                             gpointer                user_data);
void       dia_arrow_chooser_set_arrow      (DiaArrowChooser        *chooser,
                                             Arrow                  *arrow);
ArrowType  dia_arrow_chooser_get_arrow_type (DiaArrowChooser        *chooser);

G_END_DECLS
