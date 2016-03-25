//by vic
#ifndef ROIHIT_H
#define ROIHIT_H

#include "roialgo.h"

namespace larlite {

  class roihit : public roialgo {

  public:

    roihit() : roialgo() {}

    /// Default destructor
    virtual ~roihit(){}

    bool FindROI(storage_manager* storage,std::string producer);

  private:
    
  };

}

#endif
/** @} */ // end of doxygen group 

