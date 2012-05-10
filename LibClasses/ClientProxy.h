//
//  ClientProxy.h
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/02/14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

namespace mozc {
	namespace client {
		class Client;
	}
}

@interface ClientProxy : NSObject {
	mozc::client::Client *session;
}

- (BOOL)isIncognitoMode;
- (void)setIncognitoMode:(BOOL)mode;
- (void)clearUnusedPrediction;
@end
