#include <stdio.h>
#include <stdlib.h>
#include <MobileDevice.h>

void dfuConnect(struct am_recovery_device *rdev) {
	printf("Device connected in DFU Mode\r\n");
}
void dfuDisconnect(struct am_recovery_device *rdev) {
	printf("Device exited DFU Mode\r\n");
}

void recoveryConnect(struct am_recovery_device *rdev) {
	printf("Device connected in Recovery Mode\r\n");
}

void recoveryDisconnect(struct am_recovery_device *rdev) {
	printf("Device exited Recovery Mode\r\n");
}

void normalMode(struct am_device_notification_callback_info *info, void *foo) {
	printf("Device connected in Normal/Restore mode\r\n");
}
int main(int argc, char* argv[]) {
	char* loc;
	//TODO: Make this dynamically find the location
	sprintf(loc, "%s;%s;%s", getenv("PATH"), "C:\\Program Files\\Common Files\\Apple\\Mobile Device Support", "C:\\Program Files\\Common Files\\Apple\\Apple Application Support"); 
	printf("%s", getenv("PATH"));
	setenv("PATH", loc, 0);
	printf("Waiting for device...\r\n");
	struct am_device_notification *notif;
	
	//(Normal/Restore) mode callback
	AMDeviceNotificationSubscribe((am_device_notification_callback) normalMode, 0, 0, 0, &notif);
	
	//(DFU/Recovery) mode callback
	AMRestoreRegisterForDeviceNotifications(dfuConnect, recoveryConnect, dfuDisconnect, recoveryDisconnect, 0, NULL);
	return 0;	
}