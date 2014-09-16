#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe00b4984, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x9551ee6c, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0xcf26e747, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x4b0a6f, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x75bb675a, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xa56d356, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x4292364c, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xe45f60d8, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4CF95F2087918AA71DB2929");
