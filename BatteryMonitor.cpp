#include <Windows.h>
#include "BatteryMonitor.h"
#include<batclass.h>
#include<setupapi.h>
#include<devguid.h>
#include <iostream>
#include <string>


using namespace BatteryProject;
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

HPOWERNOTIFY BatteryPowerNotifyHandle;
HPOWERNOTIFY BatterySchemeNotifyHandle; //add two variables for scheme and source
HPOWERNOTIFY BatterySourceNotifyHandle;
DWORD hasBattery();

void BatteryMonitor::WndProc(Message% m) {//message handler function	
	if (m.Msg == WM_POWERBROADCAST) { //identify the message
		cout << "Message id:" << m.Msg << endl;
		int idevent = (int)m.WParam;
		cout << "Event id:" << idevent << endl;
		if (idevent == PBT_POWERSETTINGCHANGE) {//identify the event
			POWERBROADCAST_SETTING* ppstruct = (POWERBROADCAST_SETTING*)m.LParam.ToPointer();
			if (sizeof(int) == ppstruct->DataLength &&ppstruct->PowerSetting == GUID_BATTERY_PERCENTAGE_REMAINING) { //obtained remaining power info
				cout << "Received data about remaining battery power" << endl;
				int percentageremaining = *(int*)(DWORD_PTR)ppstruct->Data;
				this->label2->Text = System::Convert::ToString(percentageremaining) + "%";
			}else if (sizeof(int) == ppstruct->DataLength && ppstruct->PowerSetting == GUID_ACDC_POWER_SOURCE) { //obtained power source info
				cout << "Received data about type of power supply" << endl;
				int powerSource = *(int *)(DWORD_PTR)ppstruct->Data; 
				if (powerSource == 1) { 
					this->label6->Text = "Battery"; 
				}else{
					this->label6->Text = "AC Power";
				}
			}else if (sizeof(GUID) == ppstruct->DataLength && ppstruct->PowerSetting == GUID_POWERSCHEME_PERSONALITY) { //obtained power scheme info
				cout << "Received data about power scheme" << endl;
				GUID newScheme = *(GUID*)(DWORD_PTR)ppstruct->Data;

				if (newScheme == GUID_MAX_POWER_SAVINGS) {
					this->label4->Text = "Power Saving";
				}
				else if (newScheme == GUID_MIN_POWER_SAVINGS) {
					this->label4->Text = "Performance";
				}
				else if (newScheme == GUID_TYPICAL_POWER_SAVINGS) {
					this->label4->Text = "Balanced";
				}
				else
				{
					this->label4->Text = "Balanced";
				}			
			}
		}
	}
	if (m.Msg == WM_LBUTTONDOWN && batteryexist) {//load Battery info upon mouse click
		this->loadBatteryInfo();
	}
	Form::WndProc(m);
}
void BatteryMonitor::OnFormClosing(FormClosingEventArgs^ e){
	cout << "quit application\n" << endl;
	UnregisterPowerSettingNotification(BatteryPowerNotifyHandle);
	UnregisterPowerSettingNotification(BatterySchemeNotifyHandle);
	UnregisterPowerSettingNotification(BatterySourceNotifyHandle);
	Form::OnFormClosing(e);
}
void BatteryMonitor::OnLoad(EventArgs^ e){
	if (!hasBattery()) { 
		this->label2->Text = "This system has no battery";		
		this->batteryexist = false;
	}	
	this->Size = System::Drawing::Size(400, 550);	
	Form::OnLoad(e);
}

DWORD hasBattery()
{
//This function is used to identify if a system has a non-UPS battery
//For this function, thanks to Microsoft's online tutorial
//https://msdn.microsoft.com/en-us/library/windows/desktop/bb204769(v=vs.85).aspx
#define GBS_HASBATTERY 0x1
#define GBS_ONBATTERY  0x2
	// Returned value includes GBS_HASBATTERY if the system has a 
	// non-UPS battery, and GBS_ONBATTERY if the system is running on 
	// a battery.
	//
	// dwResult & GBS_ONBATTERY means we have not yet found AC power.
	// dwResult & GBS_HASBATTERY means we have found a non-UPS battery.

	DWORD dwResult = GBS_ONBATTERY;

	// IOCTL_BATTERY_QUERY_INFORMATION,
	// enumerate the batteries and ask each one for information.

	HDEVINFO hdev =
		SetupDiGetClassDevs(&GUID_DEVCLASS_BATTERY,
			0,
			0,
			DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
	if (INVALID_HANDLE_VALUE != hdev)
	{
		// Limit search to 100 batteries max
		for (int idev = 0; idev < 100; idev++)
		{
			SP_DEVICE_INTERFACE_DATA did = { 0 };
			did.cbSize = sizeof(did);

			if (SetupDiEnumDeviceInterfaces(hdev,
				0,
				&GUID_DEVCLASS_BATTERY,
				idev,
				&did))
			{
				DWORD cbRequired = 0;

				SetupDiGetDeviceInterfaceDetail(hdev,
					&did,
					0,
					0,
					&cbRequired,
					0);
				if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
				{
					PSP_DEVICE_INTERFACE_DETAIL_DATA pdidd =
						(PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LPTR,
							cbRequired);
					if (pdidd)
					{
						pdidd->cbSize = sizeof(*pdidd);
						if (SetupDiGetDeviceInterfaceDetail(hdev,
							&did,
							pdidd,
							cbRequired,
							&cbRequired,
							0))
						{
							// Enumerated a battery.  Ask it for information.
							HANDLE hBattery =
								CreateFile(pdidd->DevicePath,
									GENERIC_READ | GENERIC_WRITE,
									FILE_SHARE_READ | FILE_SHARE_WRITE,
									NULL,
									OPEN_EXISTING,
									FILE_ATTRIBUTE_NORMAL,
									NULL);
							if (INVALID_HANDLE_VALUE != hBattery)
							{
								// Ask the battery for its tag.
								BATTERY_QUERY_INFORMATION bqi = { 0 };

								DWORD dwWait = 0;
								DWORD dwOut;

								if (DeviceIoControl(hBattery,
									IOCTL_BATTERY_QUERY_TAG,
									&dwWait,
									sizeof(dwWait),
									&bqi.BatteryTag,
									sizeof(bqi.BatteryTag),
									&dwOut,
									NULL)
									&& bqi.BatteryTag)
								{
									// With the tag, you can query the battery info.
									BATTERY_INFORMATION bi = { 0 };
									bqi.InformationLevel = BatteryInformation;

									if (DeviceIoControl(hBattery,
										IOCTL_BATTERY_QUERY_INFORMATION,
										&bqi,
										sizeof(bqi),
										&bi,
										sizeof(bi),
										&dwOut,
										NULL))
									{																		
										// Only non-UPS system batteries count
										if (bi.Capabilities & BATTERY_SYSTEM_BATTERY)
										{
											if (!(bi.Capabilities & BATTERY_IS_SHORT_TERM)) //if the battery is not a short term one
											{
												dwResult |= GBS_HASBATTERY;              //then set the "hasbattery" bit
											}

											// Query the battery status.
											BATTERY_WAIT_STATUS bws = { 0 };
											bws.BatteryTag = bqi.BatteryTag;

											BATTERY_STATUS bs;
											if (DeviceIoControl(hBattery,
												IOCTL_BATTERY_QUERY_STATUS,
												&bws,
												sizeof(bws),
												&bs,
												sizeof(bs),
												&dwOut,
												NULL))
											{
												if (bs.PowerState & BATTERY_POWER_ON_LINE) //read the 0-th bit, if it's true, or say if it's plugged in
												{
													dwResult &= ~GBS_ONBATTERY;            //then clear the "ONBATTERY" bit, the 1-st bit
									                                                       //same as dwResult = dwResult & (~GBS_ONBATTERY);  
												}
                                                /*
												printf("powerstate:%x\n", bs.PowerState);
												switch (bs.PowerState) {
												case 0x00000005:
												case 0x00000004: cout << "Currently Charging\n"; 
													break;       																					
												case 0x00000002: cout << "Currently Discharging\n";
													break;
												case 0x00000003: cout << "Battery idling\n";
													break;
												case 0x00000008: cout << "Battery Failure Imminent\n";
													break;
												}
												cout << bs.Voltage << endl;
												cout << bs.Rate << endl;
												*/
											}
										}
									}
								}
								CloseHandle(hBattery);
							}
						}
						LocalFree(pdidd);
					}
				}
			}
			else  if (ERROR_NO_MORE_ITEMS == GetLastError())
			{
				break;  // Enumeration failed - perhaps we're out of items
			}
		}
		SetupDiDestroyDeviceInfoList(hdev);
	}

	//  Final cleanup:  If we didn't find a battery, then presume that we
	//  are on AC power.

	if (!(dwResult & GBS_HASBATTERY))     //if the 0-th bit is 0
		dwResult &= ~GBS_ONBATTERY;       //then clear the 1-st bit too
	                                      //returns 0 for desktop machines because there's no battery
	return dwResult;                     
}

void BatteryMonitor::loadBatteryInfo() {
//this is the function to obtain the detailed information about the battery
//thanks to Microsoft's online tutorial for getting the handle to the battery device
//https://msdn.microsoft.com/en-us/library/windows/desktop/bb204769(v=vs.85).aspx

	HDEVINFO hdev =
		SetupDiGetClassDevs(&GUID_DEVCLASS_BATTERY,
			0,
			0,
			DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
	if (INVALID_HANDLE_VALUE != hdev)
	{
		// Limit search to 100 batteries max
		for (int idev = 0; idev < 100; idev++)
		{
			SP_DEVICE_INTERFACE_DATA did = { 0 };
			did.cbSize = sizeof(did);

			if (SetupDiEnumDeviceInterfaces(hdev,
				0,
				&GUID_DEVCLASS_BATTERY,
				idev,
				&did))
			{
				DWORD cbRequired = 0;

				SetupDiGetDeviceInterfaceDetail(hdev,
					&did,
					0,
					0,
					&cbRequired,
					0);
				if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
				{
					PSP_DEVICE_INTERFACE_DETAIL_DATA pdidd =
						(PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LPTR,
							cbRequired);
					if (pdidd)
					{
						pdidd->cbSize = sizeof(*pdidd);
						if (SetupDiGetDeviceInterfaceDetail(hdev,
							&did,
							pdidd,
							cbRequired,
							&cbRequired,
							0))
						{
							// Enumerated a battery.  Ask it for information.
							HANDLE hBattery =
								CreateFile(pdidd->DevicePath,
									GENERIC_READ | GENERIC_WRITE,
									FILE_SHARE_READ | FILE_SHARE_WRITE,
									NULL,
									OPEN_EXISTING,
									FILE_ATTRIBUTE_NORMAL,
									NULL);
							if (INVALID_HANDLE_VALUE != hBattery)
							{
								// Ask the battery for its tag.
								BATTERY_QUERY_INFORMATION bqi = { 0 };

								DWORD dwWait = 0;
								DWORD dwOut;
								
								if (DeviceIoControl(hBattery,
									IOCTL_BATTERY_QUERY_TAG,
									&dwWait,
									sizeof(dwWait),
									&bqi.BatteryTag,
									sizeof(bqi.BatteryTag),
									&dwOut,
									NULL)
									&& bqi.BatteryTag)
								{
									TCHAR outname[100];   //null-terminated unicode string is an array of TCHAR
									bqi.InformationLevel = BatteryDeviceName;	//now bqi can be used to query battery name						
									if (DeviceIoControl(hBattery,
										IOCTL_BATTERY_QUERY_INFORMATION,
										&bqi,
										sizeof(bqi),
										outname,
										sizeof(outname),
										&dwOut,
										NULL)) {
										wstring tmp = outname; //convert the TCHAR array to a wstring object
										string tmp2(tmp.begin(),tmp.end()); //a wstring object can be converted to a string object
										this->label29->Text = gcnew String(tmp2.c_str());//convert to the System::String^ at last
									}						
								
									ULONG t1;
									bqi.InformationLevel = BatteryTemperature;  //now bqi can be used to query battery temperature
									if (DeviceIoControl(hBattery,
										IOCTL_BATTERY_QUERY_INFORMATION,
										&bqi,
										sizeof(bqi),
										&t1,
										sizeof(t1),
										&dwOut,
										NULL)) {
										ULONG c1 = t1*10-273;
										this->label31->Text = gcnew String(to_string(c1).c_str()) + " Celsius";
									}else if(ERROR_INVALID_FUNCTION== GetLastError()) {
										this->label31->Text = "Thermal sensor not detected";
									}
								
									BATTERY_INFORMATION bi = { 0 };
									bqi.InformationLevel = BatteryInformation; 
									//now bqi can be used to query the system for a battery information struct
									if (DeviceIoControl(hBattery,
										IOCTL_BATTERY_QUERY_INFORMATION,
										&bqi,
										sizeof(bqi),
										&bi,
										sizeof(bi),
										&dwOut,
										NULL))
									{										
										if(bi.Technology==1){
											this->label9->Text = "Rechargeable battery";
										}
										else {
											this->label9->Text = "Nonrechargeable battery";
										}
										string chem(reinterpret_cast<char*>(bi.Chemistry), 4);
										String^ chem2 = gcnew String(chem.c_str());//gcnew means garbage-collected new, no deallocation required
										
										this->label10->Text = gcnew String(chem.c_str());
										this->label14->Text = gcnew String(to_string(bi.DesignedCapacity).c_str()) + " mWh";					
										this->label15->Text = gcnew String(to_string(bi.FullChargedCapacity).c_str()) + " mWh";										
										if (bi.DesignedCapacity) {//battery wear is found by compareing the designed and the full capacity
											double wear = 1.0 - (double)bi.FullChargedCapacity / (double)bi.DesignedCapacity;
											string wearstr = to_string(wear * 100).substr(0, 5);
											this->label16->Text = gcnew String(wearstr.c_str())+"%";
										}														 
										this->label18->Text= gcnew String(to_string(bi.CycleCount).c_str());

										if (bi.Capabilities & BATTERY_SYSTEM_BATTERY)
										{
											// Query the battery status.
											BATTERY_WAIT_STATUS bws = { 0 };
											bws.BatteryTag = bqi.BatteryTag;

											BATTERY_STATUS bs;
											if (DeviceIoControl(hBattery,
												IOCTL_BATTERY_QUERY_STATUS,
												&bws,
												sizeof(bws),
												&bs,
												sizeof(bs),
												&dwOut,
												NULL))
											{
  		 									    printf("powerstate:%x\n", bs.PowerState);
												if (bs.PowerState&BATTERY_CRITICAL) {
													this->label22->Text = "Battery Failure Imminent";
												}else if((bs.PowerState&BATTERY_DISCHARGING)&& (bs.PowerState&BATTERY_POWER_ON_LINE)){
													this->label22->Text = "Plugged in, not charging";
												}else if (bs.PowerState&BATTERY_DISCHARGING) {
													this->label22->Text = "Battery Discharging";
												}
												else if (bs.PowerState&BATTERY_CHARGING) {
													this->label22->Text = "Battery Charging";
												}											
												this->label27->Text= gcnew String(to_string(bs.Capacity).c_str()) + " mWh";
												this->label23->Text = gcnew String(to_string(bs.Voltage).c_str())+" mV";
												this->label24->Text = gcnew String(to_string(bs.Rate).c_str())+" mW";											
												if (bs.Rate == 0) {
													this->label33->Text = "Battery idling";
												}
												else if (bs.Rate < 0) {
													int minutes = (int)((double)bs.Capacity / (double)(bs.Rate)*(-60));
													string min = to_string(minutes) + " minutes to Empty";
													this->label33->Text = gcnew String(min.c_str());

												}
												else if (bs.Rate > 0) {												
													int minutes =(int) (((double)bi.FullChargedCapacity-(double)bs.Capacity )/ (double)(bs.Rate)*60);
													string min = to_string(minutes) + " minutes to Full Charge";
													this->label33->Text = gcnew String(min.c_str());
												}
											}
										}
									}
								}
								CloseHandle(hBattery);
							}
						}
						LocalFree(pdidd);
					}
				}
			}
			else  if (ERROR_NO_MORE_ITEMS == GetLastError())
			{
				break;  // Enumeration failed - perhaps we're out of items
			}
		}
		SetupDiDestroyDeviceInfoList(hdev);
	}
}

[STAThread]
//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) //use this line instead when the debug terminal is no longer needed
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BatteryProject::BatteryMonitor form;                        //create a BatteryMonitor object called "form"
	HWND hwnd = static_cast<HWND>(form.Handle.ToPointer());     //get the window handle of that object
	BatteryPowerNotifyHandle = RegisterPowerSettingNotification(hwnd, &GUID_BATTERY_PERCENTAGE_REMAINING, DEVICE_NOTIFY_WINDOW_HANDLE);  //register to listen for windwos messages
	BatterySchemeNotifyHandle = RegisterPowerSettingNotification(hwnd, &GUID_POWERSCHEME_PERSONALITY, DEVICE_NOTIFY_WINDOW_HANDLE);
	BatterySourceNotifyHandle = RegisterPowerSettingNotification(hwnd, &GUID_ACDC_POWER_SOURCE, DEVICE_NOTIFY_WINDOW_HANDLE);
	Application::Run(%form);
}
