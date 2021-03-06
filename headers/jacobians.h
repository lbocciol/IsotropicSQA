/*
//  Copyright (c) 2018, James Kneller and Sherwood Richers
//
//  This file is part of IsotropicSQA.
//
//  IsotropicSQA is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  IsotropicSQA is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with IsotropicSQA.  If not, see <http://www.gnu.org/licenses/>.
//
*/

#if !defined(_jacobians)
#define _jacobians

//==========//
// JInverse //
//==========//
MATRIX<double,3,4> JInverse(const array<double,NY>& y){
  MATRIX<double,3,4> j;
  
  double cPsi1=cos(y[0]), sPsi1=sin(y[0]);
  double cPsi2=cos(y[1]), sPsi2=sin(y[1]);
  double cPsi3=cos(y[2]), sPsi3=sin(y[2]);
  
  j[0][0]=-sPsi1;       j[0][1]=cPsi1*cPsi2;       j[0][2]=cPsi1*sPsi2*cPsi3; j[0][3]=cPsi1*sPsi2*sPsi3;
  j[1][1]=-sPsi2/sPsi1; j[1][2]=cPsi2*cPsi3/sPsi1; j[1][3]=cPsi2*sPsi3/sPsi1;
  sPsi1*=sPsi2;
  j[2][2]=-sPsi3/sPsi1; j[2][3]=cPsi3/sPsi1;
  
  return j;
}

#endif
