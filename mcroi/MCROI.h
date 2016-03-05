#ifndef LARLITE_MCROI_H
#define LARLITE_MCROI_H

#include "Analysis/ana_base.h"
#include "DataFormat/PiZeroROI.h"
#include "DataFormat/wire.h"
#include "LArUtil/Geometry.h"

namespace larlite {

  class MCROI : public ana_base{
  
  public:

    MCROI(){ _name="MCROI"; _fout=0;}
    virtual ~MCROI(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();
    
  };
}
#endif
