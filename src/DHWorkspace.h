////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Name: DHWorkspace.h                                                       //
//  Class: DHWorkspace.cxx                                                    //
//  Creator: Andrew Hard                                                      //
//  Email: ahard@cern.ch                                                      //
//  Date: 01/14/2016                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef DHWorkspace_h
#define DHWorkspace_h

// Package libraries:
#include "CommonFunc.h"
#include "CommonHead.h"
#include "Config.h"
#include "DHAnalysis.h"
#include "DHTestStat.h"
#include "RooFitHead.h"
#include "RooStatsHead.h"
#include "statistics.h"

class DHWorkspace {

 public:
  
  DHWorkspace(TString newConfigFile, TString options);
  virtual ~DHWorkspace() {};
  
  bool fitsAllConverged();
  RooWorkspace* getCombinedWorkspace();
  ModelConfig* getModelConfig();
  
 private:

  void addCategory();
  void addSystematic(TString systematicForm);
  void createAsimovData(int valPoI);  
  void createStupidAsimovData(int valPoI);  
  void createNewWS();
  void loadWSFromFile();
  TString nameOfVar(TString varForm);
  TString nameOfFunc(TString funcForm);
  void plotCatePdfAndData(int nBins);
  void printer(TString statement, bool isFatal);
  
  // Member variables:
  TString m_configFile;
  TString m_anaType;
  TString m_options;
  TString m_outputDir;
  int m_nCategories;
  int m_muNominalSH;
  TString m_dataToPlot;
  bool m_useSystematics;
  
  // Helper classes:
  Config *m_config;
  
  // Updated for each call to addCategory():
  int m_currCateIndex;
  TString m_currCateName;
  RooArgSet *m_constraints;
  
  // The Final RooWorkspace and ModelConfig and arg sets:
  RooWorkspace *m_ws;
  ModelConfig *m_modelConfig;  
  RooArgSet *m_nonSysParameters;
  RooArgSet *m_nuisanceParameters;
  RooArgSet *m_globalObservables;
  RooArgSet *m_observables;
  RooArgSet *m_poi;

  // Objects for combined PDFs and datasets:
  RooCategory *m_categories;
  RooSimultaneous *m_combinedPdf;
  std::map<std::string, RooDataSet*> m_combData;
  std::map<string,RooDataSet*> m_dataAsimov0;
  std::map<string,RooDataSet*> m_dataAsimov1;
  std::map<TString,RooArgSet*> m_expectedList;
  
  // Track whether fits converge:
  bool m_allGoodFits;
  
};

#endif

