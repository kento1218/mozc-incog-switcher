//
//  MainController.h
//  IncogSwitcher
//
//  Created by 澤田 健都 on 10/11/21.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ClientProxy.h"

@interface MainController : NSObject {
	NSMenu *mainMenu;
	ClientProxy *client;
	BOOL internalState;
}
@property (nonatomic) BOOL incogState;
@property (nonatomic, retain) IBOutlet NSMenu *mainMenu;

- (IBAction)clearUnusedPrediction:(id)sendor;
@end
