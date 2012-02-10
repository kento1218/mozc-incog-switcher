//
//  MainController.mm
//  IncogSwitcher
//
//  Created by 澤田 健都 on 10/11/21.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "MainController.h"
#import "ClientProxy.h"

@implementation MainController

@synthesize mainMenu;

- (BOOL)incogState {
	BOOL state = [client isIncognitoMode];
	if (state != internalState) {
		// notify changing explicitly
		[self willChangeValueForKey:@"incogState"];
		internalState = state;
		[self didChangeValueForKey:@"incogState"];
	}
	return state;
}

- (void)setIncogState:(BOOL)state {
	[client setIncognitoMode:state];
	internalState = state;
}

- (id)init {
	self = [super init];
	client = [[ClientProxy alloc] init];
	internalState = [client isIncognitoMode];
	return self;
}

- (IBAction)clearUnusedPrediction:(id)sendor {
	[client clearUnusedPrediction];
}

- (void)dealloc {
	[client release];
    [mainMenu release];
    [super dealloc];
}

@end
