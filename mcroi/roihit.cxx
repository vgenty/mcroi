//by vic
#ifndef ROIHIT_CXX
#define ROIHIT_CXX

#include "roihit.h"

#include "DataFormat/hit.h"
#include "DataFormat/mcshower.h"

#include "LArUtil/GeometryUtilities.h"

namespace larlite {

  bool roihit::FindROI(storage_manager* storage,std::string producer) {
    
    auto event_h      = storage->get_data<event_hit>( producer );
    
    //is pi0 really a mctrack? Probably, just find photon start points
    auto event_shower = storage->get_data<event_mcshower>( "mcreco" );

    storage->set_id( storage->get_data<event_hit>(producer)->run(),
		     storage->get_data<event_hit>(producer)->subrun(),
		     storage->get_data<event_hit>(producer)->event_id() );

    
    auto geoh = ::larutil::GeometryUtilities::GetME();

    // 3 planes
    
    int min_time[3] = {9999999,9999999,9999999};
    int max_time[3] = {0,0,0};

    int min_wire[3] = {9999999,9999999,9999999};
    int max_wire[3] = {0,0,0};

    
    for ( const auto & hit : *event_h  ) {
      
      int plane = hit.View();
      
      auto& min_t = min_time[plane];
      auto& max_t = max_time[plane];

      auto& min_w = min_wire[plane];
      auto& max_w = max_wire[plane];

      auto wire   = hit.WireID().Wire;
      auto tstart = hit.StartTick();
      auto tend   = hit.EndTick();

      if ( tstart < min_t )
	min_t = tstart;

      if ( tend > max_t )
	max_t = tend;

      if ( wire < min_w )
	min_w = wire;

      if ( wire > max_w )
	max_w = wire;

    }

    wirerange = { {min_wire[0],max_wire[0]},
		  {min_wire[1],max_wire[1]},
		  {min_wire[2],max_wire[2]} };

    timerange = { {min_time[0],max_time[0]},
		  {min_time[1],max_time[1]},
		  {min_time[2],max_time[2]} };


    //Do the vertex
    std::vector<double> vtx;
    
    for( const auto& s : *event_shower ) {
      
      if ( s.MotherPdgCode() != 111 ) continue; // this parents particle was not pizero

      vtx = { s.Start().X(),s.Start().Y(),s.Start().Z() };
      
      break; // found it, leave
      
    }


    for(short i=0;i<3;++i) {
      auto proj = geoh->Get2DPointProjection( &vtx[0], i ); // pass as C array to return wire and time
      vertex[i] = { proj.w,proj.t - _toffset}; // - vic finds: 2255.
    }

    //check that vertex is inside ROI, if not... bad ROI
    // return false;

    return true;
    
  }
  
}

#endif

