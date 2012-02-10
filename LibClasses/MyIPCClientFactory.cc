//
//  MyIPCClientFactory.mm
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/02/14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "MyIPCClientFactory.h"
#include "MyMachPortManager.h"

#include "base/base.h"
#include "base/singleton.h"
#include "ipc/ipc.h"

using mozc::IPCClient;
using mozc::IPCClientInterface;
using mozc::IPCClientFactory;
using mozc::IPCClientFactoryInterface;
using mozc::Singleton;

MyIPCClientFactory::MyIPCClientFactory() {
	orgFactory = IPCClientFactory::GetIPCClientFactory();
}

IPCClientInterface *MyIPCClientFactory::NewClient(const string &name, const string &path_name) {
	IPCClientInterface *orgClient = orgFactory->NewClient(name, path_name);
	IPCClient *client = reinterpret_cast<IPCClient *> (orgClient);
	client->SetMachPortManager(Singleton<MyMachPortManager>::get());
	
	LOG(INFO) << "connected: " << client->GetServerProductVersion()
	<< ", PID:" << client->GetServerProcessId()
	<< ", Protocol " << client->GetServerProtocolVersion();
	
	return client;
}

IPCClientInterface *MyIPCClientFactory::NewClient(const string &name) {
	return NewClient(name, "");
}
