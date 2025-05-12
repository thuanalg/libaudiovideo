#include "libaudiovideo.h"
int main(int argc, char *argv[]) {
	int ret = 0, i = 0;
	char cfgpath[1024];
	SPL_INPUT_ARG input = { 0 };
	snprintf(cfgpath, 1024, "D:/reserach/libaudiovideo/build/Debug/simplelog.cfg");
	snprintf(input.folder, SPL_PATH_FOLDER, "%s", cfgpath);
	ret = spl_init_log_ext(&input);
	if (ret) {
		const char* p = spl_err_txt(ret);
		fprintf(stdout, "\n%s\n", p);
		exit(1);
	}
	lav_get_dev();

	spl_finish_log();
	return 0;
}