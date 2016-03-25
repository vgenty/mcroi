//by vic
#ifndef LARLITE_MCROI_H
#define LARLITE_MCROI_H

#include "Analysis/ana_base.h"
#include "DataFormat/PiZeroROI.h"
#include "DataFormat/wire.h"

#include "roialgo.h"

namespace larlite {

  class MCROI : public ana_base{
  
  public:

    MCROI() : _ralgo(nullptr) { _name="MCROI"; _fout=0;}
    virtual ~MCROI(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

    void SetROIAlgo(roialgo* ralgo) { _ralgo = ralgo; }
    
  private:

    roialgo* _ralgo;
    
  };
}
#endif
