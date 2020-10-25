/*  
 *  simple_arithmetic_tester module
 *  calls difference and average function
 *  of simple_arithmetic module
 *  */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("mrtaalebi");
MODULE_DESCRIPTION("simple_arithmetic_tester module");


extern int simple_arithmetic_difference(void);
extern int simple_arithmetic_average(void);


static int __init simple_arithmetic_tester_init(void) {
    printk(KERN_INFO "Init module simple_arithmetic_tester.\n");

    printk(KERN_INFO "simple_arithmetic_difference: %d\n",
        simple_arithmetic_difference());
    printk(KERN_INFO "simple_arithmetic_average: %d\n",
        simple_arithmetic_average());

    return 0;
}


static void __exit simple_arithmetic_tester_exit(void) {
    printk(KERN_INFO "Exit module simple_arithmetic.\n");
}


module_init(simple_arithmetic_tester_init);
module_exit(simple_arithmetic_tester_exit);
