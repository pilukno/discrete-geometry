/*
    SymbolicC++ : An object oriented computer algebra system written in C++

    Copyright (C) 2008 Yorick Hardy and Willi-Hans Steeb

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


// firstintegral.cpp

#include <iostream>
#include "symbolicc++.h"
using namespace std;

int main(void)
{
  Symbolic u1("u1"), u2("u2"), t("t");
  Symbolic f, r;

  f = ln(u1[t]) + ln(u2[t]) - u1[t] - u2[t];
  r = df(f,t);
  cout << "r = " << r << endl;
  r = r.subst(df(u1[t],t),u1[t]-u1[t]*u2[t]);
  r = r.subst(df(u2[t],t),-u2[t]+u1[t]*u2[t]);
  cout << "r = " << r << endl;
  return 0;
}   

