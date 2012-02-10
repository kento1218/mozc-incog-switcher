//
//  AppDelegate.m
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/01/20.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize mainController;
@synthesize item;

- (void)applicationDidFinishLaunching:(NSNotification *)notifer {
	NSStatusBar *systemBar = [NSStatusBar systemStatusBar];
	self.item = [systemBar statusItemWithLength:NSVariableStatusItemLength];
	[self.item setTitle:@"G"];
	[self.item setHighlightMode:YES];
	[self.item setMenu:mainController.mainMenu];
}

- (void)dealloc {
	[item release];
	[mainController release];
	[super dealloc];
}

@end
