/*  
 *  datetime module
 *  printks datetime in yyyy/MM/dd hh:mm:ss format
 */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/time.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("mrtaalebi");
MODULE_DESCRIPTION("system datetime logger");


static int __init datetime_init(void) {
    ktime_t now;
    struct tm tm_val;

    now = ktime_get_real() / 1000000000;
    time64_to_tm(now, 0, &tm_val);

    printk(
        KERN_INFO "%d/%d/%d %02d:%02d:%02d\n",
        (int) tm_val.tm_year + 1900,
	(int) tm_val.tm_mon,
	(int) tm_val.tm_mday,
	(int) tm_val.tm_hour,
	(int) tm_val.tm_min,
	(int) tm_val.tm_sec
    );

    return 0;
}


static void __exit datetime_exit(void) {
    printk(KERN_INFO "Exit module datetime.\n");
}


module_init(datetime_init);
module_exit(datetime_exit);
