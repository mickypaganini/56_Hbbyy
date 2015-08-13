////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Name: DHMaster.h                                                          //
//                                                                            //
//  Created: Andrew Hard                                                      //
//  Email: ahard@cern.ch                                                      //
//  Date: 10/08/2015                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "BkgModel.h"
#include "Config.h"
#include "DHAnalysis.h"
#include "DHCheckJobs.h"
#include "DHTestStat.h"
#include "DHToyAnalysis.h"
//#include "SigParamInterface.h"

bool m_isFirstJob;

Config *m_config;

void submitTSViaBsub(TString exeConfigFile, TString exeOption,
		     TString exeSignal);

void submitMLViaBsub(TString exeConfigFile, TString exeOption, 
		     TString exeSignal);

void submitPEViaBsub(TString exeConfigFile, TString exeOption,
		     TString exeSignal, int exeSeed, int exeToysPerJob);