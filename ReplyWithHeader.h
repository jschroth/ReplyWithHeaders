// replyWitHeaders MailBundle - compose reply with message headers as in forwards
//    Copyright (c) 2013 Saptarshi Guha and Jason Schroth
//
//    Permission is hereby granted, free of charge, to any person obtaining
//    a copy of this software and associated documentation files (the
//    "Software"), to deal in the Software without restriction, including
//    without limitation the rights to use, copy, modify, merge, publish,
//    distribute, sublicense, and/or sell copies of the Software, and to
//    permit persons to whom the Software is furnished to do so, subject to
//    the following conditions:
//
//    The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    MIT License for more details.
//
//    You should have received a copy of the MIT License along with this
//    program.  If not, see <http://opensource.org/licenses/MIT>.


/*!
 * @header
 * Defines the <code>ReplyWithHeader</code> Mail bundle (the entrypoint for the
 * plugin) and the <code>ReplyWithHeaderObject</code> category for
 * <code>NSObject</code>.
 * @copyright Copyright (c) 2013 Saptarshi Guha and Jason Schroth
 * @version \@(#) $Id$
 * @updated $Date$
 */

#import <objc/objc.h>
#import <objc/objc-runtime.h>
#import <objc/objc-class.h>

#import "MailHeaderString.h"
#import "MailQuotedOriginal.h"
#import "ReplyWithHeaderMessage.h"
#import "ReplyWithHeaderPreferences.h"
#import "ReplyWithHeaderPreferencesModule.h"

/*!
 * @class
 * The <code>ReplyWithHeader</code> class is the subclass of
 * <code>MVMailBundle</code> that provides the plugin entrypoint for the
 * ReplyWithHeader plugin.
 * @version \@(#) $Id$
 * @updated $Date$
 */
@interface ReplyWithHeader : NSObject {
}

#pragma mark Class initialization
/*! @group Class initialization */

/*!
 * Registers this plugin and swizzles the methods necessary for ReplyWithHeader's
 * functionality.
 */
+ (void)initialize;


#pragma mark MVMailBundle class methods
/*! @group MVMailBundle class methods */

/*!
 * Indicates that this plugin has a preference panel.
 * @result
 *   <code>YES</code>.
 */
+ (BOOL)hasPreferencesPanel;

/*!
 * Returns the class name for this plugin's preference panel owner.
 * @result
 *   <code>ReplyWithHeaderPreferencesModule</code>.
 */
+ (NSString*)preferencesOwnerClassName;

/*!
 * Returns the name for this plugin's preferences panel.
 * @result
 *   <code>ReplyWithHeader</code>.
 */
+ (NSString*)preferencesPanelName;

@end

/*!
 * @category
 * Adds a method for method swizzling to <code>NSObject</code> instances.
 * @version \@(#) $Id$
 * @updated $Date$
 */
@interface NSObject (ReplyWithHeaderObject)

#pragma mark Class methods
/*! @group Class methods */

/*!
 * Adds the methods from this class to the specified class.
 * @param inClass
 *   The <code>Class</code> to which this class's methods should be added.
 */
+ (void)rwhAddMethodsToClass:(Class)cls;

/*!
 * Actually m the specified methods specified to the specified class.  
 * @param m
 *   The list of methods from the cls <code>Class</code>.
 * @param cnt
 *   The number of methods in the list of methods.
 * @param c
 *   The reference to the Class to which the methods will be added.
 * @param cls
 *   The reference to the Class from which the methods were taken.
 */
+ (void)rwhAddMethods:(Method *)m numMethods:(unsigned int)cnt toClass:(Class *)c origClass:(Class *) cls;

/*!
 * Swizzles two methods.  See http://www.cocoadev.com/index.pl?MethodSwizzling
 * @param origSel
 *   The selector specifying the method being replaced.
 * @param newSel
 *   The selector specifying the replacement method.
 * @param cls
 *   The <code>BOOL</code> indicating whether or not the methods being swizzled
 *   are class methods.
 */
+ (void)rwhSwizzle:(SEL)origSel meth:(SEL)newSel classMeth:(BOOL)cls;

@end
