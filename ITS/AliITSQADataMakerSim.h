#ifndef AliITSQADataMakerSim_H
#define AliITSQADataMakerSim_H
/* Copyright(c) 2007-2009, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//
//  Checks the quality assurance. 
//  By comparing with reference data
//  contained in a DB
//
//
//  W. Ferrarese + P. Cerello Feb 2008

#include "AliQADataMakerSim.h"

class AliITSQASPDDataMakerSim;
class AliITSQASDDDataMakerSim;
class AliITSQASSDDataMakerSim;
class AliRawReader;

class AliITSQADataMakerSim: public AliQADataMakerSim {

friend class AliITSQASPDDataMakerSim;
friend class AliITSQASDDDataMakerSim;
friend class AliITSQASSDDataMakerSim;

public:
  AliITSQADataMakerSim(Short_t subDet = 0); // subDet = 0 (ALL), 1 (SPD), 2 (SDD), 3 (SSD)
  AliITSQADataMakerSim(const AliITSQADataMakerSim& qadm);
  AliITSQADataMakerSim& operator = (const AliITSQADataMakerSim& qac);
  virtual void StartOfDetectorCycle();
  virtual void EndOfDetectorCycle(AliQA::TASKINDEX_t task, TObjArray ** list);
  virtual void InitDigits();
  virtual void InitSDigits();
  virtual void InitHits();
  virtual void MakeDigits(TClonesArray * digits);
  virtual void MakeSDigits(TClonesArray * sdigits);
  virtual void MakeHits(TClonesArray * hits);
  virtual void MakeDigits(TTree * digits);
  virtual void MakeSDigits(TTree * sdigits);
  virtual void MakeHits(TTree * hits);
  virtual ~AliITSQADataMakerSim(); // dtor
  Short_t GetSubDet(){return fSubDetector;};
  Int_t GetDetTaskOffset(Int_t subdet,AliQA::TASKINDEX_t task);

private:

  Short_t fSubDetector;                    // subDetector: 0 (ALL), 1 (SPD), 2 (SDD), 3 (SSD)

  AliITSQASPDDataMakerSim *fSPDDataMaker;  // SPD Data Maker 
  AliITSQASDDDataMakerSim *fSDDDataMaker;  // SDD Data Maker 
  AliITSQASSDDataMakerSim *fSSDDataMaker;  // SSD Data Maker 

  ClassDef(AliITSQADataMakerSim,2)         // description 

};

#endif

