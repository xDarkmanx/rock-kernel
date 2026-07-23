/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Rockchip IOMMU exported helpers for master drivers.
 *
 * Mainline rockchip-iommu is driven through the generic IOMMU API, but
 * BSP-derived master drivers (e.g. rknpu) may want to handle page faults
 * themselves when "rockchip,master-handle-irq" is set on the IOMMU node.
 */
#ifndef __SOC_ROCKCHIP_IOMMU_H
#define __SOC_ROCKCHIP_IOMMU_H

#include <linux/device.h>
#include <linux/types.h>

struct device;

#if IS_ENABLED(CONFIG_ROCKCHIP_IOMMU)
int rockchip_pagefault_done(struct device *master_dev);
int rockchip_iommu_enable(struct device *master_dev);
int rockchip_iommu_disable(struct device *master_dev);
#else
static inline int rockchip_pagefault_done(struct device *master_dev)
{
	return 0;
}
static inline int rockchip_iommu_enable(struct device *master_dev)
{
	return 0;
}
static inline int rockchip_iommu_disable(struct device *master_dev)
{
	return 0;
}
#endif

#endif /* __SOC_ROCKCHIP_IOMMU_H */
