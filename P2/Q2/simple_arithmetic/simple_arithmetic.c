/*  
 *  simple_arithmetic module
 *  takes two integers in load time
 *  and returns their difference and average
 *  in two seperate functions
 *  */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("mrtaalebi");
MODULE_DESCRIPTION("simple_arithmetic module");


static int TA1;
module_param(TA1, int, 0);
MODULE_PARM_DESC(TA1, "FIRST NUMBER");

static int TA2;
module_param(TA2, int, 0);
MODULE_PARM_DESC(TA2, "SECOND NUMBER");


static int __init simple_arithmetic_init(void) {
    printk(KERN_INFO "Init module simple_arithmetic.\n");
    printk(KERN_INFO "simple_arithmetic: %d, %d recieved\n", TA1, TA2);
    return 0;
}


static int simple_arithmetic_difference(void) {
    return TA1 - TA2 > 0 ? TA1 - TA2 : TA2 - TA1;
}
EXPORT_SYMBOL(simple_arithmetic_difference);


static int simple_arithmetic_average(void) {
    return (TA1 + TA2) / 2;
}
EXPORT_SYMBOL(simple_arithmetic_average);


static void __exit simple_arithmetic_exit(void) {
    printk(KERN_INFO "Exit module simple_arithmetic.\n");
}


module_init(simple_arithmetic_init);
module_exit(simple_arithmetic_exit);
