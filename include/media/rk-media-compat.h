/* SPDX-License-Identifier: GPL-2.0 */
/*
 * rk-media-compat.h - Bridge Rockchip BSP (6.1) V4L2 API to mainline 6.18.
 *
 * The BSP media drivers were written against the 6.1 V4L2 stack. This header
 * papers over the API renames that landed between 6.1 and 6.18 so the BSP
 * sources can be kept verbatim.
 */
#ifndef __RK_MEDIA_COMPAT_H
#define __RK_MEDIA_COMPAT_H

#include <linux/property.h>
#include <media/v4l2-async.h>
#include <media/v4l2-fwnode.h>

/*
 * In 6.10 struct v4l2_async_subdev was renamed to v4l2_async_connection.
 * This is a preprocessor token rename, so the longer identifiers
 * v4l2_async_register_subdev and v4l2_async_subdev_nf_register (different
 * tokens) are left untouched and handled separately at their call sites.
 */
#define v4l2_async_subdev v4l2_async_connection

/*
 * v4l2_async_nf_parse_fwnode_endpoints() was removed in 6.10. Reimplement it
 * on top of the connection-based API so the BSP notifier setup stays verbatim.
 * The driver's parse callback must return 0 to accept an endpoint; non-zero is
 * treated as a hard error (all current BSP callbacks always return 0).
 */
static inline int
v4l2_async_nf_parse_fwnode_endpoints(struct device *dev,
				     struct v4l2_async_notifier *notifier,
				     size_t asd_struct_size,
				     int (*parse_endpoint)(struct device *dev,
							   struct v4l2_fwnode_endpoint *vep,
							   struct v4l2_async_connection *asc))
{
	struct fwnode_handle *fwnode = dev_fwnode(dev);
	struct fwnode_handle *ep;

	fwnode_graph_for_each_endpoint(fwnode, ep) {
		struct v4l2_fwnode_endpoint vep = { 0 };
		struct v4l2_async_connection *asc;
		int ret;

		ret = v4l2_fwnode_endpoint_parse(ep, &vep);
		if (ret)
			continue;

		asc = __v4l2_async_nf_add_fwnode_remote(notifier, ep,
							asd_struct_size);
		if (IS_ERR(asc)) {
			fwnode_handle_put(ep);
			return PTR_ERR(asc);
		}

		if (parse_endpoint) {
			ret = parse_endpoint(dev, &vep, asc);
			if (ret) {
				fwnode_handle_put(ep);
				return ret;
			}
		}
	}
	return 0;
}

#endif /* __RK_MEDIA_COMPAT_H */

