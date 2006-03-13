/**************************************************************************
* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
*                                                                        *
* Author: The ALICE Off-line Project.                                    *
* Contributors are mentioned in the code where appropriate.              *
*                                                                        *
* Permission to use, copy, modify and distribute this software and its   *
* documentation strictly for non-commercial purposes is hereby granted   *
* without fee, provided that the above copyright notice appears in all   *
* copies and that both the copyright notice and this permission notice   *
* appear in the supporting documentation. The authors make no claims     *
* about the suitability of this software for any purpose. It is          *
* provided "as is" without express or implied warranty.                  *
**************************************************************************/

// $Id$

#include "AliMUONCalibParam1I.h"

#include "AliLog.h"
#include "Riostream.h"
#include "TMath.h"
#include "TString.h"

ClassImp(AliMUONCalibParam1I)

//_____________________________________________________________________________
AliMUONCalibParam1I::AliMUONCalibParam1I() 
: AliMUONVCalibParam(),
  fSize(0),
  fValues(0x0)
{
    //
    // Default ctor.
    // 
}

//_____________________________________________________________________________
AliMUONCalibParam1I::AliMUONCalibParam1I(Int_t theSize, Int_t fillWithValue) 
: AliMUONVCalibParam(),
  fSize(theSize)
{
  //
  // Normal ctor, where theSize specifies the number of channels handled
  // by this object, and fillWithValue the default value assigned to each
  // channel.
  //
  if ( fSize > 0 )
  {
    fValues = new Int_t[fSize];
    memset(fValues,fillWithValue,fSize*sizeof(Int_t));
  }
}

//______________________________________________________________________________
AliMUONCalibParam1I::AliMUONCalibParam1I(const AliMUONCalibParam1I& right) 
  : AliMUONVCalibParam(right) 
{  
/// Protected copy constructor (not implemented)

  AliFatal("Copy constructor not provided.");
}

//_____________________________________________________________________________
AliMUONCalibParam1I::~AliMUONCalibParam1I()
{
  //
  // dtor.
  //
  delete[] fValues;
}

//______________________________________________________________________________
AliMUONCalibParam1I& 
AliMUONCalibParam1I::operator=(const AliMUONCalibParam1I& right)
{
/// Protected assignement operator (not implemented)

  // check assignement to self
  if (this == &right) return *this;

  AliFatal("Assignement operator not provided.");
    
  return *this;  
}    

//_____________________________________________________________________________
void
AliMUONCalibParam1I::Print(Option_t* opt) const
{
  //
  // Output this object to stdout.
  // If opt=="full", then all channels are printed, otherwise
  // only the general characteristics are printed.
  //
  TString sopt(opt);
  sopt.ToUpper();
  cout << "AliMUONCalibParam1I - Size=" << Size()
    << " Dimension=" << Dimension()
    << endl;
  if ( sopt.Contains("FULL") )
  {
    for ( Int_t i = 0; i < Size(); ++i )
    {
      cout << setw(6) << ValueAsInt(i) << " , " << endl;
    }
  }
}

//_____________________________________________________________________________
void
AliMUONCalibParam1I::SetValueAsFloat(Int_t i, Int_t j, Float_t value)
{
  //
  // Set the value as a float, which is casted to an int prior to storage.
  //
  SetValueAsInt(i,j,TMath::Nint(value));
}

//_____________________________________________________________________________
void
AliMUONCalibParam1I::SetValueAsInt(Int_t i, Int_t j, Int_t value)
{
  //
  // Set the value for a given channel.
  // (i,j) are checked for correctness before use.
  //
  if ( j != 0 || i >= fSize || i < 0 )
  {
    AliError(Form("Invalid (i,j)=(%d,%d) max allowed is (%d,%d)",
                  i,j,Size()-1,Dimension()-1));
  }
  else
  {
    fValues[i]=value;
  }
}

//_____________________________________________________________________________
Float_t
AliMUONCalibParam1I::ValueAsFloat(Int_t i, Int_t j) const
{
  //
  // Return one value as a float.
  //
  return 1.0*ValueAsInt(i,j);
}

//_____________________________________________________________________________
Int_t
AliMUONCalibParam1I::ValueAsInt(Int_t i, Int_t j) const
{
  //
  // Return one value as an integer, after checking that (i,j)
  // are valid indices.
  //
  if ( j != 0 || i >= fSize || i < 0 )
  {
    AliError(Form("Invalid (i,j)=(%d,%d) max allowed is (%d,%d)",
                  i,j,Size()-1,Dimension()-1));
    return 0;
  }
  else
  {
    return fValues[i];
  }
}
