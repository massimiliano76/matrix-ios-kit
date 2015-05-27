/*
 Copyright 2015 OpenMarket Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <MatrixSDK/MatrixSDK.h>

#import "MXKAlert.h"

@class MXKRoomTitleView;
@protocol MXKRoomTitleViewDelegate <NSObject>

/**
 Tells the delegate that a MXKAlert must be presented.
 
 @param titleView the room title view.
 @param alert the alert to present.
 */
- (void)roomTitleView:(MXKRoomTitleView*)titleView presentMXKAlert:(MXKAlert*)alert;

@optional

/**
 Tells the delegate that the saving of user's changes is in progress or is finished.
 
 @param titleView the room title view.
 @param saving YES if a request is running to save user's changes.
 */
- (void)roomTitleView:(MXKRoomTitleView*)titleView isSaving:(BOOL)saving;

@end

/**
 'MXKRoomTitleView' instance displays editable room display name.
 */
@interface MXKRoomTitleView : UIView <UITextFieldDelegate> {
    
@protected
    /**
     Potential alert.
     */
    MXKAlert *currentAlert;
    
    /**
     Room messages listener
     */
    id roomListener;
    
}

@property (weak, nonatomic) IBOutlet UITextField *displayNameTextField;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *displayNameTextFieldTopConstraint;

@property (strong, nonatomic) MXRoom *mxRoom;
@property (nonatomic) BOOL editable;
@property (nonatomic) BOOL isEditing;

/**
 *  Returns the `UINib` object initialized for the room title view.
 *
 *  @return The initialized `UINib` object or `nil` if there were errors during
 *  initialization or the nib file could not be located.
 */
+ (UINib *)nib;

/**
 The delegate notified when inputs are ready.
 */
@property (nonatomic) id<MXKRoomTitleViewDelegate> delegate;

/**
 The custom accessory view associated with the first responder item (if any).
 This view is actually used to retrieve the keyboard view. Indeed the keyboard view is the superview of
 this accessory view.
 Nil if the first responder does not belong to 'MXKRoomTitleView' instance.
 */
@property (readonly) UIView *firstResponderInputAccessoryView;

/**
 Dismiss keyboard.
 */
- (void)dismissKeyboard;

/**
 Force title view refresh.
 */
- (void)refreshDisplay;

@end