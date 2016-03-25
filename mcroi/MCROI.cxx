//by vic
#ifndef LARLITE_MCROI_CXX
#define LARLITE_MCROI_CXX

#include "MCROI.h"

namespace larlite {

  bool MCROI::initialize() { return true; }
  
  bool MCROI::analyze(storage_manager* storage) {

    auto event_roi  = storage->get_data<event_PiZeroROI>( "mcroi" );

    std::cout << "Finding ROI!!!" << std::endl;
    
    // turns out it is nontrival to pass std::vector<data_base> inheritor generically
    // to algorithm without factory implementation, just send it storage_manager who gives a shit

    _ralgo->FindROI(storage,"gaushit"); // hard code producer :)
    
    PiZeroROI proi(_ralgo->wirerange,_ralgo->timerange);
    proi.SetVertex(_ralgo->vertex);
    
    event_roi->emplace_back(proi);
    
    _ralgo->Clear();
    
    return true;
  }

  bool MCROI::finalize() { return true; }

}
#endif
