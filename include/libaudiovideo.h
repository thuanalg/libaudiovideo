#ifndef ___LIB_AUDIOVIDEO_H__
#define ___LIB_AUDIOVIDEO_H__  
#include "simplelog.h"
#ifdef __cplusplus
extern "C" {
#endif

#ifndef UNIX_LINUX
#ifndef __LIB_AUDIOVIDEO_STATIC__
#ifdef EXPORT_DLL_API_AIDIOVIDEO
#define DLL_API_AIDIOVIDEO              __declspec(dllexport)
#else
#define DLL_API_AIDIOVIDEO              __declspec(dllimport)
#endif
#else
#define DLL_API_AIDIOVIDEO              
#endif
#else
#define DLL_API_AIDIOVIDEO              
#endif /*! UNIX_LINUX */
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
DLL_API_AIDIOVIDEO
int lav_get_dev();
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
#ifdef __cplusplus
}
#endif

#endif