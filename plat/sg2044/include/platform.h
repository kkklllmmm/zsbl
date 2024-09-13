#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#if (CONFIG_RAM_START==0xc80000000)
#define OPENSBI_ADDR	0xc00000000
#define KERNEL_ADDR	0xc00200000
#define DEVICETREE_ADDR	0xc08000000
#define RAMFS_ADDR	0xc0b000000
#else
#define OPENSBI_ADDR	0x80000000
#define KERNEL_ADDR	0x80200000
#define DEVICETREE_ADDR	0x88000000
#define RAMFS_ADDR	0x8b000000
#endif

#define BOOT_FROM_SD_FIRST	BIT(0)
#define MULTI_SOCKET_MODE	BIT(15)

#define SG2040_HART_PER_CHIP	64
#define SG2042_MAX_CHIP_NUM	2
#define SG2042_CLUSTER_PER_CHIP	16

#define SG2042_MAX_PHY_ADDR_WIDTH	40
#define SG2040_CHIP_ADDR_SPACE		(1UL << 39)

#define SBI_SOPHGO_FEATURES	\
	 (SBI_PLATFORM_HAS_MFAULTS_DELEGATION | \
	 SBI_PLATFORM_HAS_TIMER_VALUE)

#define CSR_MCOR         0x7c2
#define CSR_MHCR         0x7c1
#define CSR_MCCR2        0x7c3
#define CSR_MHINT        0x7c5
#define CSR_MHINT2       0x7cc
#define CSR_MXSTATUS     0x7c0
#define CSR_PLIC_BASE    0xfc1
#define CSR_MRMR         0x7c6
#define CSR_MRVBR        0x7c7
#define CSR_MCOUNTERWEN  0x7c9
#define CSR_MCPUID       0xfc0
#define CSR_MSMPR        0x7f3

#define SBI_EXT_VENDOR_SG2040_SET_PMU            0x09000001
#define SBI_EXT_VENDOR_SG2040_BOOT_OTHER_CORE    0x09000003

#define SG2040_PLIC_BASE		0x7090000000UL
#define SG2040_MSIP_BASE		0x7094000000UL
#define SG2040_MTIMECMP_BASE		0x70ac000000UL

#define SG2040_PLIC_DELEG_OFFSET     0x001ffffc
#define SG2040_PLIC_DELEG_ENABLE     0x1

#define MANGO_DEVICE_LOCK_REGISTER0	0x7030010140UL
#define MANGO_DEVICE_LOCK_REGISTER1	0x7030010144UL
#define MANGO_PA_BASE			0x0UL
#define MANGO_IO_BASE			0x7000000000UL
#define MANGO_HW_LOCK_BASE		MANGO_DEVICE_LOCK_REGISTER0
#define MANGO_CONSOLE_LOCK		MANGO_DEVICE_LOCK_REGISTER1

#define MANGO_CORES_PER_CLUSTER		4
#define MANGO_CLUSTER_ID(_vhartid)	((_vhartid) / MANGO_CORES_PER_CLUSTER)
#define MANGO_CORE_ID(_vhartid)		((_vhartid) % MANGO_CORES_PER_CLUSTER)

#undef __SG_QEMU__

#define CHIP_WORK_MODE_POD	0x1
#define CHIP_WORK_MODE_CPU	0x2
#define CHIP_WORK_MODE_PCIE	0x3

#endif
