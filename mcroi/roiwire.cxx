//by vic
#ifndef ROIWIRE_CXX
#define ROIWIRE_CXX

#include "roiwire.h"

#include "DataFormat/wire.h"

#include "LArUtil/Geometry.h"

namespace larlite {

  bool roiwire::FindROI(storage_manager* storage,std::string producer) {


    std::cout << "producer: " << producer << std::endl;
    auto event_w = storage->get_data<event_wire>( producer );

    storage->set_id( storage->get_data<event_wire>(producer)->run(),
		     storage->get_data<event_wire>(producer)->subrun(),
		     storage->get_data<event_wire>(producer)->event_id() );

    
    auto geo = ::larutil::Geometry::GetME();

    // 3 planes
    
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


    // no padding for now, i don't want to have to check edges
    int wpad = 10;
    int tpad = 10;
    
    vertex    = {};

    wirerange = { {min_wire[0],max_wire[0]},
		  {min_wire[1],max_wire[1]},
		  {min_wire[2],max_wire[2]} };

    timerange = { {min_time[0],max_time[0]},
		  {min_time[1],max_time[1]},
		  {min_time[2],max_time[2]} };
    

    //some check that it's good?
    //return false;
    
    return true;
    
  }
  
}

#endif
