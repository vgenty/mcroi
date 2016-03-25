//by vic
#ifndef LARLITE_MCROI_CXX
#define LARLITE_MCROI_CXX

#include "MCROI.h"

namespace larlite {

  bool MCROI::initialize() { return true; }
  
  bool MCROI::analyze(storage_manager* storage) {

    auto event_roi  = storage->get_data<event_PiZeroROI>( "mcroi" );

    std::cout << "Finding ROI!!!" << std::endl;
    
    // turns out this is nontrival to pass generate std::vector<data_base> inheritor generically
    // to an algorithm, just send it storage_manager who cares

    _ralgo->FindROI(storage,"gaushit");
    
    PiZeroROI proi(_ralgo->wirerange,_ralgo->timerange);
    proi.SetVertex(_ralgo->vertex);
    
    event_roi->emplace_back(proi);
    
    _ralgo->Clear();
    
    return true;
  }

  bool MCROI::finalize() { return true; }

}
#endif
