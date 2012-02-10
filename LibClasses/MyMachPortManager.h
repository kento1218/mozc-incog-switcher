/*
 *  MyMachPortManager.h
 *  IncogSwitcher
 *
 *  Created by 澤田 健都 on 11/02/14.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __MYMACHPORTMANAGER_H_
#define __MYMACHPORTMANAGER_H_

#include <string>
#include "ipc/ipc.h"

class MyMachPortManager : public mozc::MachPortManagerInterface {
public:
	virtual bool GetMachPort(const string &name, mach_port_t *port);
	virtual bool IsServerRunning(const string &name) const;
	void SetPortName(const string &port_name);
private:
	string _port_name;
};

#endif
