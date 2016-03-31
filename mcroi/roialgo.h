//by vic
#ifndef ROIALGO_H
#define ROIALGO_H

#include <iostream>
#include <utility>
#include <string>

#include "DataFormat/storage_manager.h"
#include "LArUtil/GeometryUtilities.h"

namespace larlite {

  class roialgo {

  public:
    
    roialgo() 

    { Clear(); _geoh=::larutil::GeometryUtilities::GetME(); }

    /// Default destructor
    virtual ~roialgo(){}

    //takes generic data product -- NOT! send storage manage and producer
    virtual bool FindROI(storage_manager* storage,std::string producer) = 0;

    inline void Clear() { vertex.resize(3); wirerange.resize(3); timerange.resize(3); }

    void SetTickOffset(unsigned t) { _toffset = t; }
    // protected:
    
    std::vector<std::pair<int,int> > vertex;
    std::vector<std::pair<int,int> > wirerange;
    std::vector<std::pair<int,int> > timerange;
    
  protected:

    unsigned _toffset;
    const ::larutil::GeometryUtilities* _geoh;
    
  };
  
}
#endif
/** @} */ // end of doxygen group 

