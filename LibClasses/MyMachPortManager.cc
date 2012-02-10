/*
 *  MyMachPortManager.cpp
 *  IncogSwitcher
 *
 *  Created by 澤田 健都 on 11/02/14.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "MyMachPortManager.h"

#include <launch.h>
#include <mach/mach.h>
#include <servers/bootstrap.h>
#include <string>

#include "ipc/ipc.h"

void MyMachPortManager::SetPortName(const string &port_name) {
	_port_name.assign(port_name);
}

bool MyMachPortManager::GetMachPort(const string &name, mach_port_t *port) {
	kern_return_t kr = bootstrap_look_up(bootstrap_port, _port_name.c_str(), port);
	return kr == BOOTSTRAP_SUCCESS;
}

bool MyMachPortManager::IsServerRunning(const string &name) const {
	// TODO
	return true;
}
