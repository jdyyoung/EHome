#ifndef __DEVICE__H
#define __DEVICE__H

#define SUCCESS 1
#define ERROR   0

#define IP      "192.168.1.6"
#define PORT    8888

extern int device_init(void);
extern int zigbee_scan_mac(void);
extern int zigbee_set_mac(void);
extern int zigbee_led_on(void);
extern int zigbee_led_off(void);
extern int get_hardware_infomation(void);
extern int get_temperature(void);
extern int kernel_update(void);
extern int rootfs_update(void);
extern int userdata_update(void);

extern int zigbee_fd;
extern char macs[8];

#endif
