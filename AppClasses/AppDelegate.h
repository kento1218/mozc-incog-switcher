//
//  AppDelegate.h
//  IncogSwitcher
//
//  Created by 澤田 健都 on 11/01/20.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MainController.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> {
	NSStatusItem *item;
	MainController *mainController;
}
@property (nonatomic, retain) IBOutlet MainController *mainController;
@property (nonatomic, retain) NSStatusItem *item;
@end
