#ifndef LARLITE_MCROI_CXX
#define LARLITE_MCROI_CXX

#include "MCROI.h"

namespace larlite {

  bool MCROI::initialize() {

    
    return true;
  }
  
  bool MCROI::analyze(storage_manager* storage) {

    auto geo = ::larutil::Geometry::GetME();

    auto event_w    = storage->get_data<event_wire>     ( "caldata" );
    auto event_roi  = storage->get_data<event_PiZeroROI>( "mcroi"  );

    int min_time[3] = {9999999,9999999,9999999};
    int max_time[3] = {0,0,0};

    int min_wire[3] = {9999999,9999999,9999999};
    int max_wire[3] = {0,0,0};

    
    for ( const auto & wire : *event_w  ) {
      
      // no .empty() ??
      auto& sroi  = wire.SignalROI();
      int   plane = wire.View();

      if ( sroi.size() == 0 ) continue;
      
      auto& min_t = min_time[plane];
      auto& max_t = max_time[plane];

      auto& min_w = min_wire[plane];
      auto& max_w = max_wire[plane];

      int channel = geo->ChannelToWireID(wire.Channel()).Wire;
      if ( channel < min_w ) min_w = channel;
      if ( channel > max_w ) max_w = channel;

      for (auto & iROI : sroi.get_ranges()) {

	int FirstTick = iROI.begin_index();
	int EndTick   = iROI.begin_index() + iROI.size();
	
	if ( FirstTick < min_t ) min_t = FirstTick;
	if ( EndTick   > max_t ) max_t = EndTick;
	
      }
      
      
    }
    
    int wire_padding = 25;
    int tick_padding = 25;
    
    // for( unsigned plane = 0; plane < 3; ++plane ) {
    //   const auto& min_t = min_time[plane];
    //   const auto& max_t = max_time[plane];
      
    //   const auto& min_w = min_wire[plane];
    //   const auto& max_w = max_wire[plane];

    //   std::cout << "\tPlane: " << plane << "\n";
    //   std::cout << "Min T: " << min_t << "\n";
    //   std::cout << "Max T: " << max_t << "\n";
    //   std::cout << "Min W: " << min_w << "\n";
    //   std::cout << "Max W: " << max_w << "\n";
      
    //   }
      
    PiZeroROI proi({{min_wire[0],max_wire[0]},{min_wire[1],max_wire[1]},{min_wire[2],max_wire[2]}},
		   {{min_time[0],max_time[0]},{min_time[1],max_time[1]},{min_time[2],max_time[2]}});
  
    event_roi->emplace_back(proi);
    
    return true;
  }

  bool MCROI::finalize() {

    
    
    return true;
  }

}
#endif
