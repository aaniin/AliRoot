/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
* See cxx source for full Copyright notice                               */

// $Id$
// $MpId: AliMpTriggerSegmentation.h,v 1.2 2006/03/02 16:35:27 ivana Exp $

/// \ingroup trigger
/// \class AliMpTriggerSegmentation
/// \brief Implementation of AliMpVSegmentation for trigger slats.
/// 
/// Author: Laurent Aphecetche

#ifndef ALI_MP_TRIGGER_SEGMENTATION_H
#define ALI_MP_TRIGGER_SEGMENTATION_H

#ifndef ROOT_TString
#include "TString.h"
#endif

#ifndef ALI_MP_V_SEGMENTATION_H
#include "AliMpVSegmentation.h"
#endif

#ifndef ALI_MP_PAD_H
#include "AliMpPad.h"
#endif

class AliMpMotifPosition;
class AliMpPCB;
class AliMpTrigger;

class AliMpTriggerSegmentation : public AliMpVSegmentation
{
public:
  AliMpTriggerSegmentation();
  AliMpTriggerSegmentation(const AliMpTrigger* slat);
  virtual ~AliMpTriggerSegmentation();
  
  virtual AliMpVPadIterator* CreateIterator(const AliMpArea& area) const;
  
  const char* GetName() const;
  
  Bool_t HasPad(const AliMpIntPair& indices) const;
  
  Int_t MaxPadIndexX();
  Int_t MaxPadIndexY();
    
  virtual AliMpPad PadByLocation(const AliMpIntPair& location, 
                                 Bool_t warning) const;
  
  virtual AliMpPad PadByIndices(const AliMpIntPair& indices,  
                                Bool_t warning) const;
  
  virtual AliMpPad PadByPosition(const TVector2& position,
                                 Bool_t warning) const;
  
  const AliMpTrigger* Slat() const;
   
  virtual void GetAllElectronicCardIDs(TArrayI& ecn) const;
  
  AliMpPlaneType PlaneType() const;
  
  TVector2 Dimensions() const;
  
protected:
  AliMpTriggerSegmentation(const AliMpTriggerSegmentation& right);
  AliMpTriggerSegmentation&  operator = (const AliMpTriggerSegmentation& right);
     
private:
    const AliMpTrigger* fkSlat; // Slat
  
  ClassDef(AliMpTriggerSegmentation,1) // Segmentation for slat trigger stations
};

#endif
