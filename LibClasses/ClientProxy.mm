//
//  ClientProxy.mm
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/02/14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "ClientProxy.h"
#import "MyIPCClientFactory.h"
#import "MyMachPortManager.h"

#include "base/base.h"
#include "base/mac_util.h"
#include "base/singleton.h"
#include "base/util.h"
#include "client/session.h"
#include "session/config.pb.h"

using mozc::MacUtil;
using mozc::Singleton;
using mozc::Util;
using mozc::config::Config;
using mozc::client::Session;

/*
 Define _environ explicitly
 Workaround to avoid symbol missing
 */
#ifndef environ
#include <crt_externs.h>
char **environ = *_NSGetEnviron();
#endif

namespace {
	void InitEnvironment() {
		string gimeProfDir;
		gimeProfDir = MacUtil::GetApplicationSupportDirectory();
		gimeProfDir = Util::JoinPath(gimeProfDir, "Google");
		gimeProfDir = Util::JoinPath(gimeProfDir, "JapaneseInput");
		Util::SetUserProfileDirectory(gimeProfDir);
		
		MyMachPortManager *manager = Singleton<MyMachPortManager>::get();
		manager->SetPortName("com.google.inputmethod.Japanese.Converter.session");
	}
}

@implementation ClientProxy

- (id)init {
	self = [super init];
	
	// Init client to connect GoogleJapaneseInput
	InitEnvironment();
	session = new Session();
	session->SetIPCClientFactory(Singleton<MyIPCClientFactory>::get());
	
	return self;
}

- (BOOL)pingServer {
	BOOL status = session->PingServer();
	if (!status) {
		LOG(INFO) << "Cannot connect server";
	}
	return status;
}

- (BOOL)isIncognitoMode {
	[self pingServer];
	Config config;
	if(!session->GetConfig(&config)) {
		LOG(INFO) << "Cannot get current configuration";
		return false;
	}
	return config.incognito_mode();
}

- (void)setIncognitoMode:(BOOL)mode {
	[self pingServer];
	Config config;
	if(!session->GetConfig(&config)) {
		LOG(INFO) << "Cannot get current configuration";
		return;
	}
	config.set_incognito_mode(mode);
	if(!session->SetConfig(config)) {
		LOG(INFO) << "Cannot update configuration";
		return;
	}
}

- (void)clearUnusedPrediction {
	[self pingServer];
	if(!session->ClearUnusedUserPrediction()) {
		LOG(INFO) << "Someting wrong with ClearUserPrediction";
	}
}

- (void)dealloc {
	delete session;
	[super dealloc];
}

@end
