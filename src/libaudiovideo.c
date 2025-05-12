#include "libaudiovideo.h"
#include "simplelog.h"
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/	
#define lav_all(__fmt_____, ...) \
	spllog(SPL_LOG_BASE, __fmt_____, ##__VA_ARGS__)
#define lav_dbg(__fmt_____, ...) \
	spllog(SPL_LOG_DEBUG, __fmt_____, ##__VA_ARGS__)
#define lav_inf(__fmt_____, ...) \
	spllog(SPL_LOG_INFO, __fmt_____, ##__VA_ARGS__)
#define lav_wrn(__fmt_____, ...) \
	spllog(SPL_LOG_WARNING, __fmt_____, ##__VA_ARGS__)
#define lav_err(__fmt_____, ...) \
	spllog(SPL_LOG_ERROR, __fmt_____, ##__VA_ARGS__)
#define lav_ftl(__fmt_____, ...) \
	spllog(SPL_LOG_FATAL, __fmt_____, ##__VA_ARGS__)
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
int lav_get_dev() {
	lav_all("Test: %s", __FILE__);
	return 0;
}
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/