/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Compatibility stubs for Rockchip BSP APIs that don't exist in mainline.
 * These allow the rknpu driver to compile on mainline kernels.
 */

#ifndef _RKNPU_COMPAT_H
#define _RKNPU_COMPAT_H

#include <linux/device.h>
#include <linux/of.h>

/* BSP types used in rknpu_device struct */
struct rockchip_opp_info {
	int _compat;
};

struct monitor_dev_info {
	int _compat;
};

struct ipa_power_model_data {
	int _compat;
};

struct monitor_dev_profile {
	void *_compat;
};

enum monitor_type {
	MONITOR_TYPE_DEV,
};

/* BSP functions */
static inline bool rockchip_iommu_is_enabled(struct device *dev)
{
	return false;
}

static inline int rockchip_nvmem_cell_read_u8(struct device_node *np,
					      const char *name, u8 *val)
{
	return -ENOTSUPP;
}

#endif /* _RKNPU_COMPAT_H */
