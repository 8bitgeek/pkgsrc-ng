$NetBSD$

--- gas/config/te-armnbsd.h.orig	Mon May 19 14:12:57 2014
+++ gas/config/te-armnbsd.h
@@ -0,0 +1,22 @@
+/* Copyright 2004, 2005, 2007, 2009 Free Software Foundation, Inc.
+
+   This file is part of GAS, the GNU Assembler.
+
+   GAS is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as
+   published by the Free Software Foundation; either version 3,
+   or (at your option) any later version.
+
+   GAS is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
+   the GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with GAS; see the file COPYING.  If not, write to the Free
+   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
+   02110-1301, USA.  */
+
+#include "te-nbsd.h"
+
+#define CPU_DEFAULT ARM_ARCH_V4