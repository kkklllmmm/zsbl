#include <cache.h>

#define L1_CACHE_BYTES 64

static void sync_dcache(void)
{
	asm volatile ("fence iorw, iorw":::);
}

void __attribute__((weak)) sync_icache(void)
{
	asm volatile ("fence.i");
}

void __attribute__((weak)) flush_dcache_range(unsigned long start, unsigned long end)
{
	register unsigned long i;

	for (i = start & ~(L1_CACHE_BYTES - 1); i < end; i += L1_CACHE_BYTES)
		asm volatile ("cbo.flush (%0)": : "r" (i) :);

	sync_dcache();
}

void __attribute__((weak)) invalidate_dcache_range(unsigned long start, unsigned long end)
{
	register unsigned long i asm("a0") = start & ~(L1_CACHE_BYTES - 1);

	for (i = start & ~(L1_CACHE_BYTES - 1); i < end; i += L1_CACHE_BYTES)
		asm volatile ("cbo.inval (%0)": : "r" (i) :);

	sync_dcache();
}

void __attribute__((weak)) clean_dcache_range(unsigned long start, unsigned long end)
{
	register unsigned long i asm("a0") = start & ~(L1_CACHE_BYTES - 1);

	for (i = start & ~(L1_CACHE_BYTES - 1); i < end; i += L1_CACHE_BYTES)
		asm volatile ("cbo.clean (%0)": : "r" (i) :);

	sync_dcache();
}
