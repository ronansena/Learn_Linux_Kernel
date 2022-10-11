

#define pr_fmt(fmt) "%s:%s():%d: " fmt, KBUILD_MODNAME, __func__, __LINE__
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("<Ronan Sena>");
MODULE_DESCRIPTION("LKP book:ch4/lkm_template: template");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init lkm_template_init(void)
{
pr_info("inserted\n");

pr_emerg("Hello, world @ log-level KERN_EMERG   [0]\n");
	pr_alert("Hello, world @ log-level KERN_ALERT   [1]\n");
	pr_crit("Hello, world @ log-level KERN_CRIT    [2]\n");
	pr_err("Hello, world @ log-level KERN_ERR     [3]\n");
	pr_warn("Hello, world @ log-level KERN_WARNING [4]\n");
	pr_notice("Hello, world @ log-level KERN_NOTICE  [5]\n");
	pr_info("Hello, world @ log-level KERN_INFO    [6]\n");
	pr_debug("Hello, world @ log-level KERN_DEBUG   [7]\n");
	pr_devel("Hello, world via the pr_devel() macro"
		" (eff @KERN_DEBUG) [7]\n");

	return 0; /* success */
}

static void __exit lkm_template_exit(void)
{
	pr_info("Goodbye, world @ log-level KERN_INFO    [6]\n");
}

module_init(lkm_template_init);
module_exit(lkm_template_exit);
