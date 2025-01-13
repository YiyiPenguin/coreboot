
/* SPDX-License-Identifier: GPL-2.0-only */
#include <boot/coreboot_tables.h>
#include <commonlib/coreboot_tables.h>
#include <drivers/option/cfr_frontend.h>
#include <ec/google/chromeec/cfr.h>
#include <intelblocks/cfr.h>
#include <soc/cfr.h>
#include <inttypes.h>
#include <string.h>
#include <types.h>


static struct sm_obj_form processor = {
	.ui_name = "Processor",
	.flags    = CFR_OPTFLAG_SUPPRESS,
	.obj_list = (const struct sm_object *[]) {
		&me_state,
		&me_state_counter,
		&igd_dvmt,
		&igd_aperture,
		NULL
	},
};

static struct sm_obj_form ec = {
	.ui_name = "ChromeEC Embedded Controller",
	.obj_list = (const struct sm_object *[]) {
		&ec_sw_sync,
		&ec_rw_jump,
		NULL
	},
};

static struct sm_obj_form power = {
	.ui_name = "Power",
	.obj_list = (const struct sm_object *[]) {
		&sleep_mode,
		NULL
	},
};


static struct sm_obj_form *sm_root[] = {
	&processor,
	&ec,
	&power,
	NULL
};

void mb_cfr_setup_menu(struct lb_cfr *cfr_root)
{
	cfr_write_setup_menu(cfr_root, sm_root);
}
