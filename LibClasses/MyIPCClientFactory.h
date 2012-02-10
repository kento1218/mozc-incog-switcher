//
//  MyIPCClientFactory.h
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/02/14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef __MYIPCCLIENTFACTORY_H_
#define __MYIPCCLIENTFACTORY_H_

#include <string>
#include "ipc/ipc.h"

/*
 * IPCClientFactory that provides IPCClient
 * connected to GoogleJapaneseInput
 */
class MyIPCClientFactory : public mozc::IPCClientFactoryInterface {
public:
	MyIPCClientFactory();
	virtual mozc::IPCClientInterface *NewClient(const string &name, const string &path_name);
	virtual mozc::IPCClientInterface *NewClient(const string &name);
	
protected:
	mozc::IPCClientFactoryInterface *orgFactory;
};

#endif
