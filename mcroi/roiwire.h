//by vic
#ifndef ROIWIRE_H
#define ROIWIRE_H

#include "roialgo.h"

namespace larlite {

  class roiwire : public roialgo {

  public:

    roiwire() : roialgo() {}

    /// Default destructor
    virtual ~roiwire(){}

    bool FindROI(storage_manager* storage,std::string producer);

  private:
    
  };

}

#endif
/** @} */ // end of doxygen group 

