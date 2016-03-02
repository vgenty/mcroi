// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME pizeroroi_mcroiDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "MCROI.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *larlitecLcLMCROI_Dictionary();
   static void larlitecLcLMCROI_TClassManip(TClass*);
   static void *new_larlitecLcLMCROI(void *p = 0);
   static void *newArray_larlitecLcLMCROI(Long_t size, void *p);
   static void delete_larlitecLcLMCROI(void *p);
   static void deleteArray_larlitecLcLMCROI(void *p);
   static void destruct_larlitecLcLMCROI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::larlite::MCROI*)
   {
      ::larlite::MCROI *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::larlite::MCROI));
      static ::ROOT::TGenericClassInfo 
         instance("larlite::MCROI", "invalid", 18,
                  typeid(::larlite::MCROI), DefineBehavior(ptr, ptr),
                  &larlitecLcLMCROI_Dictionary, isa_proxy, 4,
                  sizeof(::larlite::MCROI) );
      instance.SetNew(&new_larlitecLcLMCROI);
      instance.SetNewArray(&newArray_larlitecLcLMCROI);
      instance.SetDelete(&delete_larlitecLcLMCROI);
      instance.SetDeleteArray(&deleteArray_larlitecLcLMCROI);
      instance.SetDestructor(&destruct_larlitecLcLMCROI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::larlite::MCROI*)
   {
      return GenerateInitInstanceLocal((::larlite::MCROI*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::larlite::MCROI*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *larlitecLcLMCROI_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::larlite::MCROI*)0x0)->GetClass();
      larlitecLcLMCROI_TClassManip(theClass);
   return theClass;
   }

   static void larlitecLcLMCROI_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_larlitecLcLMCROI(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::larlite::MCROI : new ::larlite::MCROI;
   }
   static void *newArray_larlitecLcLMCROI(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::larlite::MCROI[nElements] : new ::larlite::MCROI[nElements];
   }
   // Wrapper around operator delete
   static void delete_larlitecLcLMCROI(void *p) {
      delete ((::larlite::MCROI*)p);
   }
   static void deleteArray_larlitecLcLMCROI(void *p) {
      delete [] ((::larlite::MCROI*)p);
   }
   static void destruct_larlitecLcLMCROI(void *p) {
      typedef ::larlite::MCROI current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::larlite::MCROI

namespace {
  void TriggerDictionaryInitialization_libpizeroroi_mcroi_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/Users/vgenty/git/larlite/core",
"/usr/local/ROOT/include/root",
"/Users/vgenty/git/larlite/UserDev/pizeroroi/mcroi/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace larlite{class MCROI;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef LARLITE_MCROI_H
#define LARLITE_MCROI_H

#include "Analysis/ana_base.h"
#include "DataFormat/PiZeroROI.h"
#include "DataFormat/wire.h"

//#include "LArUtil/GeometryUtilities.h"


namespace larlite {

  class MCROI : public ana_base{
  
  public:

    MCROI(){ _name="MCROI"; _fout=0;}
    virtual ~MCROI(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

  protected:
    
  };
}
#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"larlite::MCROI", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libpizeroroi_mcroi",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libpizeroroi_mcroi_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libpizeroroi_mcroi_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libpizeroroi_mcroi() {
  TriggerDictionaryInitialization_libpizeroroi_mcroi_Impl();
}
