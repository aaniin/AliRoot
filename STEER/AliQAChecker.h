#ifndef ALIQAChecker_H
#define ALIQAChecker_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//
// class for running the Quality Assurance Checker
// to run type:
//   AliQAChecker qac;
//   qac.Run();
//   qac.SelectDetectors("list of detectors") ; 
//   qac.SelectTargets("list of targets among Hits, Digits, ESD") ; 
//

#include <TNamed.h>
#include <TFile.h>  
class TNtupleD ;

#include "AliQA.h"
#include "AliRecoParam.h"
class AliCDBEntry ; 
class AliRunInfo ;
class AliQACheckerBase ; 

class AliQAChecker: public TNamed {
public:
  AliQAChecker(const char* name = "AliQAChecker", 
		    const char* title = "Quality Assurance checker for Raws, Hits, Digits and ESDs");
  AliQAChecker(const AliQAChecker& qac);
  AliQAChecker& operator = (const AliQAChecker& qac);
  virtual ~AliQAChecker();

  static  AliQAChecker * Instance() ;
  AliQACheckerBase *     GetDetQAChecker(Int_t det) ; 
  void                   GetRefSubDir(const char * det, const char * task, TDirectory *& dirFile, TObjArray **& dirOCDB) ;
//  static TFile *         GetQAResultFile() ;
//  static const char *    GetQAResultFileName() { return fgQAResultFileName.Data() ; }
//  void                   SetQAResultDirName(const char * name) ; 
//  void                   SetRefDirName(const char * name) ; 

  virtual Bool_t Run(const char * fileName = NULL) ;
  virtual Bool_t Run(AliQA::DETECTORINDEX_t det, AliQA::TASKINDEX_t task, TObjArray ** list);
  virtual Bool_t Run(AliQA::DETECTORINDEX_t det, AliQA::TASKINDEX_t task, TNtupleD ** list);
  void SetRunInfo(AliRunInfo * ei) {fRunInfo = ei;}

private:

  void LoadRunInfoFromGRP() ; 

  static AliQAChecker *       fgQAChecker ;             // pointer to the instance of the singleton
  TFile *                     fDataFile ;               //! Data file to check
  AliRunInfo *                fRunInfo ;                //! Event info object 
  Bool_t                      fRunInfoOwner;            //! owns fRunInfo or not
  TFile *                     fRefFile ;                //! Reference Data file 
  TString                     fFoundDetectors ;         //! detectors for which the Quality assurance could be done
  AliQACheckerBase *          fCheckers[AliQA::kNDET] ; //! list of detectors checkers
  AliRecoParam::EventSpecie_t fEventSpecie ;            //! event specie deduced from the GRP data
  ClassDef(AliQAChecker, 1)  // class for running generation, simulation and digitization
};
#endif
