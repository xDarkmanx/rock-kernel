// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) Rockchip Electronics Co.Ltd
 * Author: Finley Xiao <finley.xiao@rock-chips.com>
 *
 * Simplified devfreq support for mainline kernel.
 * BSP OPP/monitor/IPA infrastructure removed.
 * NPU runs at fixed frequency (no DVFS).
 */

#include <linux/clk.h>
#include <linux/pm_runtime.h>

#include "rknpu_drv.h"
#include "rknpu_devfreq.h"

void rknpu_devfreq_lock(struct rknpu_device *rknpu_dev)
{
}
EXPORT_SYMBOL(rknpu_devfreq_lock);

void rknpu_devfreq_unlock(struct rknpu_device *rknpu_dev)
{
}
EXPORT_SYMBOL(rknpu_devfreq_unlock);

int rknpu_devfreq_init(struct rknpu_device *rknpu_dev)
{
	return 0;
}
EXPORT_SYMBOL(rknpu_devfreq_init);

int rknpu_devfreq_runtime_suspend(struct device *dev)
{
	return 0;
}
EXPORT_SYMBOL(rknpu_devfreq_runtime_suspend);

int rknpu_devfreq_runtime_resume(struct device *dev)
{
	return 0;
}
EXPORT_SYMBOL(rknpu_devfreq_runtime_resume);

void rknpu_devfreq_remove(struct rknpu_device *rknpu_dev)
{
}
EXPORT_SYMBOL(rknpu_devfreq_remove);
