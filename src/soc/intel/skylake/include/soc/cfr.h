/* SPDX-License-Identifier: GPL-2.0-only */

/*
 * CFR enums and structs which are used to control SoC settings.
 */

#include <drivers/option/cfr_frontend.h>

static const struct sm_object igd_dvmt = SM_DECLARE_ENUM({
	.opt_name	= "IgdDvmt50PreAlloc",
	.ui_name	= "IGD DVMT Size",
	.ui_helptext	= "Size of memory preallocated for internal graphics",
	.default_value	= 2,
	.values		= (const struct sm_enum_value[]) {
				{ "32 MB",		1		},
				{ "64 MB",		2		},
				{ "96 MB",		3		},
				{ "128 MB",		4		},
				SM_ENUM_VALUE_END			},
});

static const struct sm_object igd_aperture = SM_DECLARE_ENUM({
	.opt_name	= "ApertureSize",
	.ui_name	= "IGD Aperture Size",
	.ui_helptext	= "Select the Aperture Size",
	.default_value	= 0,
	.values		= (const struct sm_enum_value[]) {
				{ "128 MB",		0		},
				{ "256 MB",		1		},
				{ "512 MB",		2		},
				SM_ENUM_VALUE_END			},
});

static const struct sm_object sleep_mode = SM_DECLARE_ENUM({
	.opt_name	= "s0ix_enable",
	.ui_name	= "Sleep Mode",
	.ui_helptext	= "Select between legacy S3 sleep mode or S0ix (Modern Standby)",
	.default_value	= 1,
	.values		= (const struct sm_enum_value[]) {
				{ "ACPI S3",		0	},
				{ "S0ix",		1	},
				SM_ENUM_VALUE_END		},
});
